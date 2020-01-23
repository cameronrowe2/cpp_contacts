#ifndef PAGE_3_H
#define PAGE_3_H

#include <QWidget>

#include "view_contact.h"
#include "contact.h"

class QPushButton;
class Page_3 : public QWidget
{
public:
    explicit Page_3(QWidget *parent = 0);
    void setContact(Contact *contact);
private:
    ViewContact *viewContact;
};

#endif // PAGE_3_H
