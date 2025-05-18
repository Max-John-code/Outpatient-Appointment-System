#include "CDoctorWriteWin.h"

CDoctorWriteWin::CDoctorWriteWin(int x,int y,int width,int height)
				:CWindow(x,y,width,height)
{
	this->id = new Label(24,13,"用户 ID：");
	this->yuyueInfo = new Label(24,17,"预约描述：");
	this->diagnoseInfo = new Label(24,21,"就诊描述：");
	this->yuyueEdit = new Editbox(35,16,25,3,"",4,1,15);
	this->diagnoseEdit = new Editbox(35,20,25,3,"", 4,1,15);
	this->enterBtn = new Button(28,27,7,3,"确定");
	this->backBtn = new Button(48,27,7,3,"返回");
	this->showid = new Label(35,13,"");

	this->addCtrl(this->id);			//0
	this->addCtrl(this->yuyueInfo);		//1
	this->addCtrl(this->diagnoseInfo);	//2
	this->addCtrl(this->yuyueEdit);		//3
	this->addCtrl(this->diagnoseEdit);	//4
	this->addCtrl(this->enterBtn);		//5
	this->addCtrl(this->backBtn);		//6
	this->addCtrl(this->showid);		//7


}

void CDoctorWriteWin::setShowId(string id)
{
	this->showid->setContent(id);
}

void CDoctorWriteWin::setyuyueEdit(string str)
{
	this->yuyueEdit->setContent(str);
}

string CDoctorWriteWin::getDiagnoseEidt()
{
	return this->diagnoseEdit->getContent();
}

void CDoctorWriteWin::showWin()
{
	CWindow::showWin();						//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
								//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
	CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎," << CData::nowDoctor->getName() << ",用户";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int CDoctorWriteWin::doAction()
{
	return this->ctrl_index;
}

