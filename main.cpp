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
}