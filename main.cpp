#include "hygeia.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //stylesheet
    QFile styleFile( "D:/bourguiba/ESPRIT/Second Year/Projet C++/Integration/Ubuntu.qss" );
    styleFile.open( QFile::ReadOnly );
    QString style( styleFile.readAll() );
    a.setStyleSheet( style );

    connection c;
    bool test=c.createconnection();
    hygeia w;

    if (test)
        qDebug() << "connexion successful";
    else
        qDebug() << "connexion failed";
    w.show();

    return a.exec();
}
