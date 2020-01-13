#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include <QWidget>

class QPushButton;
class ContactList : public QWidget
{
    Q_OBJECT
public:
    explicit ContactList(QWidget *parent = 0);
signals:
    void closeContactList();
public slots:
    void slotDelete();

private:
    QPushButton *m_button;
};

#endif // CONTACT_LIST_H