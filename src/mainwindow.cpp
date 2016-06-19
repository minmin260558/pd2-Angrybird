#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
    StartGame();

}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::shootarea(Bird *birdie,double qt_x,double qt_y){
    if(pow((qt_x*birdie->g_worldsize.width()/birdie->g_windowsize.width()+birdie->g_size.width()/2)-4.2f,2)+pow(((1.0f-qt_y/birdie->g_windowsize.height())*birdie->g_worldsize.height()-birdie->g_size.height()/2)-6.5f,2)<6.0f)
       return true;
    else
       return false;

}
void MainWindow::checkdead(){
    cout << countbird << endl;
    if(countbird == 6){
        countbird = 7;
        EndGame();
        return;
    }

    else if(countbird != 7){
    int deadnum = 0;
    for(int i=11;i<itemList.size();i++)
        if((abs(itemList[i]->g_body->GetLinearVelocity().y)<0.03&&abs(itemList[i]->g_body->GetLinearVelocity().x)<0.03)||itemList[i]->get_b2d_x()>40.0f)
            deadnum += ((Bird*)itemList[i])->triggered;
    if(abs(((Pig*)itemList[1])->get_b2d_x()-((Pig*)itemList[1])->_x)>1.0&&win==false){
        ((Pig*)itemList[1])->changepic();
        win = true;
    }
    cout << "C: " << deadnum << endl;
    if(deadnum == itemList.size()-11){
        for(int i=0;i<deadnum;i++){
            delete itemList[itemList.size()-1];
            itemList.pop_back();
        }      
        changebird();
    }
    }

}

void MainWindow::changebird(){
    if(countbird == 2){
        birdie = new BlueBird(4.2f,6.8f,0.65f,&timer,this->width(),this->height(),world,scene);
        itemList.push_back(birdie);
        countbird = 3;
        emit losebird();
    }
    else if(countbird == 3){

        birdie = new RedBird(4.2f,6.8f,0.65f,&timer,this->width(),this->height(),world,scene);
        itemList.push_back(birdie);
        countbird = 4;
        emit losebird();
    }
    else if(countbird == 4){
        birdie = new YellowBird(4.2f,6.8f,0.65f,&timer,this->width(),this->height(),world,scene);
        itemList.push_back(birdie);
        countbird = 5;
        emit losebird();
    }
    else if(countbird == 5){
        countbird = 6;
        emit losebird();
    }
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress&&countbird<6)
    {
        QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
        if (mouse_event->pos().x() >= birdie->g_pixmap.pos().x()
                && mouse_event->pos().x() <= birdie->g_pixmap.pos().x() + birdie->g_pixmap.boundingRect().width()
                && mouse_event->pos().y() >= birdie->g_pixmap.pos().y()
                && mouse_event->pos().y() <= birdie->g_pixmap.pos().y() + birdie->g_pixmap.boundingRect().height()) {
            mouseclick = 1;
            mouse_diff = birdie->g_pixmap.pos() - mouse_event->pos();
        }
        /* TODO : add your code here */
        // std::cout << "Press !" << std::endl ;
    }
    if(event->type() == QEvent::MouseMove&&countbird<6)
    {
        if(shootarea(birdie,static_cast<QMouseEvent*>(event)->x(),static_cast<QMouseEvent*>(event)->y())){
        if(mouseclick==1){
            QPointF real_point = static_cast<QMouseEvent*>(event)->pos();
            real_point += mouse_diff;
            birdie->setpos(real_point.x(), real_point.y());

        }
        }
          /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease&&birdie->triggered==false&&countbird<6)
    {
        mouseclick = 0;
        birdie->getpos(static_cast<QMouseEvent*>(event)->x()+mouse_diff.x(),static_cast<QMouseEvent*>(event)->y()+mouse_diff.y());
        birdie->shoot();
        QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl("qrc:/image/sound-effects-globe-bird-launch-3.mp3"));
        player->setVolume(50);
        player->play();
        birdie->setLinearVelocity(b2Vec2(-(birdie->get_b2d_x()-4.2)*3.5,-(birdie->get_b2d_y()-7.2)*5.0));

        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
    }
    event->accept();
    return false;
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_A&&(((Bird*)itemList[11])->triggered==true)&&(((Bird*)itemList[11])->abilityused==false)){
        ((Bird*)itemList[11])->ability(this->itemList);
    }

    event->accept();
}

