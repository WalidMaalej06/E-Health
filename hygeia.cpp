#include "hygeia.h"
#include "ui_hygeia.h"

hygeia::hygeia(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::hygeia)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);


    //connexion    arduino
    int ret=A.connect_arduino();
    switch(ret)
    {
    case(0):qDebug() <<"arduino is available and connected to :"<<A.getarduino_port_name();
        break;
    case(1):qDebug() <<"arduino is available but not connected to :"<<A.getarduino_port_name();
        break;
    case(-1):qDebug() <<"arduino is not available";
        break;

    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(readSerial()));

    //Rayen
    //Regex (pour contrôle de saisie)
    mail_regex=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
    nom_regex=QRegExp("[a-zA-Z ]+$");
    salaire_regex=QRegExp("([0-9]+)*[.]*[0-9]+$");
    tel_regex=QRegExp("[0-9]{8}$");
    id_regex=QRegExp("^[0-9]*$");
    ui->dateEditAdhesion->setMaximumDate(QDate::currentDate());
    ui->lineEditNum->setMaxLength(8);
    ui->dateEditDebut->setMinimumDate(QDate::currentDate());
    QDate date=ui->dateEditDebut->date();
    ui->dateEditFin->setMinimumDate(date);

    ui->tableViewEmploye->setModel(tmpemploye.afficher());
    ui->tableViewEmploye->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewEmploye->setSelectionMode(QAbstractItemView::SingleSelection);

    QSqlQueryModel * modell = tmpconge.afficher();
    ui->tableViewConge->setModel( modell);
    QSortFilterProxyModel *mm=new QSortFilterProxyModel(this);
    mm->setDynamicSortFilter(true);
    mm->setSourceModel(modell);

    ui->tableViewConge->setModel(modell);
    ui->tableViewConge->setSortingEnabled(true);

    ui->tableViewConge->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewConge->setSelectionMode(QAbstractItemView::SingleSelection);

    QSqlQueryModel *modellll = new QSqlQueryModel;
    modellll->setQuery("SELECT ID FROM EMPLOYE");
    ui->comboBoxNom->setModel(modellll);

/*______________________________________________________________________________________________________________*/
    //Walid
    ui->tabMedicaments->setModel(M_tmp.afficherMedicament());
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
     /*_____________________________________________________________________________________*/
     //amine
         ui->tabdossier->setModel(d_temp.afficher());
         ui->tabconsu->setModel(c_temp.afficher());
         ui->tabpayement->setModel(p_temp.afficher());
    /*_____________________________________________________________________________________*/
         //ousema
         ui->le_cin->setValidator(new QIntValidator(0,9999999,this));

         ui->le_cin_pat->setValidator(new QIntValidator(0,9999999,this));
        ui->tab_patient->setModel(s.afficher());
          ui->tab_rdv->setModel(r.afficher());

}

hygeia::~hygeia()
{
    delete ui;
}


void hygeia::on_actionClose_triggered()
{
    QApplication::quit();
}

void hygeia::on_actionCopier_triggered()
{
    //fonction copier
}

void hygeia::on_actionCouper_triggered()
{
    //fonction couper
}

void hygeia::on_actionColler_triggered()
{
    //fonction coller
}

void hygeia::on_pushButtonQuitter_clicked()
{
    QApplication::quit();
}

void hygeia::on_rayen_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void hygeia::on_pushButtonGoEmploye_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void hygeia::on_pushButtonReturn1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void hygeia::on_pushButtonReturn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void hygeia::on_pushButtonGoConge_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

//Rayen
void hygeia::on_pushButtonAjouterEmploye_clicked()
{
            bool mail_verif = mail_regex.exactMatch(ui->lineEditMail->text());
            bool nom_verif = nom_regex.exactMatch(ui->lineEditNom->text());
            bool tel_verif = tel_regex.exactMatch(ui->lineEditNum->text());
            bool id_verif= id_regex.exactMatch(ui->lineEditID->text());
            bool depart_verif=nom_regex.exactMatch(ui->lineEditDepart->text());
            bool tel_verif2=true;
            bool salaire_verif=salaire_regex.exactMatch(ui->lineEditSalaire->text());

            //if (ui->lineEditNum->text().at(0)!='2' && ui->lineEditNum->text().at(0)!='5' && ui->lineEditNum->text().at(0)!='9' && ui->lineEditNum->text().at(0)!='7')
            //       tel_verif2=false;

            if (ui->lineEditID->text()!="" &&
                ui->lineEditNom->text()!="" &&
                ui->lineEditNum->text()!="" &&
                ui->lineEditDepart->text()!="" &&
                ui->lineEditSalaire->text()!=""
                ){
                if(id_verif && nom_verif && tel_verif && tel_verif2 && mail_verif && depart_verif && salaire_verif)
                {
                    QString id=ui->lineEditID->text();
                    QString nom=ui->lineEditNom->text();
                    QString num=ui->lineEditNum->text();
                    QString mail=ui->lineEditMail->text();
                    QString dateAd=ui->dateEditAdhesion->date().toString();
                    QString sexe=ui->comboBoxSexe->currentText();
                    QString depart=ui->lineEditDepart->text();
                    QString salaire=ui->lineEditSalaire->text();
                    employe empl(id,nom,num,mail,dateAd,sexe,depart,salaire);

                    bool test=empl.ajouter();
                    if (test)
                        ui->tableViewEmploye->setModel(tmpemploye.afficher());
                    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                        widget->clear();
                    }
                    ui->lineEditID->setStyleSheet("color: black");
                    ui->lineEditNom->setStyleSheet("color: black");
                    ui->lineEditNum->setStyleSheet("color: black");
                    ui->lineEditMail->setStyleSheet("color: black");
                    ui->lineEditDepart->setStyleSheet("color: black");
                    ui->lineEditSalaire->setStyleSheet("color: black");
                }
                else{
                    if (!mail_verif){
                        QMessageBox::warning(this,"Erreur lors de l'ajout","E-mail invalid");
                        ui->lineEditMail->setStyleSheet("color: red");

                    }
                    if (!id_verif){
                        QMessageBox::warning(this,"Erreur lors de l'ajout","ID invalid");
                        ui->lineEditID->setStyleSheet("color: red");

                    }
                    if(!nom_verif){
                        QMessageBox::warning(this,"Erreur lors de l'ajout","Nom invalid");
                        ui->lineEditNom->setStyleSheet("color: red");

                    }
                    if(!tel_verif){
                        QMessageBox::warning(this,"Erreur lors de l'ajout","Numero De Tel invalid");
                        ui->lineEditNum->setStyleSheet("color: red");

                    }
                    if(!depart_verif){
                        QMessageBox::warning(this,"Erreur lors de l'ajout","Departement invalid");
                        ui->lineEditDepart->setStyleSheet("color: red");
                    }
                    if(!salaire_verif){
                        QMessageBox::warning(this,"Erreur lors de l'ajout","Salaire invalid");
                        ui->lineEditSalaire->setStyleSheet("color: red");

                    }
                }
    }
            else {
                QMessageBox::warning(this,"Erreur lors de l'ajout","Veuillez compléter tous les champs");
            }
            QSqlQueryModel *modellll = new QSqlQueryModel;
            modellll->setQuery("SELECT ID FROM EMPLOYE");
            ui->comboBoxNom->setModel(modellll);
}


