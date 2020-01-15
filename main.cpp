#include <QApplication>
#include <QPushButton>
#include <QListView>
#include <QStringListModel>
#include <QStringList>
#include <QList>
#include <QString>
#include <QWidget>
#include <QGridLayout>
#include <QStackedWidget>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>

#include "mymainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow *mainWindow = new MainWindow();
    // mainWindow->setFixedSize(500, 600);
    mainWindow->show();

    return app.exec();

    // QApplication app(argc, argv);

    // QWidget *window = new QWidget;

    // Page_1 *firstPageWidget = new Page_1();
    // Page_2 *secondPageWidget = new Page_2();
    // Page_3 *thirdPageWidget = new Page_3();

    // QStackedWidget *stackedWidget = new QStackedWidget;
    // stackedWidget->addWidget(firstPageWidget);
    // // stackedWidget->addWidget(secondPageWidget);
    // // stackedWidget->addWidget(thirdPageWidget);
    // stackedWidget->addWidget(new QLineEdit("Second ListWidget Item"));
    // stackedWidget->addWidget(new QLineEdit("Last Widget Item"));

    // QListWidget *pageComboBox = new QListWidget(window);
    // pageComboBox->addItem("Page 1");
    // pageComboBox->addItem("Page 2");
    // pageComboBox->addItem("Page 3");
    // pageComboBox->setFixedSize(200, 100);
    // // connect(pageComboBox, SIGNAL(activated(int)),
    // // stackedWidget, SLOT(setCurrentIndex(int)));

    // QLabel *label = new QLabel("Main Window");

    // QVBoxLayout *layout = new QVBoxLayout();
    // layout->addWidget(label);
    // layout->addWidget(pageComboBox);
    // layout->addWidget(stackedWidget);
    // // setCentralWidget(widget);

    // window->setLayout(layout);
    // window->setFixedSize(500, 600);
    // window->show();

    // return app.exec();
}