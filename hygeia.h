#ifndef HYGEIA_H
#define HYGEIA_H

#include <QMainWindow>
#include <QWidget>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <QDebug>
#include <QSqlTableModel>
#include "employe.h"
#include "conge.h"
#include <QAbstractItemView>
#include <QRegExp>
#include <QFileDialog>
#include <QPrinter>
#include <QSortFilterProxyModel>
#include <QTextDocument>
#include <QPrintDialog>
#include "medicament.h"
#include "poche.h"
#include "rdv.h"
#include "patient.h"
#include "dossiermedicale.h"
#include "payement.h"
#include "consultation.h"
#include <QPropertyAnimation>
#include "connection.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class hygeia; }
QT_END_NAMESPACE

class hygeia : public QMainWindow
{
    Q_OBJECT

public:
    hygeia(QWidget *parent = nullptr);
    ~hygeia();

private slots:
    void on_actionClose_triggered();

    void on_pushButtonQuitter_clicked();

    void on_actionCopier_triggered();
    
    void on_actionCouper_triggered();
    
    void on_actionColler_triggered();
    
    void on_rayen_clicked();

    void on_pushButtonGoEmploye_clicked();

    void on_pushButtonReturn1_clicked();

    void on_pushButtonReturn_clicked();

    void on_pushButtonGoConge_clicked();

    void on_pushButtonAjouterEmploye_clicked();

    void on_pushButtonAfficherTout_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonRechercher_clicked();

    void on_pushButtonPDF_clicked();

    void on_pushButtonImprimer_clicked();

    void on_pushButtonTrier_clicked();

    void on_ajouter_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonSuppr_clicked();

    void on_pushButtonAfficherToutConge_clicked();

    void on_walid_clicked();

    void on_pushButtonGoSang_2_clicked();

    void on_pushButtonReturn1_3_clicked();

    void on_buttonAjouter_clicked();

    void on_BmedicamentDelete_clicked();

    void on_BconsulterMedicament_clicked();

    void on_BmedicamentsEdit_clicked();

    void on_buttonRechercheMed_clicked();

    void on_cTriMed_2_clicked();

    void on_ajouterPoche_2_clicked();

    void on_consulterPoche_clicked();

    void on_modifierPoche_clicked();

    void on_supprimerPoche_clicked();

    void on_rechercherButtonPoche_clicked();

    void on_actualiserTriPoches_clicked();

    void on_BimpPoches_clicked();

    void on_pdfPoches_clicked();

    void on_BimpMed_clicked();

    void on_pdfMed_clicked();

    void on_pushButtonGoSang_clicked();

    void on_pushButtonReturn1_2_clicked();

    void on_pushButtonGoMedicaments_clicked();

    void on_pushButtonVider_clicked();

    void on_viderCases_clicked();

    void on_viderCases_2_clicked();

    void on_viderCases_3_clicked();

    void on_pushButtonStatistiques_clicked();

    void on_pushButtonReturn1_4_clicked();

    void on_pushButtonEnvoyer_clicked();
    
    void on_amine_clicked();

    void on_pushButtonGoMedicaments_2_clicked();

    void on_pushButton_12_clicked();

    void on_pushButtonReturn1_5_clicked();

    void on_pushButtonGoMedicaments_3_clicked();

    void on_pushButton_11_clicked();

    void on_pushButtonGoMedicaments_5_clicked();

    void on_pushButtonGoMedicaments_4_clicked();




    //Jazi
    void on_pushButtonajoutpatient_clicked();

    void on_pushButton_suprpatient_clicked();

    void on_trienom_clicked();

    void on_triecin_clicked();

    void on_pushButton_ajoutrdv_clicked();

    void on_trienom_2_clicked();

    void on_suppRDV_clicked();

    void on_modifierpat_clicked();

    void on_pushButton_modifierrdv_clicked();

    void on_rech_patient_clicked();

    void on_imp_patient_clicked();

    void on_pdf_patient_clicked();

    void on_rech_rdv_2_clicked();

    void on_imp_patient_2_clicked();

    void on_pdf_patient_2_clicked();

    void on_trieCinRDV_clicked();

    void on_pushButtonGoMedicaments_7_clicked();

    void on_oussama_clicked();

    void on_pushButtonGoMedicaments_8_clicked();

    void on_pushButtonajoutrdv_clicked();

    //Arduino

    void update_button();

    void on_pushButton_Bed4_clicked();

    void on_pushButtonNotifications_clicked();

    void on_pushButton_13_clicked();
    void readSerial();



    //amine
    void on_pb_ajouter_clicked();

        void on_pushButton_2_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_clicked();

        void on_pushButton_4_clicked();

        void on_rech_doc_clicked();

        void on_annuler_modif_clicked();

        void on_anuuler_ajout_clicked();

        void on_trie_doc_clicked();

        void on_Impdos_clicked();

        void on_ajouterconsu_clicked();

        void on_pushButton_6_clicked();

        void on_Quitterc_clicked();

        void on_supc_clicked();

        void on_rechc_clicked();

        void on_triec_clicked();

        void on_modif_clicked();

        void on_Impdos_2_clicked();

        void on_refrech_aj_clicked();

        void on_refrech_mod_clicked();

        void on_pushButton_5_clicked();

        void on_pushButton_7_clicked();

        void on_refrech_numinterpa_clicked();

        void on_quitter_p_clicked();

        void on_modifier_p_clicked();

        void on_supprimer_payement_clicked();

        void on_refreh_sup_clicked();

        void on_pushButton_8_clicked();

        void on_pushButton_9_clicked();

        void on_pushButton_10_clicked();


        void on_pushButtonReturn1_6_clicked();

        void on_pushButtonReturn1_7_clicked();

        void on_viderCases_4_clicked();

        void on_viderCases_5_clicked();

        void on_viderCases_6_clicked();

        void on_viderCases_7_clicked();

        void on_viderCases_8_clicked();


        void on_pushButton_14_clicked();

        void on_pushButton_16_clicked();

private:
    Ui::hygeia *ui;
    //Rayen
    employe tmpemploye;
    conge tmpconge;
    QRegExp mail_regex;
    QRegExp nom_regex,tel_regex,salaire_regex, id_regex;
    //Walid
    Medicament M_tmp;
    poche P_tmp;
    //Oussama
    Patient s;
    rdv r;
    //Amine
    dossiermedicale d_temp;
    dossiermedicale tab;
    consultation c_temp;
    payement p_temp;
    QPropertyAnimation *animation;

    //Arduino Walid Rayen
    Arduino A;
    QByteArray data;

    //Arduino Amine Oussema
    Arduino a;
    QByteArray data1;
    int timerId;

protected:
    void timerEvent(QTimerEvent *event);

};
#endif // HYGEIA_H
