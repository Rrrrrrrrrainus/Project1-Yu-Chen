TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    NewString.cpp \
    checker.cpp \
    main.cpp

HEADERS += \
    catch.hpp \
    NewString.h \
    checker.h \
    test.hpp
