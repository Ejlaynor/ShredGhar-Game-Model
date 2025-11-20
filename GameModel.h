#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>



class GameModel : public QObject
{
    Q_OBJECT

public:
    explicit GameModel(QObject *parent = nullptr);
    ~GameModel();

    // Get the graphics view for the game
    QGraphicsView* getGameView();


public slots:

    void handleKeyPress(int keyValue);


private:
    QGraphicsScene *scene;
    QGraphicsView *view;

    // The Background(s)
    QGraphicsPixmapItem *background1;
    QGraphicsPixmapItem *background2;

    // The Skier Sprite
    QGraphicsPixmapItem *skier;

    // Different Images of the Skier
    QPixmap skierLeftSharp;    // -2
    QPixmap skierLeftGentle;   // -1
    QPixmap skierStraight;     // 0
    QPixmap skierRightGentle;  // 1
    QPixmap skierRightSharp;   // 2


    //Game Time
    QTimer *gameTimer;

    void setupGame();

    //Update the game state every clock game tick
    void updateGame();

    //Update the background state every clock game tick
    void updateBackground();

    // Value that determines if skier is going left (negative values) or right (positive)
    int currentTurnAngle = 0;
        //     currentTurnAngle = -2 --> Will do down by 2 left( 1
        //     currentTurnAngle = -1 --> Will do down by 1 left 2
        //     currentTurnAngle = 0 --> Will do down by 3
        //     currentTurnAngle = 1 --> Will do down by 2 right 1
        //     currentTurnAngle = 2 --> Will do down by 1 right 2


    // How fast objects are moving up (or skier "down")
    int currentSpeed = 30;

    void updateSkierSprite();

};

#endif // GAMEMODEL_H
