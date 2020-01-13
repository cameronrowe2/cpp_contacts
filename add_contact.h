#ifndef ADD_CONTACT_H
#define ADD_CONTACT_H

#include <QWidget>

class QPushButton;
class AddContact : public QWidget
{
    Q_OBJECT
public:
    explicit AddContact(QWidget *parent = 0);
private slots:
    void slotButtonClicked(bool checked);

private:
    QPushButton *m_button;
};

#endif // ADD_CONTACT_H