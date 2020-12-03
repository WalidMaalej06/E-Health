#include "pharmacie.h"
#include "ui_pharmacie.h"
#include "medicament.h"
#include "poche.h"
#include <QMessageBox>
#include <iostream>
#include <QObject>
#include<QDate>
#include <QString>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>

Pharmacie::Pharmacie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pharmacie)
{
    ui->setupUi(this);
    ui->tabMedicaments->setModel(M_tmp.afficherMedicament());
    click=new QSound(":/sons/click.wav");
     ui->cFamilleInput->addItem("Adrenaline");
     ui->cFamilleInput->addItem("Antalgiques");
     ui->cFamilleInput->addItem("Anti Inflammatoires");
     ui->cFamilleInput->addItem("Dermatologie");
     ui->cFamilleInput->addItem("Gynecologie");
     ui->cFamilleInput->addItem("Pneumologie");
     ui->cFamilleInput->addItem("Toxicologie");


     ui->cFamilleEdit->addItem("Adrenaline");
     ui->cFamilleEdit->addItem("Antalgiques");
     ui->cFamilleEdit->addItem("Anti Inflammatoires");
     ui->cFamilleEdit->addItem("Dermatologie");
     ui->cFamilleEdit->addItem("Gynecologie");
     ui->cFamilleEdit->addItem("Pneumologie");
     ui->cFamilleEdit->addItem("Toxicologie");

    ui->cCritereMed->addItem("NAME");
    ui->cCritereMed->addItem("FAMILLE");
    ui->cCritereMed->addItem("QUANTITE");
    ui->cCritereMed->addItem("PRIX");

    ui->cTriMed->addItem("REFERENCE");
    ui->cTriMed->addItem("NAME");
    ui->cTriMed->addItem("FAMILLE");
    ui->cTriMed->addItem("QUANTITE");
    ui->cTriMed->addItem("PRIX");

    ui->cTypeInputPoche->addItem("AB+");
    ui->cTypeInputPoche->addItem("AB-");
    ui->cTypeInputPoche->addItem("A+");
    ui->cTypeInputPoche->addItem("A-");
    ui->cTypeInputPoche->addItem("B+");
    ui->cTypeInputPoche->addItem("B-");
    ui->cTypeInputPoche->addItem("O+");
    ui->cTypeInputPoche->addItem("O-");

    ui->cTypeEditPoche->addItem("AB+");
    ui->cTypeEditPoche->addItem("AB-");
    ui->cTypeEditPoche->addItem("A+");
    ui->cTypeEditPoche->addItem("A-");
    ui->cTypeEditPoche->addItem("B+");
    ui->cTypeEditPoche->addItem("B-");
    ui->cTypeEditPoche->addItem("O+");
    ui->cTypeEditPoche->addItem("O-");

    ui->cRecherchePoche->addItem("TYPE");
    ui->cRecherchePoche->addItem("ID_DONNEUR");
    ui->cRecherchePoche->addItem("VOLUME");

    ui->cTriPoches->addItem("REFERENCE");
    ui->cTriPoches->addItem("TYPE");
    ui->cTriPoches->addItem("ID_DONNEUR");
    ui->cTriPoches->addItem("VOLUME");


    QSqlQuery query;
        query.prepare("SELECT REFERENCE FROM MEDICAMENT");
        if(query.exec())
        {

                while(query.next())
                {
                    ui->refEdit->addItem(query.value(0).toString());
                }
        }

        query.prepare("SELECT REFERENCE FROM POCHE");
        if(query.exec())
        {

                while(query.next())
                {
                    ui->refEditPoche->addItem(query.value(0).toString());
                }
        }






}

Pharmacie::~Pharmacie()
{
    delete ui;
}

void Pharmacie::on_buttonAjouter_clicked()
{
    click->play();
    int ref=ui->refInput->text().toInt();
    QString name=ui->nameInput->text();
    QString famille=ui->cFamilleInput->currentText();
    QString date=ui->dateInput->text();
    QString dateFab=ui->dateFabInput->text();

    float prix=ui->prixInput->text().toFloat();
    int quantite=ui->quantiteInput->text().toInt();

    QMessageBox msg;
    Medicament M(ref,name,famille,date,dateFab,prix,quantite);
    bool test=M.ajouterMedicament();
    if(test){
        msg.setText("Ajout avec Success");
        ui->refEdit->addItem(ui->refInput->text());

    }
    else{
        msg.setText("Echec d'ajout");
    }
    msg.exec();

}






void Pharmacie::on_BmedicamentDelete_clicked()
{
    click->play();
    int ref = ui->refEdit->currentText().toInt();

    bool test = M_tmp.supprimerMedicament(ref);
    QMessageBox msg;
    if(test){
        msg.setText("supprission avec Success");
        ui->refEdit->removeItem(ui->refEdit->currentIndex());


    }
    else{
        msg.setText("Echec de supprission");
    }
    msg.exec();
}

