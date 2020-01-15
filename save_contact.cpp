#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>

#include "save_contact.h"
#include "create_contact.h"

SaveContact::SaveContact(QWidget *parent) : QWidget(parent)
{
    t_button = new QPushButton("Save Contact");
    t_button2 = new QPushButton("Cancel Contact");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(t_button);
    layout->addWidget(t_button2);
    setLayout(layout);

    connect(t_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked2(bool)));
}

void SaveContact::slotButtonClicked2(bool checked)
{
    t_button2->setText(this->parentWidget()->findChild<CreateContact *>()->getName());
}