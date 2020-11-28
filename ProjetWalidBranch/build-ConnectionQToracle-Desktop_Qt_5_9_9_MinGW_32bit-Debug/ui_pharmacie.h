/********************************************************************************
** Form generated from reading UI file 'pharmacie.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHARMACIE_H
#define UI_PHARMACIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pharmacie
{
public:
    QTabWidget *afficherStock_2;
    QWidget *ajouterMedicament;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *nameInput;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *dateInput;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *prixInput;
    QLabel *label_6;
    QLabel *label_15;
    QLineEdit *refInput;
    QLineEdit *quantiteInput;
    QLineEdit *familleInput;
    QPushButton *buttonAjouter;
    QWidget *afficherStock;
    QRadioButton *radioButton_4;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton_6;
    QLabel *label_14;
    QComboBox *comboBox_3;
    QPushButton *pushButton_3;
    QTableView *tabMedicaments;
    QPushButton *BstatMedicaments;
    QWidget *modifierMedicament;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QLineEdit *nomEdit;
    QLabel *label_8;
    QDateEdit *dateEdit;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *prixEdit;
    QLabel *label_12;
    QLineEdit *quantiteEdit;
    QLabel *label_9;
    QLineEdit *familleEdit;
    QPushButton *BmedicamentDelete;
    QPushButton *BconsulterMedicament;
    QLineEdit *refEdit;
    QLabel *label_13;
    QPushButton *BmedicamentsEdit;

    void setupUi(QDialog *Pharmacie)
    {
        if (Pharmacie->objectName().isEmpty())
            Pharmacie->setObjectName(QStringLiteral("Pharmacie"));
        Pharmacie->resize(800, 600);
        afficherStock_2 = new QTabWidget(Pharmacie);
        afficherStock_2->setObjectName(QStringLiteral("afficherStock_2"));
        afficherStock_2->setGeometry(QRect(30, 20, 741, 571));
        ajouterMedicament = new QWidget();
        ajouterMedicament->setObjectName(QStringLiteral("ajouterMedicament"));
        groupBox = new QGroupBox(ajouterMedicament);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 60, 401, 311));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 111, 16));
        nameInput = new QLineEdit(groupBox);
        nameInput->setObjectName(QStringLiteral("nameInput"));
        nameInput->setGeometry(QRect(140, 70, 113, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 110, 47, 14));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 160, 91, 16));
        dateInput = new QDateEdit(groupBox);
        dateInput->setObjectName(QStringLiteral("dateInput"));
        dateInput->setGeometry(QRect(140, 200, 110, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 200, 91, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 250, 47, 14));
        prixInput = new QLineEdit(groupBox);
        prixInput->setObjectName(QStringLiteral("prixInput"));
        prixInput->setGeometry(QRect(140, 250, 81, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 250, 21, 16));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 30, 111, 16));
        refInput = new QLineEdit(groupBox);
        refInput->setObjectName(QStringLiteral("refInput"));
        refInput->setGeometry(QRect(140, 30, 113, 20));
        quantiteInput = new QLineEdit(groupBox);
        quantiteInput->setObjectName(QStringLiteral("quantiteInput"));
        quantiteInput->setGeometry(QRect(140, 150, 113, 20));
        familleInput = new QLineEdit(groupBox);
        familleInput->setObjectName(QStringLiteral("familleInput"));
        familleInput->setGeometry(QRect(140, 110, 113, 20));
        buttonAjouter = new QPushButton(ajouterMedicament);
        buttonAjouter->setObjectName(QStringLiteral("buttonAjouter"));
        buttonAjouter->setGeometry(QRect(480, 340, 75, 23));
        afficherStock_2->addTab(ajouterMedicament, QString());
        afficherStock = new QWidget();
        afficherStock->setObjectName(QStringLiteral("afficherStock"));
        radioButton_4 = new QRadioButton(afficherStock);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(240, 60, 97, 20));
        pushButton_8 = new QPushButton(afficherStock);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(340, 30, 93, 28));
        lineEdit_2 = new QLineEdit(afficherStock);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 40, 181, 22));
        radioButton_6 = new QRadioButton(afficherStock);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(240, 20, 97, 20));
        label_14 = new QLabel(afficherStock);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(490, 40, 47, 14));
        comboBox_3 = new QComboBox(afficherStock);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(540, 40, 91, 22));
        pushButton_3 = new QPushButton(afficherStock);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(650, 40, 75, 23));
        tabMedicaments = new QTableView(afficherStock);
        tabMedicaments->setObjectName(QStringLiteral("tabMedicaments"));
        tabMedicaments->setGeometry(QRect(30, 110, 691, 401));
        BstatMedicaments = new QPushButton(afficherStock);
        BstatMedicaments->setObjectName(QStringLiteral("BstatMedicaments"));
        BstatMedicaments->setGeometry(QRect(650, 520, 75, 23));
        afficherStock_2->addTab(afficherStock, QString());
        modifierMedicament = new QWidget();
        modifierMedicament->setObjectName(QStringLiteral("modifierMedicament"));
        groupBox_2 = new QGroupBox(modifierMedicament);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 100, 371, 311));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 50, 111, 16));
        nomEdit = new QLineEdit(groupBox_2);
        nomEdit->setObjectName(QStringLiteral("nomEdit"));
        nomEdit->setGeometry(QRect(140, 50, 113, 20));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 110, 47, 14));
        dateEdit = new QDateEdit(groupBox_2);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(140, 200, 110, 22));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 200, 91, 16));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 250, 47, 14));
        prixEdit = new QLineEdit(groupBox_2);
        prixEdit->setObjectName(QStringLiteral("prixEdit"));
        prixEdit->setGeometry(QRect(140, 250, 81, 20));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(230, 250, 21, 16));
        quantiteEdit = new QLineEdit(groupBox_2);
        quantiteEdit->setObjectName(QStringLiteral("quantiteEdit"));
        quantiteEdit->setGeometry(QRect(140, 150, 113, 20));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 160, 91, 16));
        familleEdit = new QLineEdit(groupBox_2);
        familleEdit->setObjectName(QStringLiteral("familleEdit"));
        familleEdit->setGeometry(QRect(140, 100, 113, 20));
        BmedicamentDelete = new QPushButton(modifierMedicament);
        BmedicamentDelete->setObjectName(QStringLiteral("BmedicamentDelete"));
        BmedicamentDelete->setGeometry(QRect(450, 390, 75, 23));
        BconsulterMedicament = new QPushButton(modifierMedicament);
        BconsulterMedicament->setObjectName(QStringLiteral("BconsulterMedicament"));
        BconsulterMedicament->setGeometry(QRect(380, 30, 93, 28));
        refEdit = new QLineEdit(modifierMedicament);
        refEdit->setObjectName(QStringLiteral("refEdit"));
        refEdit->setGeometry(QRect(170, 30, 181, 22));
        label_13 = new QLabel(modifierMedicament);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(70, 30, 71, 16));
        BmedicamentsEdit = new QPushButton(modifierMedicament);
        BmedicamentsEdit->setObjectName(QStringLiteral("BmedicamentsEdit"));
        BmedicamentsEdit->setGeometry(QRect(450, 360, 75, 23));
        afficherStock_2->addTab(modifierMedicament, QString());

        retranslateUi(Pharmacie);

        afficherStock_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Pharmacie);
    } // setupUi

    void retranslateUi(QDialog *Pharmacie)
    {
        Pharmacie->setWindowTitle(QApplication::translate("Pharmacie", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Pharmacie", "Ajouter Medicament", Q_NULLPTR));
        label->setText(QApplication::translate("Pharmacie", "Nom du m\303\251dicament", Q_NULLPTR));
        label_2->setText(QApplication::translate("Pharmacie", "Famille", Q_NULLPTR));
        label_3->setText(QApplication::translate("Pharmacie", "Quantite", Q_NULLPTR));
        label_4->setText(QApplication::translate("Pharmacie", "Date d'expiration", Q_NULLPTR));
        label_5->setText(QApplication::translate("Pharmacie", "Prix", Q_NULLPTR));
        label_6->setText(QApplication::translate("Pharmacie", "DT", Q_NULLPTR));
        label_15->setText(QApplication::translate("Pharmacie", "Reference", Q_NULLPTR));
        buttonAjouter->setText(QApplication::translate("Pharmacie", "Ajouter", Q_NULLPTR));
        afficherStock_2->setTabText(afficherStock_2->indexOf(ajouterMedicament), QApplication::translate("Pharmacie", "Ajouter medicament", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("Pharmacie", "Famille", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Pharmacie", "Rechercher", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("Pharmacie", "Nom", Q_NULLPTR));
        label_14->setText(QApplication::translate("Pharmacie", "Trier par", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Pharmacie", "Acutaliser", Q_NULLPTR));
        BstatMedicaments->setText(QApplication::translate("Pharmacie", "Statistiques", Q_NULLPTR));
        afficherStock_2->setTabText(afficherStock_2->indexOf(afficherStock), QApplication::translate("Pharmacie", "Afficher le stock", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Pharmacie", "Modifier Medicament", Q_NULLPTR));
        label_7->setText(QApplication::translate("Pharmacie", "Nom du m\303\251dicament", Q_NULLPTR));
        label_8->setText(QApplication::translate("Pharmacie", "Famille", Q_NULLPTR));
        label_10->setText(QApplication::translate("Pharmacie", "Date d'expiration", Q_NULLPTR));
        label_11->setText(QApplication::translate("Pharmacie", "Prix", Q_NULLPTR));
        label_12->setText(QApplication::translate("Pharmacie", "DT", Q_NULLPTR));
        label_9->setText(QApplication::translate("Pharmacie", "Quantite", Q_NULLPTR));
        BmedicamentDelete->setText(QApplication::translate("Pharmacie", "Supprimer", Q_NULLPTR));
        BconsulterMedicament->setText(QApplication::translate("Pharmacie", "Consulter", Q_NULLPTR));
        label_13->setText(QApplication::translate("Pharmacie", "Reference", Q_NULLPTR));
        BmedicamentsEdit->setText(QApplication::translate("Pharmacie", "Modifier", Q_NULLPTR));
        afficherStock_2->setTabText(afficherStock_2->indexOf(modifierMedicament), QApplication::translate("Pharmacie", "Modifier ou Supprimer un medicament", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Pharmacie: public Ui_Pharmacie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHARMACIE_H
