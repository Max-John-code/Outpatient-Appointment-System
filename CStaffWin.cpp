#include "CStaffWin.h"

CStaffWin::CStaffWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->center = new Button(25,15,11,3, "�û�����");
	this->appointment = new Button(45,15,11,3,"ԤԼ����");
	this->tekeNum = new Button(25,20,11,3," ȡ  ��");
	this->diagnoseInfo = new Button(45,20,11,3,"������Ϣ");
	this->backBtn = new Button(25,25,11,3," ��  ��");

	this->addCtrl(center);		//0
	this->addCtrl(appointment);	//1
	this->addCtrl(tekeNum);		//2
	this->addCtrl(diagnoseInfo);//3
	this->addCtrl(backBtn);		//4
}

void CStaffWin::showWin()
{
	CWindow::showWin();
	CTools::gotoxy(27,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ," << CData::nowStaff->getName() << ",�û�";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int CStaffWin::doAction()
{
	switch(this->ctrl_index){
	case 0:	return 6;		//�����û����Ľ�����Ϣ����
	case 1:	
		//�����Ϣû�����ƣ�Ҳ���Ǹ�������û���޸ģ����ܽ�����������
		if(CData::nowStaff->getName()==CData::nowStaff->getPhoneId())
		{
			cout <<"�������Ƹ�����Ϣ";
			system("pause");
			return 2;		//�ص��Լ�
		}
		return 9;		//ԤԼ�������
	case 2:
		//�����Ϣû�����ƣ�Ҳ���Ǹ�������û���޸ģ����ܽ�����������
		if(CData::nowStaff->getName()==CData::nowStaff->getPhoneId())
		{
			cout <<"�������Ƹ�����Ϣ";
			system("pause");
			return 2;		//�ص��Լ�
		}
		return 16;
	case 3:
		//�����Ϣû�����ƣ�Ҳ���Ǹ�������û���޸ģ����ܽ�����������
		if(CData::nowStaff->getName()==CData::nowStaff->getPhoneId())
		{
			cout <<"�������Ƹ�����Ϣ";
			system("pause");
			return 2;		//�ص��Լ�
		}
		return 18;
		//����
	case 4:	return 1;
	}
	return 0;
}