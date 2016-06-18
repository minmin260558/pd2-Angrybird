#include "hbarrier.h"

hbarrier::hbarrier(float x,float y,float w,float h, QTimer *timer, b2World *world, QGraphicsScene *scene):barrier(x,y,timer,world)
{
    g_size = QSizeF(w,h);
    _scene = scene;
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w / 2,h / 2);
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyBox;
    fixturedef.density = BARRIER_DENSITY;
    fixturedef.friction = BARRIER_FRICTION;
    fixturedef.restitution = BARRIER_RESTITUTION;
    g_body->SetAngularDamping(5);
    g_body->CreateFixture(&fixturedef);
    g_pixmap.setPixmap(QPixmap(":/image/hwood.png").scaled(GameItem::WorldSize2WindowSize(w, h)));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
     _scene->addItem(&g_pixmap);

}
