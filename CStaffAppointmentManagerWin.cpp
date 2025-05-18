#include "CStaffAppointmentManagerWin.h"

CStaffAppointmentManagerWin::CStaffAppointmentManagerWin(int x, int y, int width, int height)
						:CWindow(x,y,width,height)
{  
	this->outpatient = new Button(22,15,15,3,"  ԤԼ����");
	this->vaccine = new Button(44,15,15,3,"  ԤԼ����");
	this->vaccineList = new Button(22,20,15,3,"��������б�");
	this->backBtn = new Button(44,20,15,3,"   ��  ��");

	this->addCtrl(this->outpatient);
	this->addCtrl(this->vaccine);
	this->addCtrl(this->vaccineList);
	this->addCtrl(this->backBtn);
}

void CStaffAppointmentManagerWin::showWin()
{
								//��������paintWindow֮��Ϳ��Դ�ӡ��������
    							//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
	CWindow::showWin();						//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
	CTools::gotoxy(27,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ," << CData::nowStaff->getName() << ",�û�";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int CStaffAppointmentManagerWin::doAction()
{
	switch(this->ctrl_index)
	{
	case 0:	return 10;
	case 1:
	case 2:
	case 3:	return 2;		//�ص��û�������
	}

	return 9;		//�ص��Լ�
}
