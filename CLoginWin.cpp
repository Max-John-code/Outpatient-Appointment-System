#include "CLoginWin.h"
#include <string.h>
#include <stdlib.h>
#include <list>
#include "CStaff.h"
#include <iostream>
#include "CData.h"
#include "CDoctor.h"


using namespace std;

/*
CStaff *staffArr[10]={
					new CStaff(1001,"lulu","111111",ADMIN),
					new CStaff(1002,"marx","123456",MANAGER),
					new CStaff(1003,"lily","666666",WAITER)
};
int staffCount=3;*/
loginWin::loginWin(int x,int y,int width, int height)
					:CWindow(x,y,width,height)
{
	this->title = new Label(37, 7, "登入界面");
	this->usertitle = new Label(29, 19, "用户名");
	this->pwdtitle = new Label(29, 24, "密 码");
	this->nameEdit = new Editbox(35, 18, 15, 3, "", 1, 1, 11);		//账号密码均为纯数字
	this->pwdEdit = new Editbox(35,23,15,3, "", 1, 0, 6);
	this->loginBtn = new Button(30,28,10,3, "登录");
	this->signupBtn = new Button(40,28,10,3,"注册");
	this->backBtn = new Button(50,28,10,3,"返回");
	this->roletitle = new Label(29,14, "角色：");
	this->roleEdit = new Editbox(35,13,15,3,"",4,1,0);
	this->roleBtn = new Button(45,13,5,3,"▼");
	this->changeBtn = new Button(52,23,13,3,"切换明密文");

	this->addCtrl(title);		//0	
	this->addCtrl(usertitle);	//1
	this->addCtrl(roletitle);	//2
	this->addCtrl(roleEdit);	//3
	this->addCtrl(roleBtn);		//4
	this->addCtrl(pwdtitle);	//5
	this->addCtrl(nameEdit);	//6
	this->addCtrl(pwdEdit);		//7
	this->addCtrl(this->changeBtn);	//8
	this->addCtrl(loginBtn);	//9
	this->addCtrl(signupBtn);	//10
	this->addCtrl(backBtn);		//11
	
	this->btnContent.push_back("管理员");
	this->btnContent.push_back("医  生");
	this->btnContent.push_back("用  户");
	this->roleDown = new CPullDown(50,10,11,11,this->btnContent);
}
/*
void loginWin::showWin()
{
	CTools::paintWindow(x, y, width, height);

}*/

/*
void loginWin::winRun()
{
	CTools::gotoxy(this->nameEdit->getX()+2, this->nameEdit->getY()+1);
	int key = 0;
	//上下控件切换
	while(1)
	{
		key = CTools::getKey();
		switch(key){
		case KEY_DOWN:
			this->ctrl_index++;
			if(this->ctrl_index==7)
				this->ctrl_index = 3;
			switch(this->ctrl_index){
			case 3:
				CTools::gotoxy(this->nameEdit->getX()+2, nameEdit->getY()+1);
				break;
			case 4:
				CTools::gotoxy(pwdEdit->getX()+2, pwdEdit->getY()+1);
				break;
			case 5:
				CTools::gotoxy(loginBtn->getX()+2, loginBtn->getY()+1);
				break;
			default:
				CTools::gotoxy(signupBtn->getX()+2, signupBtn->getY()+1);
				break;
			}
			break;
		
		case KEY_ENTER:
			if(this->ctrl_index==5)
			{
				this->ctrl_index = 5;
				return ;
			}
			break;
		default:
			if(this->ctrl_index==3)
			{
				this->nameEdit->editKeyListen((char)key);
			}
			else if(this->ctrl_index==4)
			{
				this->pwdEdit->editKeyListen((char)key);
			}
			break;
			
		}
	}
	
}*/

void loginWin::clear()
{
	this->roleEdit->setContent("");
	this->nameEdit->setContent("");
	this->pwdEdit->setContent("");
}

