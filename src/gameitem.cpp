#include "gameitem.h"

#include <iostream>

GameItem::GameItem(b2World *world):
    g_body(NULL),g_world(world)
{
}

GameItem::~GameItem()
{
    g_world->DestroyBody(g_body);
}

QSizeF GameItem::g_windowsize = QSizeF();
QSizeF GameItem::g_worldsize = QSizeF();

void GameItem::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
}

QSize GameItem::WorldSize2WindowSize(float width, float height) {
    return QSize(width * g_windowsize.width() / g_worldsize.width(), height * g_windowsize.height() / g_worldsize.height());
}//box2d大小轉Qt

b2Vec2 GameItem::setpos(double x, double y){

    double b2d_x = x*g_worldsize.width()/g_windowsize.width()+g_size.width()/2;
    double b2d_y = (1.0f-y/g_windowsize.height())*g_worldsize.height()-g_size.height()/2;

    return b2Vec2(b2d_x, b2d_y);
}//Qt座標轉box2d

void GameItem::paint()
{
    b2Vec2 pos = g_body->GetPosition();
    //std::cout << g_body->GetAngle() << std::endl;

    QPointF mappedPoint;
    mappedPoint.setX(((pos.x-g_size.width()/2) * g_windowsize.width())/g_worldsize.width());//b2d轉qt
    mappedPoint.setY((1.0f - (pos.y+g_size.height()/2)/g_worldsize.height()) * g_windowsize.height());

    g_pixmap.setPos(mappedPoint);//設定在qt的座標
    g_pixmap.resetTransform();//重設旋轉矩陣
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));//設定角度 = 設定旋轉矩陣

    //g_world->DrawDebugData();
}
float GameItem::get_b2d_x(){
    double b2d_x = (this->g_pixmap.pos().x())*g_worldsize.width()/g_windowsize.width()+g_size.width()/2;
    return b2d_x;
}
float GameItem::get_b2d_y(){
    double b2d_y = (1.0f-(this->g_pixmap.pos().y())/g_windowsize.height())*g_worldsize.height()-g_size.height()/2;
    return b2d_y;
}