void hygeia::on_pushButtonAfficherTout_clicked()
{
    ui->tableViewEmploye->setModel(tmpemploye.afficher());
}

void hygeia::on_pushButtonModifier_clicked()
{
    if (ui->pushButtonModifier->isChecked())
                {
                    ui->pushButtonModifier->setDisabled(true);
                    ui->pushButtonModifier->setText("Modifiable");
                    QSqlTableModel *tableModel= new QSqlTableModel();
                    tableModel->setTable("EMPLOYE");
                    tableModel->select();
                    ui->tableViewEmploye->setModel(tableModel);
                }
                else
                {
                    ui->pushButtonModifier->setText("Modifier");QSqlQueryModel * model = tmpemploye.afficher();
                    ui->tableViewEmploye->setModel( model);
                    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
                    m->setDynamicSortFilter(true);
                    m->setSourceModel(model);
                    ui->tableViewEmploye->setModel(m);
                    ui->tableViewEmploye->setSortingEnabled(true);
                }
    ui->pushButtonModifier->setChecked(false);
}

void hygeia::on_pushButtonSupprimer_clicked()
{
    QItemSelectionModel *select = ui->tableViewEmploye->selectionModel();
    QString idemploye =select->selectedRows(0).value(0).data().toString();
    if(tmpemploye.supprimer(idemploye))
            {
                ui->pushButtonModifier->setText("Modifier");QSqlQueryModel * model = tmpemploye.afficher();
                ui->tableViewEmploye->setModel( model);
                QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
                m->setDynamicSortFilter(true);
                m->setSourceModel(model);
                ui->tableViewEmploye->setModel(m);
                ui->tableViewEmploye->setSortingEnabled(true);

                QSqlQueryModel *modellll = new QSqlQueryModel;
                modellll->setQuery("SELECT ID FROM EMPLOYE");
                ui->comboBoxNom->setModel(modellll);
            }

}


void hygeia::on_pushButtonRechercher_clicked()
{
    QString nom=ui->lineEditChercher->text();
    QDate date=ui->date_recherche->date();
    QString sexe;
    QString email=ui->lineEditChercher->text();
    if (ui->radioButtonHomme->isChecked())
       sexe=ui->radioButtonHomme->text();
    else if (ui->radioButtonFemme->isChecked())
       sexe=ui->radioButtonFemme->text();
    if (ui->checkBoxNom->isChecked() && ui->checkBoxSexe->isChecked() && ui->checkBoxDate->isChecked())
        {

            QSqlQueryModel *verif_combinaison=tmpemploye.rechercher_combinaison_all(nom,sexe,date);
            if (verif_combinaison!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_combinaison);
            }

        }
    else if (!ui->checkBoxNom->isChecked() && ui->checkBoxSexe->isChecked() && !ui->checkBoxDate->isChecked())
        {
            QSqlQueryModel *verif_sexe=tmpemploye.rechercher_sexe(sexe);
            if (verif_sexe!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_sexe);
            }
        }
        else if (!ui->checkBoxNom->isChecked() && !ui->checkBoxSexe->isChecked() && ui->checkBoxDate->isChecked())
        {
            QSqlQueryModel *verif_date=tmpemploye.rechercher_date(date);
            if (verif_date!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_date);
            }
        }
        else if (ui->checkBoxNom->isChecked() && !ui->checkBoxSexe->isChecked() && !ui->checkBoxDate->isChecked())
        {
            QSqlQueryModel *verif_nom=tmpemploye.rechercher_nom(nom);
            if (verif_nom!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_nom);
            }
        }
        else if (ui->checkBoxNom->isChecked() && ui->checkBoxSexe->isChecked() && !ui->checkBoxDate->isChecked())
        {
            QSqlQueryModel *verif_nom_sexe=tmpemploye.rechercher_combinaison_nom_sexe(nom,sexe);
            if (verif_nom_sexe!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_nom_sexe);
            }
        }
        else if (!ui->checkBoxNom->isChecked() && ui->checkBoxSexe->isChecked() && ui->checkBoxDate->isChecked())
        {
            QSqlQueryModel *verif_sexe_date=tmpemploye.rechercher_combinaison_sexe_date(sexe,date);
            if (verif_sexe_date!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_sexe_date);
            }
        }
        else if (ui->checkBoxNom->isChecked() && !ui->checkBoxSexe->isChecked() && ui->checkBoxDate->isChecked())
        {
            QSqlQueryModel *verif_nom_date=tmpemploye.rechercher_combinaison_nom_date(nom,date);
            if (verif_nom_date!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_nom_date);
            }
        }

        else if (!ui->checkBoxNom->isChecked() && !ui->checkBoxSexe->isChecked() && !ui->checkBoxDate->isChecked() && ui->checkBoxMail)
        {
            QSqlQueryModel *verif_mail=tmpemploye.rechercher_email(email);
            if (verif_mail!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_mail);
            }
        }
}

