TARGET = NMath

SOURCES += \
    mpapproximation.cpp \
    mparc.cpp \
    mpbase.cpp \
    mpcircle.cpp \
    mpcirclegeo.cpp \
    mpfigure.cpp \
    mphalfline.cpp \
    mpline.cpp \
    mplinesection.cpp \
    mppoint.cpp \
    mppointgeo.cpp \
    mppolarcoordinat.cpp \
    mppolygon.cpp \
    mpquadratic.cpp \
    mprectangle.cpp \
    mprectanglegeo.cpp \
    mprelativepoint.cpp \
    mpgrademinsecmsec.cpp \
    mplinegeo.cpp \
    mppolygongeo.cpp \
    mptriangle.cpp

HEADERS  += \
    imphalfline.h \
    mpapproximation.h \
    mparc.h \
    mpbase.h \
    mpcircle.h \
    mpcirclegeo.h \
    mpfigure.h \
    mphalfline.h \
    mpline.h \
    mplinesection.h \
    mppoint.h \
    mppointgeo.h \
    mppolarcoordinat.h \
    mppolygon.h \
    mpquadratic.h \
    mprectangle.h \
    mprectanglegeo.h \
    mprelativepoint.h \
    imparc.h \
    impcircle.h \
    mpgrademinsecmsec.h \
    implinesection.h \
    imppolygon.h \
    mplinegeo.h \
    mppolygongeo.h \
    mptriangle.h

include(../../../project.pri)
out = $$setPath(../../../)
out = $$configLib()
out = $$addLibsSystem(NType NUnit)

