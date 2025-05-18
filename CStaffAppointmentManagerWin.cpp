#include "CStaffAppointmentManagerWin.h"

CStaffAppointmentManagerWin::CStaffAppointmentManagerWin(int x, int y, int width, int height)
						:CWindow(x,y,width,height)
{  
	this->outpatient = new Button(22,15,15,3,"  预约门诊");
	this->vaccine = new Button(44,15,15,3,"  预约疫苗");
	this->vaccineList = new Button(22,20,15,3,"疫苗接种列表");
	this->backBtn = new Button(44,20,15,3,"   返  回");

	this->addCtrl(this->outpatient);
	this->addCtrl(this->vaccine);
	this->addCtrl(this->vaccineList);
	this->addCtrl(this->backBtn);
}

void CStaffAppointmentManagerWin::showWin()
{
								//在清屏和paintWindow之后就可以打印以下内容
    							//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
	CWindow::showWin();						//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
	CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎," << CData::nowStaff->getName() << ",用户";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int CStaffAppointmentManagerWin::doAction()
{
	switch(this->ctrl_index)
	{
	case 0:	return 10;
	case 1:
	case 2:
	case 3:	return 2;		//回到用户主界面
	}

	return 9;		//回到自己
}
