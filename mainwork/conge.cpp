#include "conge.h"

conge::conge(){}

bool conge::ajouter(){
    QSqlQuery query;
        query.prepare("INSERT INTO CONGE (ID, NOMEMPLOYE, DATED, DATEF, TYPE) VALUES (:ID, :NOMEMPLOYE, :DATED, :DATEF,:TYPE)");
        query.bindValue(":ID", id);
        query.bindValue(":NOMEMPLOYE", nom);
        query.bindValue(":DATED", dated);
        query.bindValue(":DATEF", datef);
        query.bindValue(":TYPE", type);
        return query.exec();
}
bool conge::supprimer(QString idconge){
    QSqlQuery qry;
        qry.prepare("Delete from CONGE where ID = :ID");
        qry.bindValue(":ID",idconge);
        return qry.exec();
}
QSqlQueryModel *conge::afficher(){
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM CONGE");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMEMPLOYE"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATED"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEF"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("TYPE"));
        return model;
}


void conge::setid(QString n){id=n;}
void conge::setnom(QString n){nom=n;}
void conge::setdated(QString n){dated=n;}
void conge::setdatef(QString n){datef=n;}
void conge::settype(QString n){type=n;}


QString conge::get_id(){return id;}
QString conge::get_nom(){return nom;}
QString conge::get_dated(){return dated;}
QString conge::get_datef(){return datef;}
QString conge::get_type(){return type;}


