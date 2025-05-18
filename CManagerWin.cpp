#include "CManagerWin.h"

CManagerWin::CManagerWin(int x,int y,int width, int height)
			:CWindow(x,y,width,height)
{
	this->title = new Label(35,8,"管理员主界面");
	this->usermanager = new Button(28,15,11,3,"用户管理");
	this->doctormanager = new Button(42,15,11,3,"医生管理");
	this->roommanager = new Button(28,20,11,3,"科室管理");
	this->dataBtn = new Button(42,20,11,3,"数据统计");
	this->backBtn = new Button(28,25,11,3," 退 出");
	
	this->addCtrl(title);
	this->addCtrl(usermanager);
	this->addCtrl(doctormanager);
	this->addCtrl(roommanager);
	this->addCtrl(dataBtn);
	this->addCtrl(backBtn);
}

int CManagerWin::doAction()
{
	return 1;	
}