void hygeia::on_pushButtonPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("Liste Des Employés.pdf"); }

                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                QTextDocument doc;
                QSqlQuery q;
                q.prepare("SELECT * FROM EMPLOYE ");
                q.exec();
                QString pdf="<br><br><img src='D:/bourguiba/ESPRIT/Second Year/Projet C++/logo.png' height='42' align='left' width='42'/>  <h1 align='middle' style='color:blue;   style='display: block;margin: auto;max-width: 600px;padding:5px;width: 100%;'>LISTE DES EMPLOYES  <><br></h1>\n <br> <table  style='border: 1px solid black;background: white; border-radius:3px; border-collapse: collapse; margin: auto;  padding:5px; width: 100%; box-shadow: 0 5px 10px rgba(0, 0, 0, 0.1);'>  <tr>  <th style='border: 1px solid black;color:#D5DDE5;background:#1b1e24;border-bottom:4px solid #9ea7af;border-right: 1px solid #343a45;font-size:12px;font-weight: 100;padding:24px;text-align:left;text-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);vertical-align:middle;'>ID </th> <th style='border: 1px solid black;color:#D5DDE5;background:#1b1e24;border-bottom:4px solid #9ea7af;border-right: 1px solid #343a45;font-size:12px;font-weight: 100;padding:24px;text-align:left;text-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);vertical-align:middle;'>NOM </th> <th style='border: 1px solid black;color:#D5DDE5;background:#1b1e24;border-bottom:4px solid #9ea7af;border-right: 1px solid #343a45;font-size:12px;font-weight: 100;padding:24px;text-align:left;text-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);vertical-align:middle;'>NUM </th> <th style='border: 1px solid black;color:#D5DDE5;background:#1b1e24;border-bottom:4px solid #9ea7af;border-right: 1px solid #343a45;font-size:12px;font-weight: 100;padding:12px;text-align:left;text-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);vertical-align:middle;'> EMAIL </th> <th style='border: 1px solid black;color:#D5DDE5;background:#1b1e24;border-bottom:4px solid #9ea7af;border-right: 1px solid #343a45;font-size:12px;font-weight: 100;padding:12px;text-align:left;text-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);vertical-align:middle;border: 1px solid black;'>Departement </th>  </tr>";


                while ( q.next()) {

                    pdf= pdf+ " <br> <tr style='border-top: 1px solid #C1C3D1; border-bottom-: 1px solid #C1C3D1; color:#666B85;padding-bottom:5px; font-size:16px; font-weight:normal; text-shadow: 0 1px 1px rgba(256, 256, 256, 0.1);'> <td style='border: 1px solid black;border: 1px solid black;background:#FFFFFF; padding:20px; text-align:left; vertical-align:middle; font-weight:300; font-size:8px; text-shadow: -1px -1px 1px rgba(0, 0, 0, 0.1); border-right: 1px solid #C1C3D1;'>"+ q.value(0).toString()+"</td>  <td style='border: 1px solid black;border: 1px solid black;background:#FFFFFF; padding:20px; text-align:left; vertical-align:middle; font-weight:300; font-size:8px; text-shadow: -1px -1px 1px rgba(0, 0, 0, 0.1); border-right: 1px solid #C1C3D1;'> " + q.value(1).toString() +"</td>   <td style='border: 1px solid black;background:#FFFFFF; padding:20px; text-align:left; vertical-align:middle; font-weight:300; font-size:8px; text-shadow: -1px -1px 1px rgba(0, 0, 0, 0.1); border-right: 1px solid #C1C3D1;'>" +q.value(2).toString() +"  "" " "</td>   <td style='border: 1px solid black;background:#FFFFFF; padding:20px; text-align:left; vertical-align:middle; font-weight:300; font-size:8px; text-shadow: -1px -1px 1px rgba(0, 0, 0, 0.1); border-right: 1px solid #C1C3D1;'>"+q.value(3).toString()+"</td>   <td style='border: 1px solid black;background:#FFFFFF; padding:20px; text-align:left; vertical-align:middle; font-weight:300; font-size:8px; text-shadow: -1px -1px 1px rgba(0, 0, 0, 0.1); border-right: 1px solid #C1C3D1;'>"+q.value(6).toString()+" "  " " "</td> </td>" ;

                }
                doc.setHtml(pdf);
                doc.setPageSize(printer.pageRect().size()); // t5abbi numero l page
                doc.print(&printer);
}

void hygeia::on_pushButtonImprimer_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableViewEmploye->model()->rowCount();
        const int columnCount = ui->tableViewEmploye->model()->columnCount();

        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
             <<  QString("<title>%1</title>\n").arg("Title")
              <<  "</head>\n"
                  "<body bgcolor=#ffffff link=#5000A0>\n"
                  "<table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableViewEmploye->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableViewEmploye->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableViewEmploye->isColumnHidden(column)) {
                    QString data = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;
}


void hygeia::on_pushButtonTrier_clicked()
{
    if (ui->checkBoxNom->isChecked() && !ui->checkBoxSexe->isChecked() && !ui->checkBoxDate->isChecked())
            ui->tableViewEmploye->setModel(tmpemploye.trier("nom",ui->comboBoxOrdre->currentText()));
        else if (!ui->checkBoxNom->isChecked() && ui->checkBoxSexe->isChecked() && !ui->checkBoxDate->isChecked())
            ui->tableViewEmploye->setModel(tmpemploye.trier("sexe",ui->comboBoxOrdre->currentText()));
        else if (!ui->checkBoxNom->isChecked() && !ui->checkBoxSexe->isChecked() && ui->checkBoxDate->isChecked())
            ui->tableViewEmploye->setModel(tmpemploye.trier("date_naissance",ui->comboBoxOrdre->currentText()));
        else if (ui->checkBoxNom->isChecked() && ui->checkBoxSexe->isChecked() && !ui->checkBoxDate->isChecked())
            ui->tableViewEmploye->setModel(tmpemploye.trier("nom, sexe",ui->comboBoxOrdre->currentText()));
        else if (ui->checkBoxNom->isChecked() && !ui->checkBoxSexe->isChecked() && ui->checkBoxDate->isChecked())
            ui->tableViewEmploye->setModel(tmpemploye.trier("nom, date_naissance",ui->comboBoxOrdre->currentText()));
        else if (!ui->checkBoxNom->isChecked() && ui->checkBoxSexe->isChecked() && ui->checkBoxDate->isChecked())
            ui->tableViewEmploye->setModel(tmpemploye.trier("sexe, date_naissance",ui->comboBoxOrdre->currentText()));
        else if (ui->checkBoxNom->isChecked() && ui->checkBoxSexe->isChecked() && ui->checkBoxDate->isChecked())
            ui->tableViewEmploye->setModel(tmpemploye.trier("nom, sexe, date_naissance",ui->comboBoxOrdre->currentText()));
        else if (ui->checkBoxNom->isChecked())
            ui->tableViewEmploye->setModel(tmpemploye.trier("cin",ui->comboBoxOrdre->currentText()));
        else if (ui->checkBoxMail->isChecked())
            ui->tableViewEmploye->setModel(tmpemploye.trier("mail",ui->comboBoxOrdre->currentText()));
}

void hygeia::on_ajouter_clicked()
{
        if(ui->lineEditNumConge->text()!=""){
        QString id=ui->lineEditNumConge->text();
        QString nom=ui->comboBoxNom->currentText();
        QString dated=ui->dateEditDebut->date().toString();
        QString datef=ui->dateEditFin->date().toString();
        QString type=ui->comboBoxType->currentText();

        conge conge(id, nom, dated, datef, type);
        conge.ajouter();
        QSqlQueryModel * modell = tmpconge.afficher();
        ui->tableViewConge->setModel( modell);
        QSortFilterProxyModel *mm=new QSortFilterProxyModel(this);
           mm->setDynamicSortFilter(true);
           mm->setSourceModel(modell);
           ui->tableViewConge->setModel(mm);
           ui->tableViewConge->setSortingEnabled(true);
        foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
            widget->clear();
        }
    }
    else{
                QMessageBox::warning(this,"Erreur lors de l'ajout","Veuillez verifier tous les champs");
            }
}


void hygeia::on_pushButtonEdit_clicked()
{
    if (ui->pushButtonEdit->isChecked())
            {
                ui->pushButtonEdit->setDisabled(true);
                ui->pushButtonEdit->setText("Modifiable");
                QSqlTableModel *tableModel= new QSqlTableModel();
                tableModel->setTable("CONGE");
                tableModel->select();
                ui->tableViewConge->setModel(tableModel);
            }
            else
            {
                ui->pushButtonEdit->setText("Modifier");
                QSqlQueryModel * modell = tmpconge.afficher();
               ui->tableViewConge->setModel( modell);
               QSortFilterProxyModel *mm=new QSortFilterProxyModel(this);
                   mm->setDynamicSortFilter(true);
                   mm->setSourceModel(modell);
                   ui->tableViewConge->setModel(mm);
                   ui->tableViewConge->setSortingEnabled(true);

            }
    ui->pushButtonEdit->setChecked(false);

}

