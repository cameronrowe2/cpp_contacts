#ifndef CANCEL_CONTACT_H
#define CANCEL_CONTACT_H

#include <QWidget>

class QPushButton;
class CancelContact : public QWidget
{
    Q_OBJECT
public:
    explicit CancelContact(QWidget *parent = 0);
private slots:
    void slotButtonClicked(bool checked);

private:
    QPushButton *m_button;
    QPushButton *m_button2;
};

#endif // CANCEL_CONTACT_H