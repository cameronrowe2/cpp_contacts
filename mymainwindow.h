#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QStackedWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "page_1.h"
#include "page_3.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    void addContactPage();
    void seeContactPage(int row);
    void seeContactListPage();
    void refreshList();

private:
    QStackedWidget *stack;
    QListWidget *list;
    QVBoxLayout *vertical;
    QWidget *widget;
    Page_1 *page_1;
    Page_3 *page_3;
    int editingRow;
};

#endif
