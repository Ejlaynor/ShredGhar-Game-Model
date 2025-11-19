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

}

MainWindow::~MainWindow()
{
    delete ui;
}
