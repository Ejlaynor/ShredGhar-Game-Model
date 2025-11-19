#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class GameModel : public QObject
{
    Q_OBJECT

public:
    explicit GameModel(QObject *parent = nullptr);
    ~GameModel();

    // Get the graphics view for the game
    QGraphicsView* getGameView();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPixmapItem *skier;  // The skier sprite

    void setupGame();
};

#endif // GAMEMODEL_H
