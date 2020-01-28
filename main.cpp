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

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "mymainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    app.setStyleSheet("MainWindow { background-color: white } QPushButton {background-color: grey }");

    // fstream inFile;
    // // open the file stream
    // inFile.open("stylesheet.txt", std::fstream::in);
    // // check if opening a file failed
    // if (inFile.fail()) {
    //     cerr << "Error: " << strerror(errno) << endl;
    //     cerr << "Error opeing a file" << endl;
    //     inFile.close();
    //     exit(1);
    // }
    // string line;
    // while (getline(inFile, line))
    // {
    //     cout << line << endl;
    // }
    // // close the fil
    // inFile.close();

    MainWindow *mainWindow = new MainWindow();
    // mainWindow->setFixedSize(500, 600);
    mainWindow->show();

    return app.exec();
}
