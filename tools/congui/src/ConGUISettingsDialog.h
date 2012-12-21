#ifndef CONGUISETTINGSDIALOG_H
#define CONGUISETTINGSDIALOG_H

#include <qdebug.h>
#include <QDialog>
#include <ui_ConGUISettingsDialog.h>

class ConGUISettingsDialog : public QDialog, Ui::ConGUISettingsDialog {

Q_OBJECT

public:

  ConGUISettingsDialog();

private:

  QString xmmeExecutablePath;
  QString popguiExecutablePath;
  QString gxparserExecutablePath;
  QString simulatorExecutablePath;
  QString visguiExecutablePath;

private slots:

  void chooseXMMELocation();
  void choosePopGUILocation();
  void chooseGXParserLocation();
  void chooseSimulatorLocation();
  void chooseVisGUILocation();
  void settingsInfoChanged();

};
#endif
