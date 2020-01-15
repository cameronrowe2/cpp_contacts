#include <QStackedWidget>
#include <QListWidget>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>

#include "mymainwindow.h"
#include "page_1.h"
#include "page_2.h"

MainWindow::MainWindow() : QMainWindow()
{
    stack = new QStackedWidget();
    list = new QListWidget();

    widget = new QWidget();

    Page_1 *page_1 = new Page_1(stack);
    Page_2 *page_2 = new Page_2(stack);

    stack->addWidget(page_1);
    stack->addWidget(page_2);
    stack->addWidget(new QLineEdit("Last Widget Item"));

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
}

void MainWindow::addContactPage()
{
    stack->setCurrentIndex(1);
}