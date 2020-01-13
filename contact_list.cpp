#include <QString>
#include <QList>
#include <QStringList>
#include <QStringListModel>
#include <QListView>

#include "contact_list.h"

ContactList::ContactList(QWidget *parent) : QWidget(parent)
{
    QList<QString> list = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
    QStringList *stringList = new QStringList(list);

    QStringListModel *stringListModel = new QStringListModel();
    stringListModel->setStringList(*stringList);

    QListView *listView = new QListView(parent);
    listView->setModel(stringListModel);
    listView->setGeometry(0, 20, 300, 300);
}
