#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include "connection.h"
#include "pharmacie.h"
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection C;
    bool test = C.createConnection();

    MainWindow w;
    Pharmacie p;

    QFile styleSheetFile(":/styleSheet/Integrid.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);


    if(test)
        {
               //w.show();
        qDebug() <<"Connexion avec success";
        p.show();


        }
    else
        qDebug() <<"erreur de conexion";


    return a.exec();
}
