#ifndef VBARRIER_H
#define VBARRIER_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include "barrier.h"
class vbarrier : public barrier
{
public:
    vbarrier(float x,float y,float w,float h, QTimer *timer, b2World *world, QGraphicsScene *scene);
    QGraphicsScene *_scene;
};

#endif // VBARRIER_H
