PATH = ./

defineReplace(setPath){
    PATH = $$1
    export(PATH)
    DESTDIR = $${PATH}lib/
    export(DESTDIR)
}

defineReplace(configLib){
    win32 {
        TEMPLATE = lib
    }
    win64 {
        TEMPLATE = lib
    }
    unix {
        TEMPLATE = plugin
    }
    export(TEMPLATE)
    CONFIG += lib
    export(CONFIG)
}

defineReplace(addLibsSystem){
    for( lib, ARGS ){
        LIBS += -L$${PATH}lib/ -l$${lib}
    }
    export(LIBS)
    for( lib, ARGS ){
        INCLUDEPATH += $${PATH}libs/system/$${lib}/
    }
    export(INCLUDEPATH)
}
