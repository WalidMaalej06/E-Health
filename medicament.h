#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQuery>
#include <QDate>
#include <QString>
#include <QObject>
#include <iostream>
#include <QMessageBox>
#include <QComboBox>
class Medicament
{
    int ref;
    QString name,famille,date,dateFab;

    int quantite;
    float prix;

public:
    Medicament();
    Medicament(int,QString,QString, QString,QString,float,int);

    int getRef();
    QString getName();
    QString getFamille();
    QString getDate();
    QString getDateFab();
    int getQuantite();
    float getPrix();

    void setRef(int);
    void setName(QString);
    void setFamille(QString);
    void setDate(QString);
    void setDateFab(QString);
    void setQuantite(int);
    void setPrix(float);

    bool ajouterMedicament();
    bool rechercheMedicament(QString);
    QSqlQueryModel* afficherMedicament();
    bool supprimerMedicament(int);
    bool modifierMedicament(int);
    bool rechercheMedicamentMulti(QString,QString);
    QSqlQueryModel* afficherMedicamentMulti(QString,QString);
    QSqlQueryModel* afficherMedicamentTri(QString);

};

#endif // MEDICAMENT_H
