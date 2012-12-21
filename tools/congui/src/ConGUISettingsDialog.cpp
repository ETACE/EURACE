#include <qsettings.h>
#include <qfiledialog.h>
#include "ConGUISettingsDialog.h"
#include "globals.h"

ConGUISettingsDialog::ConGUISettingsDialog(){
  setupUi(this);

  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  if(settings.value("xmmeExecutablePath") == QVariant()){
	settings.setValue("xmmeExecutablePath", QString());
  }
  this->xmmeExecutablePath = settings.value("xmmeExecutablePath").toString();
  this->xmmeLocationLineEdit->setText(this->xmmeExecutablePath);
  connect(this->xmmeLocationButton, SIGNAL(clicked()), this, SLOT(chooseXMMELocation()));

  if(settings.value("popguiExecutablePath") == QVariant()){
	settings.setValue("popguiExecutablePath", QString());
  }
  this->popguiExecutablePath = settings.value("popguiExecutablePath").toString();
  this->popguiLocationLineEdit->setText(this->popguiExecutablePath);
  connect(this->popguiLocationButton, SIGNAL(clicked()), this, SLOT(choosePopGUILocation()));

  if(settings.value("gxparserExecutablePath") == QVariant()){
	settings.setValue("gxparserExecutablePath", QString());
  }
  this->gxparserExecutablePath = settings.value("gxparserExecutablePath").toString();
  this->gxparserLocationLineEdit->setText(this->gxparserExecutablePath);
  connect(this->gxparserLocationButton, SIGNAL(clicked()), this, SLOT(chooseGXParserLocation()));

  if(settings.value("simulatorExecutablePath") == QVariant()){
	settings.setValue("simulatorExecutablePath", QString());
  }
  this->simulatorExecutablePath = settings.value("simulatorExecutablePath").toString();
  this->simulatorLocationLineEdit->setText(this->simulatorExecutablePath);
  connect(this->simulatorLocationButton, SIGNAL(clicked()), this, SLOT(chooseSimulatorLocation()));

  if(settings.value("visguiExecutablePath") == QVariant()){
	settings.setValue("visguiExecutablePath", QString());
  }
  this->visguiExecutablePath = settings.value("visguiExecutablePath").toString();
  this->visguiLocationLineEdit->setText(this->visguiExecutablePath);
  connect(this->visguiLocationButton, SIGNAL(clicked()), this, SLOT(chooseVisGUILocation()));

  connect(this, SIGNAL(accepted()), this, SLOT(settingsInfoChanged()));
}

void ConGUISettingsDialog::chooseXMMELocation(){
  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  QString fileName = QFileDialog::getOpenFileName(this,
												  "Select AgentGUI executable",
												  this->xmmeExecutablePath);
  while(!QFile(fileName).exists()){
	fileName = QFileDialog::getOpenFileName(this,
											"Select AgentGUI executable",
											this->xmmeExecutablePath);
  }
  this->xmmeExecutablePath = fileName;
  this->xmmeLocationLineEdit->setText(fileName);  
}

void ConGUISettingsDialog::choosePopGUILocation(){
  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  QString fileName = QFileDialog::getOpenFileName(this,
												  "Select popgui executable",
												  this->popguiExecutablePath);
  while(!QFile(fileName).exists()){
	fileName = QFileDialog::getOpenFileName(this,
											"Select popgui executable",
											this->popguiExecutablePath);
  }
  this->popguiExecutablePath = fileName;
  this->popguiLocationLineEdit->setText(fileName);  
}

void ConGUISettingsDialog::chooseGXParserLocation(){
  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  QString fileName = QFileDialog::getOpenFileName(this,
												  "Select gxparser executable",
												  this->gxparserExecutablePath);
  while(!QFile(fileName).exists()){
	fileName = QFileDialog::getOpenFileName(this,
											"Select gxparser executable",
											this->gxparserExecutablePath);
  }
  this->gxparserExecutablePath = fileName;
  this->gxparserLocationLineEdit->setText(fileName);  
}

void ConGUISettingsDialog::chooseSimulatorLocation(){
  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  QString fileName = QFileDialog::getOpenFileName(this,
												  "Select ExpGUI executable",
												  this->simulatorExecutablePath);
  while(!QFile(fileName).exists()){
	fileName = QFileDialog::getOpenFileName(this,
											"Select ExpGUI executable",
											this->simulatorExecutablePath);
  }
  this->simulatorExecutablePath = fileName;
  this->simulatorLocationLineEdit->setText(fileName);
}

void ConGUISettingsDialog::chooseVisGUILocation(){
  QSettings settings(ORGANIZATION, SOFTWARE_NAME);

  QString fileName = QFileDialog::getOpenFileName(this,
												  "Select visgui executable",
												  this->visguiExecutablePath);
  while(!QFile(fileName).exists()){
	fileName = QFileDialog::getOpenFileName(this,
											"Select visgui executable",
											this->visguiExecutablePath);
  }
  this->visguiExecutablePath = fileName;
  this->visguiLocationLineEdit->setText(fileName);
}

void ConGUISettingsDialog::settingsInfoChanged(){
  QSettings settings(ORGANIZATION, SOFTWARE_NAME);
  settings.setValue("xmmeExecutablePath", this->xmmeExecutablePath);
  settings.setValue("popguiExecutablePath", this->popguiExecutablePath);
  settings.setValue("gxparserExecutablePath", this->gxparserExecutablePath);
  settings.setValue("simulatorExecutablePath", this->simulatorExecutablePath);
  settings.setValue("visguiExecutablePath", this->visguiExecutablePath);
}
