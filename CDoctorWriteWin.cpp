#include "CDoctorWriteWin.h"

CDoctorWriteWin::CDoctorWriteWin(int x,int y,int width,int height)
				:CWindow(x,y,width,height)
{
	this->id = new Label(24,13,"�û� ID��");
	this->yuyueInfo = new Label(24,17,"ԤԼ������");
	this->diagnoseInfo = new Label(24,21,"����������");
	this->yuyueEdit = new Editbox(35,16,25,3,"",4,1,15);
	this->diagnoseEdit = new Editbox(35,20,25,3,"", 4,1,15);
	this->enterBtn = new Button(28,27,7,3,"ȷ��");
	this->backBtn = new Button(48,27,7,3,"����");
	this->showid = new Label(35,13,"");

	this->addCtrl(this->id);			//0
	this->addCtrl(this->yuyueInfo);		//1
	this->addCtrl(this->diagnoseInfo);	//2
	this->addCtrl(this->yuyueEdit);		//3
	this->addCtrl(this->diagnoseEdit);	//4
	this->addCtrl(this->enterBtn);		//5
	this->addCtrl(this->backBtn);		//6
	this->addCtrl(this->showid);		//7


}

void CDoctorWriteWin::setShowId(string id)
{
	this->showid->setContent(id);
}

void CDoctorWriteWin::setyuyueEdit(string str)
{
	this->yuyueEdit->setContent(str);
}

string CDoctorWriteWin::getDiagnoseEidt()
{
	return this->diagnoseEdit->getContent();
}

void CDoctorWriteWin::showWin()
{
	CWindow::showWin();						//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
								//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
	CTools::gotoxy(27,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ," << CData::nowDoctor->getName() << ",�û�";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

int CDoctorWriteWin::doAction()
{
	return this->ctrl_index;
}

