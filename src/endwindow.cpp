#include "endwindow.h"
#include "ui_endwindow.h"

EndWindow::EndWindow(MainWindow *mainwindow,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndWindow)
{
    ui->setupUi(this);
    QPixmap bg;
    bg.scaled(900,520);
    setFixedSize(900,500);
    if(mainwindow->win==true){
        bg.load(":/image/win.png");
        ui->label->setPixmap(bg);
        ui->win->setText("You Win!!");
    }
    else{
        bg.load(":/image/lose.png");
        ui->label->setPixmap(bg);
        ui->win->setText("You Lose..");
    }
    _mainwindow = mainwindow;
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));

}

EndWindow::~EndWindow()
{
    delete ui;
}
void EndWindow::closeEvent(QCloseEvent *event)
{
    // Close event
    emit quitGame();
}
void EndWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
void EndWindow::on_restart_clicked()
{
    _mainwindow->CleanGame();
    _mainwindow->StartGame();
    _mainwindow->show();
    this->close();
}

void EndWindow::on_exit_clicked()
{
    emit quitGame();
    QApplication::quit();
}
