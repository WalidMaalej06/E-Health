#include "patient_rdv.h"
#include "ui_patient_rdv.h"
#include "patient.h"
#include "rdv.h"
#include <iostream>
#include <QMessageBox>
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>


patient_rdv::patient_rdv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patient_rdv)
{

    ui->setupUi(this);

    ui->le_cin->setValidator(new QIntValidator(0,9999999,this));

    ui->le_cin_pat->setValidator(new QIntValidator(0,9999999,this));
   ui->tab_patient->setModel(s.afficher());
     ui->tab_rdv->setModel(r.afficher());

}

patient_rdv::~patient_rdv()
{
    delete ui;
}

void patient_rdv::on_pushButtonajoutpatient_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString sexe=ui->le_sexe->text();
    QString ville=ui->le_ville->text();
    QString region=ui->le_region->text();
    QString date_naissance=ui->le_date->text();
    QString lieu=ui->le_lieu->text();
     Patient s(cin,nom,prenom,sexe,ville,region,date_naissance,lieu);
    QMessageBox msg ;
    bool test=s.ajouter();
    if(test)
    {
   msg.setText("Ajout avec succes");
    ui->tab_patient->setModel(s.afficher());
    }
    else
      msg.setText("Echec de l'Ajout");
    msg.exec();

}


void patient_rdv::on_pushButton_suprpatient_clicked()
{
    Patient S1; S1.setcin(ui->le_cin_supp->text().toInt());
    bool test =S1.supprimer(S1.getcin());
    QMessageBox msgBox;
    if(test)

        {
          msgBox.setText("suppression avec succes.");
          ui->tab_patient->setModel(s.afficher());
        }
        else
         msgBox.setText("Echec de suppression.");
    msgBox.exec();
}

void patient_rdv::on_trienom_clicked()
{
    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM PATIENT order by nom ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("ville"));
                 model->setHeaderData(5, Qt::Horizontal, QObject::tr("region"));
                 model->setHeaderData(6, Qt::Horizontal, QObject::tr("date"));
                  model->setHeaderData(7, Qt::Horizontal, QObject::tr("lieu"));
                 ui->tab_patient->setModel(model);
                 ui->tab_patient->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();
}

void patient_rdv::on_triecin_clicked()
{QMessageBox msgBox ;

    QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery("SELECT * FROM PATIENT order by cin ASC");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("ville"));
             model->setHeaderData(5, Qt::Horizontal, QObject::tr("region"));
             model->setHeaderData(6, Qt::Horizontal, QObject::tr("date"));
              model->setHeaderData(7, Qt::Horizontal, QObject::tr("lieu"));
             ui->tab_patient->setModel(model);
             ui->tab_patient->show();
             msgBox.setText("Tri avec succès.");
             msgBox.exec();

}

void patient_rdv::on_trienom_2_clicked()
{
    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM RDV order by nom_prenom ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin_pat"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("jours"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("heures"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("la_maladies"));
                 ui->tab_rdv->setModel(model);
                 ui->tab_rdv->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();
}


void patient_rdv::on_pushButton_ajoutrdv_clicked()
{
    int cin_pat=ui->le_cin_pat->text().toInt();
    QString nom_prenom=ui->le_np->text();

    QString jours=ui->le_j->text();
    QString heures =ui->le_h->text();
    QString la_maladies=ui->le_maladie->text();

     rdv r( cin_pat,nom_prenom, jours, heures, la_maladies);
    QMessageBox msg ;

    bool test=r.ajouter();
    if(test)
    {
   msg.setText("Ajout avec succes");
   ui->tab_rdv->setModel(r.afficher());
    }
    else
      msg.setText("Echec de l'Ajout");
    msg.exec();
}






void patient_rdv::on_pushButton_clicked()
{

   rdv R; R.setcinpat(ui->le_cin_pat_supp->text().toInt());
    bool test =R.supprimer(R.getcinpat());
    QMessageBox msgBox;
    if(test)

        {
          msgBox.setText("suppression avec succes.");
          ui->tab_rdv->setModel(r.afficher());
        }
        else
         msgBox.setText("Echec de suppression.");
    msgBox.exec();

}

void patient_rdv::on_pushButton_5_clicked()
{
    close();
}


void patient_rdv::on_pushButton_8_clicked()
{
    close();
}


void patient_rdv::on_pushButton_retouradmin_clicked()
{
    close();
}


void patient_rdv::on_pushButton_4_clicked()
{
    close();
}


void patient_rdv::on_pushButton_10_clicked()
{
    close();
}


void patient_rdv::on_pushButton_12_clicked()
{
    close();
}

