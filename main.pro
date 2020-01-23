TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS +=  add_contact.h contact_list.h page_1.h page_2.h page_3.h mymainwindow.h save_contact.h cancel_contact.h create_contact.h contact.h db.h view_contact.h edit_contact.h
SOURCES +=  main.cpp add_contact.cpp contact_list.cpp page_1.cpp page_2.cpp page_3.cpp mymainwindow.cpp save_contact.cpp cancel_contact.cpp create_contact.cpp contact.cpp db.cpp view_contact.cpp edit_contact.cpp

LIBS += -L/usr/local/mysql-connector-c++-8.0.19/lib64 -lmysqlcppconn.7 -lssl.1.1
INCLUDEPATH += /usr/local/mysql-connector-c++-8.0.19/include/jdbc /usr/local/opt/boost/include

# -Wl,-rpath,/usr/local/mysql-connector-c++-8.0.19/lib64
