#include "CDoctorWin.h"

CDoctorWin::CDoctorWin(int x,int y,int width, int height)
				:CWindow(x,y,width,height)
{
	this->uesrtitle = new Button(20,20,13,3," ��������");
	this->diagnoseInfoSearch = new Button(45,20,15,3,"������Ϣ��ѯ");
	this->backBtn = new Button(20,25,13,3,"  ��  ��");

	this->addCtrl(this->uesrtitle);
	this->addCtrl(this->diagnoseInfoSearch);
	this->addCtrl(this->backBtn);
}

void CDoctorWin::showWin()
{
	CWindow::showWin();
								//��������paintWindow֮��Ϳ��Դ�ӡ��������
								//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
								//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
	CTools::gotoxy(27,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ," << CData::nowDoctor->getName() << ",ҽ��";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int CDoctorWin::doAction()
{
	switch(this->ctrl_index){
	case 0:	return 19;
	case 1:	return 17;
	case 2:	return 1;//�˳����ص���½����
		return 1;
	}
	return 0;
}