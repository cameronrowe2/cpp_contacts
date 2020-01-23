#ifndef VIEW_CONTACT_H
#define VIEW_CONTACT_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QMouseEvent>
#include <QVBoxLayout>

#include "contact.h"

class QPushButton;
class ViewContact : public QWidget
{
    Q_OBJECT
public:
    explicit ViewContact(QWidget *parent = 0);
    void createView(QString name = "", QString phone = "", QString address = "", QString state = "", QString postcode = "", QString country = "");
    void refreshContact(Contact *contact = 0);
    QString getId();
    QString getName();
    QString getPhone();
    QString getAddress();
    QString getState();
    QString getPostcode();
    QString getCountry();

private:
    QLineEdit *lineEditName;
    QLineEdit *lineEditPhone;
    QLineEdit *lineEditAddress;
    QLineEdit *lineEditState;
    QLineEdit *lineEditPostcode;
    QLineEdit *lineEditCountry;
    QVBoxLayout *boxLayout;
    QWidget *nameWidget;
    QWidget *phoneWidget;
    QWidget *addressWidget;
    QWidget *stateWidget;
    QWidget *postcodeWidget;
    QWidget *countryWidget;
    QString contactId;
};

#endif // VIEW_CONTACT_H
