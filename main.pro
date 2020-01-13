TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS +=  add_contact.h contact_list.h page_1.h page_2.h page_3.h mymainwindow.h
SOURCES +=  main.cpp add_contact.cpp contact_list.cpp page_1.cpp page_2.cpp page_3.cpp mymainwindow.cpp