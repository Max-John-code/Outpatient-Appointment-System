#include "CDoctorWin.h"

CDoctorWin::CDoctorWin(int x,int y,int width, int height)
				:CWindow(x,y,width,height)
{
	this->uesrtitle = new Button(20,20,13,3," 个人中心");
	this->diagnoseInfoSearch = new Button(45,20,15,3,"就诊信息查询");
	this->backBtn = new Button(20,25,13,3,"  退  出");

	this->addCtrl(this->uesrtitle);
	this->addCtrl(this->diagnoseInfoSearch);
	this->addCtrl(this->backBtn);
}

void CDoctorWin::showWin()
{
	CWindow::showWin();
								//在清屏和paintWindow之后就可以打印以下内容
								//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
								//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
	CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎," << CData::nowDoctor->getName() << ",医生";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int CDoctorWin::doAction()
{
	switch(this->ctrl_index){
	case 0:	return 19;
	case 1:	return 17;
	case 2:	return 1;//退出，回到登陆界面
		return 1;
	}
	return 0;
}