#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>

#include "page_1.h"
#include "add_contact.h"
#include "contact_list.h"

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

using namespace std;

Page_1::Page_1(QWidget *parent) : QWidget()
{
    contactList = new ContactList();
    AddContact *addContact = new AddContact();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(contactList);
    layout->addWidget(addContact);
    setLayout(layout);
}

void Page_1::refreshList()
{
  contactList->refreshList();
}
