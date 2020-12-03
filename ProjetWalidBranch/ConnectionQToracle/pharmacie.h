#ifndef PHARMACIE_H
#define PHARMACIE_H

#include <QDialog>
#include "medicament.h"
#include "poche.h"
#include <QSound>

namespace Ui {
class Pharmacie;
}

class Pharmacie : public QDialog
{
    Q_OBJECT

public:
    explicit Pharmacie(QWidget *parent = nullptr);
    ~Pharmacie();

private slots:
    void on_buttonAjouter_clicked();

    void on_BmedicamentDelete_clicked();

    void on_BconsulterMedicament_clicked();

    void on_BmedicamentsEdit_clicked();

    void on_afficherStock_2_tabBarClicked(int index);

    void on_buttonRechercheMed_clicked();

    void on_bTri_clicked();

    void on_ajouterPoche_2_clicked();

    void on_tabPharmacie_tabBarClicked(int index);

    void on_consulterPoche_clicked();

    void on_modifierPoche_clicked();

    void on_supprimerPoche_clicked();

    void on_rechercherButtonPoche_clicked();

    void on_actualiserTriPoches_clicked();

    void on_BimpPoches_clicked();

    void on_pdfPoches_clicked();

    void on_BimpMed_clicked();

    void on_pdfMed_clicked();

private:
    Ui::Pharmacie *ui;
    Medicament M_tmp;
    poche P_tmp;
    QSound *click,*messagesound;
};



#endif // PHARMACIE_H
