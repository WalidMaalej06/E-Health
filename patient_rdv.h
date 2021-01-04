#ifndef PATIENT_RDV_H
#define PATIENT_RDV_H
#include "patient.h"
#include <QDialog>
#include "rdv.h"

namespace Ui {
class patient_rdv;
}

class patient_rdv : public QDialog
{
    Q_OBJECT

public:
    explicit patient_rdv(QWidget *parent = nullptr);
    ~patient_rdv();

private slots:
    void on_pushButtonajoutpatient_clicked();

    void on_pushButton_suprpatient_clicked();

    void on_trienom_clicked();

    void on_triecin_clicked();

    void on_pushButton_ajoutrdv_clicked();


    void on_trienom_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_retouradmin_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_modifierpat_clicked();

    void on_pushButton_modifierrdv_clicked();


    void on_rech_patient_clicked();

    void on_imp_patient_clicked();

    void on_pdf_patient_clicked();

    void on_rech_rdv_2_clicked();

    void on_imp_patient_2_clicked();

    void on_pdf_patient_2_clicked();

    void on_pushButton_2_clicked();

    void on_modifierpat_2_clicked();

private:
    Ui::patient_rdv *ui;
     Patient s;
     rdv r;
};

#endif // PATIENT_RDV_H
