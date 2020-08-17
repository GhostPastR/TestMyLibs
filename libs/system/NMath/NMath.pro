TARGET = NMath

SOURCES += \
    napproximation.cpp \
    narc.cpp \
    nbase.cpp \
    ncircle.cpp \
    ncirclegeo.cpp \
    nfigure.cpp \
    ngrademinsecmsec.cpp \
    nhalfline.cpp \
    nline.cpp \
    nlinegeo.cpp \
    nlinesection.cpp \
    npoint.cpp \
    npointgeo.cpp \
    npolarcoordinat.cpp \
    npolygon.cpp \
    npolygongeo.cpp \
    nquadratic.cpp \
    nrectangle.cpp \
    nrectanglegeo.cpp \
    nrelativepoint.cpp \
    ntriangle.cpp

HEADERS  += \
    inarc.h \
    incircle.h \
    inhalfline.h \
    inlinesection.h \
    inpolygon.h \
    napproximation.h \
    narc.h \
    nbase.h \
    ncircle.h \
    ncirclegeo.h \
    nfigure.h \
    ngrademinsecmsec.h \
    nhalfline.h \
    nline.h \
    nlinegeo.h \
    nlinesection.h \
    npoint.h \
    npointgeo.h \
    npolarcoordinat.h \
    npolygon.h \
    npolygongeo.h \
    nquadratic.h \
    nrectangle.h \
    nrectanglegeo.h \
    nrelativepoint.h \
    ntriangle.h

include(../../../project.pri)
out = $$setPath(../../../)
out = $$configLib()
out = $$addLibsSystem(NType NUnit)

