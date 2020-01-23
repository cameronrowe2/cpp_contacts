#ifndef EDIT_CONTACT_H
#define EDIT_CONTACT_H

#include <QWidget>

class QPushButton;
class EditContact : public QWidget
{
    Q_OBJECT
public:
    explicit EditContact(QWidget *parent = 0);
private slots:
    void slotButtonClicked2(bool checked);

private:
    QPushButton *t_button;
    QPushButton *t_button2;
};

#endif // EDIT_CONTACT_H
