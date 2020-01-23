#include <QString>
#include <QList>
// #include "mysql_connection.h"

#include "db.h"

#include "contact.h"

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

using namespace std;

#include <cppconn/driver.h>
#include <cppconn/exception.h>
// #include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

Db::Db()
{
    str = "started";

    try
    {
        sql::Driver *driver;
        // sql::Connection *con;

        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root");

        // delete con;
        str = "suceeded";
    }
    catch (sql::SQLException &e)
    {
        str = "failed";
    }
}

void Db::deleteDb()
{
  delete con;
}

void Db::printContacts()
{
  sql::Statement *stmt;
  sql::ResultSet  *res;

  stmt = con->createStatement();

  stmt->execute("USE cppcontacts");
  res = stmt->executeQuery("SELECT * FROM Contact");
  cout << "Here we go!" << endl;
  while (res->next()) {
    // You can use either numeric offsets...
    cout << "ID = " << res->getInt(1); // getInt(1) returns the first column
    // ... or column names for accessing results.
    // The latter is recommended.
    cout << ", Name = '" << res->getString("Name") << "'" << endl;
  }

  delete res;
  delete stmt;
}

QList<Contact> Db::getContacts()
{
  QList<Contact> list;

  sql::Statement *stmt;
  sql::ResultSet  *res;

  stmt = con->createStatement();

  stmt->execute("USE cppcontacts");
  res = stmt->executeQuery("SELECT * FROM Contact");
  cout << "Here we go!" << endl;
  while (res->next()) {
    QString *id = new QString(res->getString("ID").asStdString().c_str());
    QString *name = new QString(res->getString("Name").asStdString().c_str());
    QString *number = new QString(res->getString("Number").asStdString().c_str());
    QString *address = new QString(res->getString("Address").asStdString().c_str());
    QString *state = new QString(res->getString("State").asStdString().c_str());
    QString *postcode = new QString(res->getString("Postcode").asStdString().c_str());
    QString *country = new QString(res->getString("Country").asStdString().c_str());
    Contact *contact = new Contact(
      *id,
      *name,
      *number,
      *address,
      *state,
      *postcode,
      *country
    );
    list.append(*contact);
    // cout << "ID = " << res->getInt(1); // getInt(1) returns the first column
  }

  delete res;
  delete stmt;

  return list;
}

void Db::addContact(QString name, QString number, QString address, QString state, QString postcode, QString country)
{
  sql::PreparedStatement *prep_stmt;
  sql::Statement *stmt;

  stmt = con->createStatement();
  stmt->execute("USE cppcontacts");

  prep_stmt = con->prepareStatement("INSERT INTO Contact(Name, Number, Address, State, Postcode, Country) VALUES (?, ?, ?, ?, ?, ?)");

  prep_stmt->setString(1, name.toStdString());
  prep_stmt->setString(2, number.toStdString());
  prep_stmt->setString(3, address.toStdString());
  prep_stmt->setString(4, state.toStdString());
  prep_stmt->setString(5, postcode.toStdString());
  prep_stmt->setString(6, country.toStdString());
  prep_stmt->execute();

  delete stmt;
  delete prep_stmt;
}

void Db::editContact(QString id, QString name, QString number, QString address, QString state, QString postcode, QString country)
{
  sql::PreparedStatement *prep_stmt;
  sql::Statement *stmt;

  stmt = con->createStatement();
  stmt->execute("USE cppcontacts");

  prep_stmt = con->prepareStatement("UPDATE Contact SET Name = ?, Number = ?, Address = ?, State = ?, Postcode = ?, Country = ? WHERE ID = ?");

  prep_stmt->setString(1, name.toStdString());
  prep_stmt->setString(2, number.toStdString());
  prep_stmt->setString(3, address.toStdString());
  prep_stmt->setString(4, state.toStdString());
  prep_stmt->setString(5, postcode.toStdString());
  prep_stmt->setString(6, country.toStdString());
  prep_stmt->setString(7, id.toStdString());
  prep_stmt->execute();

  delete stmt;
  delete prep_stmt;
}
