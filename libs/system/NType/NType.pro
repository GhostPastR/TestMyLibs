TARGET = NType

SOURCES += \
    ndouble.cpp \
    nint32.cpp \
    nuint32.cpp \
    nint64.cpp \
    nuint64.cpp \

HEADERS  += \
    infloatingpoint.h \
    ininteger.h \
    innumber.h \
    intype.h \
    ndouble.h \
    nint32.h \
    ntype.h \
    nuint32.h \
    nint64.h \
    nuint64.h \

include(../../../project.pri)
out = $$setPath(../../../)
out = $$configLib()
