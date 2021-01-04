#include "patient.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QMessageBox>

Patient::Patient()
{
cin=0;
}

Patient::Patient(int cin,QString nom,QString prenom,QString sexe,QString ville,QString region,QString date_naissance,QString lieu)
{
 this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->ville=ville;
    this->region=region;
    this->date_naissance=date_naissance;
    this->lieu=lieu;
}


bool Patient::ajouter()
{

    QSqlQuery query;

     QString cin_string=QString::number(cin);


     query.prepare("INSERT INTO PATIENT (cin,nom,prenom,sexe,ville,region,date_naissance,lieu)"
                   "VALUES(:cin,:nom,:prenom,:sexe,:ville,:region,:date_naissance,:lieu)");

     query.bindValue(":cin",cin_string);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":sexe",sexe);
     query.bindValue(":ville",ville);
     query.bindValue(":region",region);
     query.bindValue(":date_naissance",date_naissance);
     query.bindValue(":lieu",lieu);
    return query.exec();
}
bool Patient::supprimer(int cin)
{
    QSqlQuery query;
     query.prepare("Delete from patient where cin=:cin");

     query.bindValue(0,cin);

     return query.exec();

}
bool Patient::recherche_cin(int cin){
QMessageBox msgBox;
    QSqlQuery query;
     QString cin_string=QString::number(cin);
    query.prepare("SELECT * FROM PATIENT WHERE CIN= :cin");
    query.bindValue(":cin", cin_string);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {
        msgBox.setText("Patient n existe pas");
        msgBox.exec();
        return false;
    }
        }
QSqlQueryModel*Patient::afficher()
{

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM patient");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("SEXE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("VILLE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("REGION"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("LIEU"));


   return model;
}
bool Patient::modifier(int cin)
    {
        QSqlQuery query;
        QString cin_string=QString::number(cin);
        if (recherche_cin(cin))
        {

              query.prepare("UPDATE PATIENT SET nom=:nom, prenom=:prenom, sexe=:sexe, ville=:ville, region=:region, date_naissance=:date_naissance,lieu=:lieu WHERE CIN=:cin");
              query.bindValue(":cin", cin_string);
              query.bindValue(":nom",nom);
              query.bindValue(":prenom", prenom);
              query.bindValue(":sexe", sexe);
              query.bindValue(":ville", ville);
              query.bindValue(":region", region);
              query.bindValue(":date_naissance", date_naissance);
              query.bindValue(":lieu", lieu);

        }
              return query.exec();
    }
bool Patient::recherche_nom(QString nom)
{
    QMessageBox msgBox;
    QSqlQuery query;

    query.prepare("SELECT * FROM PATIENT WHERE NOM= :nom");
    query.bindValue(":nom", nom);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {

        msgBox.setText("Patient n existe pas");
        msgBox.exec();
        return false;
    }
}



bool Patient::recherche_region(QString region)
{
    QMessageBox msgBox;
    QSqlQuery query;

    query.prepare("SELECT * FROM PATIENT WHERE REGION= :region");
    query.bindValue(":region",region);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {
        msgBox.setText("Patient n existe pas");
        msgBox.exec();
        return false;
    }
}
QSqlQueryModel* Patient::afficher_cin(int cin)
{
    QSqlQueryModel* model= new QSqlQueryModel();
    QString CIN_string=QString::number(cin);

          model->setQuery("SELECT * FROM PATIENT WHERE CIN='"+CIN_string+"'");

    return model;
}

QSqlQueryModel* Patient::afficher_nom(QString nom)
{
    QSqlQueryModel* model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM PATIENT WHERE NOM='"+nom+"'");

    return model;
}

QSqlQueryModel* Patient::afficher_region(QString region)
{
    QSqlQueryModel* model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM PATIENT WHERE SALAIRE='"+region+"'");

    return model;
}
