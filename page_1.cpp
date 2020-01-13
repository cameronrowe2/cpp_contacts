#include <QPushButton>
#include <QApplication>

#include "page_1.h"
#include "add_contact.h"
#include "contact_list.h"

Page_1::Page_1(QWidget *parent) : QWidget()
{
    ContactList *contactList = new ContactList(this);
    AddContact *addContact = new AddContact(this);
}