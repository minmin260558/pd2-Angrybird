#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <bird.h>
#define YELLOWBIRD_RESTITUTION 0.2f
#define YELLOWBIRD_DENSITY 60.0f

class YellowBird: public Bird
{
public:
    YellowBird(float x, float y, float radius, QTimer *timer,int wid_x,int wid_y, b2World *world, QGraphicsScene *scene);
    QGraphicsScene *_scene;
    virtual void ability(QList<GameItem*> &list);
    virtual void shoot();
};

#endif // YELLOWBIRD_H
