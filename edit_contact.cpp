#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>

#include "edit_contact.h"
#include "view_contact.h"
#include "contact.h"
#include "db.h"
#include "mymainwindow.h"


EditContact::EditContact(QWidget *parent) : QWidget(parent)
{
    t_button = new QPushButton("Edit Contact");
    // t_button2 = new QPushButton("Cancel Contact");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(t_button);
    // layout->addWidget(t_button2);
    setLayout(layout);

    connect(t_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked2(bool)));
}

void EditContact::slotButtonClicked2(bool checked)
{
    // save to database
    Db *db = new Db();
    db->editContact(
      this->parentWidget()->findChild<ViewContact *>()->getId(),
      this->parentWidget()->findChild<ViewContact *>()->getName(),
      this->parentWidget()->findChild<ViewContact *>()->getPhone(),
      this->parentWidget()->findChild<ViewContact *>()->getAddress(),
      this->parentWidget()->findChild<ViewContact *>()->getState(),
      this->parentWidget()->findChild<ViewContact *>()->getPostcode(),
      this->parentWidget()->findChild<ViewContact *>()->getCountry()
    );
    db->deleteDb();

    // navigate to all contacts
    MainWindow *mainWindow = nullptr;
    const QWidgetList topLevelWidgets = QApplication::topLevelWidgets();
    for (QWidget *widget : topLevelWidgets)
    {
        mainWindow = dynamic_cast<MainWindow *>(widget);
        mainWindow->seeContactListPage();
        mainWindow->refreshList();
    }
}
