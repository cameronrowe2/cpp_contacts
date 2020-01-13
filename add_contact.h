#ifndef ADD_CONTACT_H
#define ADD_CONTACT_H

#include <QWidget>

class QPushButton;
class AddContact : public QWidget
{
public:
    explicit AddContact(QWidget *parent = 0);

private:
    QPushButton *m_button;
};

#endif // ADD_CONTACT_H