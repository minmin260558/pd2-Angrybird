#include "bluebird.h"

BlueBird::BlueBird(float x, float y, float radius, QTimer *timer,int wid_x,int wid_y, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,world)
{
    g_pixmap.setPixmap(QPixmap(":/image/birdie 2.png").scaled(wid_x/30.0,wid_y/15.0));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    _scene = scene;
    _scene->addItem(&g_pixmap);
    _timer = timer;
    _world = world;
    _wid_x = wid_x;
    _wid_y = wid_y;
}

void BlueBird::ability(QList<GameItem*> &list){
    abilityused = true;
    list.push_back(new BlueBird(this->get_b2d_x(),this->get_b2d_y(),0.65f,_timer,_wid_x,_wid_y,_world,_scene));
    ((Bird*)list[12])->shoot();
    ((Bird*)list[12])->setLinearVelocity(b2Vec2(this->g_body->GetLinearVelocity().x+2,this->g_body->GetLinearVelocity().y+2));
}
