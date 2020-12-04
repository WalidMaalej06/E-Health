#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QDebug>
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test=c.createconnection();
    QFile stylefile(":/./StyleFile.qss");
        stylefile.open(QFile::ReadOnly);
        QString chaine=QLatin1String(stylefile.readAll());
        a.setStyleSheet(chaine);
    MainWindow w;
    if(test){
    w.show();
    QMessageBox::information(nullptr,QObject::tr("Connection Successful"),
    QObject::tr("Done! Database Is Open.\n"
                "Click Cancel To Exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Connection Failed."),
                              QObject::tr("Something Happened! Database Is Not Open.\n"
                                          "Click Cancel To Exit."),QMessageBox::Cancel);
    return a.exec();
    }


