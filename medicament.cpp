#include "medicament.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQuery>
#include <QDate>
#include <QString>
#include <QObject>
#include <QMessageBox>
#include <iostream>


Medicament::Medicament()
{
     date="04/04/2000";
     dateFab="05/04/2000";
    //date = QDate::fromString(stringDate,"dd/MM/yyyy");

ref=0; name="",famille="";
 prix=0; quantite=0;
}

Medicament::Medicament(int ref,QString name,QString famille,QString date,QString dateFab,float prix,int quantite)
{
    this->ref=ref; this->name=name; this->famille=famille; this->date=date; this->prix=prix; this->quantite=quantite; this->dateFab=dateFab;
}

int Medicament::getRef(){return ref;}
QString Medicament::getName(){return name;}
QString Medicament::getFamille(){return famille;}
QString Medicament::getDate(){return date;}
QString Medicament::getDateFab(){return dateFab;}
int Medicament::getQuantite(){return quantite;}
float Medicament::getPrix(){return prix;}

void Medicament::setRef(int ref){this->ref=ref;}
void Medicament::setName(QString name){this->name=name;}
void Medicament::setFamille(QString famille){this->famille=famille;}
void Medicament::setDate(QString date){this->date=date;}
void Medicament::setDateFab(QString dateFab){this->dateFab=dateFab;}
void Medicament::setQuantite(int quantite){this->quantite=quantite;}
void Medicament::setPrix(float prix){this->prix=prix;}

bool Medicament::ajouterMedicament()
{
    QMessageBox msgBox;
        QString ref_string=QString::number(ref);
        QString quantite_string=QString::number(quantite);
        QString prix_string=QString::number(prix);

        QDate date1Compare = QDate::fromString(date,"M/d/yyyy");
        QDate date2Compare = QDate::fromString(dateFab,"M/d/yyyy");
        qint64 days = date2Compare.daysTo(date1Compare);


            if (days<0)
            {
                msgBox.setText("Fabrication date is greater than Expiration date");
                msgBox.exec();
                return false;
            }
            else
            {
        QSqlQuery query;
         query.prepare("INSERT INTO MEDICAMENT (REFERENCE,NAME,FAMILLE,QUANTITE,PRIX,DATE_EXPIRATION,DATE_FABRICATION) "
                       "VALUES (:REFERENCE, :NAME, :FAMILLE, :QUANTITE, :PRIX, :DATE_EXPIRATION, :DATE_FABRICATION)");
         query.bindValue(":REFERENCE",ref_string);
         query.bindValue(":NAME",name);
         query.bindValue(":FAMILLE",famille);
         query.bindValue(":QUANTITE",quantite_string);
         query.bindValue(":PRIX",prix_string);
         query.bindValue(":DATE_EXPIRATION",date);
         query.bindValue(":DATE_FABRICATION",dateFab);

         return query.exec();
            }

}

bool Medicament::rechercheMedicament(QString ref)
{
    QMessageBox msgBox;
    QSqlQuery query;
    query.prepare("SELECT * from MEDICAMENT where REFERENCE=:REF");
    query.bindValue(":REF",ref);

    if (query.exec() && query.next())
    {

        msgBox.setText("item found");
        msgBox.exec();
        return true;
    }
    else
    {
    msgBox.setText("item not found");
    msgBox.exec();
    return false;
    }

}

QSqlQueryModel* Medicament::afficherMedicament()
{
    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * FROM MEDICAMENT");
          model->setHeaderData(0, Qt::Horizontal , QObject::tr("Reference"));
          model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom du medicament"));
          model->setHeaderData(2, Qt::Horizontal , QObject::tr("Famille"));
          model->setHeaderData(3, Qt::Horizontal , QObject::tr("Quantite"));
          model->setHeaderData(6, Qt::Horizontal , QObject::tr("Date de fabrication"));
          model->setHeaderData(5, Qt::Horizontal , QObject::tr("Date d'expiration"));
          model->setHeaderData(4, Qt::Horizontal , QObject::tr("Prix (DT)"));

    return model;

}

bool Medicament::supprimerMedicament(int reff){

     QString ref_string=QString::number(reff);
     QSqlQuery query;
     Medicament M;
     if(M.rechercheMedicament(ref_string))
     {
     query.prepare("Delete from MEDICAMENT where REFERENCE = :REF");
     query.bindValue(":REF",ref_string);

     }

     return query.exec();

}

bool Medicament::modifierMedicament(int reff){

    QString ref_string=QString::number(reff);
    QString quantite_string=QString::number(quantite);
    QString prix_string=QString::number(prix);
    QSqlQuery query;
    Medicament M;


    if(M.rechercheMedicament(ref_string))
    {
    query.prepare("UPDATE MEDICAMENT SET NAME=:name , FAMILLE=:famille, QUANTITE=:quantite, PRIX=:prix, DATE_EXPIRATION=:date,DATE_FABRICATION=:dateFab where REFERENCE = :ref");
    query.bindValue(":name",name);
    query.bindValue(":famille",famille);
    query.bindValue(":quantite",quantite_string);
    query.bindValue(":prix",prix_string);
    query.bindValue(":date",date);
    query.bindValue(":dateFab",dateFab);
    query.bindValue(":ref",ref_string);

    }

    return query.exec();
}

bool Medicament::rechercheMedicamentMulti(QString critere,QString value)
{
    QMessageBox msgBox;
    QSqlQuery query;

    query.prepare("SELECT * from MEDICAMENT WHERE "+critere+" = :value ");
    query.bindValue(":value",value);

    if (query.exec() && query.next())
    {

        msgBox.setText("item found");
        msgBox.exec();
        return true;
    }
    else
    {
    msgBox.setText("item not found");
    msgBox.exec();
    return false;
    }
}

QSqlQueryModel* Medicament::afficherMedicamentMulti(QString critere,QString value)
{
    QSqlQueryModel *model = new QSqlQueryModel;



          model->setQuery("SELECT * from MEDICAMENT WHERE "+critere+" = '"+value+"' ");



          model->setHeaderData(0, Qt::Horizontal , QObject::tr("Reference"));
          model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom du medicament"));
          model->setHeaderData(2, Qt::Horizontal , QObject::tr("Famille"));
          model->setHeaderData(3, Qt::Horizontal , QObject::tr("Quantite"));
          model->setHeaderData(6, Qt::Horizontal , QObject::tr("Date de fabrication"));
          model->setHeaderData(5, Qt::Horizontal , QObject::tr("Date d'expiration"));
          model->setHeaderData(4, Qt::Horizontal , QObject::tr("Prix (DT)"));

    return model;
}

QSqlQueryModel* Medicament::afficherMedicamentTri(QString critere)
{
    QSqlQueryModel *model = new QSqlQueryModel;



          model->setQuery("SELECT * from MEDICAMENT ORDER BY "+critere+" ASC");


          model->setHeaderData(0, Qt::Horizontal , QObject::tr("Reference"));
          model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom du medicament"));
          model->setHeaderData(2, Qt::Horizontal , QObject::tr("Famille"));
          model->setHeaderData(3, Qt::Horizontal , QObject::tr("Quantite"));
          model->setHeaderData(6, Qt::Horizontal , QObject::tr("Date de fabrication"));
          model->setHeaderData(5, Qt::Horizontal , QObject::tr("Date d'expiration"));
          model->setHeaderData(4, Qt::Horizontal , QObject::tr("Prix (DT)"));

    return model;
}



