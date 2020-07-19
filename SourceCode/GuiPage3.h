//graphic user interface defination of third page

#include <QWidget>
#include "ui_GuiPage3.h"
#include"proj2.h"

class GuiPage3 : public QWidget
{
	Q_OBJECT

public:
	GuiPage3(QWidget *parent = Q_NULLPTR);
	~GuiPage3();

private:
	Ui::GuiPage3 ui;
	std::string dicPath;
	vector<vector<Word>> allWords = { vector<vector<Word>>(15, vector<Word>(0)) };

public slots:
	void submit();
	void dicChoose();
};


