#ifndef DB_H
#define DB_H

#include <cppconn/driver.h>

#include <QString>
#include <QList>

#include "contact.h"

class Db
{
public:
    explicit Db();
    QString str;
    void deleteDb();
    QList<Contact> getContacts();
    void printContacts();
    void addContact(QString name, QString number, QString address, QString state, QString postcode, QString country);
    void editContact(QString id, QString name, QString number, QString address, QString state, QString postcode, QString country);
  private:
    sql::Connection *con;
};

#endif // DB_H
