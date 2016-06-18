#include "pig.h"

Pig::Pig(float x, float y, float radius, QTimer *timer,int wid_x,int wid_y, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    g_size = QSize(radius*2,radius*2);
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    g_pixmap.setPixmap(QPixmap(":/image/boxing.png").scaled(wid_x/26.0,wid_y/15.0));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    _x = x;
    _y = y;
    _wid_x = wid_x;
    _wid_y = wid_y;
    killedpig.load(":/image/killedboxing.png");
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = PIG_DENSITY;
    fixturedef.friction = PIG_FRICTION;
    fixturedef.restitution = PIG_RESTITUTION;
    g_body->SetAngularDamping(5);
    g_body->CreateFixture(&fixturedef);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    _scene = scene;
    _scene->addItem(&g_pixmap);

}

void Pig::changepic(){
    g_pixmap.setPixmap(killedpig.scaled(_wid_x/25.0,_wid_y/15.0));
    _scene->addItem(&g_pixmap);

}
