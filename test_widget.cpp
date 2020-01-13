#include <QPushButton>

#include "test_widget.h"

TestWidget::TestWidget(QWidget *parent) : QWidget(parent)
{
    m_button = new QPushButton("Test", this);
    m_button->setGeometry(0, 0, 300, 50);
}