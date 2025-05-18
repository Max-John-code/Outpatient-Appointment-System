#include "CSignupWin.h"
#include <stdlib.h>
#include <iomanip>		
#include <sstream>

extern bool addStaff;

CSignupWin::CSignupWin(int x,int y,int width, int height)
				:CWindow(x,y,width,height)
{
	this->title = new Label(38,10,"注册界面");
	this->numtitle = new Label(25,15,"手机号：");
	this->pwdtitle = new Label(25,20,"验证码：");
	this->numEdit = new Editbox(35,14,15,3,"", 1,1,11);
	this->pwdEdit = new Editbox(35,19,15,3,"", 1,1,6);
	this->getNumBtn = new Button(52,19,13,3,"获取验证码");
	this->signupBtn = new Button(33,25,8,3,"注 册");
	this->backBtn = new Button(50,25,8,3,"返 回");
	//创建一个标签来记录验证码，输出的时候不会被窗口绘制给盖住
	this->showNumLabel = new Label(40,23,"");		//没有按下验证码按钮时不需要有任何内容
	
	this->addCtrl(this->title);		//0
	this->addCtrl(this->numtitle);	//1	
	this->addCtrl(this->pwdtitle);	//2
	this->addCtrl(this->numEdit);		//3
	this->addCtrl(this->pwdEdit);		//4验证码
	this->addCtrl(this->getNumBtn);	//5
	this->addCtrl(this->signupBtn);	//6
	this->addCtrl(this->backBtn);		//7
	this->addCtrl(this->showNumLabel); // 8
}
/*
void CSignupWin::showWin()
{
	system("cls");
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//标签转换
	{
		this->ctrlArr[i]->show();
	}

}*/

void CSignupWin::clear()
{
	this->numEdit->setContent("");
	this->pwdEdit->setContent("");
}

int CSignupWin::doAction()
{
	switch(this->ctrl_index){
	case 5:{		//在生成验证码时就可以对手机号的格式进行判断
		//手机号必须是11位，且必须是1开头
		if(this->numEdit->getContent().size()!=11||this->numEdit->getContent().at(0)!='1')
		{
			cout <<"手机号格式不正确，请重新输入";
			system("pause");
			system("cls");
			return 5;			//回到该页面
		}
		//验证手机号是否已存在
		map<string,CStaff*> ::iterator it;
		it = CData::staffMap.find(this->numEdit->getContent());
		if(it!=CData::staffMap.end())
		{
			cout <<"注册失败，用户已存在";
			system("pause");
			return 5;		
		}

		int randnum = rand()%1000000;		//123
		stringstream ss;					//string流
		ss << setw(6) << setfill('0') << randnum;		//将randnum转换为6位string（不够就用0填充）
		this->b = ss.str();//string流转换成string
		this->showNumLabel->setContent("用户验证码为："+ this->b);	//填充此标签的内容
		return 5;
	}
	case 6:{
		//验证码不能为空
		//上面已经判断过如果能获取验证码就需要手机号格式正确，所以这里就不需要再进行手机号的格式判断了
		if(this->pwdEdit->getContent().empty())
		{
			cout <<"验证码不能为空";
			system("pause");
			system("cls");
			return 5;
		}

		
		else
		{
			if(this->pwdEdit->getContent()==this->b)
			{
				cout <<"注册成功";
				system("pause");		//注册成功后map添加
				//创建一个CStaff指针用于传入数据
				CStaff* newStaff = new CStaff(this->numEdit->getContent(), this->numEdit->getContent(), "123456", 0, "待完善", "待完善");
				CData::staffMap[newStaff->getPhoneId()] = new CStaff(this->numEdit->getContent(), this->numEdit->getContent(), "123456", 0, "待完善", "待完善");
				cout <<newStaff->getPhoneId() << "   " << newStaff->getPwd();
				system("pause");
				//文件追加写入
				CData::addStaff(newStaff);
				addStaff = true;
				this->clear();
				return 1;		//回到登陆界面
			}
			else
			{
				cout <<"注册失败，验证码错误";
				system("pause");
				return 5;		//返回注册界面
			}
		}
	}
		
	case 7:
		this->clear();
		return 0;
	}
	return 0;
}


