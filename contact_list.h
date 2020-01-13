#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include <QWidget>

class QPushButton;
class ContactList : public QWidget
{
public:
    explicit ContactList(QWidget *parent = 0);

private:
    QPushButton *m_button;
};

#endif // CONTACT_LIST_H