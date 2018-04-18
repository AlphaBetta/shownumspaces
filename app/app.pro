TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    shownumspaces.c \
    process_forward.c \
    editor.c \
    create_text.c \
    load.c \
    save.c \
    tracer.c \
    process_forward_extra_option.c \
    append_line.c \
    remove_all.c

HEADERS += \
    common.h \
    text.h \
    _text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
