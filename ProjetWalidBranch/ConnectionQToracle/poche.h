#ifndef POCHE_H
#define POCHE_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQuery>
#include <QDate>
#include <QString>
#include <QObject>
#include <iostream>
#include <QMessageBox>

class poche
{
    int ref,volume,id;
    QString type,dateDon,dateExp;
public:
    poche();
    poche(int,QString,int,QString,QString,int);

    int getRef();
    QString getType();
    int getId();
    QString getDateDon();
    QString getDateExp();
    int getVolume();

    void setRef(int);
    void setType(QString);
    void setId(int);
    void setDateDon(QString);
    void setDateExp(QString);
    void setVolume(int);

    bool ajouterPoche();
    QSqlQueryModel* afficherPoches();
    bool recherchePoche(QString);
    bool modifierPoche(int);
    bool supprimerPoche(int);
    bool recherchePocheMulti(QString,QString);
    QSqlQueryModel* afficherPochesMulti(QString,QString);
    QSqlQueryModel* afficherPochesTri(QString);

};

#endif // POCHE_H
