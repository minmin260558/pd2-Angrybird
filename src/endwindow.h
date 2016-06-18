#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
class MainWindow;

namespace Ui {
class EndWindow;
}

class EndWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndWindow(MainWindow *mainwindow,QWidget *parent = 0);
    ~EndWindow();
    MainWindow *_mainwindow;
signals:
    // Signal for closing the game
    void quitGame();
private slots:
    void on_restart_clicked();
    void on_exit_clicked();
    void QUITSLOT();
    void closeEvent(QCloseEvent *event);

private:
    Ui::EndWindow *ui;
};

#endif // ENDWINDOW_H
