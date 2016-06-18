#ifndef BLACKBIRD_H
#define BLACKBIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <bird.h>


class BlackBird: public Bird
{
public:
    BlackBird(float x, float y, float radius, QTimer *timer,int wid_x,int wid_y, b2World *world, QGraphicsScene *scene);
    QGraphicsScene *_scene;
    virtual void ability(QList<GameItem*> &list);
};

#endif // BLACKBIRD_H
