//graphic user interface defination of first page

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include "GuiPage2.h"

class GuiPage1 : public QMainWindow
{
	Q_OBJECT

public:
	GuiPage1(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApplication1Class ui;
	GuiPage2 w;

public slots:
	void Btn_Click();
	void Skip_Click();
};
