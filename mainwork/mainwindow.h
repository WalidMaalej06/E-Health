#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonVider_clicked();

    void on_viderCases_clicked();

    void on_pushButtonAjouterEmploye_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_ajouter_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonSuppr_clicked();

    void on_pushButtonPDF_clicked();

    void on_pushButtonRechercher_clicked();

private:
    Ui::MainWindow *ui;
    employe tmpemploye;
    conge tmpconge;
    QRegExp mail_regex;
    QRegExp num_regex;
    QRegExp cin_regex;
    QRegExp telephone_regex;

};

#endif // MAINWINDOW_H
