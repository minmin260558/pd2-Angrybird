#ifndef BLUEBIRD_H
#define BLUEBIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <bird.h>
#define BLUEBIRD_DENSITY 30.0f
#define BLUEBIRD_FRICTION 0.8f

class BlueBird: public Bird
{
public:
    BlueBird(float x, float y, float radius, QTimer *timer,int wid_x,int wid_y, b2World *world, QGraphicsScene *scene);
    QGraphicsScene *_scene;
    virtual void ability(QList<GameItem*> &list);
    QTimer *_timer;
    b2World *_world;
    int _wid_x;
    int _wid_y;
};

#endif // BLUEBIRD_H
