#ifndef ARCH_H
#define ARCH_H
#include "gameitem.h"
#include <QGraphicsScene>
class Arch : public GameItem
{
public:
    Arch(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // ARCH_H
