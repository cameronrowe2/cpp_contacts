#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>

#include "page_1.h"
#include "add_contact.h"
#include "contact_list.h"

Page_1::Page_1(QWidget *parent) : QWidget()
{
    ContactList *contactList = new ContactList();
    AddContact *addContact = new AddContact();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(contactList);
    layout->addWidget(addContact);
    setLayout(layout);
}