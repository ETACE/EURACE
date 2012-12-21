TEMPLATE = app
DEPENDPATH += "." "src"

win32 {
  CONFIG += release
  RC_FILE = congui.rc
}

# Input
FORMS += \
  "ui/ConsoleOutputViewer.ui" \
  "ui/ConGUIMainWindow.ui" \
  "ui/ConGUISettingsDialog.ui"

HEADERS += \
  "src/ConGUIMainWindow.h" \
  "src/ConsoleOutputViewer.h" \
  "src/ConGUISettingsDialog.h" \
  "src/globals.h"

SOURCES += \
  "src/ConGUIMainWindow.cpp" \
  "src/ConsoleOutputViewer.cpp" \
  "src/ConGUISettingsDialog.cpp" \
  "src/main.cpp"

RESOURCES += \
  "congui.qrc"

DESTDIR = "./compilation"
MOC_DIR = "./compilation"
OBJECTS_DIR = "./compilation"
RCC_DIR = "./compilation"
UI_DIR = "./compilation"
UI_HEADERS_DIR = "./compilation"
UI_SOURCES_DIR = "./compilation"
