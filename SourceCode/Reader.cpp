//implement Reader class which have two method
//fileRead method reads dictionary into memory
//inputRead method reads and analyse user inputs

#include"GuiPage3.h"
#include<QPlainTextEdit>
#include<vector>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<sstream>
#include<regex>

using namespace std;

//load data from file
void Reader::fileRead(fstream& f, vector<vector<Word>>& allWords) {

	for (int i = 0; i < allWords.size(); i++) {
		allWords[i].clear();
	}

	string line;

	//for each line
	while (getline(f, line)) {
		int p1 = line.find(",", 0);//word
		int p2 = line.find(",", p1 + 1);//number

		//initialize current word
		Word current;
		current.word = line.substr(0, p1);
		current.frequence = stringToInt(line.substr(p1 + 1, p2 - p1 - 1));
		
		//according length of current word, push it into corresponding vector
		int n = current.word.length() - 1;
		if (n >= 15) {
			allWords[14].push_back(current);
		}
		else {
			allWords[n].push_back(current);
		}
	}

}

//analyse the input of user
void Reader::inputRead(QPlainTextEdit* plainTextEdit,string in, vector<vector<Word>>& allWords) {
	plainTextEdit->setPlainText(QString::fromStdString(""));

	//initialize
	int length = in.length();
	string exp = "^";

	//create the regular expression
	for (int i = 0; i < length; i++) {
		if (in[i] == '*') {
			exp += "\\w";
		}
		else {
			exp += in[i];
		}
	}
	exp += "$";
	regex regex(exp);

	//match in the same-length vector
	int j = 0;
	for (int i = 0; i < allWords[length - 1].size(); i++) {
		if (regex_match(allWords[length - 1][i].word, regex)) {
			plainTextEdit->appendPlainText(QString::fromStdString(allWords[length - 1][i].word + "   frequency:" + to_string(allWords[length - 1][i].frequence)));
			j++;
		}
		/*if (j == n) {
			break;
		}*/
	}
	if (j == 0)
		plainTextEdit->setPlainText(QString::fromStdString("Dictionary does not contain word like that"));
}
int stringToInt(string in) {
	int out;
	stringstream s;
	s << in;
	s >> out;
	return out;
}

//load data from file to vectors
void readData(fstream& f, vector<string>& words, vector<int>& frequence) {
	string line;
	while (getline(f, line)) {

		int p1 = line.find(",", 0);//word
		int p2 = line.find(",", p1 + 1);//number

		words.push_back(line.substr(0, p1));//get word
		frequence.push_back(stringToInt(line.substr(p1 + 1, p2 - p1 - 1)));//get number

	}
}