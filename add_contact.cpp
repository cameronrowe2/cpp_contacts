#include <QPushButton>
#include <QApplication>

#include "add_contact.h"
#include "contact_list.h"
#include "test_widget.h"

AddContact::AddContact(QWidget *parent) : QWidget(parent)
{
    m_button = new QPushButton("Add Contact", this);
    m_button->setGeometry(0, 320, 300, 50);

    // connect(m_button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
}

void AddContact::slotButtonClicked(bool checked)
{
    delete this;
    ContactList *contactList = this->parentWidget()->findChild<ContactList *>();
    emit contactList->closeContactList();
}