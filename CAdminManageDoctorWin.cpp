#include "CAdminManageDoctorWin.h"

CAdminManageDoctorWin::CAdminManageDoctorWin(int x,int y,int width, int height)
					:CWindow(x,y,width,height)
{
	this->searchBtn = new Button(24,15,11,3,"医生查询");
	this->addBtn = new Button(45,15,11,3,"新增医生");
	this->backBtn = new Button(24,19,11,3," 返  回");
	
	this->addCtrl(this->searchBtn);
	this->addCtrl(this->addBtn);
	this->addCtrl(this->backBtn);
}

void CAdminManageDoctorWin::showWin()
{
	CWindow::showWin();
	CTools::gotoxy(27,7);	
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎，管理员";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int CAdminManageDoctorWin::doAction()
{
	switch(this->ctrl_index){
	case 0:
		return 14;		//医生查询界面
	case 1:
		return 13;	//医生新增界面
	case 2:
		return 3;		//回到管理员界面
	}
	return 12		;//自己
}