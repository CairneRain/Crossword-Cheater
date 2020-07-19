//logic header file of first page

#include<fstream>
#include<vector>
#include<string>
using namespace std;

//sort by word
struct Word {
	string word;
	int frequence=0;

	//overload == operator
	bool operator==(const Word b) const
	{
		return this->word == b.word;
	}
	bool operator!=(const Word b) const
	{
		return this->word != b.word;
	}
	bool operator<=(const Word b) const
	{
		return this->word <= b.word;
	}
	bool operator<(const Word b) const
	{
		return this->word < b.word;
	}
	bool operator>=(const Word b) const
	{
		return this->word >= b.word;
	}
	bool operator>(const Word b) const
	{
		return this->word > b.word;
	}
};


//sort by frequence
struct Words {
	string word;
	int frequence;

	//overload == operator
	bool operator==(const Words b) const
	{
		return this->frequence == b.frequence;
	}
	bool operator!=(const Words b) const
	{
		return this->frequence != b.frequence;
	}
	bool operator<=(const Words b) const
	{
		return this->frequence <= b.frequence;
	}
	bool operator<(const Words b) const
	{
		return this->frequence < b.frequence;
	}
	bool operator>=(const Words b) const
	{
		return this->frequence >= b.frequence;
	}
	bool operator>(const Words b) const
	{
		return this->frequence > b.frequence;
	}
};

//deal with txt file
class textDealer
{
public:
	void normalize(fstream& origin);
	fstream& getNewFile();
private:
	fstream newFile;
};

//transform txt file to dictionary in memory
class preprocessor {
public:
	static void preprocess(vector<Word>& c_dict,fstream& fd);
};

//tranform dictionay in memory to .csv file
class completioner {
public:
	static void fill_completions(vector<Word>& c_dict, fstream& fd);
 
};

