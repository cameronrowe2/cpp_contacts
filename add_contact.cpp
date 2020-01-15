#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>
#include <QWidgetList>
#include <QWidget>

#include "add_contact.h"
#include "contact_list.h"
#include "test_widget.h"
#include "page_1.h"
#include "mymainwindow.h"

AddContact::AddContact(QWidget *parent) : QWidget(parent)
{
    m_button = new QPushButton("Add Contact", this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_button);
    setLayout(layout);

    connect(m_button, SIGNAL(clicked()), this, SLOT(onSwitchPageClicked()));
}

void AddContact::onSwitchPageClicked()
{
    MainWindow *mainWindow = nullptr;
    const QWidgetList topLevelWidgets = QApplication::topLevelWidgets();
    for (QWidget *widget : topLevelWidgets)
    {
        mainWindow = dynamic_cast<MainWindow *>(widget);
        mainWindow->addContactPage();
    }
}