#include "barrier.h"

barrier::barrier(float x, float y, QTimer *timer, b2World *world):GameItem(world)
{
    _x = x;
    _y = y;
    _timer = timer;
    _world = world;
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.position.Set(_x,_y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

}
