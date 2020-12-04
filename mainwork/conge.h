#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include "qstring.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>

class conge
{
public:
    conge();
    conge(QString i,QString n,QString dd,QString df,QString t):id(i),nom(n),dated(dd),datef(df),type(t){}
    void setid(QString n);
    void setnom(QString n);
    void setdated(QString n);
    void setdatef(QString n);
    void settype(QString n);
    QString get_id();
    QString get_nom();
    QString get_dated();
    QString get_datef();
    QString get_type();
    bool ajouter();
    bool supprimer(QString idconge);
    QSqlQueryModel *afficher();

private:
    QString id;
    QString nom;
    QString dated;
    QString datef;
    QString type;
};

#endif // CONGE_H
