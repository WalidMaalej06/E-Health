#include "connection.h"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlError>
Connection::Connection()
{

}

bool Connection::createConnection(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test_db");
    db.setUserName("walid");
    db.setPassword("esprit19");

    if(db.open())
        test=true;

    return test;
}
