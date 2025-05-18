#include "mainWin.h"
#include <iostream>
using namespace std;

mainWin::mainWin(int x,int y,int width, int height)
				:CWindow(x,y,width,height)
{
	this->title = new Label(34,10,"��������ԤԼϵͳ");
	this->nametitle = new Label(35,8,"OMO2407���");
//	this->nametitle = new Label(35,8,"");
	this->loginBtn = new Button(33,14,15,3,"   �� ¼");
	this->signupBtn = new Button(33,20,15,3,"   ע ��");
	this->exitBtn = new Button(33,26,15,3,"   �� ��");
 
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
	case 2:		//��¼
		return 1;
	case 3:		//ע��
		return 5;
	case 4:		//�˳�
		this->exitWin->showWin();
		this->exitWin->winRun();
		return this->exitWin->doAction();
	default:
		return 0;
	}
}