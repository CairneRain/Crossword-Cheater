//implement preprocessor which have one static method
//preprocess normalize the original text file
//and call fill_completions method


#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"PartB.h"
using namespace std;

void preprocessor::preprocess(vector<Word>& c_dict,fstream& fd) {

	//normalize data
	textDealer td;
	td.normalize(fd);//fd is closed in normalize()

	//construct dictionary using normalized txt file
	completioner::fill_completions(c_dict, td.getNewFile());

	fd.close();
}
