#include <QPushButton>

#include "add_contact.h"

AddContact::AddContact(QWidget *parent) : QWidget(parent)
{
    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(0, 320, 300, 50);
}
