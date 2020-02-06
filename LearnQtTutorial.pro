TEMPLATE = subdirs

SUBDIRS += \
    cm-lib \
    cm-tests \
    cm-ui

cm-ui.depends = cm-lib
cm-tests.depends = cm-lib

message(cm project dir: $${PWD})
message(qt docs: $$[QT_INSTALL_DOCS])
message( qt libraries: $$[QT_INSTALL_LIBS])
