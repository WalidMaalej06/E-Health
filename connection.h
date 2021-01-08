#ifndef CONNECTION_H
#define CONNECTION_H

//includes
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
//define class connection
class connection
{
    QSqlDatabase db;
public:
    connection();
    bool createconnection();
    void closeconnection();
};

#endif // CONNECTION_H
