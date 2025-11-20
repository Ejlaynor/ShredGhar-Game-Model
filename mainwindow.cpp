#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "GameModel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameModel = new GameModel(this);

    // Add the game view to the central widget
    setCentralWidget(gameModel->getGameView());  // Fixed: gameScreen -> gameModel

    // Set window size
    setFixedSize(750, 750);

    // Set white background on the main window
    setStyleSheet("background-color: white;");


    // For Testing - Remove Later.
    setFocus();

    connect(this, &MainWindow::arrowKeyPress,
            gameModel, &GameModel::handleKeyPress);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key()){


    case Qt::Key_Left:
        qDebug() << "Left Pressed";
        emit arrowKeyPress(-1);
        break;

    case Qt::Key_Down:
        qDebug() << "Down Pressed";
        emit arrowKeyPress(0);
        break;


    case Qt::Key_Right:
        qDebug() << "Right Pressed";
        emit arrowKeyPress(1);
        break;

    }
}
