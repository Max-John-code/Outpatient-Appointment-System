#include "CAddDoctorWin.h"

extern bool addDoctor;

CAddDoctorWin::CAddDoctorWin(int x,int y,int width, int height)
					:CWindow(x,y,width,height)
{
	this->id = new Label(25,12,"ҽ�� ID��");
	this->name = new Label(25,15, "ҽ��������");
	this->hospital = new Label(25,18,"����ҽԺ��");
	this->room = new Label(25,21,"�������ң�");
	this->position = new Label(25,24,"ҽ��ְλ��");
	this->Info = new Label(25,27,"��飺");
	
	this->nameEdit = new Editbox(36,14,25,3,"",4,1,6);
	this->hospitalEdit = new Editbox(36,17,25,3,"ʡ��ҽԺ",4,1,0);
	this->roomEdit = new Editbox(36,20,25,3,"",4,1,0);
	this->roomBtn = new Button(56,20,5,3,"��");
	this->postionEdit = new Editbox(36,23,25,3,"",4,1,0);
	this->positionBtn = new Button(56,23,5,3,"��");
	this->InfoEdit = new Editbox(36,26,25,3,"",4,1,20);

	this->entetBtn = new Button(33,30,7,3,"ȷ��");
	this->backBtn = new Button(50,30,7,3,"����");

	this->addCtrl(this->id);			//0
	this->addCtrl(this->name);			//1
	this->addCtrl(this->hospital);		//2
	this->addCtrl(this->room);			//3
	this->addCtrl(this->position);		//4
	this->addCtrl(this->Info);			//5
	this->addCtrl(this->nameEdit);		//6
	this->addCtrl(this->hospitalEdit);	//7
	this->addCtrl(this->roomEdit);		//8
	this->addCtrl(this->roomBtn);		//9
	this->addCtrl(this->postionEdit);	//10
	this->addCtrl(this->positionBtn);	//11
	this->addCtrl(this->InfoEdit);		//12
	this->addCtrl(this->entetBtn);		//13
	this->addCtrl(this->backBtn);		//14

	this->roomContent.push_back("�ڿ�");
	this->roomContent.push_back("���");
	this->roomContent.push_back("Ƥ����");
	this->roomContent.push_back("�ۿ�");
	this->roomContent.push_back("��ǻ��");
	this->roomDown = new CPullDown(57,20,11,17,this->roomContent);

	this->positionContent.push_back("ר��");
	this->positionContent.push_back("����ҽʦ");
	this->positionContent.push_back("������ҽʦ");
	this->positionContent.push_back("����ҽʦ");
	this->positionDown = new CPullDown(57,23,15,14, this->positionContent);

}

void CAddDoctorWin::showWin()
{
	CWindow::showWin();
	CTools::gotoxy(27,7);	
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ������Ա";
    CTools::gotoxy(48,10);
    CTools::printTime();
	CTools::gotoxy(36,12);		//rbegin����ȡ���������
	iDD = (CData::doctorMap.rbegin()->first);	//����ת��
	iDD.erase(0,1);
	int idd = CTools::str2int(iDD);
	++idd;
	iDD = CTools::int2str(idd);
	iDD = "D" + iDD;
	cout <<iDD;
}

int CAddDoctorWin::doAction()
{
	switch(this->ctrl_index){
	case 9:
		this->roomDown->showWin();
		this->roomDown->winRun();
		switch(this->roomDown->doAction()){
		case 0:	
			this->roomEdit->setContent("�ڿ�");
			break;
		case 1:
			this->roomEdit->setContent("���");
			break;
		case 2:
			this->roomEdit->setContent("Ƥ����");
			break;
		case 3:
			this->roomEdit->setContent("�ۿ�");
			break;
		case 4:
			this->roomEdit->setContent("��ǻ��");
			break;
		}
		return 13;
	case 11:
		this->positionDown->showWin();
		this->positionDown->winRun();
		switch(this->positionDown->doAction()){
		case 0:
			this->postionEdit->setContent("ר��");
			break;
		case 1:
			this->postionEdit->setContent("����ҽʦ");
			break;
		case 2:
			this->postionEdit->setContent("������ҽʦ");
			break;
		case 3:
			this->postionEdit->setContent("����ҽʦ");
			break;

		}
		return 13;
	case 13:{
		//���б༭����Ϊ��
		if(this->nameEdit->getContent()==""||this->roomEdit->getContent()==""||this->postionEdit->getContent()==""||this->InfoEdit->getContent()=="")
		{
			cout <<"�뽫��Ϣ��д���";
			system("pause");
			return 13;
		}
		cout <<"����ҽ���ɹ�";
		system("pause");
		CDoctor* newdoctor = new CDoctor(this->iDD, this->nameEdit->getContent(), "123456", this->roomEdit->getContent(), this->postionEdit->getContent(),this->hospitalEdit->getContent(), this->InfoEdit->getContent() );
		CData::doctorMap[newdoctor->getId()] = new CDoctor(*newdoctor);
		CData::addDoctor(newdoctor);
		addDoctor = true;
		//�����
		this->nameEdit->setContent("");
		this->roomEdit->setContent("");
		this->postionEdit->setContent("");
		this->InfoEdit->setContent("");
		}
	case 14:
		return 12;				//12����Աҽ������������
	}

	return 13;
}