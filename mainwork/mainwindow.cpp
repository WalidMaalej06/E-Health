#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mail_regex=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
    cin_regex=QRegExp("[0-9]{8}$");
    telephone_regex=cin_regex=QRegExp("[0-9]{8}$");
    ui->setupUi(this);

    QSqlQueryModel * model = tmpemploye.afficher();
    ui->tableViewEmploye->setModel( model);
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(model);
    ui->tableViewEmploye->setModel(m);
    ui->tableViewEmploye->setSortingEnabled(true);
    ui->tableViewEmploye->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewEmploye->setSelectionMode(QAbstractItemView::SingleSelection);

    QSqlQueryModel * modell = tmpconge.afficher();
    ui->tableViewConge->setModel( modell);
    QSortFilterProxyModel *mm=new QSortFilterProxyModel(this);
    mm->setDynamicSortFilter(true);
    mm->setSourceModel(modell);
    ui->tableViewConge->setModel(mm);
    ui->tableViewConge->setSortingEnabled(true);

    ui->tableViewConge->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewConge->setSelectionMode(QAbstractItemView::SingleSelection);

    //longeur max ID 8
    ui->lineEditID->setMaxLength(8);

    //placeholders when empty
    ui->lineEditID->setPlaceholderText("ID");
    ui->lineEditNom->setPlaceholderText("Nom & Prénom");
    ui->lineEditDepart->setPlaceholderText("Département");
    ui->lineEditMail->setPlaceholderText("E-mail");
    ui->lineEditNum->setPlaceholderText("Numero De Tel");
    ui->lineEditMail->setPlaceholderText("E-mail");
    ui->lineEditSalaire->setPlaceholderText("Salaire");
}
bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
/*****************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}
/*****************************************************************/
//vider les cases
void MainWindow::on_pushButtonVider_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
            widget->clear();
        }
}
void MainWindow::on_viderCases_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
            widget->clear();
        }
}
/*****************************************************************/
//Ajout employe
void MainWindow::on_pushButtonAjouterEmploye_clicked()
{
        bool mail_verif = mail_regex.exactMatch(ui->lineEditMail->text());
        bool id_verif= cin_regex.exactMatch(ui->lineEditID->text());
        bool num_verif= telephone_regex.exactMatch(ui->lineEditNum->text());
        bool salaire_verif= cin_regex.exactMatch(ui->lineEditSalaire->text());
        if (ui->lineEditID->text()!="" &&
            ui->lineEditNom->text()!="" &&
            ui->lineEditNum->text()!="" &&
            ui->lineEditDepart->text()!="" &&
            ui->lineEditSalaire->text()!=""
            && id_verif!=false &&
            num_verif!=false &&
            salaire_verif !=false
            ){
            if (!mail_verif)
                    {
                        QMessageBox::warning(this,"Erreur lors de l'ajout","E-mail invalid");
                    }
                    else
                    {
                QString id=ui->lineEditID->text();
                QString nom=ui->lineEditNom->text();
                QString num=ui->lineEditNum->text();
                QString mail=ui->lineEditMail->text();
                QString dateAd=ui->dateEditAdhesion->date().toString();
                QString sexe=ui->comboBoxSexe->currentText();
                QString depart=ui->lineEditDepart->text();
                QString salaire=ui->lineEditSalaire->text();

                employe employe(id,nom,num,mail,dateAd,sexe,depart,salaire);
                employe.ajouter();
                ui->comboBoxNom->addItem(nom);
                QSqlQueryModel * model = tmpemploye.afficher();
                ui->tableViewEmploye->setModel( model);
                QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
                m->setDynamicSortFilter(true);
                m->setSourceModel(model);
                ui->tableViewEmploye->setModel(m);
                ui->tableViewEmploye->setSortingEnabled(true);
                foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                    widget->clear();
                }
            }
        }
        else{
            QMessageBox::warning(this,"Erreur lors de l'ajout","Veuillez verifier tous les champs");
        }
}
/*****************************************************************/
//Modificarion Employe
void MainWindow::on_pushButtonModifier_clicked()
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
}
/*****************************************************************/
//Suppression employe
void MainWindow::on_pushButtonSupprimer_clicked()
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
        }
}
/*****************************************************************/
//Ajout conge
void MainWindow::on_ajouter_clicked()
{
    QString id=ui->lineEditNumConge->text();
    QString nom=ui->comboBoxNom->currentText();
    QString dated=ui->dateEditDebut->date().toString();
    QString datef=ui->dateEditFin->date().toString();
    QString type=ui->lineEditDepart->text();

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
/*****************************************************************/
//Modificarion Conge
void MainWindow::on_pushButtonEdit_clicked()
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
}
/*****************************************************************/
//Suppression conge
void MainWindow::on_pushButtonSuppr_clicked()
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
/*****************************************************************/
//Exportation PDF
void MainWindow::on_pushButtonPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

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
/*****************************************************************/
//Rechercher
void MainWindow::on_pushButtonRechercher_clicked()
{
    QString nom=ui->lineEditChercher->text();
    QString id=ui->lineEditChercher->text();
    QString salaire=ui->lineEditChercher->text();
    QString date=ui->dateEditRecherche->date().toString();
    QString sexe="";
    if (ui->radioButtonHomme->isChecked())
        sexe=ui->radioButtonHomme->text();
    else if (ui->radioButtonFemme->isChecked())
        sexe=ui->radioButtonFemme->text();
    QString criter=ui->comboBoxCritaire->currentText();

    if (criter=="sexe"){
        QSqlQueryModel *verif_sexe=tmpemploye.rechercher_sexe(sexe);
        if (verif_sexe!=nullptr)
        {
            ui->tableViewEmploye->setModel(verif_sexe);
        }
    }
    if (criter=="nom"){
        QSqlQueryModel *verif_nom=tmpemploye.rechercher_nom(nom);
        if (verif_nom!=nullptr)
        {
            ui->tableViewEmploye->setModel(verif_nom);
        }
    }
    if (criter=="id"){
        QSqlQueryModel *verif_id=tmpemploye.rechercher_id(id);
        if (verif_id!=nullptr)
        {
            ui->tableViewEmploye->setModel(verif_id);
        }
    }
    if (criter=="combinaison"){
        if(nom!="" && sexe!="" && ui->checkBoxDate->isChecked()){
            QSqlQueryModel *verif_combinaison=tmpemploye.rechercher_combinaison_all(nom,sexe,date);
            if (verif_combinaison!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_combinaison);
            }
        }
        if(nom!="" && sexe!="" && !ui->checkBoxDate->isChecked()){
            QSqlQueryModel *verif_nom_sexe=tmpemploye.rechercher_combinaison_nom_sexe(nom,sexe);
            if (verif_nom_sexe!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_nom_sexe);
            }
        }
        if (nom!="" && sexe=="" && ui->checkBoxDate->isChecked()){
            QSqlQueryModel *verif_nom_date=tmpemploye.rechercher_combinaison_nom_date(nom,date);
            if (verif_nom_date!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_nom_date);
            }
        }
        if (nom=="" && sexe!="" && ui->checkBoxDate->isChecked()){
            QSqlQueryModel *verif_sexe_date=tmpemploye.rechercher_combinaison_sexe_date(sexe,date);
            if (verif_sexe_date!=nullptr)
            {
                ui->tableViewEmploye->setModel(verif_sexe_date);
            }
        }
    }
}
