QT       += core gui serialport core sql
QT += webenginewidgets bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 sdk_no_version_check


INCLUDEPATH += "/Users/corentin/opencv/build/install/include/opencv4" #https://www.youtube.com/watch?v=fcpseh9wK1Q
LIBS += -L"/Users/corentin/opencv/build/install/lib" \
        -lopencv_world

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Checkpoint.cpp \
    Style.cpp \
    connexion_deconnexion.cpp \
    deplacement_robot.cpp \
    identification.cpp \
    main.cpp \
    manette.cpp \
    pince_robot.cpp \
    tacquisitionvideo.cpp \
    widget.cpp

HEADERS += \
    connexion_deconnexion.h \
    deplacement_robot.h \
    identification.h \
    manette.h \
    pince_robot.h \
    tacquisitionvideo.h \
    widget.h

FORMS += \
    identification.ui \
    widget.ui

# Default rules for deployment.


#INCLUDEPATH += "/usr/local/include/msodbcsql17/"
#LIBS += -L"/usr/local/lib/" -l"msodbcsql.17"

INCLUDEPATH += /Library/Frameworks/SDL2.framework/Headers

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Library/Frameworks/release/ -lSDL2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../Library/Frameworks/debug/ -lSDL2
else:mac: LIBS += -F$$PWD/../../../../../Library/Frameworks/ -framework SDL2
else:unix: LIBS += -L$$PWD/../../../../../Library/Frameworks/ -lSDL2

INCLUDEPATH += $$PWD/../../../../../Library/Frameworks
DEPENDPATH += $$PWD/../../../../../Library/Frameworks

#CONFIG -= x86_64
#CONFIG += x86
#QMAKE_LFLAGS += -F/Library/Frameworks
#INCLUDEPATH += -F/Library/Frameworks
#LIBS += -F/Library/Frameworks

#INCLUDEPATH += /Library/Frameworks/SDL2.framework/Headers
#INCLUDEPATH += /Library/Frameworks/opencv2.framework/Headers

#LIBS += -framework Cocoa -framework SDL2

