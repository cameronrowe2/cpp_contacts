#include <QPushButton>
#include <QApplication>

#include "page_2.h"
#include "add_contact.h"
#include "contact_list.h"

Page_2::Page_2(QWidget *parent) : QWidget()
{
    ContactList *contactList = new ContactList(this);
    AddContact *addContact = new AddContact(this);
}