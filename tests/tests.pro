include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD\\\"

HEADERS += \
    mytest1.h

SOURCES +=     main.cpp \
    ../app/create_text.c \
    ../app/shownumspaces.c \
    ../app/process_forward.c \
    ../app/load.c \
    ../app/remove_all.c \
    ../app/append_line.c



INCLUDEPATH += ../app
