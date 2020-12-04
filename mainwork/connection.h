#ifndef COONECTION_H
#define COONECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connection
{
    QSqlDatabase db;
public:
    connection();
    bool createconnection();
    void closeconnection();
};

#endif // COONECTION_H
