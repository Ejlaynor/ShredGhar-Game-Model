#include "GameModel.h"
#include <QBrush>
#include <QColor>

GameModel::GameModel(QObject *parent)
    : QObject(parent)
{
    // Create the scene with 750x750 dimensions
    scene = new QGraphicsScene(0, 0, 750, 750, this);

    // Set white background
    scene->setBackgroundBrush(QBrush(Qt::white));

    // Create the view
    view = new QGraphicsView(scene);
    view->setFixedSize(750, 750);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Set white background on the view widget
    view->setStyleSheet("background-color: white;");

    setupGame();
}

GameModel::~GameModel()
{
    // scene and view will be deleted by Qt's parent-child relationship
}

void GameModel::setupGame()
{
    // Load and add the skier image
    QPixmap skierPixmap(":/images/skier.png");  // Adjust filename as needed

    // Scale if needed (adjust size as you like)
    skierPixmap = skierPixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    skier = scene->addPixmap(skierPixmap);

    // Position skier at bottom center of screen
    skier->setPos(375 - skierPixmap.width()/2, 650);
}

QGraphicsView* GameModel::getGameView()
{
    return view;
}
