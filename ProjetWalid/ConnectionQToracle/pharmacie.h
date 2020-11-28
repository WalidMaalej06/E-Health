#ifndef PHARMACIE_H
#define PHARMACIE_H

#include <QDialog>
#include "medicament.h"

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

private:
    Ui::Pharmacie *ui;
    Medicament M_tmp;
};



#endif // PHARMACIE_H
