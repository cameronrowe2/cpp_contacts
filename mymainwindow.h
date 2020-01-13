#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QStackedWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QStackedWidget *stack;
    QListWidget *list;
    QVBoxLayout *vertical;
    QWidget *widget;
};

#endif