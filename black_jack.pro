TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        deck.cpp \
        main.cpp \
        model.cpp \
        view.cpp

HEADERS += \
    deck.h \
    general_types.h \
    model.h \
    view.h

DISTFILES += \
    sequence
