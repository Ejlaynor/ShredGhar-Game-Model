#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Forward declaration
class GameModel;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GameModel *gameModel;

protected:
    void keyPressEvent(QKeyEvent *event) override;


signals:
    void arrowKeyPress(int keyValue);

};
#endif // MAINWINDOW_H
