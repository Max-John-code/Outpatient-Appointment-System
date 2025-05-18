#include "CAdminWin.h"
#include <iostream>
using namespace std;

AdminWin::AdminWin(int x, int y, int width, int height)
						:CWindow(x, y, width, height)
{
	this->admintitle = new Label(35,7,"管理员主界面");
	this->usermanager = new Button(24,15,11,3,"用户管理");
	this->doctormanager = new Button(45,15,11,3,"医生管理");
	this->roommanager = new Button(24,19,11,3,"科室管理");
	this->dataBtn = new Button(45,19,11,3,"数据统计");
	this->backBtn = new Button(24,24,11,3,"  退 出");

	this->addCtrl(this->admintitle);		//0
	this->addCtrl(this->usermanager);		//1
	this->addCtrl(this->doctormanager);		//2
	this->addCtrl(this->roommanager);		//3
	this->addCtrl(this->dataBtn);		//4
	this->addCtrl(this->backBtn);			//5
}

void AdminWin::showWin()
{							
	CWindow::showWin();											//在清屏和paintWindow之后就可以打印以下内容	
											//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
											//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
	CTools::gotoxy(13,10);
	cout <<"欢迎,管理员";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int AdminWin::doAction()
{
	switch(this->ctrl_index){
	case 1:
		return 11;
	case 2:
		return 12;
	case 3:
		return 15;
	case 4:
		cout <<"该功能还未实现";
		system("pause");
		return 3;
		
	case 5:	//退出，回到登陆界面
		return 1;
	}
	return 3;
}