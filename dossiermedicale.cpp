#include "dossiermedicale.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QDebug>
#include <QSqlQueryModel>
#include<QLineEdit>
#include<QString>
#include<QComboBox>
dossiermedicale::dossiermedicale()
{
num=0;
cin=0;
}

dossiermedicale::dossiermedicale(int num,QString datec ,int cin)
{
   this->num=num;
    this->datec=datec;
    this->cin=cin;

}
int dossiermedicale:: getnum()
{
    return num;
}
QString dossiermedicale:: getdatec()
{
    return datec;
}
int dossiermedicale::getcin()
{
    return cin;
}
void dossiermedicale:: setnum(int num )
{
    this->num=num;
}
void dossiermedicale::setdatec(QString datec )
{
   this->datec=datec;
}
void dossiermedicale::setcin(int cin)
{
    this->cin=cin;
}
bool dossiermedicale::ajouter()
{

    QString num_string=QString::number(num);
     QString cin_string=QString::number(cin);

    QSqlQuery query;
          query.prepare("INSERT INTO docmedical (NUM_DOSSIER,DATE_CREATION,CIN) "
                        "VALUES (:id, :forename, :surname)");

          query.bindValue(":id", num_string);
          query.bindValue(":forename", datec);
          query.bindValue(":surname", cin_string);
           return query.exec();


}

QSqlQueryModel * dossiermedicale:: afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * FROM docmedical left join patient on docmedical.cin=patient.cin");
    return model;

}

bool dossiermedicale:: supprimer(int num)
{

   // QString num_string=QString::number(numm);

    QSqlQuery query;
          query.prepare("DELETE FROM docmedical WHERE NUM_DOSSIER= :numm");
          query.bindValue(":numm",num);

           return query.exec();

}



bool dossiermedicale::modifier(int num,QString datec,int cin){
    QSqlQuery query;

    QString num_string= QString::number(num);
    QString cin_string= QString::number(cin);


    query.prepare("UPDATE docmedical SET  DATE_CREATION = :datec, CIN= :cin  WHERE NUM_DOSSIER = :num ");
    query.bindValue(":num", num_string);
    query.bindValue(":datec", datec);
    query.bindValue(":cin", cin_string);

    return  query.exec();
}



QSqlQueryModel * dossiermedicale::rechercher(int cin)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model-> setQuery("SELECT * FROM patient left join docmedical on patient.cin=docmedical.cin where patient.cin = cin");
    return model;
}


QSqlQueryModel * dossiermedicale::tridesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from docmedical left join patient on docmedical.cin=patient.cin order by NUM_DOSSIER  ");

    return model;
}

/*QSqlQueryModel * dossiermedicale::consulter(QString cin)
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Patient where patient.cin = "+cin);

    return model;
}*/

QString dossiermedicale:: apercu_pdf()
 {
     QString text="             ** Les dossiers medicaux  **       \n \n " ;
     QSqlQuery query ;
     QString i,x,z;


      query.exec("select * from docmedical left join patient on docmedical.cin=patient.cin ");
      while (query.next())
      {
         i=query.value(0).toString();
          x=query.value(1).toString();
          z=query.value(2).toString();

        text += "\n num dossier medicale: "+i+"\n - date de creation : "+ x+"\n  - - cin : "+ z+"\n_____________\n";



     }

             return text ;
 }

bool dossiermedicale::verifierId(int cin)
{

    QSqlQuery query;
    QString n;

            query.exec("SELECT cin from PATIENT ");
            while (query.next())
            {
                n=query.value("cin").toString();
                if (n==cin)
                {
                    return true;
                }
            }
    return false;

      }
bool dossiermedicale::verifiernum(int num)
{

    QSqlQuery query;
    QString n;

            query.exec("SELECT NUM_DOSSIER from docmedical ");
            if (query.value(num)==0)
            {
                n=query.value("NUM_DOSSIER").toString();
                if (n==num)
                {
                    return true;
                }
            }
    return false;

      }
