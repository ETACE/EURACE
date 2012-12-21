#include <qsettings.h>
#include "ConGUIMainWindow.h"
#include "ConGUISettingsDialog.h"
#include <qpalette.h>
#include <qpixmap.h>
#include "globals.h"
#include <qfiledialog.h>
#include <qprocess.h>
#include <qmessagebox.h>
#include <QInputDialog>
#include "ConsoleOutputViewer.h"
#include <qdatetime.h>

ConGUIMainWindow::ConGUIMainWindow(){
  ////////////////////////
  // DEFAULT OPERATIONS //
  ////////////////////////

  setupUi(this);
  setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

  this->setStyleSheet("QFrame#frame {background-image: url(:/bg/images/diagram.png); background-repeat: none;} QMainWindow {background-color: white;} QPushButton {color: red;}");

  connect(actionSettings, SIGNAL(triggered()), this, SLOT(showSettings()));
  connect(actionOpen, SIGNAL(triggered()), this, SLOT(actionChooseFiles()));
  connect(actionCheck_Updates, SIGNAL(triggered()), this, SLOT(actionCheckUpdates()));
  connect(xmmeButton, SIGNAL(clicked()), this, SLOT(triggerXMME()));
  connect(popguiButton, SIGNAL(clicked()), this, SLOT(triggerPopGUI()));
  connect(gxparserButton, SIGNAL(clicked()), this, SLOT(triggerGXParser()));
  connect(simulationButton, SIGNAL(clicked()), this, SLOT(triggerSimulation()));
  connect(visguiButton, SIGNAL(clicked()), this, SLOT(triggerVisGUI()));

  QSettings settings(ORGANIZATION, SOFTWARE_NAME);
  // xmmePath
  // popguiPath
  // gxparserPath
  // simulatorPath
  // visguiPath

  this->modelFile = QString();
  this->popFile = QString();
}

void ConGUIMainWindow::showSettings(){
  qDebug() << "Not implemented yet!";
  ConGUISettingsDialog sd;
  if(sd.exec()){
	qDebug() << "Accepted";
  }
  else{
	qDebug() << "Not accepted";
  }
}

void ConGUIMainWindow::triggerXMME(){
  if(this->modelFile == QString()){
	QMessageBox::critical(0, SOFTWARE_NAME,
						  QString("You should first select a model file from File menu."),
						  QMessageBox::Close);
	return;
  }

  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  QProcess xmme;
  if(!xmme.startDetached(settings.value("xmmeExecutablePath").toString(), QStringList() << this->modelFile)){
	QMessageBox::critical(0, SOFTWARE_NAME,
						  QString("Could not create a new process. Check your settings for the AgentGUI executable."),
						  QMessageBox::Close);
  }
}

void ConGUIMainWindow::triggerPopGUI(){
  if(this->modelFile == QString() && this->popFile == QString()){
	QMessageBox::critical(0, SOFTWARE_NAME,
						  QString("You should first select a model or population file from File menu."),
						  QMessageBox::Close);
	return;
  }

  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  QProcess popgui;
  QString inFile;
  if(this->popFile == QString()){
    inFile = this->modelFile;
  }
  else{
    inFile = this->popFile;
  }
  // Change directory DIR
  QFileInfo info(settings.value("popguiExecutablePath").toString());
  popgui.setWorkingDirectory(info.absoluteDir().path());  
  if(!popgui.startDetached(settings.value("popguiExecutablePath").toString(), QStringList() << inFile)){
	QMessageBox::critical(0, SOFTWARE_NAME,
						  QString("Could not create a new process. Check your settings for the PopGUI executable."),
						  QMessageBox::Close);
  }
}

void ConGUIMainWindow::triggerGXParser(){
  if(this->modelFile == QString()){
	QMessageBox::critical(0, SOFTWARE_NAME,
						  QString("You should first select a model file from File menu."),
						  QMessageBox::Close);
	return;
  }

  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  QProcess gxparser;
  if(!gxparser.startDetached(settings.value("gxparserExecutablePath").toString(), QStringList() << this->modelFile)){
	QMessageBox::critical(0, SOFTWARE_NAME,
						  QString("Could not create a new process. Check your settings for the GXParser executable."),
						  QMessageBox::Close);
  }
}

void ConGUIMainWindow::triggerSimulation(){
  if(this->modelFile == QString()){
	QMessageBox::critical(0, SOFTWARE_NAME,
						  QString("You should first select a model file from File menu."),
						  QMessageBox::Close);
	return;
  }

  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  QProcess expgui;
  // Set popFile, simulation executable and output folder path
  QString tmpPopFile = this->popFile;
  QFileInfo info(this->modelFile);
#ifdef Q_WS_WIN
  qDebug() << "Detected Win platform";
  QString tmpSimulationExecutable = info.absoluteDir().path() + "/main.exe";
#else
  qDebug() << "Detected NonWin platform";
  QString tmpSimulationExecutable = info.absoluteDir().path() + "/main";
#endif
  QDir tmpOutDir(info.absoluteDir().path());
  QString subFName = QDateTime::currentDateTime().toString("exp_yyyy-MM-dd_hhmmss");
  tmpOutDir.mkdir(subFName);
  QString tmpOutputFolder = info.absoluteDir().path() + "/" + subFName;
  if(!expgui.startDetached(settings.value("simulatorExecutablePath").toString(),
						   QStringList() << tmpPopFile << tmpSimulationExecutable << tmpOutputFolder)){
	QMessageBox::critical(0, SOFTWARE_NAME,
						  QString("Could not create a new process. Check your settings for the ExpGUI executable."),
						  QMessageBox::Close);
  }
}

void ConGUIMainWindow::triggerVisGUI(){
  if(this->modelFile == QString()){
	QMessageBox::critical(0, SOFTWARE_NAME,
						  QString("You should first select a model file from File menu."),
						  QMessageBox::Close);
	return;
  }

  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  QFileInfo info(this->modelFile);

  QProcess visgui;
  if(!visgui.startDetached(settings.value("visguiExecutablePath").toString(), QStringList() << info.absoluteDir().path() + "/its/")){
	QMessageBox::critical(0, SOFTWARE_NAME,
						  QString("Could not create a new process. Check your settings for the VisGUI executable."),
						  QMessageBox::Close);
  }
}

void ConGUIMainWindow::actionChooseFiles(){
  QSettings settings(ORGANIZATION, SOFTWARE_NAME);
  this->modelFile = QFileDialog::getOpenFileName(this,
										   "Select a model file",
						 settings.value("lastChoosesModelDir").toString());
  this->popFile = QFileDialog::getOpenFileName(this,
										   "Select an initial Population file",
					       settings.value("lastChoosesPopDir").toString());

  QFileInfo infoModel(this->modelFile);
  settings.setValue("lastChoosesModelDir", infoModel.absoluteDir().path());
  QFileInfo infoPop(this->popFile);
  settings.setValue("lastChoosesPopDir", infoPop.absoluteDir().path());
}

void ConGUIMainWindow::actionCheckUpdates(){
  QMessageBox::critical(0, SOFTWARE_NAME,
						"Checking updates (NOT IMPLEMENTED YET).",
						QMessageBox::Close);
}
