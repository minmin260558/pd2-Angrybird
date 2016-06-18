#ifndef REDBIRD_H
#define REDBIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <bird.h>
#define REDBIRD_FRICTION 0.8

class RedBird: public Bird
{
public:
    RedBird(float x, float y, float radius, QTimer *timer,int wid_x,int wid_y, b2World *world, QGraphicsScene *scene);
    QGraphicsScene *_scene;
    virtual void shoot();
};

#endif // REDBIRD_H
