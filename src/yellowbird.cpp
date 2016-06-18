#include "yellowbird.h"

YellowBird::YellowBird(float x, float y, float radius, QTimer *timer,int wid_x,int wid_y, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,world)
{
    g_pixmap.setPixmap(QPixmap(":/image/birdie 3.png").scaled(wid_x/30.0,wid_y/16.0));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);

    _scene = scene;
    _scene->addItem(&g_pixmap);
}
void YellowBird::ability(QList<GameItem*> &list){
    abilityused = true;
    float x = this->g_body->GetLinearVelocity().x+10;
    float y = this->g_body->GetLinearVelocity().y-15;
    this->g_body->SetLinearVelocity(b2Vec2(x,y));

}
void YellowBird::shoot(){

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
    fixturedef.density = YELLOWBIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = YELLOWBIRD_RESTITUTION;
    g_body->SetAngularDamping(5);
    g_body->CreateFixture(&fixturedef);
}