void hygeia::on_pushButtonSuppr_clicked()
{
    QItemSelectionModel *select = ui->tableViewConge->selectionModel();
        QString idemploye =select->selectedRows(0).value(0).data().toString();
        if(tmpconge.supprimer(idemploye))
            {
               QSqlQueryModel * modell = tmpconge.afficher();
               ui->tableViewConge->setModel( modell);
               QSortFilterProxyModel *mm=new QSortFilterProxyModel(this);
               mm->setDynamicSortFilter(true);
               mm->setSourceModel(modell);
               ui->tableViewConge->setModel(mm);
               ui->tableViewConge->setSortingEnabled(true);
            }
}

void hygeia::on_pushButtonAfficherToutConge_clicked()
{
    ui->tableViewConge->setModel(tmpconge.afficher());
}

void hygeia::on_walid_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void hygeia::on_pushButtonGoSang_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void hygeia::on_pushButtonReturn1_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//Walid
void hygeia::on_buttonAjouter_clicked()
{
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
    ui->tabMedicaments->setModel(M_tmp.afficherMedicamentTri(ui->cTriMed->currentText()));
}


void hygeia::on_BmedicamentDelete_clicked()
{
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
    ui->tabMedicaments->setModel(M_tmp.afficherMedicamentTri(ui->cTriMed->currentText()));
}


