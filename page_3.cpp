#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>

#include "page_3.h"
#include "view_contact.h"
#include "edit_contact.h"

Page_3::Page_3(QWidget *parent) : QWidget()
{
  viewContact = new ViewContact();
  EditContact *editContact = new EditContact();

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(viewContact);
  layout->addWidget(editContact);
  setLayout(layout);
}

void Page_3::setContact(Contact *contact)
{
  viewContact->refreshContact(contact);
}
