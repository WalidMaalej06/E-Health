#include "pharmacie.h"
#include "ui_pharmacie.h"
#include "medicament.h"
#include <QMessageBox>

Pharmacie::Pharmacie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pharmacie)
{
    ui->setupUi(this);
    ui->tabMedicaments->setModel(M_tmp.afficherMedicament());
}

Pharmacie::~Pharmacie()
{
    delete ui;
}

void Pharmacie::on_buttonAjouter_clicked()
{
    int ref=ui->refInput->text().toInt();
    QString name=ui->nameInput->text();
    QString famille=ui->familleInput->text();
    QString date=ui->dateInput->text();

    float prix=ui->prixInput->text().toFloat();
    int quantite=ui->quantiteInput->text().toInt();

    QMessageBox msg;
    Medicament M(ref,name,famille,date,prix,quantite);
    bool test=M.ajouterMedicament();
    if(test){
        msg.setText("Ajout avec Success");
        ui->tabMedicaments->setModel(M_tmp.afficherMedicament());
    }
    else{
        msg.setText("Echec d'ajout");
    }
    msg.exec();

}






void Pharmacie::on_BmedicamentDelete_clicked()
{
    int ref = ui->refEdit->text().toInt();
    bool test = M_tmp.supprimerMedicament(ref);
    QMessageBox msg;
    if(test){
        msg.setText("supprission avec Success");
        ui->tabMedicaments->setModel(M_tmp.afficherMedicament());
    }
    else{
        msg.setText("Echec de supprission");
    }
    msg.exec();
}

void Pharmacie::on_BconsulterMedicament_clicked()
{
    QMessageBox msgBox;
    QSqlQuery query;
    QString ref=ui->refEdit->text();
    query.prepare("SELECT * from MEDICAMENT where REFERENCE='"+ref+"'");
    if (query.exec())
    {
        query.next();
        msgBox.setText("item found");
        ui->nomEdit->setText(query.value(1).toString());
        ui->familleEdit->setText(query.value(2).toString());
        ui->quantiteEdit->setText(query.value(3).toString());
        ui->prixEdit->setText(query.value(4).toString());
        ui->dateEdit->setDate(query.value(5).toDate());
        ui->tabMedicaments->setModel(M_tmp.afficherMedicament());
    }
    else
    {
        msgBox.setText("item not found");
    }
    msgBox.exec();
}



void Pharmacie::on_BmedicamentsEdit_clicked()
{
    int ref=ui->refEdit->text().toInt();
    QString name=ui->nomEdit->text();
    QString famille=ui->familleEdit->text();
    QString date=ui->dateEdit->text();
    float prix=ui->prixEdit->text().toFloat();
    int quantite=ui->quantiteEdit->text().toInt();
    Medicament M(ref,name,famille,date,prix,quantite);

    QMessageBox msgBox;


    bool test = M.modifierMedicament(ref);
    if(test){
        msgBox.setText("Modification avec Success");
        ui->tabMedicaments->setModel(M_tmp.afficherMedicament());
    }
    else{
        msgBox.setText("Echec de Modification");
    }
    msgBox.exec();

}
