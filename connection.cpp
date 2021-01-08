//include
#include "connection.h"
//fonctions
connection::connection(){}
bool connection::createconnection(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("test-bd");
    db.setUserName("rayen");
    db.setPassword("rayen");
    if (db.open()) test=true;
    return test;
}
void connection::closeconnection(){
    db.close();
}
