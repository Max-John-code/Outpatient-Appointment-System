#include "CDoctorAmendPwdWin.h"

CDoctorAmendPwdWin::CDoctorAmendPwdWin(int x, int y, int width, int height)
						:CWindow(x,y,width,height)
{
	this->phoneId = new Label(28,14,"账  号：");
    this->oldPwd = new Label(28,17,"  原密码：");
    this->newPwd1 = new Label(28,20," 新密码：");
	this->newPwd2 = new Label(28,23,"确认密码：");

	this->oldPwdEdit = new Editbox(38,16,21,3,"", 1,0,6);	//密码是数字长度为6
	this->newPwd1Edit = new Editbox(38,19,21,3,"", 1,0,6);
	this->newPwd2Edit = new Editbox(38,22,21,3,"", 1,0,6 );
	this->enterBtn = new Button(30,27,8,3,"确 定");
	this->backBtn = new Button(45,27,8,3,"返 回");

	this->addCtrl(this->phoneId);		//0
	this->addCtrl(this->oldPwd);		//1
	this->addCtrl(this->newPwd1);		//2
	this->addCtrl(this->newPwd2);		//3
	this->addCtrl(this->oldPwdEdit);	//4
	this->addCtrl(this->newPwd1Edit);	//5
	this->addCtrl(this->newPwd2Edit);	//6
	this->addCtrl(this->enterBtn);		//7
	this->addCtrl(this->backBtn);		//8
}

void CDoctorAmendPwdWin::showWin()
{
								//在清屏和paintWindow之后就可以打印以下内容
    							//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
	CWindow::showWin();						//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
	CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎," << CData::nowDoctor->getName() << ",用户";
    CTools::gotoxy(48,10);
    CTools::printTime();

	//下面是这个窗口特有的在手机号右边打印出账号
	CTools::gotoxy(40,14);
	cout << CData::nowDoctor->getId();
}

int CDoctorAmendPwdWin::doAction()
{
	switch(this->ctrl_index){
	case 7:				//旧密码验证
		if(this->oldPwdEdit->getContent()!=CData::nowDoctor->getPwd())
		{
			cout <<"旧密码错误";
			system("pause");
			return 19;
		}		//密码长度必须为6
		if(this->newPwd1Edit->getContent().size()<6)
		{
			cout <<"密码格式错误";
			system("pause");
			return 19;
		}	//不能和原密码一样
		else if(this->newPwd1Edit->getContent()==CData::nowDoctor->getPwd())
		{
			cout << "新密码不能和旧密码一致";
			system("pause");
			return 19;
		}
			//密码与确认密码
		if(this->newPwd1Edit->getContent()!=this->newPwd2Edit->getContent())
		{
			cout <<"两次新密码输入有误，请重新输入";
			system("pause");
			return 19;
		}

		//经过重重验证，以下的就是能够正确修改密码的结果了
		CData::nowDoctor->setPwd(this->newPwd1Edit->getContent());
		CData::updataDoctor();
		cout <<"密码修改成功";
		system("pause");
		return 1;		//回到登陆界面重新登陆

	case 8:
		return 4;		//返回医生个人中心
	}

	return 19;
}