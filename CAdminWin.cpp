#include "CAdminWin.h"
#include <iostream>
using namespace std;

AdminWin::AdminWin(int x, int y, int width, int height)
						:CWindow(x, y, width, height)
{
	this->admintitle = new Label(35,7,"����Ա������");
	this->usermanager = new Button(24,15,11,3,"�û�����");
	this->doctormanager = new Button(45,15,11,3,"ҽ������");
	this->roommanager = new Button(24,19,11,3,"���ҹ���");
	this->dataBtn = new Button(45,19,11,3,"����ͳ��");
	this->backBtn = new Button(24,24,11,3,"  �� ��");

	this->addCtrl(this->admintitle);		//0
	this->addCtrl(this->usermanager);		//1
	this->addCtrl(this->doctormanager);		//2
	this->addCtrl(this->roommanager);		//3
	this->addCtrl(this->dataBtn);		//4
	this->addCtrl(this->backBtn);			//5
}

void AdminWin::showWin()
{							
	CWindow::showWin();											//��������paintWindow֮��Ϳ��Դ�ӡ��������	
											//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
											//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
	CTools::gotoxy(13,10);
	cout <<"��ӭ,����Ա";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int AdminWin::doAction()
{
	switch(this->ctrl_index){
	case 1:
		return 11;
	case 2:
		return 12;
	case 3:
		return 15;
	case 4:
		cout <<"�ù��ܻ�δʵ��";
		system("pause");
		return 3;
		
	case 5:	//�˳����ص���½����
		return 1;
	}
	return 3;
}