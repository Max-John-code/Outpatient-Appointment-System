#include "CStaffPersonalCenterWin.h"

CStaffPersonalCenterWin::CStaffPersonalCenterWin(int x,int y,int width, int height)
				:CWindow(x,y,width,height)
{
	this->Info = new Button(23,15,11,3,"��Ϣ����");
	this->amendPwd = new Button(45,15,11,3,"�޸�����");
	this->backBtn = new Button(23,20,11,3,"  ����");

	this->addCtrl(this->Info);
	this->addCtrl(this->amendPwd);
	this->addCtrl(this->backBtn);
}

void CStaffPersonalCenterWin::showWin()
{
	CWindow::showWin();					
	CTools::gotoxy(27,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ," << CData::nowStaff->getName() << ",�û�";
    CTools::gotoxy(48,10);
    CTools::printTime();

}

int CStaffPersonalCenterWin::doAction()
{
	switch(this->ctrl_index){
	case 0:	return 7;		//������Ϣ
	case 1:	return 8;		//�޸�����
	case 2:	return 2;		//�ص��û�������
	}
	return 2;
}