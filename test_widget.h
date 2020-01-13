#ifndef TEST_WIDGET_H
#define TEST_WIDGET_H

#include <QWidget>

class QPushButton;
class TestWidget : public QWidget
{
public:
    explicit TestWidget(QWidget *parent = 0);

private:
    QPushButton *m_button;
};

#endif // TEST_WIDGET_H