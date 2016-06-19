#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 50.0f
#define BIRD_FRICTION 0.5f
#define BIRD_RESTITUTION 0.5f

using namespace std;
class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, b2World *world);
    void setLinearVelocity(b2Vec2 velocity);
    virtual void shoot();
    b2Vec2 setpos(double x,double y);
    virtual void ability(QList<GameItem*> &list);
    float _radius;
    b2World *_world;
    float _x,_y;
    bool triggered;
    bool abilityused;
    virtual void getpos(float x,float y);

};

#endif // BIRD_H
