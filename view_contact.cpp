#include <QString>
#include <QList>
#include <QStringList>
#include <QStringListModel>
#include <QListView>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>

#include "view_contact.h"

#include "contact.h"

ViewContact::ViewContact(QWidget *parent) : QWidget(parent)
{
    this->createView();
}

void ViewContact::createView(QString name, QString phone, QString address, QString state, QString postcode, QString country)
{
  boxLayout = new QVBoxLayout();

  nameWidget = new QWidget();
  phoneWidget = new QWidget();
  addressWidget = new QWidget();
  stateWidget = new QWidget();
  postcodeWidget = new QWidget();
  countryWidget = new QWidget();

  boxLayout->addWidget(nameWidget);
  boxLayout->addWidget(phoneWidget);
  boxLayout->addWidget(addressWidget);
  boxLayout->addWidget(stateWidget);
  boxLayout->addWidget(postcodeWidget);
  boxLayout->addWidget(countryWidget);

  QHBoxLayout *nameLayout = new QHBoxLayout(nameWidget);
  nameLayout->addWidget(new QLabel("Name:"));
  lineEditName = new QLineEdit();
  lineEditName->setText(name);
  nameLayout->addWidget(lineEditName);

  QHBoxLayout *phoneLayout = new QHBoxLayout(phoneWidget);
  phoneLayout->addWidget(new QLabel("Phone:"));
  lineEditPhone = new QLineEdit();
  lineEditPhone->setText(phone);
  phoneLayout->addWidget(lineEditPhone);

  QHBoxLayout *addressLayout = new QHBoxLayout(addressWidget);
  addressLayout->addWidget(new QLabel("Address:"));
  lineEditAddress = new QLineEdit();
  lineEditAddress->setText(address);
  addressLayout->addWidget(lineEditAddress);

  QHBoxLayout *stateLayout = new QHBoxLayout(stateWidget);
  stateLayout->addWidget(new QLabel("State:"));
  lineEditState = new QLineEdit();
  lineEditState->setText(state);
  stateLayout->addWidget(lineEditState);

  QHBoxLayout *postcodeLayout = new QHBoxLayout(postcodeWidget);
  postcodeLayout->addWidget(new QLabel("Postcode:"));
  lineEditPostcode = new QLineEdit();
  lineEditPostcode->setText(postcode);
  postcodeLayout->addWidget(lineEditPostcode);

  QHBoxLayout *countryLayout = new QHBoxLayout(countryWidget);
  countryLayout->addWidget(new QLabel("Country:"));
  lineEditCountry = new QLineEdit();
  lineEditCountry->setText(country);
  countryLayout->addWidget(lineEditCountry);

  setLayout(boxLayout);
}

void ViewContact::refreshContact(Contact *contact)
{
  delete boxLayout;
  qDeleteAll(nameWidget->children());
  qDeleteAll(phoneWidget->children());
  qDeleteAll(addressWidget->children());
  qDeleteAll(stateWidget->children());
  qDeleteAll(postcodeWidget->children());
  qDeleteAll(countryWidget->children());

  this->contactId = contact->getId();

  this->createView(
    contact->getName(),
    contact->getPhone(),
    contact->getAddress(),
    contact->getState(),
    contact->getPostcode(),
    contact->getCountry()
  );
}

QString ViewContact::getId()
{
    return this->contactId;
}

QString ViewContact::getName()
{
    return lineEditName->text();
}

QString ViewContact::getPhone()
{
    return lineEditPhone->text();
}

QString ViewContact::getAddress()
{
    return lineEditAddress->text();
}

QString ViewContact::getState()
{
    return lineEditState->text();
}

QString ViewContact::getPostcode()
{
    return lineEditPostcode->text();
}

QString ViewContact::getCountry()
{
    return lineEditCountry->text();
}
