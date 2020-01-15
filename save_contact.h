#ifndef SAVE_CONTACT_H
#define SAVE_CONTACT_H

#include <QWidget>

class QPushButton;
class SaveContact : public QWidget
{
    Q_OBJECT
public:
    explicit SaveContact(QWidget *parent = 0);
private slots:
    void slotButtonClicked2(bool checked);

private:
    QPushButton *t_button;
    QPushButton *t_button2;
};

#endif // SAVE_CONTACT_H