void hygeia::on_BconsulterMedicament_clicked()
{
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

void hygeia::on_BmedicamentsEdit_clicked()
{
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
    ui->tabMedicaments->setModel(M_tmp.afficherMedicamentTri(ui->cTriMed->currentText()));
}

void hygeia::on_buttonRechercheMed_clicked()
{
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

void hygeia::on_cTriMed_2_clicked()
{
    ui->tabMedicaments->setModel(M_tmp.afficherMedicamentTri(ui->cTriMed->currentText()));
}


void hygeia::on_ajouterPoche_2_clicked()
{
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


void hygeia::on_consulterPoche_clicked()
{
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


void hygeia::on_modifierPoche_clicked()
{
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

void hygeia::on_supprimerPoche_clicked()
{
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

void hygeia::on_rechercherButtonPoche_clicked()
{
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

void hygeia::on_actualiserTriPoches_clicked()
{
    ui->tabPoches->setModel(P_tmp.afficherPochesTri(ui->cTriPoches->currentText()));

}

void hygeia::on_BimpPoches_clicked()
{
    QPrinter printer;

              printer.setPrinterName("desiered printer name");

            QPrintDialog dialog(&printer,this);

              if(dialog.exec()== QDialog::Rejected)

                 return;
}

void hygeia::on_pdfPoches_clicked()
{
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

void hygeia::on_BimpMed_clicked()
{
    QPrinter printer;

              printer.setPrinterName("desiered printer name");

            QPrintDialog dialog(&printer,this);

              if(dialog.exec()== QDialog::Rejected)

                 return;
}

void hygeia::on_pdfMed_clicked()
{
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

void hygeia::on_pushButtonGoSang_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void hygeia::on_pushButtonReturn1_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void hygeia::on_pushButtonGoMedicaments_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void hygeia::on_pushButtonVider_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void hygeia::on_viderCases_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void hygeia::on_viderCases_2_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void hygeia::on_viderCases_3_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void hygeia::on_pushButtonStatistiques_clicked()
{
    QString id=ui->lineEdit_recherche_table->text();
    QString nomemploye=ui->lineEdit_recherche_table->text();
    QString type=ui->lineEdit_recherche_table->text();
    if (ui->checkBoxTypeConge->isChecked() && ui->checkBoxNomEmploye->isChecked() && ui->checkBoxNumConge->isChecked())
        {

            QSqlQueryModel *verif_combinaison=tmpconge.rechercher_combinaison_all(id,nomemploye,type);
            if (verif_combinaison!=nullptr)
            {
                ui->tableViewConge->setModel(verif_combinaison);
            }

        }
    else if (ui->checkBoxTypeConge->isChecked() && !ui->checkBoxNomEmploye->isChecked() && !ui->checkBoxNumConge->isChecked())
        {
            QSqlQueryModel *verif_type=tmpconge.rechercher_type(type);
            if (verif_type!=nullptr)
            {
                ui->tableViewConge->setModel(verif_type);
            }
        }
        else if (!ui->checkBoxTypeConge->isChecked() && !ui->checkBoxNomEmploye->isChecked() && ui->checkBoxNumConge->isChecked())
        {
            QSqlQueryModel *verif_id=tmpconge.recherche(id);
            if (verif_id!=nullptr)
            {
                ui->tableViewConge->setModel(verif_id);
            }
        }
        else if (!ui->checkBoxTypeConge->isChecked() && ui->checkBoxNomEmploye->isChecked() && !ui->checkBoxNumConge->isChecked())
        {
            QSqlQueryModel *verif_nomemploye=tmpconge.rechercher_nomemploye(nomemploye);
            if (verif_nomemploye!=nullptr)
            {
                ui->tableViewConge->setModel(verif_nomemploye);
            }
        }
        else if (ui->checkBoxTypeConge->isChecked() && ui->checkBoxNomEmploye->isChecked() && !ui->checkBoxNumConge->isChecked())
        {
            QSqlQueryModel *verif_nom_type=tmpconge.rechercher_combinaison_nom_type(nomemploye,type);
            if (verif_nom_type!=nullptr)
            {
                ui->tableViewConge->setModel(verif_nom_type);
            }
        }
        else if (!ui->checkBoxTypeConge->isChecked() && ui->checkBoxNomEmploye->isChecked() && ui->checkBoxNumConge->isChecked())
        {
            QSqlQueryModel *verif_id_nom=tmpconge.rechercher_combinaison_id_nom(id,nomemploye);
            if (verif_id_nom!=nullptr)
            {
                ui->tableViewConge->setModel(verif_id_nom);
            }
        }
        else if (ui->checkBoxTypeConge->isChecked() && !ui->checkBoxSexe->isChecked() && ui->checkBoxNumConge->isChecked())
        {
            QSqlQueryModel *verif_type_id=tmpconge.rechercher_combinaison_id_type(id,type);
            if (verif_type_id!=nullptr)
            {
                ui->tableViewConge->setModel(verif_type_id);
            }
        }
}

void hygeia::on_pushButtonEnvoyer_clicked()
{
    
}

void hygeia::on_pushButtonReturn1_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void hygeia::on_amine_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void hygeia::on_pushButtonGoMedicaments_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void hygeia::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void hygeia::on_pushButtonReturn1_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void hygeia::on_pushButtonGoMedicaments_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void hygeia::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void hygeia::on_pushButtonGoMedicaments_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void hygeia::on_pushButtonGoMedicaments_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



























void hygeia::on_pushButtonajoutpatient_clicked()
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
    QSqlQueryModel *modelllll = new QSqlQueryModel;
    modelllll->setQuery("SELECT ID FROM PATIENT");
    ui->comboBox1->setModel(modelllll);


}


void hygeia::on_pushButton_suprpatient_clicked()
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

void hygeia::on_trienom_clicked()
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

void hygeia::on_triecin_clicked()
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

void hygeia::on_trienom_2_clicked()
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


void hygeia::on_pushButton_ajoutrdv_clicked()
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






void hygeia::on_suppRDV_clicked()
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

void hygeia::on_modifierpat_clicked()
{
        int cin=ui->cinmodif->text().toInt();
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
            ui->cinmodif->clear();
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

void hygeia::on_pushButton_modifierrdv_clicked()
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



void hygeia::on_rech_patient_clicked()
{
    bool test;
   Patient p;
       int cin=0;
       QString region=ui->lineEditChercherPatient->text();
       QString nom=ui->lineEditChercherPatient->text();
       QString choix=ui->comboBoxPatient->currentText();
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

void hygeia::on_imp_patient_clicked()
{

    //imprimer

           QPrinter printer;

           printer.setPrinterName("desiered printer name");

         QPrintDialog dialog(&printer,this);

           if(dialog.exec()== QDialog::Rejected)

               return;
}

void hygeia::on_pdf_patient_clicked()
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

void hygeia::on_rech_rdv_2_clicked()
{   bool test;
    rdv r;
        int cin_pat=0;

        QString nom_prenom=ui->chercherRDV->text();
        QString la_maladies=ui->chercherRDV->text();
        QString choix=ui->comboBox_RDV->currentText();
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

void hygeia::on_imp_patient_2_clicked()
{
    //imprimer

           QPrinter printer;

           printer.setPrinterName("desiered printer name");

         QPrintDialog dialog(&printer,this);

           if(dialog.exec()== QDialog::Rejected)

               return;
}

void hygeia::on_pdf_patient_2_clicked()
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

void hygeia::on_trieCinRDV_clicked()
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

void hygeia::on_pushButtonGoMedicaments_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void hygeia::on_oussama_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void hygeia::on_pushButtonGoMedicaments_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void hygeia::on_pushButtonajoutrdv_clicked()
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


//Arduino
void readSerial()
{
    /*QString serialBuffer;
    QStringList bufferSplit = serialBuffer.split(",");
    if(bufferSplit.length()<3)
    {
        data = A.read_from_arduino();
        serialBuffer += QString::fromStdString(data.toStdString());

    }
    else
    {
        qDebug() << bufferSplit;
        Capteurtemp::update_lcdnumber(bufferSplit[1]);
        serialBuffer="";
    }*/
    qDebug() << "serial port works";
}

void hygeia::update_button() {
/*data=A.read_from_arduino();
if(data=="1")
ui->pushButton_Bed4->setStyleSheet("background-color: red"); // si les donnees recues de arduino via la liaison serie sont egales a 1 // alors afficher ON . 1
else if (data=="0")
ui->pushButton_Bed4->setStyleSheet("background-color: green"); // si les donnees revues de arduino via la liaison serie sont egales a 0 //alors afficher ON*/
}

void hygeia::on_pushButton_Bed4_clicked()
{
    ui->pushButton_Bed4->setStyleSheet("background-color: green");
    A.write_to_arduino("1");

}

void hygeia::on_pushButtonNotifications_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void hygeia::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void hygeia::readSerial(){
    data=A.read_from_arduino();
    if (data=="1")
    {
        ui->pushButton_Bed4->setStyleSheet("background-color: red");
    }
}




void hygeia::on_pb_ajouter_clicked()
{

    int num=ui->le_num->text().toInt();
QString datec=ui->le_date_ajout->date().toString();
   // QString id_p=ui->le_id->text();
int cin= ui->comboBox1->currentText().toInt();




    QString numbers = "123456789";
// bool verifHedhi = false;
  //bool verif_id_p=true;
  bool verif_num=true;
 /*for(int i = 0; i < id_p.length(); i++){
               for(int j = 0; j < numbers.length(); j++){

                   if(id_p[i] == numbers[j]){
                                         verifHedhi = true;      // test sur id_p numero
                                     }
               }
               if(verifHedhi == false ){
                                 verif_id_p = false;
                                 QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                             QObject::tr("id_p il faut que un numero .\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);

                                 break;
                             }
                         }*/
 if (num ==0){
                      verif_num = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("il faut que le numero de dossier different de 0 .\n"//test num
                                              "Click Cancel to exit."), QMessageBox::Cancel);
              }




//if((verif_num==true)&&(verif_id_p==true)){
    if(verif_num==true){

dossiermedicale d(num,datec,cin);
    QMessageBox msg;
    bool testt=d.verifierId(cin);
            if(testt)
             {
                 QMessageBox::critical(nullptr, QObject::tr("Ajouter une Annonce"),
                             QObject::tr(" id patient déjà existant !.\n"
                                         "Click Ok to exit."), QMessageBox::Ok);

               }
            else

    {
                bool test=d.ajouter();
                if(test){


        ui->tabdossier->setModel(d_temp.afficher());
         msg.setText("Ajout avec succes");
    }

        else {
        msg.setText("Echec au niveau de lajout d un dossier medicale");
    }
    msg.exec();
    }
}
}



void hygeia::on_pushButton_2_clicked()
{
    dossiermedicale d;
   // int num=ui->le_num_sup->text().toInt();
    int num= ui->com->currentText().toInt();
    /*bool verif_num=true;
    bool testt=d.verifiernum(num);
    if (num ==0) {
                          verif_num = false;
                         QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                     QObject::tr("il faut que le numero de dossier different de 0 .\n"//test num
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
                 }

            if(testt==true)
             {
                 QMessageBox::critical(nullptr, QObject::tr("Ajouter une Annonce"),
                             QObject::tr(" num dossier n existant pas !.\n"
                                         "Click Ok to exit."), QMessageBox::Ok);

               }

   if((verif_num==true)&&(testt==false)){*/
     bool test=d_temp.supprimer(num);
     QMessageBox msg;
     if(test)
     {

         msg.setText("suppression avec succes");
     ui->tabdossier->setModel(d_temp.afficher());

     }

         else {
         msg.setText("Echec au niveau de la suppression d un dossier medicale");
     }
     msg.exec();

}

void hygeia::on_pushButton_3_clicked()
{
    int num=ui->le_num_modif->text().toInt();
     QString datec=ui->le_date_modif->date().toString();
int cin= ui->comboBox3->currentText().toInt();



    dossiermedicale d(num,datec,cin);
    QMessageBox msg;
    bool test=d.modifier(num,datec,cin);
   // bool verif_id=true;
    bool verif_num=true;
    if (num ==0){
                          verif_num = false;
                         QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                     QObject::tr("il faut que le numero de dossier different de 0 .\n"//test num
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}

                        /* if ((id_p ==0)&&(id_p=="")) {
                                               verif_id = false;
                                              QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                                          QObject::tr("il faut que le id de patient different de 0 .\n"//test num
                                                                      "Click Cancel to exit."), QMessageBox::Cancel);}*/
    if((test)&&(verif_num ))//&&(verif_id ))
    {
        ui->le_num_modif->clear();
        ui->le_date_modif->clear();
        //ui->le_idpatient_modif->clear();
 ui->tabdossier->setModel(d_temp.afficher());

        msg.setText("modifiction avec succes");


    }

        else {
        msg.setText("Echec au niveau de la modification d un dossier medicale");
    }
    msg.exec();

}
//}
//}

void hygeia::on_rech_doc_clicked()
{
    int cin = ui->lineEdit->text().toInt();

    ui->tabdossier->setModel(d_temp.rechercher(cin));



}

void hygeia::on_annuler_modif_clicked()
{
    ui->le_num_modif->clear();
    ui->le_date_modif->clear();//annuler ajout
    //ui->le_idpatient_modif->clear();
}



void hygeia::on_trie_doc_clicked()
{
    ui->tabdossier->setModel(d_temp.tridesc());
}



/*void hygeia::on_consulter_clicked()
{
    QString id_p = ui->le_id->text();
    ui->tabdos1->setModel(tab.consulter(id_p));
}*/




void hygeia::on_Impdos_clicked()
{
    //pour imprimer
                dossiermedicale ds;
                     QString text=ds.apercu_pdf();
                     ui->imprimer->setText(text);

                     QPrinter printer ;
                     printer.setPrinterName("imprim");
                     QPrintDialog dialog (&printer,this);
                     if(dialog.exec()==QDialog::Rejected) return ;
                     ui->imprimer->print(&printer);
}



void hygeia::on_anuuler_ajout_clicked()
{



    ui->le_num->clear();
    ui->le_date_ajout->clear();//annuler modif
    //ui->le_id->clear();
}


void hygeia::on_ajouterconsu_clicked()
{
     int num= ui->combondc->currentText().toInt();
    //int num=ui->numc->text().toInt();
    int num_interv=ui->nintervaj->text().toInt();
    QString date_inter=ui->dinteraj->date().toString();
    QString probl=ui->probaj->text();
    int tension=ui->tnaj->text().toInt();
    int glycemie=ui->glaj->text().toInt();
    int poids=ui->pdaj->text().toInt();
    int taille=ui->tlaj->text().toInt();
    QString ordonnance=ui->ordaj->text();

    QString num_tension= QString::number(tension);
     QString num_glycemie= QString::number(glycemie);//convertir les int en chaine
QString num_poids= QString::number(poids);
QString num_taille= QString::number(taille);

 QString numbers = "123456789";
 bool verif_tension=false;
  bool verif_glycemie=false;
  bool verif_poids=false;
   bool verif_taille=false;

 bool verif_num=true;

  for(int i = 0; i < num_tension.length(); i++){
                for(int j = 0; j < numbers.length(); j++){

                    if(num_tension[i] == numbers[j]){
                                          verif_tension = true;      // test sur id_p numero
                                      }
                }
                if(verif_tension == false ){

                                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                              QObject::tr("il faut que le tension un numero .\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);

                                  break;
                              }
                          }

  for(int i = 0; i < num_glycemie.length(); i++){
                for(int j = 0; j < numbers.length(); j++){

                    if(num_glycemie[i] == numbers[j]){
                                          verif_glycemie = true;      // test sur id_p numero
                                      }
                }
                if(verif_glycemie == false ){

                                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                              QObject::tr("il faut que le glycemie un numero .\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);

                                  break;
                              }
                          }
  for(int i = 0; i < num_poids.length(); i++){
                for(int j = 0; j < numbers.length(); j++){

                    if(num_poids[i] == numbers[j]){
                                          verif_poids = true;      // test sur id_p numero
                                      }
                }
                if(verif_poids == false ){

                                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                              QObject::tr("il faut que le poids un numero .\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);

                                  break;
                              }
                          }
  for(int i = 0; i < num_taille.length(); i++){
                for(int j = 0; j < numbers.length(); j++){

                    if(num_taille[i] == numbers[j]){
                                          verif_taille = true;      // test sur id_p numero
                                      }
                }
                if(verif_taille == false ){

                                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                              QObject::tr("il faut que la taille un numero .\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);

                                  break;
                              }
                          }



 if ((num ==0)||(num_interv==0)){
                      verif_num = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("il faut que le numero de dossier different et num inter <> 0 .\n"//test num
                                              "Click Cancel to exit."), QMessageBox::Cancel);
              }

           else

    {
     consultation c( num, num_interv, date_inter, probl, tension, glycemie, poids, taille,ordonnance);
         QMessageBox msg;
                bool test=c.ajouter();
                if((test)&&(verif_poids==true)&&(verif_num==true)&&(verif_taille==true)&&(verif_tension==true)&&(verif_glycemie==true))
                {


       ui->tabconsu->setModel(c_temp.afficher());
         msg.setText("Ajout avec succes");
    }

        else {
        msg.setText("Echec au niveau de lajout d un dossier medicale");
    }
    msg.exec();

}

}



void hygeia::on_Quitterc_clicked()
{
    ui->le_num->clear();
    ui->le_date_ajout->clear();//annuler modif
    //ui->le_id->clear();
    //ui->numc->clear();
         ui->nintervaj->clear();
        ui->dinteraj->clear();
         ui->probaj->clear();
        ui->tnaj->clear();
      ui->glaj->clear();
       ui->pdaj->clear();
     ui->tlaj->clear();
       ui->ordaj->clear();
}

void hygeia::on_supc_clicked()
{
    consultation c;
   // int num_interv=ui->numinsup->text().toInt();
   // QString num_inter= QString::number(num_interv);
    int num_interv= ui->combnic->currentText().toInt();
   // bool verif_num=true;
   /* QString numbers = "123456789";
    bool verif_inter=false;

    for(int i = 0; i < num_inter.length(); i++){
                  for(int j = 0; j < numbers.length(); j++){

                      if(num_inter[i] == numbers[j]){
                                            verif_inter = true;
                                        }
                  }
                  if(verif_inter == false ){

                                    QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                                QObject::tr("il faut que le num interv est un numero .\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);

                                    break;
                                }
                            }*/

    /*if (num_interv ==0) {
                          verif_num = false;
                         QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                     QObject::tr("il faut que le numero dintervention different de 0 .\n"//test num
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
                 }*/


    bool test=c_temp.supprimer(num_interv);
    QMessageBox msg;

     if (test)//&&(verif_num))//&&(verif_inter = true))
     {
         ui->tabconsu->setModel(c_temp.afficher());
         msg.setText("suppression avec succes");

     }

         else {
         msg.setText("Echec au niveau de la suppression de consultation");
     }
     msg.exec();


}

void hygeia::on_rechc_clicked()
{
int num_interv=ui->intervcherch->text().toInt();
ui->tabconsu->setModel(c_temp.rechercher(num_interv));
}

void hygeia::on_triec_clicked()
{
    ui->tabconsu->setModel(c_temp.tridesc());


}


void hygeia::on_modif_clicked()
{
    int num= ui->combondc->currentText().toInt();
    int num_interv=ui->nintervaj->text().toInt();
    QString date_inter=ui->dinteraj->date().toString();
    QString probl=ui->probaj->text();
    int tension=ui->tnaj->text().toInt();
    int glycemie=ui->glaj->text().toInt();
    int poids=ui->pdaj->text().toInt();
    int taille=ui->tlaj->text().toInt();
    QString ordonnance=ui->ordaj->text();



    QString num_tension= QString::number(tension);
     QString num_glycemie= QString::number(glycemie);//convertir les int en chaine
QString num_poids= QString::number(poids);
QString num_taille= QString::number(taille);

 QString numbers = "123456789";
 bool verif_tension=false;
  bool verif_glycemie=false;
  bool verif_poids=false;
   bool verif_taille=false;

 bool verif_num=true;

  for(int i = 0; i < num_tension.length(); i++){
                for(int j = 0; j < numbers.length(); j++){

                    if(num_tension[i] == numbers[j]){
                                          verif_tension = true;      // test sur id_p numero
                                      }
                }
                if(verif_tension == false ){

                                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                              QObject::tr("il faut que le tension un numero .\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);

                                  break;
                              }
                          }

  for(int i = 0; i < num_glycemie.length(); i++){
                for(int j = 0; j < numbers.length(); j++){

                    if(num_glycemie[i] == numbers[j]){
                                          verif_glycemie = true;      // test sur id_p numero
                                      }
                }
                if(verif_glycemie == false ){

                                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                              QObject::tr("il faut que le glycemie un numero .\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);

                                  break;
                              }
                          }
  for(int i = 0; i < num_poids.length(); i++){
                for(int j = 0; j < numbers.length(); j++){

                    if(num_poids[i] == numbers[j]){
                                          verif_poids = true;      // test sur id_p numero
                                      }
                }
                if(verif_poids == false ){

                                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                              QObject::tr("il faut que le poids un numero .\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);

                                  break;
                              }
                          }
  for(int i = 0; i < num_taille.length(); i++){
                for(int j = 0; j < numbers.length(); j++){

                    if(num_taille[i] == numbers[j]){
                                          verif_taille = true;      // test sur id_p numero
                                      }
                }
                if(verif_taille == false ){

                                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                              QObject::tr("il faut que la taille un numero .\n"
                                                          "Click Cancel to exit."), QMessageBox::Cancel);

                                  break;
                              }
                          }




 if ((num ==0)||(num_interv==0)){
                      verif_num = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("il faut que le numero de dossier different et num inter <> 0 .\n"//test num
                                              "Click Cancel to exit."), QMessageBox::Cancel);
              }

           else

    {
     consultation c(num, num_interv, date_inter, probl, tension, glycemie, poids, taille,ordonnance);
         QMessageBox msg;
                bool test=c.modifier(num, num_interv, date_inter, probl, tension, glycemie, poids, taille,ordonnance);
                if((test)&&(verif_poids==true)&&(verif_num==true)&&(verif_taille==true)&&(verif_tension==true)&&(verif_glycemie==true))
                {


       ui->tabconsu->setModel(c_temp.afficher());
         msg.setText("modification avec succes");
    }

        else {
        msg.setText("Echec au niveau de modification consultation");
    }
    msg.exec();

}


}

void hygeia::on_Impdos_2_clicked()
{
    consultation c;
         QString text=c.apercu_pdf();
         ui->impc->setText(text);

         QPrinter printer ;
         printer.setPrinterName("imprim");
         QPrintDialog dialog (&printer,this);
         if(dialog.exec()==QDialog::Rejected) return ;
         ui->impc->print(&printer);
}


void hygeia::on_refrech_aj_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery();
    qry->prepare("select CIN from PATIENT");
    qry->exec();
    model->setQuery(*qry);
    ui->comboBox1->setModel(model);
}

void hygeia::on_refrech_mod_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery();
    qry->prepare("select CIN from PATIENT");
    qry->exec();
    model->setQuery(*qry);
    ui->comboBox3->setModel(model);
}

void hygeia::on_pushButton_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery();
    qry->prepare("select NUM_DOSSIER from DOCMEDICAL");//
    qry->exec();
    model->setQuery(*qry);
    ui->com->setModel(model);
}

void hygeia::on_pushButton_4_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery();
    qry->prepare("select NUM_DOSSIER from DOCMEDICAL");//
    qry->exec();
    model->setQuery(*qry);
    ui->combondc->setModel(model);
}

void hygeia::on_pushButton_5_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery();
    qry->prepare("select NUM_INTERV from CONSULTATION");//
    qry->exec();
    model->setQuery(*qry);
    ui->combnic->setModel(model);

}



void hygeia::on_pushButton_7_clicked()
{
int num_interv= ui->com_2->currentText().toInt();
QString montant=ui->montant->text();
QString mode_p=ui->mode->text();
QString date_op=ui->dateop->date().toString();


QString caractere="azertyuiopmlkjhgfdsqwxcvbn";
QString numbers = "123456789";
bool verifHedhi = false;
bool verif_modep=true;
bool verif_montant=true;
bool verifHedhi1= false;



for(int i = 0; i < montant.length(); i++){
           for(int j = 0; j < numbers.length(); j++){

               if(montant[i] == numbers[j]){
                                     verifHedhi = true;      // test sur id_p numero
                                 }
           }
           if(verifHedhi == false ){

                             QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                         QObject::tr("id il faut que le montant de labo est un numero .\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

                             break;
                         }
                     }
if ((mode_p =="0")||(mode_p =="")){
                  verif_modep = false;
                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                              QObject::tr("il faut que le mode de payement different de vide et dif de 0.\n"//test num
                                          "Click Cancel to exit."), QMessageBox::Cancel);
          }
if ((montant =="0")||(montant =="")){
                  verif_modep = false;
                  QMessageBox::information(nullptr, QObject::tr("Erreur"),
                              QObject::tr("il faut que le montant different de vide et dif de 0.\n"//test num
                                          "Click Cancel to exit."), QMessageBox::Cancel);
          }



for(int i = 0; i < mode_p.length(); i++){
         for(int j = 0; j < caractere.length(); j++){

             if(mode_p[i] == caractere[j]){
                                   verifHedhi1 = true;      // test sur id_p numero
                               }
         }
         if(verifHedhi1 == false ){

                           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                       QObject::tr("id il faut que le mode de payement   est un caractere .\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

                           break;
                       }
                   }







if((verif_montant==true)&&(verifHedhi==true)&&( verif_modep==true)&&(verifHedhi1==true)){

payement p(num_interv,montant,mode_p,date_op);
QMessageBox msg;
bool testt=p.verifiernum(num_interv);
        if(testt)
         {
             QMessageBox::critical(nullptr, QObject::tr("Ajouter une Annonce"),
                         QObject::tr(" num intervention déjà existant !.\n"
                                     "Click Ok to exit."), QMessageBox::Ok);

           }
        else

{
            bool test=p.ajouter();
            if(test){


  ui->tabpayement->setModel(p_temp.afficher());
     msg.setText("Ajout avec succes");
}

    else {
    msg.setText("Echec au niveau de lajout d un payementt");
}
msg.exec();
}
}


}

void hygeia::on_refrech_numinterpa_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery();
    qry->prepare("select NUM_INTERV from CONSULTATION");//
    qry->exec();
    model->setQuery(*qry);
    ui->com_2->setModel(model);
}

void hygeia::on_quitter_p_clicked()
{
    ui->com_2->clear();
    ui->montant->clear();
   ui->mode->clear();
    ui->dateop->clear();
}

void hygeia::on_modifier_p_clicked()
{
    int num_interv= ui->com_2->currentText().toInt();
    QString montant=ui->montant->text();
    QString mode_p=ui->mode->text();
    QString date_op=ui->dateop->date().toString();


    QString caractere="azertyuiopmlkjhgfdsqwxcvbn";
    QString numbers = "123456789";
    bool verifHedhi = false;
    bool verif_modep=true;
    bool verif_montant=true;
    bool verifHedhi1= false;



    for(int i = 0; i < montant.length(); i++){
               for(int j = 0; j < numbers.length(); j++){

                   if(montant[i] == numbers[j]){
                                         verifHedhi = true;      // test sur id_p numero
                                     }
               }
               if(verifHedhi == false ){

                                 QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                             QObject::tr(" il faut que le montant de labo est un numero .\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);

                                 break;
                             }
                         }
    if ((mode_p =="0")||(mode_p =="")){
                      verif_modep = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("il faut que le mode de payement different de vide et dif de 0.\n"//test num
                                              "Click Cancel to exit."), QMessageBox::Cancel);
              }
    if ((montant =="0")||(montant =="")){
                      verif_modep = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("il faut que le montant different de vide et dif de 0.\n"//test num
                                              "Click Cancel to exit."), QMessageBox::Cancel);
              }



    for(int i = 0; i < mode_p.length(); i++){
             for(int j = 0; j < caractere.length(); j++){

                 if(mode_p[i] == caractere[j]){
                                       verifHedhi1 = true;      // test sur id_p numero
                                   }
             }
             if(verifHedhi1 == false ){

                               QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                           QObject::tr("id il faut que le mode de payement est un caractere .\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);

                               break;
                           }
                       }







    if((verif_montant==true)&&(verifHedhi==true)&&( verif_modep==true)&&(verifHedhi1==true)){

    payement p(num_interv,montant,mode_p,date_op);
    QMessageBox msg;
    bool testt=p.verifiernum(num_interv);
            if(testt)
             {
                 QMessageBox::critical(nullptr, QObject::tr("Ajouter une Annonce"),
                             QObject::tr(" numero abo déjà existant !.\n"
                                         "Click Ok to exit."), QMessageBox::Ok);

               }
            else

    {
                bool test=p.modifier(num_interv,montant,mode_p,date_op);
                if(test){


      ui->tabpayement->setModel(p_temp.afficher());
         msg.setText("Ajout avec succes");
    }

        else {
        msg.setText("Echec au niveau de lajout d un abonnement");
    }
    msg.exec();
    }
}
}

void hygeia::on_supprimer_payement_clicked()
{
    payement p;

    int num_interv= ui->combosuppp->currentText().toInt();


    bool test=p_temp.supprimer(num_interv);
    QMessageBox msg;

     if (test)
     {
         ui->tabpayement->setModel(p_temp.afficher());
         msg.setText("suppression avec succes");

     }

         else {
         msg.setText("Echec au niveau de la suppression de payement");
     }
     msg.exec();
}

void hygeia::on_refreh_sup_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery();
    qry->prepare("select NUM_INTERV from CONSULTATION");//
    qry->exec();
    model->setQuery(*qry);
    ui->combosuppp->setModel(model);
}

void hygeia::on_pushButton_6_clicked()
{
    int num_interv=ui->rech_n_p->text().toInt();
    ui->tabpayement->setModel(p_temp.rechercher(num_interv));
}

void hygeia::on_pushButton_8_clicked()
{
 ui->tabpayement->setModel(p_temp.tridesc());
}

void hygeia::on_pushButton_9_clicked()
{
    ui->tabpayement->setModel(p_temp.triasc());
}

void hygeia::on_pushButton_10_clicked()
{
    payement p;
         QString text=p.apercu_pdf();
         ui->improumer->setText(text);

         QPrinter printer ;
         printer.setPrinterName("imprim");
         QPrintDialog dialog (&printer,this);
         if(dialog.exec()==QDialog::Rejected) return ;
         ui->improumer->print(&printer);
}

void hygeia::on_pushButtonReturn1_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void hygeia::on_pushButtonReturn1_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void hygeia::on_viderCases_4_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void hygeia::on_viderCases_5_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void hygeia::on_viderCases_6_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void hygeia::on_viderCases_7_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void hygeia::on_viderCases_8_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void hygeia::timerEvent(QTimerEvent *event)
{

   QString ss=QString::fromUtf8(a.read_from_arduino()); // 9rina mel arduino

   int i=0;
   for(int j=0;j<4;j++)
   {
       if(ss[j].isNumber())
       {

           i=i*10+ss[j].digitValue();
       }

   }
   qDebug() << i;
   if(i<900)
       QMessageBox::information(nullptr, QObject::tr("database is open"),
                   QObject::tr("alarme de feu .\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}

void hygeia::on_pushButton_14_clicked()
{
    QTableView *table;

                            table = ui->tableViewEmploye;


                            QString filters("Excel Files (.xls)");

                            QString defaultFilter("Excel Files (*.xls)");

                            QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),

                                               filters, &defaultFilter);

                            QFile file(fileName);


                            QAbstractItemModel *model =  table->model();

                            if (file.open(QFile::WriteOnly | QFile::Truncate)) {

                                QTextStream data(&file);

                                QStringList strList;

                                for (int i = 0; i < model->columnCount(); i++) {

                                    if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)

                                        strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");

                                    else

                                        strList.append("");

                                }

                                data << strList.join(";") << "\n";

                                for (int i = 0; i < model->rowCount(); i++) {

                                    strList.clear();

                                    for (int j = 0; j < model->columnCount(); j++) {


                                        if (model->data(model->index(i, j)).toString().length() > 0)

                                            strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");

                                        else

                                            strList.append("");

                                    }

                                    data << strList.join(";") + "\n";

                                }

                                file.close();
            }
}

void hygeia::on_pushButton_16_clicked()
{
        QTableView *table;

                                table = ui->tabMedicaments;


                                QString filters("Excel Files (.xls)");

                                QString defaultFilter("Excel Files (*.xls)");

                                QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),

                                                   filters, &defaultFilter);

                                QFile file(fileName);


                                QAbstractItemModel *model =  table->model();

                                if (file.open(QFile::WriteOnly | QFile::Truncate)) {

                                    QTextStream data(&file);

                                    QStringList strList;

                                    for (int i = 0; i < model->columnCount(); i++) {

                                        if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)

                                            strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");

                                        else

                                            strList.append("");

                                    }

                                    data << strList.join(";") << "\n";

                                    for (int i = 0; i < model->rowCount(); i++) {

                                        strList.clear();

                                        for (int j = 0; j < model->columnCount(); j++) {


                                            if (model->data(model->index(i, j)).toString().length() > 0)

                                                strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");

                                            else

                                                strList.append("");

                                        }

                                        data << strList.join(";") + "\n";

                                    }

                                    file.close();

                                    QMessageBox::information(nullptr, QObject::tr("Export excel"),

                                                              QObject::tr("Export avec succes .\n"

                                                                          "Click OK to exit."), QMessageBox::Ok);
                }

    }
