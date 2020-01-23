#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>

#include "save_contact.h"
#include "create_contact.h"
#include "contact.h"
#include "db.h"
#include "mymainwindow.h"


SaveContact::SaveContact(QWidget *parent) : QWidget(parent)
{
    t_button = new QPushButton("Save Contact");
    // t_button2 = new QPushButton("Cancel Contact");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(t_button);
    // layout->addWidget(t_button2);
    setLayout(layout);

    connect(t_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked2(bool)));
}

void SaveContact::slotButtonClicked2(bool checked)
{
    // t_button2->setText(this->parentWidget()->findChild<CreateContact *>()->getName());

    // Contact *contact = new Contact(
    //     this->parentWidget()->findChild<CreateContact *>()->getName(),
    //     this->parentWidget()->findChild<CreateContact *>()->getPhone(),
    //     this->parentWidget()->findChild<CreateContact *>()->getAddress(),
    //     this->parentWidget()->findChild<CreateContact *>()->getState(),
    //     this->parentWidget()->findChild<CreateContact *>()->getPostcode(),
    //     this->parentWidget()->findChild<CreateContact *>()->getCountry()
    // );

    // save to database
    Db *db = new Db();
    db->addContact(
      this->parentWidget()->findChild<CreateContact *>()->getName(),
      this->parentWidget()->findChild<CreateContact *>()->getPhone(),
      this->parentWidget()->findChild<CreateContact *>()->getAddress(),
      this->parentWidget()->findChild<CreateContact *>()->getState(),
      this->parentWidget()->findChild<CreateContact *>()->getPostcode(),
      this->parentWidget()->findChild<CreateContact *>()->getCountry()
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
