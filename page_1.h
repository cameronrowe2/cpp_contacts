#ifndef PAGE_1_H
#define PAGE_1_H

#include <QWidget>

#include "contact_list.h"

class QPushButton;
class Page_1 : public QWidget
{
public:
    explicit Page_1(QWidget *parent = 0);
    void refreshList();
private:
    ContactList *contactList;
};

#endif // PAGE_1_H
