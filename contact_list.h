#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include <QWidget>
#include <QStringListModel>
#include <QVBoxLayout>
#include <QListView>

class QPushButton;
class ContactList : public QWidget
{
    Q_OBJECT
public:
    explicit ContactList(QWidget *parent = 0);
    void insertRow(QString str);
    void refreshList();
    void createView();
signals:
    void closeContactList();
public slots:
    void slotDelete();
    void displayContact(const QModelIndex &index);

private:
    QPushButton *m_button;
    QStringListModel *stringListModel;
    QVBoxLayout *layout;
    QListView *listView;
};

#endif // CONTACT_LIST_H
