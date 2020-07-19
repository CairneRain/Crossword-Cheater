//graphic user interface defination of second page

#include "ui_GuiPage2.h"
#include "GuiPage3.h"
#include<string>
#include <QWidget>

class GuiPage2 : public QWidget
{
	Q_OBJECT

public:
	GuiPage2(QWidget *parent = Q_NULLPTR);
	~GuiPage2();

private:
	Ui::GuiPage2 ui;
	std::string f1="";
	std::string f2="";
	GuiPage3 w;

public slots:
	void Choose();
	void Choose2();
	void Merge();
	void Next();
};
