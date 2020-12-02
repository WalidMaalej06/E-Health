#include "rdv.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
rdv::rdv()
{
cin_pat=0;
}

rdv::rdv(int cin_pat,QString nom_prenom,QString jours,QString heures,QString la_maladies)
{

    this->cin_pat=cin_pat;
    this->nom_prenom=nom_prenom;
    this->jours=jours;
    this->heures=heures;
    this->la_maladies=la_maladies;

}

bool rdv::ajouter()
{

    QSqlQuery query;

     QString cin_pat_string=QString::number(cin_pat);


     query.prepare("INSERT INTO RDV (cin_pat,nom_prenom,jours,heures,la_maladies)"
                   "VALUES(:cin_pat,:nom_prenom,:jours,:heures,:la_maladies)");

     query.bindValue(":cin_pat",cin_pat_string);
     query.bindValue(":nom_prenom",nom_prenom);

     query.bindValue(":jours",jours);
     query.bindValue(":heures",heures);
     query.bindValue(":la_maladies",la_maladies);

    return query.exec();
}

bool rdv::supprimer(int cin_pat)
{

    QSqlQuery query;
     query.prepare("Delete from rdv where cin_pat=:cin_pat");

     query.bindValue(0,cin_pat);

     return query.exec();
}


QSqlQueryModel*rdv::afficher()
{

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM rdv");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_PAT"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_PRENOM"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("JOURS"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("HEURES"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("LA_MALADIES"));



   return model;
}
bool rdv::modifier(int cin_pat,QString nom_prenom,QString jours,QString heures,QString la_maladies){
    QSqlQuery query;

    QString cin_pat_string= QString::number(cin_pat);

    query.prepare("UPDATE RDV SET  nom_prenom=:nom_prenom, jours=:jours,heures=:heures,la_maladies=:la_maladies  WHERE cin_pat=:cin_pat ");
    query.bindValue(":cin_pat", cin_pat_string);
    query.bindValue(":nom_prenom", nom_prenom);
    query.bindValue(":jours", jours);
    query.bindValue(":heures", heures);
    query.bindValue(":la_maladies", la_maladies);
    return  query.exec();
}



