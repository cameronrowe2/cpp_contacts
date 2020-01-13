TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS +=  add_contact.h contact_list.h
SOURCES +=  main.cpp add_contact.cpp contact_list.cpp