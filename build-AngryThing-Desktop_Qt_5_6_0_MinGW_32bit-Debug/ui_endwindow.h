/********************************************************************************
** Form generated from reading UI file 'endwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDWINDOW_H
#define UI_ENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndWindow
{
public:
    QWidget *centralwidget;
    QPushButton *restart;
    QPushButton *exit;
    QLabel *label;
    QLabel *win;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EndWindow)
    {
        if (EndWindow->objectName().isEmpty())
            EndWindow->setObjectName(QStringLiteral("EndWindow"));
        EndWindow->setEnabled(true);
        EndWindow->resize(932, 542);
        centralwidget = new QWidget(EndWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        restart = new QPushButton(centralwidget);
        restart->setObjectName(QStringLiteral("restart"));
        restart->setGeometry(QRect(20, 290, 101, 101));
        restart->setStyleSheet(QStringLiteral("border-image: url(:/image/restart.png);"));
        restart->setFlat(false);
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(780, 280, 101, 101));
        exit->setAutoFillBackground(false);
        exit->setStyleSheet(QLatin1String("background-image: url(:/image/exit.png);\n"
"border-image: url(:/image/exit.png);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 901, 501));
        win = new QLabel(centralwidget);
        win->setObjectName(QStringLiteral("win"));
        win->setGeometry(QRect(380, 20, 1141, 61));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        win->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("AR CENA"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        win->setFont(font);
        win->setFrameShape(QFrame::VLine);
        win->setTextFormat(Qt::PlainText);
        win->setScaledContents(false);
        EndWindow->setCentralWidget(centralwidget);
        label->raise();
        restart->raise();
        exit->raise();
        win->raise();
        menubar = new QMenuBar(EndWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 932, 25));
        EndWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EndWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        EndWindow->setStatusBar(statusbar);

        retranslateUi(EndWindow);

        QMetaObject::connectSlotsByName(EndWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EndWindow)
    {
        EndWindow->setWindowTitle(QApplication::translate("EndWindow", "MainWindow", 0));
        restart->setText(QString());
        exit->setText(QString());
        label->setText(QApplication::translate("EndWindow", "TextLabel", 0));
        win->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EndWindow: public Ui_EndWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDWINDOW_H
