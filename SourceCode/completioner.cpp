//implement completioner class, which have two static method
//fill_completions construct the dictionary and calculate the frequence of each word
//find_completions output N possible results as user required.


#include"PartB.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void completioner::fill_completions(vector<Word>& c_dict, fstream& fd) {

	//save every normalized word into c_dict
	while (!fd.eof()) {
		Word tmp;
		tmp.frequence = 1;
		fd >> tmp.word;

		//push words into c_dict
		c_dict.push_back(tmp);
	}
	
	//sort c_dict
	sort(c_dict.begin(), c_dict.end());

	//create another vector to save all words, which is sorted
	vector<Word> all_dict;
	all_dict.assign(c_dict.begin(), c_dict.end());

	//erase duplicate words
	c_dict.erase(unique(c_dict.begin(), c_dict.end()), c_dict.end());

	//create two iterators for two vectors
	vector<Word>::iterator iter_all=all_dict.begin();
	vector<Word>::iterator iter_c = c_dict.begin();

	//count the frequence of each word
	while(iter_all != all_dict.end() && iter_c != c_dict.end())//when two iterator is not out of range
	{	
		/*because they are all sorted in the same way,
		it will be faster to go through the all_dict for one time,
		and record the frequence to each word in c_dict. */

		if ((*iter_all) == (*iter_c)){
			(*iter_c).frequence++;
			iter_all++;
		}

		else {
			iter_c++;
		}
	}
}

