#include "CManagerWin.h"

CManagerWin::CManagerWin(int x,int y,int width, int height)
			:CWindow(x,y,width,height)
{
	this->title = new Label(35,8,"����Ա������");
	this->usermanager = new Button(28,15,11,3,"�û�����");
	this->doctormanager = new Button(42,15,11,3,"ҽ������");
	this->roommanager = new Button(28,20,11,3,"���ҹ���");
	this->dataBtn = new Button(42,20,11,3,"����ͳ��");
	this->backBtn = new Button(28,25,11,3," �� ��");
	
	this->addCtrl(title);
	this->addCtrl(usermanager);
	this->addCtrl(doctormanager);
	this->addCtrl(roommanager);
	this->addCtrl(dataBtn);
	this->addCtrl(backBtn);
}

int CManagerWin::doAction()
{
	return 1;	
}
