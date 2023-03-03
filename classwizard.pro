HEADERS       = classwizard.h
SOURCES       = classwizard.cpp \
                main.cpp
RESOURCES     = classwizard.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/dialogs/classwizard
INSTALLS += target

QT += widgets
simulator: warning(This example might not fully work on Simulator platform)

DISTFILES += \
    images/logo1.png \
    images/watermark1.png \
    images/watermark2.png
