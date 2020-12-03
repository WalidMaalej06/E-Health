#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Patient
{
public:
    Patient();
    Patient(int,QString,QString,QString,QString,QString,QString,QString);

    int getcin(){return cin;}
    void setcin(int cin){this->cin=cin;}

    QString getnom(){return nom;}
    void setnom(QString nom){this->nom=nom;}

    QString getprenom(){return prenom;}
    void setprenom(QString prenom){this->prenom=prenom;}

    QString getsexe(){return sexe;}
    void setsexe(QString sexe){this->sexe=sexe;}

    QString getregion(){return region;}
    void setregion(QString region){this->region=region;}

    QString getville(){return ville;}
    void setville(QString ville){this->ville=ville;}

    QString getdate(){return date_naissance;}
    void setdate(QString date_naissance){this->date_naissance=date_naissance;}


    QString getlieu(){return lieu;}
    void setlieu(QString lieu){this->lieu=lieu;}
    bool ajouter();
     QSqlQueryModel* afficher();
      bool supprimer(int);
      bool modifier(int,QString,QString,QString,QString,QString,QString,QString);
      bool recherche(QString nom,int cin,QString region);
 private:
 int cin;
 QString nom,prenom,sexe,region,ville,date_naissance,lieu;
};

#endif // PATIENT_H
