#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>

#include "page_2.h"
#include "create_contact.h"
#include "save_contact.h"
#include "cancel_contact.h"

Page_2::Page_2(QWidget *parent) : QWidget()
{
    CreateContact *createContact = new CreateContact();
    SaveContact *saveContact = new SaveContact();
    // CancelContact *cancelContact = new CancelContact(this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(createContact);
    layout->addWidget(saveContact);
    setLayout(layout);
}