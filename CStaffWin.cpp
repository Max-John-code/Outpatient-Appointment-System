#include "CStaffWin.h"

CStaffWin::CStaffWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->center = new Button(25,15,11,3, "用户中心");
	this->appointment = new Button(45,15,11,3,"预约管理");
	this->tekeNum = new Button(25,20,11,3," 取  号");
	this->diagnoseInfo = new Button(45,20,11,3,"就诊信息");
	this->backBtn = new Button(25,25,11,3," 退  出");

	this->addCtrl(center);		//0
	this->addCtrl(appointment);	//1
	this->addCtrl(tekeNum);		//2
	this->addCtrl(diagnoseInfo);//3
	this->addCtrl(backBtn);		//4
}

void CStaffWin::showWin()
{
	CWindow::showWin();
	CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎," << CData::nowStaff->getName() << ",用户";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int CStaffWin::doAction()
{
	switch(this->ctrl_index){
	case 0:	return 6;		//进入用户中心进行信息完善
	case 1:	
		//如果信息没有完善，也就是个人名字没有修改，不能进入其他界面
		if(CData::nowStaff->getName()==CData::nowStaff->getPhoneId())
		{
			cout <<"请先完善个人信息";
			system("pause");
			return 2;		//回到自己
		}
		return 9;		//预约管理界面
	case 2:
		//如果信息没有完善，也就是个人名字没有修改，不能进入其他界面
		if(CData::nowStaff->getName()==CData::nowStaff->getPhoneId())
		{
			cout <<"请先完善个人信息";
			system("pause");
			return 2;		//回到自己
		}
		return 16;
	case 3:
		//如果信息没有完善，也就是个人名字没有修改，不能进入其他界面
		if(CData::nowStaff->getName()==CData::nowStaff->getPhoneId())
		{
			cout <<"请先完善个人信息";
			system("pause");
			return 2;		//回到自己
		}
		return 18;
		//返回
	case 4:	return 1;
	}
	return 0;
}