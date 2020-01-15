#ifndef CREATE_CONTACT_H
#define CREATE_CONTACT_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QMouseEvent>

class QPushButton;
class CreateContact : public QWidget
{
    Q_OBJECT
public:
    explicit CreateContact(QWidget *parent = 0);
    QString getName();
    QString getPhone();
    QString getAddress();
    QString getState();
    QString getPostcode();
    QString getCountry();
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    QLineEdit *lineEditName;
    QLineEdit *lineEditPhone;
    QLineEdit *lineEditAddress;
    QLineEdit *lineEditState;
    QLineEdit *lineEditPostcode;
    QLineEdit *lineEditCountry;
};

#endif // CREATE_CONTACT_H