void Pharmacie::on_BconsulterMedicament_clicked()
{
    click->play();
    QString ref=ui->refEdit->currentText();
    QSqlQuery query;

    if (M_tmp.rechercheMedicament(ui->refEdit->currentText()))
    {
        query.prepare("SELECT * from MEDICAMENT where REFERENCE='"+ref+"'");
        query.exec();
        query.next();

        ui->nomEdit->setText(query.value(1).toString());
        ui->cFamilleEdit->setCurrentText(query.value(2).toString());
        ui->quantiteEdit->setText(query.value(3).toString());
        ui->prixEdit->setText(query.value(4).toString());

        QDate date = QDate::fromString(query.value(5).toString(),"M/d/yyyy");
        ui->dateEdit->setDate(date);


        QDate dateFab = QDate::fromString(query.value(6).toString(),"M/d/yyyy");
        ui->dateFabEdit->setDate(dateFab);

    }

}



void Pharmacie::on_BmedicamentsEdit_clicked()
{
    click->play();
    int ref=ui->refEdit->currentText().toInt();
    QString name=ui->nomEdit->text();
    QString famille=ui->cFamilleEdit->currentText();
    QString date=ui->dateEdit->text();
    QString dateFab=ui->dateFabEdit->text();
    float prix=ui->prixEdit->text().toFloat();
    int quantite=ui->quantiteEdit->text().toInt();
    Medicament M(ref,name,famille,date,dateFab,prix,quantite);

    QMessageBox msgBox;


    bool test = M.modifierMedicament(ref);
    if(test){
        msgBox.setText("Modification avec Success");

    }
    else{
        msgBox.setText("Echec de Modification");
    }
    msgBox.exec();

}

void Pharmacie::on_afficherStock_2_tabBarClicked(int index)
{
    if (index==1)
    ui->tabMedicaments->setModel(M_tmp.afficherMedicament());

}



void Pharmacie::on_buttonRechercheMed_clicked()
{
    click->play();
    Medicament M;

    if(M.rechercheMedicamentMulti(ui->cCritereMed->currentText(),ui->valueResearch->text()))
    {
    ui->tabMedicaments->setModel(M_tmp.afficherMedicamentMulti(ui->cCritereMed->currentText(),ui->valueResearch->text()));
    }
    else
    {
        ui->tabMedicaments->setModel(M_tmp.afficherMedicament());
    }
}

void Pharmacie::on_bTri_clicked()
{
    click->play();
    ui->tabMedicaments->setModel(M_tmp.afficherMedicamentTri(ui->cTriMed->currentText()));
}

void Pharmacie::on_ajouterPoche_2_clicked()
{
    click->play();
    int ref=ui->refInputPoche->text().toInt();
    QString type=ui->cTypeInputPoche->currentText();
    int id=ui->idInputPoche->text().toInt();
    QString dateDon=ui->dateInputPoche->text();

    QDate date = QDate::fromString(dateDon,"M/d/yyyy");

    qint64 days = 40;
    QString dateExp = date.addDays(days).toString("M/d/yyyy");




    int volume=ui->volumeInputPoche->text().toInt();

    QMessageBox msg;
    poche P(ref,type,id,dateDon,dateExp,volume);

    if(P.ajouterPoche())
    {
        msg.setText("Ajout avec Success");
        ui->refEditPoche->addItem(ui->refInputPoche->text());
    }
    else{
        msg.setText("Echec d'ajout");
    }
    msg.exec();


}

void Pharmacie::on_tabPharmacie_tabBarClicked(int index)
{

    if (index==1)
        ui->tabPoches->setModel(P_tmp.afficherPoches());

}



void Pharmacie::on_consulterPoche_clicked()
{
    click->play();
    QString ref=ui->refEditPoche->currentText();
    QSqlQuery query;
    if(P_tmp.recherchePoche(ref))
    {
        query.prepare("SELECT * from POCHE where REFERENCE='"+ref+"'");
        query.exec();
        query.next();


        ui->cTypeEditPoche->setCurrentText(query.value(1).toString());
        ui->idEditPoche->setText(query.value(2).toString());


        QDate date = QDate::fromString(query.value(3).toString(),"M/d/yyyy");
        ui->dateDonEditPoche->setDate(date);




        ui->volumeEditPoche->setText(query.value(5).toString());
    }
}

void Pharmacie::on_modifierPoche_clicked()
{
    click->play();
    int ref=ui->refEditPoche->currentText().toInt();
    QString type=ui->cTypeEditPoche->currentText();
    int id=ui->idEditPoche->text().toInt();
    QString dateDon=ui->dateDonEditPoche->text();

    QDate date = QDate::fromString(dateDon,"M/d/yyyy");

    qint64 days = 40;
    QString dateExp = date.addDays(days).toString("M/d/yyyy");


    int volume=ui->volumeEditPoche->text().toInt();
    poche P(ref,type,id,dateDon,dateExp,volume);

    QMessageBox msgBox;


    bool test = P.modifierPoche(ref);
    if(test){
        msgBox.setText("Modification avec Success");

    }
    else{
        msgBox.setText("Echec de Modification");
    }
    msgBox.exec();



}

