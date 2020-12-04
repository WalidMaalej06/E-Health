#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include "qstring.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>

class employe
{
public:
    employe();
    employe(QString i,QString n,QString nu, QString m,QString d,QString s, QString dep, QString sa):id(i),nom(n),num(nu),mail(m),datead(d),sexe(s),departement(dep),salaire(sa){}
    void setid(QString n);
    void setnom(QString n);
    void setnum(QString n);
    void setmail(QString n);
    void setsexe(QString n);
    void setdatead(QString n);
    void setsalaire(QString n);
    void setdepartement(QString n);

    QString get_id();
    QString get_nom();
    QString get_num();
    QString get_mail();
    QString get_sexe();
    QString get_datead();
    QString get_salaire();
    QString get_departement();

    bool ajouter();
    bool supprimer(QString idemploye);
    QSqlQueryModel *afficher();

    QSqlQueryModel *rechercher_id(QString);
    QSqlQueryModel *rechercher_nom(QString);
    QSqlQueryModel *rechercher_sexe(QString);
    QSqlQueryModel *rechercher_date(QString);
    QSqlQueryModel *rechercher_departement(QString);
    QSqlQueryModel *rechercher_salaire(QString);
    QSqlQueryModel *rechercher_combinaison_all(QString,QString,QString);
    QSqlQueryModel *rechercher_combinaison_nom_date(QString,QString);
    QSqlQueryModel *rechercher_combinaison_sexe_date(QString,QString);
    QSqlQueryModel *rechercher_combinaison_nom_sexe(QString,QString);

private:
    QString id;
    QString nom;
    QString num;
    QString mail;
    QString datead;
    QString sexe;
    QString departement;
    QString salaire;
};

#endif // EMPLOYE_H
