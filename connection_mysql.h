#ifndef CONNECTIONMYSQL_H
#define CONNECTIONMYSQL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QFileInfo>

static QSqlDatabase con(){
    QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Program Files/SQLiteStudio/gestion.db");
    return db;
}

#endif // CONNECTIONMYSQL_H
