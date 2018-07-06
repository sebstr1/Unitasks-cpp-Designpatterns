TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    GasTurbine.cpp \
    FuelCell.cpp \
    PowerSourceAdapters.cpp \
    V8Classic.cpp \
    PowerSourceTest.cpp

HEADERS += \
    GasTurbine.h \
    FuelCell.h \
    PowerSource.h \
    PowerSourceAdapters.h \
    V8Classic.h
