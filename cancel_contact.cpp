#include <QPushButton>
#include <QApplication>

#include "cancel_contact.h"

CancelContact::CancelContact(QWidget *parent) : QWidget(parent)
{
    m_button = new QPushButton("Cancel Contact", this);
    m_button->setGeometry(150, 320, 150, 50);

    m_button2 = new QPushButton("Cancel Contact", this);
    m_button2->setGeometry(150, 370, 150, 50);

    connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
}

void CancelContact::slotButtonClicked(bool checked)
{
    m_button2->setText("Hehehehehe");
}