#include <QtDebug>
#include <QApplication>
#include "ConGUIMainWindow.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  app.setWindowIcon(QIcon(":/icons/images/euracelogo.png"));

  ConGUIMainWindow w;
  w.show();
  
  return app.exec();
}
