QT += quick quick3d

target.path = $$[QT_INSTALL_EXAMPLES]/quick3d/hellocube
INSTALLS += target

SOURCES += \
    main.cpp \
    view.cpp

RESOURCES += \
    qml.qrc

OTHER_FILES += \
    doc/src/*.*

HEADERS += \
    view.h
