#include <QString>
#include <QList>
#include <QStringList>
#include <QStringListModel>
#include <QListView>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>

#include "create_contact.h"

CreateContact::CreateContact(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *boxLayout = new QVBoxLayout(this);

    QWidget *nameWidget = new QWidget(this);
    QWidget *phoneWidget = new QWidget(this);
    QWidget *addressWidget = new QWidget(this);
    QWidget *stateWidget = new QWidget(this);
    QWidget *postcodeWidget = new QWidget(this);
    QWidget *countryWidget = new QWidget(this);

    boxLayout->addWidget(nameWidget);
    boxLayout->addWidget(phoneWidget);
    boxLayout->addWidget(addressWidget);
    boxLayout->addWidget(stateWidget);
    boxLayout->addWidget(postcodeWidget);
    boxLayout->addWidget(countryWidget);

    QHBoxLayout *nameLayout = new QHBoxLayout(nameWidget);
    nameLayout->addWidget(new QLabel("Name:"));
    lineEditName = new QLineEdit();
    nameLayout->addWidget(lineEditName);

    QHBoxLayout *phoneLayout = new QHBoxLayout(phoneWidget);
    phoneLayout->addWidget(new QLabel("Phone:"));
    lineEditPhone = new QLineEdit();
    phoneLayout->addWidget(lineEditPhone);

    QHBoxLayout *addressLayout = new QHBoxLayout(addressWidget);
    addressLayout->addWidget(new QLabel("Address:"));
    lineEditAddress = new QLineEdit();
    addressLayout->addWidget(lineEditAddress);

    QHBoxLayout *stateLayout = new QHBoxLayout(stateWidget);
    stateLayout->addWidget(new QLabel("State:"));
    lineEditState = new QLineEdit();
    stateLayout->addWidget(lineEditState);

    QHBoxLayout *postcodeLayout = new QHBoxLayout(postcodeWidget);
    postcodeLayout->addWidget(new QLabel("Postcode:"));
    lineEditPostcode = new QLineEdit();
    postcodeLayout->addWidget(lineEditPostcode);

    QHBoxLayout *countryLayout = new QHBoxLayout(countryWidget);
    countryLayout->addWidget(new QLabel("Country:"));
    lineEditCountry = new QLineEdit();
    countryLayout->addWidget(lineEditCountry);
}

QString CreateContact::getName()
{
    return lineEditName->text();
}

QString CreateContact::getPhone()
{
    return lineEditPhone->text();
}

QString CreateContact::getAddress()
{
    return lineEditAddress->text();
}

QString CreateContact::getState()
{
    return lineEditState->text();
}

QString CreateContact::getPostcode()
{
    return lineEditPostcode->text();
}

QString CreateContact::getCountry()
{
    return lineEditCountry->text();
}

void CreateContact::mouseDoubleClickEvent(QMouseEvent *event)
{
    lineEditName->setText("hahaha");
}