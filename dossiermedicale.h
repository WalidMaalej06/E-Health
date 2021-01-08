#ifndef DOSSIERMEDICALE_H
#define DOSSIERMEDICALE_H
#include<QSqlQueryModel>
#include<QString>
class dossiermedicale
{
public:
    dossiermedicale();
    dossiermedicale(int,QString,int);
    int getnum();
    QString getdatec();
    int getcin();
   void setnum(int );
   void setdatec(QString);
   void setcin(int);
   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int);
   bool modifier(int,QString ,int);
   QSqlQueryModel * rechercher(int );
   QSqlQueryModel * tridesc();
   QSqlQueryModel * consulter(QString cin);
   QString  apercu_pdf();
   bool verifierId(int cin);
   bool verifiernum(int num);

private:
    int num;
    QString datec;
    int cin;
};

#endif // DOSSIERMEDICALE_H
