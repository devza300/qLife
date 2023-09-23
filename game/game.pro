TARGET = qLife
TEMPLATE = app

QT += core gui widgets
CONFIG += c++20

SOURCES += \
    MainWindow.cpp \
    main.cpp

HEADERS += \
    MainWindow.h

FORMS += \
    MainWindow.ui

RESOURCES += \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core/release/ -llifeCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core/debug/ -llifeCore
else:unix: LIBS += -L$$OUT_PWD/../core/ -llifeCore

INCLUDEPATH += $$PWD/../core
DEPENDPATH += $$PWD/../core

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/release/liblifeCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/debug/liblifeCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/release/lifeCore.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../core/debug/lifeCore.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../core/liblifeCore.a
