#ifndef CONGUIMAINWINDOW_H
#define CONGUIMAINWINDOW_H

#include <qdebug.h>
#include <QMainWindow>
#include <ui_ConGUIMainWindow.h>

class ConGUIMainWindow : public QMainWindow, Ui::ConGUIMainWindow {

Q_OBJECT

public:
  ConGUIMainWindow();

private slots:
  void showSettings();
  void triggerXMME();
  void triggerPopGUI();
  void triggerGXParser();
  void triggerSimulation();
  void triggerVisGUI();
  void actionChooseFiles();
  void actionCheckUpdates();

private:

  QString modelFile;
  QString popFile;

};
#endif
