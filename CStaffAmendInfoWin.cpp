#include "CStaffAmendInfoWin.h"

CStaffAmendInfoWin::CStaffAmendInfoWin(int x,int y,int width, int height)
        :CWindow(x,y,width,height)
{   
    this->phoneNum = new Label(28,14,"手机号码：");
    this->nameLabel = new Label(28,17,"  姓  名：");
    this->IdCardLabel = new Label(28,21,"身份证号：");
	this->nameEdit = new Editbox(38,16,21,3,"", 4,1,6);
	this->IdCardEdit = new Editbox(38,20,21,3,"",3,1,18);
	this->EnterBtn = new Button(30,26,8,3,"确 定");
	this->backBtn = new Button(45,26,8,3,"返 回");

    this->addCtrl(this->phoneNum);		//0
    this->addCtrl(this->nameLabel);		//1
    this->addCtrl(this->IdCardLabel);	//2
	this->addCtrl(this->nameEdit);		//3
	this->addCtrl(this->IdCardEdit);	//4

	this->addCtrl(this->EnterBtn);		//5
	this->addCtrl(this->backBtn);		//6
}

void CStaffAmendInfoWin::showWin()
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

	//下面是这个窗口特有的在手机号右边打印出手机号码
	CTools::gotoxy(40,14);
	cout << CData::nowStaff->getPhoneId();
}

int CStaffAmendInfoWin::doAction()
{
	switch(this->ctrl_index){
	case 5:
		//先判断，名字不能为空，为空要有提示
		if(this->nameEdit->getContent().size()==0)
		{
			cout <<"名字不能为空，请重新输入";
			system("pause");
			return 7;
		}
		//身份证不足18位要提示格式不正确
		if(this->IdCardEdit->getContent().size()!=18)
		{
			cout <<"身份证号码不足18位，格式不正确，请重新输入";
			system("pause");
			return 7;
		}
		//修改名字和身份证号，后写入文件
		CData::nowStaff->setName(this->nameEdit->getContent());
		CData::nowStaff->setIdCard(this->IdCardEdit->getContent());
		CData::updataStaff();
		cout <<"修改成功";
		system("pause");
		return 6;//回到个人中心主界面
	case 6:
		return 6;
	}
    return 6;
}
