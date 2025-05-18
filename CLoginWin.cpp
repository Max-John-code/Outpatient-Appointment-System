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
	this->title = new Label(37, 7, "�������");
	this->usertitle = new Label(29, 19, "�û���");
	this->pwdtitle = new Label(29, 24, "�� ��");
	this->nameEdit = new Editbox(35, 18, 15, 3, "", 1, 1, 11);		//�˺������Ϊ������
	this->pwdEdit = new Editbox(35,23,15,3, "", 1, 0, 6);
	this->loginBtn = new Button(30,28,10,3, "��¼");
	this->signupBtn = new Button(40,28,10,3,"ע��");
	this->backBtn = new Button(50,28,10,3,"����");
	this->roletitle = new Label(29,14, "��ɫ��");
	this->roleEdit = new Editbox(35,13,15,3,"",4,1,0);
	this->roleBtn = new Button(45,13,5,3,"��");
	this->changeBtn = new Button(52,23,13,3,"�л�������");

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
	
	this->btnContent.push_back("����Ա");
	this->btnContent.push_back("ҽ  ��");
	this->btnContent.push_back("��  ��");
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
	//���¿ؼ��л�
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
{	//����Ա���˺ź������Ҿ�����Ϊ1000 123456 ��
	if("����Ա"==this->roleEdit->getContent())
	{
		//�˺Ŵ������������
		if(this->nameEdit->getContent()!="1000")
		{
			cout <<"�û�������";
			system("pause");
			return 1;
		}
		//����������������
		if(this->pwdEdit->getContent()!="123456")
		{
			cout <<"����Ա�������";
			system("pause");
			return 1;
		}

		cout <<"��½�ɹ�";
		system("pause");
		this->clear();
		return 3;			//����Ա����
		
	}

	else if(this->roleEdit->getContent()=="ҽ��")
	{
		map<string, CDoctor*> ::iterator i;
		string bb = "D" + this->nameEdit->getContent();
		i = CData::doctorMap.find(bb);
		
		if(i==CData::doctorMap.end())
		{
			cout <<"ҽ���˺Ų�����";
			system("pause");
			return 1;
		}
		if(this->pwdEdit->getContent()==i->second->getPwd())
		{
			cout <<"��½�ɹ�";
			system("pause");
			this->clear();
			CData::nowDoctor = i->second;
			return 4;
		}
		else{
			cout <<"�������";
			system("pause");
			return 1;
		}

	}

	else if(this->roleEdit->getContent()=="�û�")
	{
		map<string, CStaff*> ::iterator i;
		i = CData::staffMap.find(this->nameEdit->getContent());
		if(i==CData::staffMap.end())
		{
			cout << "��¼ʧ�ܣ��û�������" ;
			system("pause");
			return 1;
		}
		if(this->pwdEdit->getContent()==i->second->getPwd())
		{
			cout <<"��½�ɹ�";
			system("pause");
			this->clear();
			CData::nowStaff = i->second;
			return 2;		//����������
		}
		else{
			cout <<"��½ʧ�ܣ��������";
			system("pause");
			return 1;
		}
		
	}

	
	
	
	
	/*
	for(i=CData::staffList.begin();i!=CData::staffList.end();++i)
		{	
		if(this->nameEdit->getContent() == string((*i)->getName()))
			{
				if(this->pwdEdit->getContent()==string((*i)->getPwd()))//�ȶ�����
				{
					CTools::gotoxy(30,25);
					printf("��¼�ɹ�\n");
					system("pause");
					return 0;
					//���ݽ�ɫ��ת����
				}
				else 
				{
					CTools::gotoxy(30,25);
					printf("��¼ʧ��\n");
					system("pause");
					return 0;
				}
			}
			
		}
	if(i==CData::staffList.end()){
			CTools::gotoxy(25,30);
			printf("�û����������ѩҩn�ѩ�,����������\n");
		}*/
		return 1;
}


int loginWin::doAction()
{
	switch(this->ctrl_index){
	case 4:		//������
		this->roleDown->showWin();
		this->roleDown->winRun();
		switch(this->roleDown->doAction()){		//���ݷ��ص��±��޸Ľ�ɫ
		case 0:	this->roleEdit->setContent("����Ա");
				//�����˺ŵĳ���
				this->nameEdit->setMaxLen(4);
				break;
		case 1:	this->roleEdit->setContent("ҽ��");
				//�����˺ŵĳ���
				this->nameEdit->setMaxLen(4);
				break;
		case 2:	this->roleEdit->setContent("�û�");
				//�����˺ŵĳ���
				this->nameEdit->setMaxLen(11);
				break;
		default:
			break;
		}
		this->ctrl_index = 6;			//ѡ���ɫ�ƶ����˺ű༭��
		return 1;
	case 9:	
		//���û���κ���ϢҪ��ʾ
		if(this->roleEdit->getContent().empty()||this->pwdEdit->getContent().empty()||this->nameEdit->getContent().empty())
		{
			cout <<"���������˺�����";
			system("pause");
			return 1;
		}
		//��¼
		return Jude();
		
		break;
	case 10:		//ע��
		this->clear();
		return 5;
	case 11:		//����
		this->clear();
		return 0;
	case 8:
		this->pwdEdit->setMode();
		return 1;
	}
	return 0;
}