//graphic user interface page 2 implementation

#include "GuiPage2.h"
#include<QFileDialog>
#include<QString>
#include<QMessageBox>

GuiPage2::GuiPage2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

GuiPage2::~GuiPage2()
{
}

//When left choose button clicked
void GuiPage2::Choose() {
	
	//open file chooser
	QString fileName = QFileDialog::getOpenFileName(this, tr("choose a text file"), " ", tr("csvfile(*.csv)"));
	fileName.replace("/", "\\");//reformat the address of file
	this->f1 = fileName.toStdString();

	//show the name of file in the text area
	QString file_name;
	QFileInfo fileinfo;
	fileinfo = QFileInfo(fileName);
	file_name = fileinfo.fileName();
	ui.plainTextEdit->setPlainText(file_name);
}

//when right choose button clicked
void GuiPage2::Choose2() {

	//open file chooser
	QString fileName = QFileDialog::getOpenFileName(this, tr("choose a text file"), " ", tr("csvfile(*.csv)"));
	fileName.replace("/", "\\");//reformat the address of file
	this->f2 = fileName.toStdString();

	//show the name of file in the text area
	QString file_name;
	QFileInfo fileinfo;
	fileinfo = QFileInfo(fileName);
	file_name = fileinfo.fileName();
	ui.plainTextEdit_2->setPlainText(file_name);
}

//merge two chosen .csv file to a new file, its name is the left .csv file + _v2
void GuiPage2::Merge() {

	//if first file is not chosen
	if (this->f1 == "") {
		QMessageBox msg;
		msg.setText(QString::fromStdString("Please choose the first file"));
		msg.exec();
	}

	//if second file is not chosen
	else if (this->f2 == "") {
		QMessageBox msg;
		msg.setText(QString::fromStdString("Please choose the second file"));
		msg.exec();
	}

	else {
		//create two vector to store data
		vector<int> frequence;
		vector<string> words;
		fstream newfile(this->f1, ios::in);
		fstream f2(this->f2, ios::in);

		//read data from two files
		readData(newfile, words, frequence);
		readData(f2, words, frequence);

		//read finish
		f2.close();
		newfile.close();

		//dictionary_v2.csv
		fstream f(this->f2.replace(this->f2.find("."), 4, "_v2.csv"), ios::out);

		//create a Red-Black tree
		RBTree tree;
		for (int i = 0; i < words.size(); i++) {
			tree.put(words[i], frequence[i]);
		}

		//get all keys
		vector<Words> t;
		tree.keys(t);
		for (int i = 0; i < t.size(); i++) {
			f << t[i].word << "," << to_string(t[i].frequence) << ",\n";
		}

		//prompt
		QMessageBox msg;
		msg.setText(QString::fromStdString("The combination is successful!\nThe number of words in the new dictionary is " + to_string(tree.size())));
		msg.exec();
		
		f.close();
		// end step 2
	}
}

void GuiPage2::Next() {
	this->close();

	this->w.show();
}