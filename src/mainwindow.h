#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsTextItem>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include "arch.h"
#include <gameitem.h>
#include <land.h>
#include "bluebird.h"
#include "redbird.h"
#include "yellowbird.h"
#include "blackbird.h"
#include "barrier.h"
#include "vbarrier.h"
#include "hbarrier.h"
#include "pig.h"
#include "endwindow.h"
#include "cmath"
#include <QKeyEvent>
#include <score.h>
#include <QtMultimedia/QMediaPlayer>

class EndWindow;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *,QEvent *event);
    bool shootarea(Bird *birdie,double qt_x,double qt_y);
    void changebird();
    void keyPressEvent(QKeyEvent *event);
    QList<GameItem *> itemList;
    void EndGame();
    void CleanGame();
    void StartGame();

    bool win;
signals:
    void losebird();
private slots:
    void CalPoint();
    void checkdead();
    void tick();

    // For debug slot
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QTimer timer;
    Bird *birdie;
    int mouseclick;
    QPointF mouse_diff;
    int countbird;
    QTimer deadtmr;
    Score *_score;


};

#endif // MAINWINDOW_H
