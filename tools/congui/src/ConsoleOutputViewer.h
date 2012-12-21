#ifndef CONSOLEOUTPUTVIEWER_H
#define CONSOLEOUTPUTVIEWER_H

#include <qdebug.h>
#include <QDialog>
#include <QProcess>
#include <ui_ConsoleOutputViewer.h>

class ConsoleOutputViewer : public QDialog, Ui::ConsoleOutputViewer {

Q_OBJECT

public:
  ConsoleOutputViewer(QProcess *process);

private:
  QProcess *process;
  int status;

public slots:
  void startedProcess();
  void stdOutReceived();
  void stdErrReceived();
  void finishedProcess(int, QProcess::ExitStatus);
  void closedOK();
};
#endif
