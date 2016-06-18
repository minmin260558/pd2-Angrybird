#include "redbird.h"

RedBird::RedBird(float x, float y, float radius, QTimer *timer,int wid_x,int wid_y, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,world)
{
    g_pixmap.setPixmap(QPixmap(":/bird.png").scaled(wid_x / 28, wid_y / 15));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    _scene = scene;
    _scene->addItem(&g_pixmap);

}
void RedBird::shoot(){

    triggered = true;

    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(_x,_y);
    bodydef.userData = this;
    _world->DestroyBody(g_body);
    g_body = _world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = _radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = REDBIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(5);
    g_body->CreateFixture(&fixturedef);
}
