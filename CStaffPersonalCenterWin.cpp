#include "CStaffPersonalCenterWin.h"

CStaffPersonalCenterWin::CStaffPersonalCenterWin(int x,int y,int width, int height)
				:CWindow(x,y,width,height)
{
	this->Info = new Button(23,15,11,3,"信息完善");
	this->amendPwd = new Button(45,15,11,3,"修改密码");
	this->backBtn = new Button(23,20,11,3,"  返回");

	this->addCtrl(this->Info);
	this->addCtrl(this->amendPwd);
	this->addCtrl(this->backBtn);
}

void CStaffPersonalCenterWin::showWin()
{
	CWindow::showWin();					
	CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎," << CData::nowStaff->getName() << ",用户";
    CTools::gotoxy(48,10);
    CTools::printTime();

}

int CStaffPersonalCenterWin::doAction()
{
	switch(this->ctrl_index){
	case 0:	return 7;		//完善信息
	case 1:	return 8;		//修改密码
	case 2:	return 2;		//回到用户主界面
	}
	return 2;
}