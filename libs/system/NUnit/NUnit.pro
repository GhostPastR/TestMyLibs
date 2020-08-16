TARGET = NUnit

SOURCES += \
    mpangle.cpp \
    mpdistance.cpp \
    mpspeed.cpp \
    mptime.cpp

HEADERS  += \
    mpangle.h \
    mpspeed.h \
    mpdistance.h \
    mptime.h \
    mpmass.h \
    mplimit.h \
    mpldistance.h \
    mplspeed.h \
    mpunit.h \

include(../../../project.pri)
out = $$setPath(../../../)
out = $$configLib()
out = $$addLibsSystem(NType)
