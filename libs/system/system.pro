TEMPLATE = subdirs

SUBDIRS += \
    NType \
    NUnit \
    NMath \

NUnit.depends = NType
NMath.depends = NUnit
