//implement textDealer which have one static method
//normalize : remove all none-alphabet character 
//			  and transform all uppercase character to lowercase character


#include "PartB.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void textDealer::normalize(fstream& fd) {

	char character;

	//create a txt file to store normalized data
	fstream normalizedFile("normalize.txt", ios::out);
	if (!normalizedFile) {
		cout << "normalizedFile open error" << endl;
	}

	//normalization
	while (!fd.eof())
	{

		character = fd.get();

		//change uppercase character and write to new file
		if (character >= 'A' && character <= 'Z')
		{
			character = character - 'A' + 'a';
			normalizedFile << character;
		}

		//write space and lowercase character to new file
		else if ((character >= 'a' && character <= 'z') || character == ' ') {
			normalizedFile << character;
		}

		//change enter character to space and write
		else if (character == '\n')
			normalizedFile << ' ';
	}

	fd.close();
	normalizedFile.close();
	this->newFile.open("normalize.txt", ios::in);
}


fstream& textDealer::getNewFile() {
	
	if (newFile)
		return newFile;
	
	else
	{
		//prompt if new file cannot be open
		cout << "get newFile error";
		return newFile;
	}
}
