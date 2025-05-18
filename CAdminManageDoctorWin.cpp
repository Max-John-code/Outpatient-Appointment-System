#include "CAdminManageDoctorWin.h"

CAdminManageDoctorWin::CAdminManageDoctorWin(int x,int y,int width, int height)
					:CWindow(x,y,width,height)
{
	this->searchBtn = new Button(24,15,11,3,"ҽ����ѯ");
	this->addBtn = new Button(45,15,11,3,"����ҽ��");
	this->backBtn = new Button(24,19,11,3," ��  ��");
	
	this->addCtrl(this->searchBtn);
	this->addCtrl(this->addBtn);
	this->addCtrl(this->backBtn);
}

void CAdminManageDoctorWin::showWin()
{
	CWindow::showWin();
	CTools::gotoxy(27,7);	
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ������Ա";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int CAdminManageDoctorWin::doAction()
{
	switch(this->ctrl_index){
	case 0:
		return 14;		//ҽ����ѯ����
	case 1:
		return 13;	//ҽ����������
	case 2:
		return 3;		//�ص�����Ա����
	}
	return 12		;//�Լ�
}