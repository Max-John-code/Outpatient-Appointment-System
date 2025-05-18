#include "mainWin.h"
#include <iostream>
using namespace std;

mainWin::mainWin(int x,int y,int width, int height)
				:CWindow(x,y,width,height)
{
	this->title = new Label(34,10,"ÖÇÄÜÃÅÕïÔ¤Ô¼ÏµÍ³");
	this->nametitle = new Label(35,8,"OMO2407³Âê»");
//	this->nametitle = new Label(35,8,"");
	this->loginBtn = new Button(33,14,15,3,"   µÇ Â¼");
	this->signupBtn = new Button(33,20,15,3,"   ×¢ ²á");
	this->exitBtn = new Button(33,26,15,3,"   ÍË ³ö");
 
	this->addCtrl(title);		//0
	this->addCtrl(nametitle);	//1
	this->addCtrl(loginBtn);	//2
	this->addCtrl(signupBtn);	//3
	this->addCtrl(exitBtn);		//4
	this->exitWin = new popupWin(20,20,40,10);
}

mainWin::~mainWin()
{

}

int mainWin::doAction()
{
	switch(this->ctrl_index){
	case 2:		//µÇÂ¼
		return 1;
	case 3:		//×¢²á
		return 5;
	case 4:		//ÍË³ö
		this->exitWin->showWin();
		this->exitWin->winRun();
		return this->exitWin->doAction();
	default:
		return 0;
	}
}