TARGET = NUnit

SOURCES += \
    nangle.cpp \
    ndistance.cpp \
    nspeed.cpp \
    ntime.cpp

HEADERS  += \
    nangle.h \
    ndistance.h \
    nldistance.h \
    nlimit.h \
    nlspeed.h \
    nmass.h \
    nspeed.h \
    ntime.h \
    nunit.h

include(../../../project.pri)
out = $$setPath(../../../)
out = $$configLib()
out = $$addLibsSystem(NType)
