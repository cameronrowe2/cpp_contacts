#include <QApplication>
#include <QPushButton>
#include <QListView>
#include <QStringListModel>
#include <QStringList>
#include <QList>
#include <QString>
#include <QWidget>

#include "add_contact.h"
#include "contact_list.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget();

    ContactList *contactList = new ContactList(window);
    AddContact *addContact = new AddContact(window);

    window->setFixedSize(500, 500);
    window->show();

    return app.exec();
}