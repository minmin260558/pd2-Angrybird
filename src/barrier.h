#ifndef BARRIER_H
#define BARRIER_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BARRIER_DENSITY 17.0f
#define BARRIER_FRICTION 0.5f
#define BARRIER_RESTITUTION 0.5f

class barrier: public GameItem
{
public:
    barrier(float x, float y, QTimer *timer, b2World *world);
    QTimer *_timer;
    b2World *_world;
    float _x;
    float _y;

};

#endif // BARRIER_H
