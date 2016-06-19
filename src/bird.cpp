#include "bird.h"

Bird::Bird(float x, float y, float radius, QTimer *timer, b2World *world):GameItem(world)
{
    triggered = false;
    abilityused = false;
    g_size = QSize(radius* 2,radius* 2);
    _x = x;
    _y = y;
    _radius = radius;
    _world = world;
    b2BodyDef bodydef;
    bodydef.type = b2_staticBody;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = _world->CreateBody(&bodydef);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
}
b2Vec2 Bird::setpos(double x,double y){

    b2Vec2 b2d = GameItem::setpos(x, y);
    g_body->SetTransform(b2d, g_body->GetAngle());
}
void Bird::getpos(float x,float y){
    _x=x*g_worldsize.width()/g_windowsize.width()+g_size.width()/2;
    _y=(1.0f-y/g_windowsize.height())*g_worldsize.height()-g_size.height()/2;

}


void Bird::shoot(){

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
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(5);
    g_body->CreateFixture(&fixturedef);
}

void Bird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);

}
void Bird::ability(QList<GameItem*> &list){
    abilityused = true;
}
