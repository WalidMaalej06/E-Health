#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QString>
#include <QSqlQuery>
#include<QDate>
#include <QSqlQueryModel>
class Medicament
{
    int ref;
    QString name,famille,date;

    int quantite;
    float prix;

public:
    Medicament();
    Medicament(int,QString,QString, QString,float,int);

    int getRef();
    QString getName();
    QString getFamille();
    QString getDate();
    int getQuantite();
    float getPrix();

    void setRef(int);
    void setName(QString);
    void setFamille(QString);
    void setDate(QString);
    void setQuantite(int);
    void setPrix(float);

    bool ajouterMedicament();
    QSqlQueryModel* afficherMedicament();
    bool supprimerMedicament(int);
    bool modifierMedicament(int);
};

#endif // MEDICAMENT_H
