#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    explicit Contact(QString id = "", QString name = "", QString phone = "", QString address = "", QString state = "", QString postcode = "", QString country = "");
    QString getName();
    QString getId();
    QString getPhone();
    QString getAddress();
    QString getState();
    QString getPostcode();
    QString getCountry();

private:
    QString id;
    QString name;
    QString phone;
    QString address;
    QString state;
    QString postcode;
    QString country;
};

#endif // CONTACT_H
