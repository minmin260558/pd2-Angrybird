#ifndef HBARRIER_H
#define HBARRIER_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include "barrier.h"

class hbarrier: public barrier
{
public:
    hbarrier(float x,float y,float w,float h, QTimer *timer, b2World *world, QGraphicsScene *scene);
    QGraphicsScene *_scene;

};

#endif // HBARRIER_H
