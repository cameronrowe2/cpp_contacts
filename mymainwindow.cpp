#include <QStackedWidget>
#include <QListWidget>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>

#include "mymainwindow.h"
#include "page_1.h"
#include "page_2.h"
#include "page_3.h"
#include "db.h"
#include "contact.h"

MainWindow::MainWindow() : QMainWindow()
{
    stack = new QStackedWidget();
    list = new QListWidget();

    widget = new QWidget();

    page_1 = new Page_1(stack);
    Page_2 *page_2 = new Page_2(stack);
    page_3 = new Page_3(stack);


    stack->addWidget(page_1);
    stack->addWidget(page_2);
    stack->addWidget(page_3);
    // stack->addWidget(new QLineEdit("Last Widget Item"));

    QLabel *label = new QLabel("Contact List App");

    list->addItem("Contact List");
    list->addItem("Add Contact");
    list->addItem("See Contact");

    list->setFixedSize(200, 100);

    vertical = new QVBoxLayout();
    vertical->addWidget(label);
    vertical->addWidget(list);
    vertical->addWidget(stack);

    widget->setLayout(vertical);
    setCentralWidget(widget);

    connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));

    Db *db = new Db();
    vertical->addWidget(new QLabel(db->str));
    db->printContacts();
    db->deleteDb();
}

void MainWindow::addContactPage()
{
    stack->setCurrentIndex(1);
}

void MainWindow::seeContactPage(int row)
{
    stack->setCurrentIndex(2);
    list->setCurrentRow(2);

    editingRow = row;

    Contact *chosenContact;
    Db *db = new Db();
    QList<Contact> contacts = db->getContacts();
    db->deleteDb();

    for( int i=0; i < contacts.count(); ++i )
    {
        if(i == row)
        {
          chosenContact = new Contact(
            contacts[i].getId(),
            contacts[i].getName(),
            contacts[i].getPhone(),
            contacts[i].getAddress(),
            contacts[i].getState(),
            contacts[i].getPostcode(),
            contacts[i].getCountry()
          );

        }
    }

    page_3->setContact(chosenContact);
}

void MainWindow::seeContactListPage()
{
    stack->setCurrentIndex(0);
}

void MainWindow::refreshList()
{
  page_1->refreshList();
}
