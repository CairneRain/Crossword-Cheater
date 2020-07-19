//logic header file of page 3

#include"RBTree.h"
#include<QPlainTextEdit>

using namespace std;

//read file and construct dictionary
class Reader {
public:
	static void  fileRead(fstream& f, vector<vector<Word>>& allWords);
	static void inputRead(QPlainTextEdit* plainTextEdit,string in, vector<vector<Word>>& allWords);
};

//convert string to int
int stringToInt(string in);

//read data from .csv file
void readData(fstream& f, vector<string>& words, vector<int>& frequence);