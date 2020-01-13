#include <QStackedWidget>
#include <QListWidget>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>

#include "mymainwindow.h"
#include "page_1.h"

MainWindow::MainWindow() : QMainWindow()
{
    stack = new QStackedWidget();
    list = new QListWidget();

    Page_1 *page_1 = new Page_1();

    stack->addWidget(page_1);
    stack->addWidget(new QLineEdit("Second ListWidget Item"));
    stack->addWidget(new QLineEdit("Last Widget Item"));

    widget = new QWidget();

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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Down:
        connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
        break;
    case Qt::Key_Up:
        connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
        break;
    case Qt::Key_Left:
        stack->show(); // <---- Added
        break;
    case Qt::Key_Enter: // <---- Added
        stack->hide();  // <---- Added
        break;          // <---- Added
    }
}