void patient_rdv::on_modifierpat_clicked()
{
        int cin=ui->le_cinmodif->text().toInt();
        QString nom=ui->le_nom_2->text();
        QString prenom = ui->le_prenom_2->text();
        QString sexe=ui->le_sexe_2->text();
        QString ville=ui->le_ville_2->text();
        QString region=ui->le_region_2->text();
        QString date_naissance=ui->le_date_2->text();
        QString lieu=ui->le_lieu_2->text();
        QMessageBox msg;
        bool test=s.modifier(cin,nom,prenom,sexe,ville,region,date_naissance,lieu);

        if(test)
        {
            ui->le_cinmodif->clear();
            ui->le_nom_2->clear();
            ui->le_prenom_2->clear();
            ui->le_sexe_2->clear();
            ui->le_ville_2->clear();
            ui->le_region_2->clear();
            ui->le_date_2->clear();
            ui->le_lieu_2->clear();
            ui->tab_patient->setModel(s.afficher());
            msg.setText("modifiction avec succes");
        }
            else {
            msg.setText("Echec au niveau de la modification d un patient");
        }
        msg.exec();


}

void patient_rdv::on_pushButton_modifierrdv_clicked()
{
    int cin_pat=ui->lineEdit_scinrdv->text().toInt();
    QString nom_prenom=ui->le_np_2->text();
    QString jours = ui->le_j_2->text();
    QString heures=ui->le_h_2->text();
    QString la_maladies=ui->le_maladie_2->text();
    QMessageBox msg;
    bool test=r.modifier(cin_pat,nom_prenom,jours,heures,la_maladies);

    if(test)
    {
        ui->lineEdit_scinrdv->clear();
        ui->le_np_2->clear();
        ui->le_j_2->clear();
        ui->le_h_2->clear();
        ui->le_maladie_2->clear();
        ui->tab_patient->setModel(r.afficher());
        msg.setText("modifiction avec succes");
    }
        else {
        msg.setText("Echec au niveau de la modification d un rdv");
    }
    msg.exec();
}



void patient_rdv::on_rech_patient_clicked()
{
    bool test;
   Patient p;
       int cin=0;
       QString region=ui->lineEdit->text();
       QString nom=ui->lineEdit->text();
       QString choix=ui->comboBox->currentText();
   if(choix=="nom")
   {
       test=p.recherche(nom,cin,region);
   }
   if(choix=="cin")
   {
      cin= nom.toInt();
      test=p.recherche(nom,cin,region);
   }
   if(choix=="region")
   {

       test=p.recherche(nom,cin,region);
   }
if(test)
{
ui->tab_patient->setModel(p.afficher());
}
}

void patient_rdv::on_imp_patient_clicked()
{

    //imprimer

           QPrinter printer;

           printer.setPrinterName("desiered printer name");

         QPrintDialog dialog(&printer,this);

           if(dialog.exec()== QDialog::Rejected)

               return;
}

void patient_rdv::on_pdf_patient_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tab_patient->model()->rowCount();
                     const int columnCount = ui->tab_patient->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tab_patient->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tab_patient->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tab_patient->isColumnHidden(column)) {
                                 QString data = ui->tab_patient->model()->data(ui->tab_patient->model()->index(row, column)).toString().simplified();
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

void patient_rdv::on_rech_rdv_2_clicked()
{   bool test;
    rdv r;
        int cin_pat=0;

        QString nom_prenom=ui->lineEdit_2->text();
        QString la_maladies=ui->lineEdit_2->text();
        QString choix=ui->comboBox_2->currentText();
    if(choix=="nom_prenom")
    {
        test=r.recherche(nom_prenom,cin_pat,la_maladies);
    }
    if(choix=="cin_pat")
    {
       cin_pat= nom_prenom.toInt();
       test=r.recherche(nom_prenom,cin_pat,la_maladies);
    }
    if(choix=="la_maladies")
    {

        test=r.recherche(nom_prenom,cin_pat,la_maladies);
    }
 if(test)
 {
 ui->tab_rdv->setModel(r.afficher());
 }

}

void patient_rdv::on_imp_patient_2_clicked()
{
    //imprimer

           QPrinter printer;

           printer.setPrinterName("desiered printer name");

         QPrintDialog dialog(&printer,this);

           if(dialog.exec()== QDialog::Rejected)

               return;
}

void patient_rdv::on_pdf_patient_2_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tab_rdv->model()->rowCount();
                     const int columnCount = ui->tab_rdv->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tab_rdv->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tab_rdv->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tab_rdv->isColumnHidden(column)) {
                                 QString data = ui->tab_rdv->model()->data(ui->tab_rdv->model()->index(row, column)).toString().simplified();
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

void patient_rdv::on_pushButton_2_clicked()
{
    QMessageBox msgBox ;

        QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM RDV order by cin_pat ASC");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin_pat"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom"));
                 model->setHeaderData(2, Qt::Horizontal, QObject::tr("jours"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("heures"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("la_maladies"));
                 ui->tab_rdv->setModel(model);
                 ui->tab_rdv->show();
                 msgBox.setText("Tri avec succès.");
                 msgBox.exec();
}
