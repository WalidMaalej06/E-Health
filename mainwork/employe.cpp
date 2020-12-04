#include "employe.h"

employe::employe(){}


//CRUD
bool employe::ajouter(){
    QSqlQuery query;
        query.prepare("INSERT INTO EMPLOYE (ID, NOM, NUM, MAIL,DATEAD,SEXE,DEPARTEMENT,SALAIRE) VALUES (:ID, :NOM, :NUM, :MAIL, :DATEAD, :SEXE, :DEPARTEMENT, :SALAIRE)");
        query.bindValue(":ID", id);
        query.bindValue(":NOM", nom);
        query.bindValue(":NUM", num);
        query.bindValue(":MAIL", mail);
        query.bindValue(":DATEAD", datead);
        query.bindValue(":SEXE", sexe);
        query.bindValue(":DEPARTEMENT", departement);
        query.bindValue(":SALAIRE", salaire);
        return query.exec();
}
bool employe::supprimer(QString idemploye){
    QSqlQuery qry;
        //QString id = QString::number(idemploye);
        qry.prepare("Delete from EMPLOYE where ID = :ID");
        qry.bindValue(":ID",idemploye);
        return qry.exec();
}
QSqlQueryModel *employe::afficher(){
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYE");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("NUM"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEAD"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("SEXE"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("DEPARTEMENT"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("SALAIRE"));
        return model;
}

//setters
void employe::setid(QString n){id=n;}
void employe::setnom(QString n){nom=n;}
void employe::setnum(QString n){num=n;}
void employe::setmail(QString n){mail=n;}
void employe::setsexe(QString n){sexe=n;}
void employe::setdatead(QString n){datead=n;}
void employe::setdepartement(QString n){departement=n;}
void employe::setsalaire(QString n){salaire=n;}


//getters
QString employe::get_id(){return id;}
QString employe::get_nom(){return nom;}
QString employe::get_num(){return num;}
QString employe::get_mail(){return mail;}
QString employe::get_sexe(){return sexe;}
QString employe::get_datead(){return datead;}
QString employe::get_departement(){return departement;}
QString employe::get_salaire(){return salaire;}


//Metiers
QSqlQueryModel * employe::rechercher_sexe(QString SEXE)
{
    QSqlQuery qry;
    qry.prepare("select * from EMPLOYE where SEXE = :SEXE");
    qry.bindValue(":SEXE",SEXE);
    qry.exec();
    QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery(qry);
    return model;
}

QSqlQueryModel *employe::rechercher_nom(QString NOM)
{

    QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery("select * from EMPLOYE where NOM like'"+NOM+"%'");

    return model;
}

QSqlQueryModel * employe::rechercher_id(QString ID)
{
    QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery("select * from EMPLOYE where ID like'"+ID+"%'");
    return model;
}

QSqlQueryModel * employe::rechercher_date(QString DATEAD)
{
    QSqlQuery qry;
    qry.prepare("select * from EMPLOYE where DATEAD = :DATEAD");
    qry.bindValue(":DATEAD",DATEAD);
    qry.exec();
    QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery(qry);
    return model;
}

QSqlQueryModel * employe::rechercher_combinaison_all(QString NOM,QString SEXE,QString DATEAD)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from EMPLOYE where NOM=:NOM and SEXE=:SEXE and DATEAD=:DATEAD");
    qry->bindValue(":NOM",NOM);
    qry->bindValue(":SEXE",SEXE);
    qry->bindValue(":DATEAD",DATEAD);
    qry->exec();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}

QSqlQueryModel * employe::rechercher_combinaison_nom_date(QString NOM, QString DATEAD)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from EMPLOYE where NOM=:NOM and DATEAD=:DATEAD");
    qry->bindValue(":NOM",NOM);
    qry->bindValue(":DATEAD",DATEAD);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}

QSqlQueryModel * employe::rechercher_combinaison_sexe_date(QString SEXE, QString DATEAD)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from EMPLOYE where SEXE=:SEXE and DATEAD=:DATEAD");
    qry->bindValue(":SEXE",SEXE);
    qry->bindValue(":DATEAD",DATEAD);
    qry->exec();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}

QSqlQueryModel * employe::rechercher_combinaison_nom_sexe(QString NOM, QString SEXE)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from EMPLOYE where NOM=:NOM and SEXE=:SEXE");
    qry->bindValue(":NOM",NOM);
    qry->bindValue(":sexe",SEXE);
    qry->exec();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}


