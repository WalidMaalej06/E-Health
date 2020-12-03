#include "poche.h"

poche::poche()
{
    ref=volume=id=0;
    type="";
    dateDon=dateExp="1/1/1800";
}

poche::poche(int ref,QString type,int id,QString dateDon,QString dateExp,int volume)
{
    this->ref=ref; this->type=type; this->id=id; this->dateDon=dateDon; this->dateExp=dateExp; this->volume=volume;
}

int poche::getRef(){return ref;}
QString poche::getType(){return type;}
int poche::getId(){return id;}
QString poche::getDateDon(){return dateDon;}
QString poche::getDateExp(){return dateExp;}
int poche::getVolume(){return volume;}

void poche::setRef(int ref){this->ref=ref;}
void poche::setType(QString type){this->type=type;}
void poche::setId(int id){this->id=id;}
void poche::setDateDon(QString dateDon){this->dateDon=dateDon;}
void poche::setDateExp(QString dateExp){this->dateExp=dateExp;}
void poche::setVolume(int volume){this->volume=volume;}

bool poche::ajouterPoche(){

    QString ref_string=QString::number(ref);
    QString id_string=QString::number(id);
    QString volume_string=QString::number(volume);
    QSqlQuery query;
     query.prepare("INSERT INTO POCHE (REFERENCE,TYPE,ID_DONNEUR,DATE_DON,DATE_EXPIRATION,VOLUME) "
                   "VALUES (:REFERENCE, :TYPE, :ID_DONNEUR, :DATE_DON, :DATE_EXPIRATION, :VOLUME)");
     query.bindValue(":REFERENCE",ref_string);
     query.bindValue(":TYPE",type);
     query.bindValue(":ID_DONNEUR",id_string);
     query.bindValue(":DATE_DON",dateDon);
     query.bindValue(":DATE_EXPIRATION",dateExp);
     query.bindValue(":VOLUME",volume_string);

     return query.exec();
}

QSqlQueryModel* poche::afficherPoches(){

    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * FROM POCHE");
          model->setHeaderData(0, Qt::Horizontal , QObject::tr("Reference"));
          model->setHeaderData(1, Qt::Horizontal , QObject::tr("Type"));
          model->setHeaderData(2, Qt::Horizontal , QObject::tr("ID donneur"));
          model->setHeaderData(3, Qt::Horizontal , QObject::tr("Date de don"));
          model->setHeaderData(4, Qt::Horizontal , QObject::tr("Date d'expiration"));
          model->setHeaderData(5, Qt::Horizontal , QObject::tr("Volume (mL)"));

    return model;
}

bool poche::recherchePoche(QString ref)
{
    QMessageBox msgBox;
    QSqlQuery query;
    query.prepare("SELECT * from POCHE where REFERENCE=:ref");
    query.bindValue(":ref",ref);

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

bool poche::modifierPoche(int reff){

    QString ref_string=QString::number(reff);
    QString id_string=QString::number(id);
    QString volume_string=QString::number(volume);
    QSqlQuery query;
    poche P;


    if(P.recherchePoche(ref_string))
    {
    query.prepare("UPDATE POCHE SET TYPE=:type, ID_DONNEUR=:idDonneur , DATE_DON=:dateDon, DATE_EXPIRATION=:dateExp , VOLUME=:volume where REFERENCE = :ref");
    query.bindValue(":type",type);
    query.bindValue(":idDonneur",id_string);
    query.bindValue(":dateDon",dateDon);
    query.bindValue(":dateExp",dateExp);
    query.bindValue(":volume",volume_string);
    query.bindValue(":ref",ref_string);

    }

    return query.exec();
}

bool poche::supprimerPoche(int reff){

     QString ref_string=QString::number(reff);
     QSqlQuery query;
     poche P;
     if(P.recherchePoche(ref_string))
     {
     query.prepare("Delete from POCHE where REFERENCE = :ref");
     query.bindValue(":ref",ref_string);
     }

     return query.exec();

}

bool poche::recherchePocheMulti(QString critere,QString value)
{
    QMessageBox msgBox;
    QSqlQuery query;

    query.prepare("SELECT * from POCHE WHERE "+critere+" = :value ");
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

QSqlQueryModel* poche::afficherPochesMulti(QString critere,QString value)
{
    QSqlQueryModel *model = new QSqlQueryModel;



          model->setQuery("SELECT * from POCHE WHERE "+critere+" = '"+value+"' ");


          model->setHeaderData(0, Qt::Horizontal , QObject::tr("Reference"));
          model->setHeaderData(1, Qt::Horizontal , QObject::tr("Type"));
          model->setHeaderData(2, Qt::Horizontal , QObject::tr("ID donneur"));
          model->setHeaderData(3, Qt::Horizontal , QObject::tr("Date de don"));
          model->setHeaderData(4, Qt::Horizontal , QObject::tr("Date d'expiration"));
          model->setHeaderData(5, Qt::Horizontal , QObject::tr("Volume (mL)"));

    return model;
}

QSqlQueryModel* poche::afficherPochesTri(QString critere)
{
    QSqlQueryModel *model = new QSqlQueryModel;



          model->setQuery("SELECT * from POCHE ORDER BY "+critere+" ASC");


          model->setHeaderData(0, Qt::Horizontal , QObject::tr("Reference"));
          model->setHeaderData(1, Qt::Horizontal , QObject::tr("Type"));
          model->setHeaderData(2, Qt::Horizontal , QObject::tr("ID donneur"));
          model->setHeaderData(3, Qt::Horizontal , QObject::tr("Date de don"));
          model->setHeaderData(4, Qt::Horizontal , QObject::tr("Date d'expiration"));
          model->setHeaderData(5, Qt::Horizontal , QObject::tr("Volume (mL)"));


    return model;
}