int loginWin::Jude()
{	//管理员的账号和密码我就设置为1000 123456 了
	if("管理员"==this->roleEdit->getContent())
	{
		//账号错误就重新输入
		if(this->nameEdit->getContent()!="1000")
		{
			cout <<"用户名错误";
			system("pause");
			return 1;
		}
		//密码错误就重新输入
		if(this->pwdEdit->getContent()!="123456")
		{
			cout <<"管理员密码错误";
			system("pause");
			return 1;
		}

		cout <<"登陆成功";
		system("pause");
		this->clear();
		return 3;			//管理员界面
		
	}

	else if(this->roleEdit->getContent()=="医生")
	{
		map<string, CDoctor*> ::iterator i;
		string bb = "D" + this->nameEdit->getContent();
		i = CData::doctorMap.find(bb);
		
		if(i==CData::doctorMap.end())
		{
			cout <<"医生账号不存在";
			system("pause");
			return 1;
		}
		if(this->pwdEdit->getContent()==i->second->getPwd())
		{
			cout <<"登陆成功";
			system("pause");
			this->clear();
			CData::nowDoctor = i->second;
			return 4;
		}
		else{
			cout <<"密码错误";
			system("pause");
			return 1;
		}

	}

	else if(this->roleEdit->getContent()=="用户")
	{
		map<string, CStaff*> ::iterator i;
		i = CData::staffMap.find(this->nameEdit->getContent());
		if(i==CData::staffMap.end())
		{
			cout << "登录失败，用户不存在" ;
			system("pause");
			return 1;
		}
		if(this->pwdEdit->getContent()==i->second->getPwd())
		{
			cout <<"登陆成功";
			system("pause");
			this->clear();
			CData::nowStaff = i->second;
			return 2;		//病人主界面
		}
		else{
			cout <<"登陆失败，密码错误";
			system("pause");
			return 1;
		}
		
	}

	
	
	
	
	/*
	for(i=CData::staffList.begin();i!=CData::staffList.end();++i)
		{	
		if(this->nameEdit->getContent() == string((*i)->getName()))
			{
				if(this->pwdEdit->getContent()==string((*i)->getPwd()))//比对密码
				{
					CTools::gotoxy(30,25);
					printf("登录成功\n");
					system("pause");
					return 0;
					//根据角色跳转界面
				}
				else 
				{
					CTools::gotoxy(30,25);
					printf("登录失败\n");
					system("pause");
					return 0;
				}
			}
			
		}
	if(i==CData::staffList.end()){
			CTools::gotoxy(25,30);
			printf("用户名输入错误┭┮﹏┭┮,请重新输入\n");
		}*/
		return 1;
}


int loginWin::doAction()
{
	switch(this->ctrl_index){
	case 4:		//下拉框
		this->roleDown->showWin();
		this->roleDown->winRun();
		switch(this->roleDown->doAction()){		//根据返回的下边修改角色
		case 0:	this->roleEdit->setContent("管理员");
				//设置账号的长度
				this->nameEdit->setMaxLen(4);
				break;
		case 1:	this->roleEdit->setContent("医生");
				//设置账号的长度
				this->nameEdit->setMaxLen(4);
				break;
		case 2:	this->roleEdit->setContent("用户");
				//设置账号的长度
				this->nameEdit->setMaxLen(11);
				break;
		default:
			break;
		}
		this->ctrl_index = 6;			//选完角色移动到账号编辑框
		return 1;
	case 9:	
		//如果没有任何信息要提示
		if(this->roleEdit->getContent().empty()||this->pwdEdit->getContent().empty()||this->nameEdit->getContent().empty())
		{
			cout <<"请先输入账号密码";
			system("pause");
			return 1;
		}
		//登录
		return Jude();
		
		break;
	case 10:		//注册
		this->clear();
		return 5;
	case 11:		//返回
		this->clear();
		return 0;
	case 8:
		this->pwdEdit->setMode();
		return 1;
	}
	return 0;
}