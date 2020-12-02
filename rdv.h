#ifndef RDV_H
#define RDV_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class rdv
{
public:
    rdv();
    rdv(int,QString,QString,QString,QString);

    int getcinpat(){return cin_pat;}
    void setcinpat(int cin_pat){this->cin_pat=cin_pat;}

    QString getnomprenom(){return nom_prenom;}
    void setnomprenom(QString nom_prenom){this->nom_prenom=nom_prenom;}

    QString getjours(){return jours;}
    void setjours(QString jours){this->jours=jours;}

    QString getheures(){return heures;}
    void setheures(QString heures){this->heures=heures;}

    QString getmaladies(){return la_maladies;}
    void setmaladies(QString la_maladies){this->la_maladies=la_maladies;}
     bool ajouter();
      QSqlQueryModel* afficher();
      bool supprimer(int);
      bool modifier(int,QString,QString,QString,QString);



private:
  int cin_pat;
QString nom_prenom,jours,heures,la_maladies;
};

#endif // RDV_H
