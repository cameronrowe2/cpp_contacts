#include <QPushButton>
#include <QApplication>

#include "page_3.h"
#include "add_contact.h"
#include "contact_list.h"

Page_3::Page_3(QWidget *parent) : QWidget()
{
    ContactList *contactList = new ContactList(this);
    AddContact *addContact = new AddContact(this);
}