void Pharmacie::on_supprimerPoche_clicked()
{
    click->play();
    int ref = ui->refEditPoche->currentText().toInt();
    bool test = P_tmp.supprimerPoche(ref);
    QMessageBox msg;
    if(test){
        msg.setText("supprission avec Success");
        ui->refEditPoche->removeItem(ui->refEditPoche->currentIndex());

    }
    else{
        msg.setText("Echec de supprission");
    }
    msg.exec();
}



void Pharmacie::on_rechercherButtonPoche_clicked()
{
    click->play();
    poche P;

    if(P.recherchePocheMulti(ui->cRecherchePoche->currentText(),ui->rechercheInputPoche->text()))
    {
    ui->tabPoches->setModel(P_tmp.afficherPochesMulti(ui->cRecherchePoche->currentText(),ui->rechercheInputPoche->text()));
    }
    else
    {
        ui->tabPoches->setModel(P_tmp.afficherPoches());
    }
}


void Pharmacie::on_actualiserTriPoches_clicked()
{
    click->play();
    ui->tabPoches->setModel(P_tmp.afficherPochesTri(ui->cTriPoches->currentText()));
}

void Pharmacie::on_BimpPoches_clicked()
{
    click->play();
    QPrinter printer;

              printer.setPrinterName("desiered printer name");

            QPrintDialog dialog(&printer,this);

              if(dialog.exec()== QDialog::Rejected)

                 return;

}

void Pharmacie::on_pdfPoches_clicked()
{
    click->play();
    QString strStream;
                              QTextStream out(&strStream);

                              const int rowCount = ui->tabPoches->model()->rowCount();
                              const int columnCount = ui->tabPoches->model()->columnCount();

                              out <<  "<html>\n"
                                  "<head>\n"
                                  "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                  <<  QString("<title>%1</title>\n").arg("strTitle")
                                  <<  "</head>\n"
                                  "<body bgcolor=#ffffff link=#5000A0>\n"

                                 //     "<align='right'> " << datefich << "</align>"
                                  "<center> <H1>Liste des Poches </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                              // headers
                              out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                              for (int column = 0; column < columnCount; column++)
                                  if (!ui->tabPoches->isColumnHidden(column))
                                      out << QString("<th>%1</th>").arg(ui->tabPoches->model()->headerData(column, Qt::Horizontal).toString());
                              out << "</tr></thead>\n";

                              // data table
                              for (int row = 0; row < rowCount; row++) {
                                  out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                  for (int column = 0; column < columnCount; column++) {
                                      if (!ui->tabPoches->isColumnHidden(column)) {
                                          QString data = ui->tabPoches->model()->data(ui->tabPoches->model()->index(row, column)).toString().simplified();
                                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                      }
                                  }
                                  out << "</tr>\n";
                              }
                              out <<  "</table> </center>\n"
                                  "</body>\n"
                                  "</html>\n";

                        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                          if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                         QPrinter printer (QPrinter::PrinterResolution);
                          printer.setOutputFormat(QPrinter::PdfFormat);
                         printer.setPaperSize(QPrinter::A4);
                        printer.setOutputFileName(fileName);

                         QTextDocument doc;
                          doc.setHtml(strStream);
                          doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                          doc.print(&printer);
}

void Pharmacie::on_BimpMed_clicked()
{
    click->play();
    QPrinter printer;

              printer.setPrinterName("desiered printer name");

            QPrintDialog dialog(&printer,this);

              if(dialog.exec()== QDialog::Rejected)

                 return;
}

void Pharmacie::on_pdfMed_clicked()
{
    click->play();
    QString strStream;
                              QTextStream out(&strStream);

                              const int rowCount = ui->tabMedicaments->model()->rowCount();
                              const int columnCount = ui->tabMedicaments->model()->columnCount();

                              out <<  "<html>\n"
                                  "<head>\n"
                                  "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                  <<  QString("<title>%1</title>\n").arg("strTitle")
                                  <<  "</head>\n"
                                  "<body bgcolor=#ffffff link=#5000A0>\n"

                                 //     "<align='right'> " << datefich << "</align>"
                                  "<center> <H1>Liste des Medicaments </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                              // headers
                              out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                              for (int column = 0; column < columnCount; column++)
                                  if (!ui->tabMedicaments->isColumnHidden(column))
                                      out << QString("<th>%1</th>").arg(ui->tabMedicaments->model()->headerData(column, Qt::Horizontal).toString());
                              out << "</tr></thead>\n";

                              // data table
                              for (int row = 0; row < rowCount; row++) {
                                  out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                  for (int column = 0; column < columnCount; column++) {
                                      if (!ui->tabMedicaments->isColumnHidden(column)) {
                                          QString data = ui->tabMedicaments->model()->data(ui->tabMedicaments->model()->index(row, column)).toString().simplified();
                                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                      }
                                  }
                                  out << "</tr>\n";
                              }
                              out <<  "</table> </center>\n"
                                  "</body>\n"
                                  "</html>\n";

                        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                          if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                         QPrinter printer (QPrinter::PrinterResolution);
                          printer.setOutputFormat(QPrinter::PdfFormat);
                         printer.setPaperSize(QPrinter::A4);
                        printer.setOutputFileName(fileName);

                         QTextDocument doc;
                          doc.setHtml(strStream);
                          doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                          doc.print(&printer);
}
