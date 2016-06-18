#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include<QGraphicsScene>
#include <QPixmap>
class Score: public QObject{

public:
   Score(QGraphicsScene *scene){
         point = 4;
        _scene = scene;
        _point = _scene->addText(QString::number(point),QFont(QString::fromLocal8Bit("AR CENA"),20,QFont::Bold));
        _point->setDefaultTextColor(Qt::white);
        _point->setPos(850,60);
        _scene->addPixmap(QPixmap(":/bird.png"))->setPos(790,60);
        s =_scene->addText("x",QFont(QString::fromLocal8Bit("AR CENA"),20,QFont::Bold));
        s->setPos(835,60);
        s->setDefaultTextColor(Qt::white);

}

   int point ;
   QGraphicsTextItem *_point;
   QGraphicsScene * _scene;
   QGraphicsTextItem *s;
};

#endif // SCORE_H
