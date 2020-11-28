#include "medicament.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQuery>
#include<QDate>
#include <QString>
#include <QObject>

Medicament::Medicament()
{
     date="04/04/2000";
    //date = QDate::fromString(stringDate,"dd/MM/yyyy");

ref=0; name="",famille="";
 prix=0; quantite=0;
}

Medicament::Medicament(int ref,QString name,QString famille,QString date,float prix,int quantite)
{
    this->ref=ref; this->name=name; this->famille=famille; this->date=date; this->prix=prix; this->quantite=quantite;
}

int Medicament::getRef(){return ref;}
QString Medicament::getName(){return name;}
QString Medicament::getFamille(){return famille;}
QString Medicament::getDate(){return date;}
int Medicament::getQuantite(){return quantite;}
float Medicament::getPrix(){return prix;}

void Medicament::setRef(int ref){this->ref=ref;}
void Medicament::setName(QString name){this->name=name;}
void Medicament::setFamille(QString famille){this->famille=famille;}
void Medicament::setDate(QString date){this->date=date;}
void Medicament::setQuantite(int quantite){this->quantite=quantite;}
void Medicament::setPrix(float prix){this->prix=prix;}

bool Medicament::ajouterMedicament()
{
        QString ref_string=QString::number(ref);
        QString quantite_string=QString::number(quantite);
        QString prix_string=QString::number(prix);
        QSqlQuery query;
         query.prepare("INSERT INTO MEDICAMENT (REFERENCE,NAME,FAMILLE,QUANTITE,PRIX,DATE_EXPIRATION) "
                       "VALUES (:REFERENCE, :NAME, :FAMILLE, :QUANTITE, :PRIX, :DATE_EXPIRATION)");
         query.bindValue(":REFERENCE",ref_string);
         query.bindValue(":NAME",name);
         query.bindValue(":FAMILLE",famille);
         query.bindValue(":QUANTITE",quantite_string);
         query.bindValue(":PRIX",prix_string);
         query.bindValue(":DATE_EXPIRATION",date);

         return query.exec();
}

QSqlQueryModel* Medicament::afficherMedicament()
{
    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * FROM MEDICAMENT");
          model->setHeaderData(0, Qt::Horizontal , QObject::tr("Reference"));
          model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom du medicament"));
          model->setHeaderData(2, Qt::Horizontal , QObject::tr("Famille"));
          model->setHeaderData(3, Qt::Horizontal , QObject::tr("Quantite"));
          model->setHeaderData(5, Qt::Horizontal , QObject::tr("Date d'expiration"));
          model->setHeaderData(4, Qt::Horizontal , QObject::tr("Prix (DT)"));
    return model;

}

bool Medicament::supprimerMedicament(int reff){

     QString ref_string=QString::number(reff);
     QSqlQuery query;
     query.prepare("Delete from MEDICAMENT where REFERENCE = :REFERENCE");
     query.bindValue(":REFERENCE",ref_string);

     return query.exec();

}

bool Medicament::modifierMedicament(int reff){

    QString ref_string=QString::number(reff);
    QString quantite_string=QString::number(quantite);
    QString prix_string=QString::number(prix);
    QSqlQuery query;



    query.prepare("UPDATE MEDICAMENT SET NAME='"+name+"', FAMILLE='"+famille+"', QUANTITE='"+quantite_string+"', PRIX='"+prix_string+"', DATE_EXPIRATION='"+date+"' where REFERENCE = '"+ref_string+"'");


    return query.exec();
}
