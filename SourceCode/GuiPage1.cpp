//graphic user interface page 1 implementation

#include "GuiPage1.h"
#include <QMessageBox>
#include <QProcess>
#include <QDir>
#include <QString>
#include <QFileDialog>
#include <QFileInfo>

//constructor
GuiPage1::GuiPage1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

//when click button clicked
void GuiPage1::Btn_Click()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("choose a text file"), " ", tr("txtfile(*.txt)"));

	QString file_name;
	QFileInfo fileinfo;
	fileinfo = QFileInfo(fileName);
	file_name = fileinfo.fileName();
	ui.plainTextEdit->setPlainText(file_name);

	fileName.replace("/", "\\");//reformat the address of file

//.csv file constructing(logic part)
	vector<Word> c_dict;

	string file= fileName.toStdString();
	string out;

	//open original data
	fstream fd(file.c_str(), ios::in);
	if (!fd) {
		out= file + " open fail";
	}
	else {
		preprocessor::preprocess(c_dict, fd);//open and normalize the original data, construct dictionary

		fstream newfile;
		newfile.open("newsDict.csv", ios::out);

		//create new dictionary file 
		for (int i = 0; i < c_dict.size(); i++) {
			newfile << c_dict[i].word << "," << c_dict[i].frequence << "," << endl;
		}

		newfile.close();
		out = "New file is created";
		remove("normalize.txt");
	}

	
	//message prompt
	QMessageBox msg;
	msg.setText(QString::fromStdString(out));
	msg.exec();
	
}

//Skip button clicked
void GuiPage1::Skip_Click() {
	this->close();

	this->w.show();
}
