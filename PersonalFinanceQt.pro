QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/model/account.cpp \
    src/model/article.cpp \
    src/model/currency.cpp \
    src/model/modelexception.cpp \
    src/model/transaction.cpp \
    src/model/transfer.cpp \
    src/settings/text.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    README.md

HEADERS += \
    src/model/account.h \
    src/model/article.h \
    src/model/currency.h \
    src/model/icommon.h \
    src/model/modelexception.h \
    src/model/transaction.h \
    src/model/transfer.h \
    src/settings/text.h

RESOURCES += \
    fonts.qrc
