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
bool Patient::modifier(int cin,QString nom,QString prenom,QString sexe,QString ville,QString region,QString date_naissance,QString lieu){
    QSqlQuery query;

    QString cin_string= QString::number(cin);

    query.prepare("UPDATE PATIENT SET  cin=:cin, nom=:nom,prenom=:prenom,sexe=:sexe ,ville=:ville,region=:region,date_naissance=:date_naissance,lieu=:lieu WHERE cin=:cin ");
    query.bindValue(":cin", cin_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":ville", ville);
    query.bindValue(":region", region);
    query.bindValue(":date_naissance", date_naissance);
    query.bindValue(":lieu", lieu);
    return  query.exec();
}
bool Patient::recherche(QString nom,int cin,QString region)
{
    QMessageBox msgBox;
    QMessageBox msgBox1;
    QSqlQuery query;
    bool retour=0;
    int count=0;
    query.prepare("SELECT * FROM Patient WHERE nom= ? or cin= ? or region= ?");
    query.addBindValue(nom);
    query.addBindValue(cin);
    query.addBindValue(region);
    if(query.exec() )
        {
while (query.next())
   {
   count ++;
    }
if(count==1)
   {
    msgBox.setText("Patient existe");
    msgBox.exec();
    retour=1;
   }
else if (count<1)
{
    msgBox1.setText("Patient n'existe pas");
        msgBox1.exec();
        retour=0;
}
        }
    return retour;

}
