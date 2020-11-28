#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include "connection.h"
#include "pharmacie.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection C;
    bool test = C.createConnection();

    MainWindow w;
    Pharmacie p;


    if(test)
        {
               //w.show();
        qDebug() <<"saha hak connectit";
        p.show();


        }
    else
        qDebug() <<"erreur de conexion";


    return a.exec();
}
