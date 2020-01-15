#include <QString>
#include <QList>
#include <QStringList>
#include <QStringListModel>
#include <QListView>
#include <QVBoxLayout>
#include <QModelIndex>
#include <QAbstractItemView>

#include "contact_list.h"

ContactList::ContactList(QWidget *parent) : QWidget(parent)
{
    QList<QString> list = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
    QStringList *stringList = new QStringList(list);

    stringListModel = new QStringListModel();
    stringListModel->setStringList(*stringList);

    QListView *listView = new QListView(parent);
    listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    listView->setModel(stringListModel);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(listView);
    setLayout(layout);

    connect(this, SIGNAL(closeContactList()), this, SLOT(slotDelete()));
    connect( listView, SIGNAL(doubleClicked(const QModelIndex &) ), this, SLOT( displayContact(const QModelIndex &) ) );
}

void ContactList::displayContact(const QModelIndex &index)
{
    this->insertRow("a");
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
