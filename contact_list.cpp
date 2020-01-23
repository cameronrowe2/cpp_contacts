#include <QString>
#include <QList>
#include <QStringList>
#include <QStringListModel>
#include <QListView>
#include <QVBoxLayout>
#include <QModelIndex>
#include <QAbstractItemView>
#include <QWidgetList>
#include <QWidget>
#include <QApplication>

#include "contact_list.h"
#include "mymainwindow.h"
#include "db.h"
#include "contact.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

ContactList::ContactList(QWidget *parent) : QWidget(parent)
{
    this->createView();
}

void ContactList::displayContact(const QModelIndex &index)
{
    int row = index.row();
    cout << "row: " << row << endl;
    MainWindow *mainWindow = nullptr;
    const QWidgetList topLevelWidgets = QApplication::topLevelWidgets();
    for (QWidget *widget : topLevelWidgets)
    {
        mainWindow = dynamic_cast<MainWindow *>(widget);
        mainWindow->seeContactPage(row);
    }
}

void ContactList::insertRow(QString str)
{
    stringListModel->insertRow(stringListModel->rowCount());
    QModelIndex index = stringListModel->index(stringListModel->rowCount()-1);
    stringListModel->setData(index, str);
}

void ContactList::slotDelete()
{
    delete this;
}

void ContactList::refreshList()
{
  delete layout;
  qDeleteAll(listView->children());
  this->createView();
}

void ContactList::createView()
{
  Db *db = new Db();
  QList<Contact> contacts = db->getContacts();
  db->deleteDb();

  QList<QString> list;
  foreach( Contact contact, contacts )
  {
      list.append(contact.getName());
  }

  // QList<QString> list = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
  QStringList *stringList = new QStringList(list);

  stringListModel = new QStringListModel();
  stringListModel->setStringList(*stringList);

  listView = new QListView();
  listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
  listView->setModel(stringListModel);

  layout = new QVBoxLayout();
  layout->addWidget(listView);
  setLayout(layout);

  connect(this, SIGNAL(closeContactList()), this, SLOT(slotDelete()));
  connect( listView, SIGNAL(doubleClicked(const QModelIndex &) ), this, SLOT( displayContact(const QModelIndex &) ) );
}
