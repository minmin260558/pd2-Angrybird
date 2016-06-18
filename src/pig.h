#ifndef PIG_H
#define PIG_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <cmath>
#define PIG_DENSITY 50.0f
#define PIG_FRICTION 0.5f
#define PIG_RESTITUTION 0.5f

class Pig: public GameItem
{
public:
    Pig(float x, float y, float radius, QTimer *timer,int wid_x,int wid_y, b2World *world, QGraphicsScene *scene);
    QGraphicsScene *_scene;
    float _x;
    float _y;
    int _wid_x;
    int _wid_y;
    void changepic();
    QPixmap killedpig;
};

#endif // PIG_H
