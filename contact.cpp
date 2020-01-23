#include <QString>

#include "contact.h"

Contact::Contact(QString id, QString name, QString phone, QString address, QString state, QString postcode, QString country)
{
    this->id = id;
    this->name = name;
    this->phone = phone;
    this->address = address;
    this->state = state;
    this->postcode = postcode;
    this->country = country;
}

QString Contact::getId()
{
    return this->id;
}


QString Contact::getName()
{
    return this->name;
}

QString Contact::getPhone()
{
    return this->phone;
}

QString Contact::getAddress()
{
    return this->address;
}

QString Contact::getState()
{
    return this->state;
}

QString Contact::getPostcode()
{
    return this->postcode;
}

QString Contact::getCountry()
{
    return this->country;
}