void MainWindow::CalPoint(){
    _score->point-=1;
    _score->_point->setPlainText(QString::number(_score->point));
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}


void MainWindow::EndGame() {
    timer.stop();
    deadtmr.stop();

    timer.disconnect();
    deadtmr.disconnect();
    this->disconnect();

    this->hide();
    (new EndWindow(this))->show();

}

void MainWindow::CleanGame(){
    for(int i=0;i<itemList.size();++i){
        delete itemList[i];
    }

    itemList.clear();
}
void MainWindow::StartGame(){
    countbird = 2;
    win = false;
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width() - 2,height() - 2);
    ui->graphicsView->setScene(scene);
    scene->addPixmap(QPixmap(":/image/20131210124050890 (1).png"));
    QPixmap arch1(":/image/shooter.png");
    scene->addPixmap(arch1.scaled(arch1.size()/1.6))->setPos(100,342);

    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    _score = new Score(scene);

//    world->SetDebugDraw(&debug_draw);
//    debug_draw.SetGraphicsScene(scene);
//    debug_draw.SetFlags( b2Draw::e_shapeBit );
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    // Create ground (You can edit here)
    itemList.push_back(new Land(16, 1.5, 32, 3, QPixmap(":/ground.png").scaled(GameItem::WorldSize2WindowSize(32, 3)),world,scene));
//    itemList.push_back(new Arch(4.0,5.1, 1.5, 2.5, QPixmap(":/image/shooter.png").scaled(GameItem::WorldSize2WindowSize(1.9, 3.5)),world,scene));
    // Create bird (You can edit here)
    Pig *pig = new Pig(15.0f,5.0f,0.65f,&timer,this->width(),this->height(),world,scene);
    itemList.push_back(pig);
    barrier *subbarrier9 = new hbarrier(15.0f,3,10.0, 1.0,&timer,world,scene);
    itemList.push_back(subbarrier9);
    barrier *subbarrier1 = new vbarrier(13.5f,6.5f,1.0, 4.0,&timer,world,scene);
    itemList.push_back(subbarrier1);
    barrier *subbarrier2 = new hbarrier(15.0f,8.5,10.0, 1.0,&timer,world,scene);
    itemList.push_back(subbarrier2);
    barrier *subbarrier3 = new vbarrier(16.6f,6.5f,1.0, 4.0,&timer,world,scene);
    itemList.push_back(subbarrier3);
    barrier *subbarrier4 = new vbarrier(10.5f,6.5f,1.0, 4.0,&timer,world,scene);
    itemList.push_back(subbarrier4);
    barrier *subbarrier5 = new vbarrier(19.5f,6.5f,1.0, 4.0,&timer,world,scene);
    itemList.push_back(subbarrier5);
    barrier *subbarrier6 = new vbarrier(12.0f,10.0f,1.0, 3.0,&timer,world,scene);
    itemList.push_back(subbarrier6);
    barrier *subbarrier7 = new vbarrier(18.0f,10.0f,1.0, 3.0,&timer,world,scene);
    itemList.push_back(subbarrier7);
    barrier *subbarrier8 = new hbarrier(15.0f,12.0f,7.0, 1.0,&timer,world,scene);
    itemList.push_back(subbarrier8);
    birdie = new BlackBird(4.2f,6.8f,0.65f,&timer,this->width(),this->height(),world,scene);
    itemList.push_back(birdie);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(losebird()),this,SLOT(CalPoint()));
    connect(&deadtmr,SIGNAL(timeout()),this,SLOT(checkdead())); 
    timer.start(100/6);
    deadtmr.start(3000);
}
