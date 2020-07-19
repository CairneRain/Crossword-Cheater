//graphic user interface page 3 implementation

#include "GuiPage3.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QFileInfo>
#include <QRegExpValidator>

GuiPage3::GuiPage3(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//set validator to constrain the input of user
	QRegExp regx("^[a-zA-Z*]*$");
	QValidator * validator = new QRegExpValidator(regx, ui.lineEdit);
	ui.lineEdit->setValidator(validator);
}

GuiPage3::~GuiPage3()
{
}

//when submit button clicked
void GuiPage3::submit() {

	//judge whether user is choose dictionary or not
	bool flag=false;
	for (int i = 0; i < 15; i++) {
		if (allWords[i].size() != 0) {
			break;
		}
		if (i == 14) {
			flag = true;
		}
	}

	//if not choose dictionary
	if (flag) {
		QMessageBox msg;
		msg.setText(QString::fromStdString("Please choose a dictionary first"));
		msg.exec();
	}
	//if choose
	else
	{
		string in=this->ui.lineEdit->text().toStdString();
		if (in != "") {
			//search in the current dictionary
			Reader::inputRead(this->ui.plainTextEdit, in, allWords);
		}
	}
	
}

//when dictionary choose button clicked
void GuiPage3::dicChoose() {

	//file chooser open, return file path
	QString fileName = QFileDialog::getOpenFileName(this, tr("choose a text file"), " ", tr("csvfile(*.csv)"));
	fileName.replace("/", "\\");//reformat the address of file
	this->dicPath = fileName.toStdString();

	//set file name to the plain text area
	QString file_name;
	QFileInfo fileinfo;
	fileinfo = QFileInfo(fileName);
	file_name = fileinfo.fileName();
	ui.plainTextEdit_2->setPlainText(QString::fromStdString("You choose\n\'"+file_name.toStdString()+"\'\nas your dictionary"));

	fstream f(this->dicPath, ios::in);

	//read data and construct the structure
	Reader::fileRead(f, allWords);
}