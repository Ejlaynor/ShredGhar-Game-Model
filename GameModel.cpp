#include "GameModel.h"
#include <QBrush>
#include <QColor>
#include <QKeyEvent>
#include <QTimer>



GameModel::GameModel(QObject *parent)
    : QObject(parent)
{
    // Create the scene with 750x750 dimensions
    scene = new QGraphicsScene(0, 0, 750, 750, this);

    // Set white background
    // scene->setBackgroundBrush(QBrush(Qt::white));

    // Create the view
    view = new QGraphicsView(scene);
    view->setFixedSize(750, 750);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Set white background on the view widget
    view->setStyleSheet("background-color: white;");

    // Don't let view steal focus
    view->setFocusPolicy(Qt::NoFocus);



    setupGame();



    gameTimer = new QTimer(this);

    connect(gameTimer, &QTimer::timeout,
            this, &GameModel::updateGame);




    gameTimer->start(25);

}

GameModel::~GameModel() {}

void GameModel::setupGame()
{
    // Load and add the skier image and background
    QPixmap skierPixmap(":/images/images/SkierStraight.png");
    QPixmap backgroundPixmap(":/images/images/GameBackground.png");

    // Scaling Skier Image
    skierPixmap = skierPixmap.scaled(75, 75, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Adding Skier Image to the Scene
    skier = scene->addPixmap(skierPixmap);

    // Setting the position of the Skier at the top center
    skier->setPos(375 - skierPixmap.width()/2, 150);


    // Scaling Background Image
    backgroundPixmap = backgroundPixmap.scaled(750, 750, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Adding Both backgrounds to the scene (seamless scrolling)
    background1 = scene->addPixmap(backgroundPixmap);
    background2 = scene->addPixmap(backgroundPixmap);

    // Setting the position of the backgrouds (first one is on screen - the second one starts above)
    background1->setPos(0, 0);
    background2->setPos(0, 750);

    background1->setZValue(-1);
    background2->setZValue(-1);
}

QGraphicsView* GameModel::getGameView()
{
    return view;
}


void GameModel::handleKeyPress(int keyValue){

    currentTurnAngle = (keyValue == 0) ? 0 : currentTurnAngle + keyValue;

    if (currentTurnAngle > 2)  currentTurnAngle = 2;
    if (currentTurnAngle < -2) currentTurnAngle = -2;

    qDebug() << "currentTurnAngle" << currentTurnAngle;

}


void GameModel::updateGame(){


    updateBackground();


    // Movement based on currentTurnAngle
    int horizontalMove = 0;

    switch(currentTurnAngle) {
    case -2:  // Sharp left turn
        horizontalMove = -10;
        break;
    case -1:  // Gentle left turn
        horizontalMove = -5;
        break;
    case 0:   // Straight down
        horizontalMove = 0;
        break;
    case 1:   // Gentle right turn
        horizontalMove = 5;
        break;
    case 2:   // Sharp right turn
        horizontalMove = 10;
        break;
    }

    // Move the skier
    qreal newX = skier->x() + horizontalMove;

    // Keep skier within horizontal bounds
    if (newX >= 0 && newX + 75 <= 750) {  // 75 is skier width
        skier->setX(newX);
    }



}


void GameModel::updateBackground(){

    switch(currentTurnAngle) {
        case -2: currentSpeed = -10; break;
        case -1: currentSpeed = -20; break;
        case 0:  currentSpeed = -30; break;
        case 1:  currentSpeed = -20; break;
        case 2:  currentSpeed = -10; break;
    }


    background1->moveBy(0, currentSpeed);
    background2->moveBy(0, currentSpeed);



    if (background1->y() <= -750) {
        // Reposition it above background2
        background1->setPos(0, background2->y() +750);
    }

    // Check if background2 has scrolled completely off the top
    if (background2->y() <= -750 ) {
        // Reposition it above background1
        background2->setPos(0, background1->y() + 750);
    }

}
