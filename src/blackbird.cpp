#include "blackbird.h"

BlackBird::BlackBird(float x, float y, float radius, QTimer *timer,int wid_x,int wid_y, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,world)
{
    g_pixmap.setPixmap(QPixmap(":/image/birdie 4.png").scaled(wid_x/30.0,wid_y/13.0));
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    _scene = scene;
    _scene->addItem(&g_pixmap);
}
void BlackBird::ability(QList<GameItem*> &list){

    abilityused = true;
    this->g_body->SetLinearVelocity(b2Vec2(10,12));
    this->g_body->SetAngularVelocity(50.0f);

}
