/********************************************************************************
** Form generated from reading UI file 'banquedusang.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANQUEDUSANG_H
#define UI_BANQUEDUSANG_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_banqueDuSang
{
public:
    QTabWidget *tabPharmacie;
    QWidget *ajouterPoche;
    QPushButton *pushButton;
    QGroupBox *groupBox_3;
    QLabel *label_15;
    QLineEdit *lineEdit_7;
    QComboBox *comboBox_4;
    QLabel *label_16;
    QLabel *label_17;
    QDateEdit *dateEdit_3;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *lineEdit_9;
    QLabel *label_20;
    QLineEdit *lineEdit_10;
    QWidget *afficherStock;
    QTableWidget *tableWidget;
    QRadioButton *radioButton_4;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton_6;
    QLabel *label_14;
    QComboBox *comboBox_3;
    QPushButton *pushButton_3;
    QPushButton *BstatPoches;
    QWidget *modifierMedicament;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit_6;
    QLabel *label_13;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_2;
    QLabel *label_8;
    QLabel *label_9;
    QDateEdit *dateEdit_2;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_5;
    QLabel *label_12;
    QLineEdit *lineEdit_8;

    void setupUi(QDialog *banqueDuSang)
    {
        if (banqueDuSang->objectName().isEmpty())
            banqueDuSang->setObjectName(QStringLiteral("banqueDuSang"));
        banqueDuSang->resize(800, 600);
        tabPharmacie = new QTabWidget(banqueDuSang);
        tabPharmacie->setObjectName(QStringLiteral("tabPharmacie"));
        tabPharmacie->setGeometry(QRect(20, 20, 741, 571));
        ajouterPoche = new QWidget();
        ajouterPoche->setObjectName(QStringLiteral("ajouterPoche"));
        pushButton = new QPushButton(ajouterPoche);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 410, 75, 23));
        groupBox_3 = new QGroupBox(ajouterPoche);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(60, 70, 461, 371));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 50, 111, 16));
        lineEdit_7 = new QLineEdit(groupBox_3);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(140, 50, 113, 20));
        comboBox_4 = new QComboBox(groupBox_3);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(140, 100, 62, 22));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 110, 47, 14));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 160, 91, 16));
        dateEdit_3 = new QDateEdit(groupBox_3);
        dateEdit_3->setObjectName(QStringLiteral("dateEdit_3"));
        dateEdit_3->setGeometry(QRect(140, 210, 110, 22));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 210, 91, 16));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 260, 47, 14));
        lineEdit_9 = new QLineEdit(groupBox_3);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(140, 260, 81, 20));
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(230, 260, 21, 16));
        lineEdit_10 = new QLineEdit(groupBox_3);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(140, 160, 113, 20));
        tabPharmacie->addTab(ajouterPoche, QString());
        afficherStock = new QWidget();
        afficherStock->setObjectName(QStringLiteral("afficherStock"));
        tableWidget = new QTableWidget(afficherStock);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 100, 711, 401));
        tableWidget->setMinimumSize(QSize(0, 192));
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
        BstatPoches = new QPushButton(afficherStock);
        BstatPoches->setObjectName(QStringLiteral("BstatPoches"));
        BstatPoches->setGeometry(QRect(650, 510, 75, 23));
        tabPharmacie->addTab(afficherStock, QString());
        modifierMedicament = new QWidget();
        modifierMedicament->setObjectName(QStringLiteral("modifierMedicament"));
        pushButton_2 = new QPushButton(modifierMedicament);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 390, 75, 23));
        pushButton_9 = new QPushButton(modifierMedicament);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(380, 30, 93, 28));
        lineEdit_6 = new QLineEdit(modifierMedicament);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(170, 30, 181, 22));
        label_13 = new QLabel(modifierMedicament);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(70, 30, 71, 16));
        pushButton_4 = new QPushButton(modifierMedicament);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(510, 360, 75, 23));
        groupBox_2 = new QGroupBox(modifierMedicament);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 100, 411, 311));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(150, 60, 62, 22));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 70, 47, 14));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 120, 91, 16));
        dateEdit_2 = new QDateEdit(groupBox_2);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(150, 170, 110, 22));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 170, 91, 16));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 220, 47, 14));
        lineEdit_5 = new QLineEdit(groupBox_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(150, 220, 81, 20));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(240, 220, 21, 16));
        lineEdit_8 = new QLineEdit(groupBox_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(150, 120, 113, 20));
        tabPharmacie->addTab(modifierMedicament, QString());

        retranslateUi(banqueDuSang);

        tabPharmacie->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(banqueDuSang);
    } // setupUi

    void retranslateUi(QDialog *banqueDuSang)
    {
        banqueDuSang->setWindowTitle(QApplication::translate("banqueDuSang", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("banqueDuSang", "Ajouter", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("banqueDuSang", "Ajouter Poche", Q_NULLPTR));
        label_15->setText(QApplication::translate("banqueDuSang", "Reference", Q_NULLPTR));
        label_16->setText(QApplication::translate("banqueDuSang", "Type", Q_NULLPTR));
        label_17->setText(QApplication::translate("banqueDuSang", "Id de donneur", Q_NULLPTR));
        label_18->setText(QApplication::translate("banqueDuSang", "Date de don", Q_NULLPTR));
        label_19->setText(QApplication::translate("banqueDuSang", "Volume", Q_NULLPTR));
        label_20->setText(QApplication::translate("banqueDuSang", "mL", Q_NULLPTR));
        tabPharmacie->setTabText(tabPharmacie->indexOf(ajouterPoche), QApplication::translate("banqueDuSang", "Ajouter poche de sang", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("banqueDuSang", "Reference", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("banqueDuSang", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("banqueDuSang", "ID de donneur", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("banqueDuSang", "Date de don", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("banqueDuSang", "Date D'expiration", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("banqueDuSang", "Volume (mL)", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("banqueDuSang", "Reference", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("banqueDuSang", "Rechercher", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("banqueDuSang", "Type", Q_NULLPTR));
        label_14->setText(QApplication::translate("banqueDuSang", "Trier par", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("banqueDuSang", "Acutaliser", Q_NULLPTR));
        BstatPoches->setText(QApplication::translate("banqueDuSang", "Statistiques", Q_NULLPTR));
        tabPharmacie->setTabText(tabPharmacie->indexOf(afficherStock), QApplication::translate("banqueDuSang", "Afficher le stock", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("banqueDuSang", "Supprimer", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("banqueDuSang", "Consulter", Q_NULLPTR));
        label_13->setText(QApplication::translate("banqueDuSang", "Reference", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("banqueDuSang", "Modifier", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("banqueDuSang", "Modifier Poche", Q_NULLPTR));
        label_8->setText(QApplication::translate("banqueDuSang", "Type", Q_NULLPTR));
        label_9->setText(QApplication::translate("banqueDuSang", "Id de donneur", Q_NULLPTR));
        label_10->setText(QApplication::translate("banqueDuSang", "Date de don", Q_NULLPTR));
        label_11->setText(QApplication::translate("banqueDuSang", "Volume", Q_NULLPTR));
        label_12->setText(QApplication::translate("banqueDuSang", "mL", Q_NULLPTR));
        tabPharmacie->setTabText(tabPharmacie->indexOf(modifierMedicament), QApplication::translate("banqueDuSang", "Modifier ou Supprimer une poche", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class banqueDuSang: public Ui_banqueDuSang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANQUEDUSANG_H
