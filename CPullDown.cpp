#include "CPullDown.h"


CPullDown::CPullDown(int x, int y, int width, int height,vector<string> btnContent)
			:CWindow(x,y,width,height)
{		//��btn������ӽ��ؼ�������
	for(int i=0;i<btnContent.size();++i)
	{
		this->btn = new Button(x+1,1+y+3*i,width-2,3,btnContent[i]);
		this->addCtrl(this->btn);
	}

}

void CPullDown::showWin()
{		//��д������system("cls")
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//��ǩת��
	{
		this->ctrlArr[i]->show();
	}
}

int CPullDown::doAction()
{
	return this->ctrl_index;
}


//--------------popupWin��

popupWin::popupWin(int x,int y,int width,int height)
			:CWindow(x,y,width,height)
{
	this->yesBtn = new Button(28,25,8,3," Yes");
	this->noBtn = new Button(45,25,8,3," No");

	this->addCtrl(this->yesBtn);
	this->addCtrl(this->noBtn);
}

void popupWin::showWin()
{	//��д������system("cls")
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//��ǩת��
	{
		this->ctrlArr[i]->show();
	}
	//�ƶ���һ�����ʵ�λ�ý��д�ӡ�Ƿ���Ҫ�˳�
	CTools::gotoxy(this->x+this->width/3,this->y+2);
	cout << "��ȷ��Ҫ�˳���";
}

int popupWin::doAction()
{
	switch(this->ctrl_index){
	case 0:
		cout <<"лл�����ε�ʹ��" << endl;
	//	system("pause");
		exit(0);
	case 1:
		return 0;	//����������
	}
	return 0;
}

//---------popupAmendDoctorWin��

popupAmendDoctorWin::popupAmendDoctorWin(int x,int y,int width,int height)
			:CWindow(x,y,width,height)
{
	this->reminder = new Label(13,17,"��ʾ���޸�ְλ");
	this->doctorid = new Label(26,19,"ҽ��ID��");
	//ҽ���޸Ľ����ʱ������ⲿ���ö�id����setContent
	this->id = new Label(35,19,"");
	this->position = new Label(26,23,"ְ  λ��");
	//һ�����ⲿ����ѡ�е�ʱ���������setContent
	this->positionEdit = new Editbox(35,22,18,3,"", 4,1,0);
	//������
	this->positionDown = new Button(50,22,5,3,"��");
	this->enterBtn = new Button(28,26,9,3," ȷ��");
	this->backBtn = new Button(44,26,9,3," ����");

	this->addCtrl(this->reminder);				//0
	this->addCtrl(this->doctorid);				//1
	this->addCtrl(this->id);					//2
	this->addCtrl(this->position);				//3
	this->addCtrl(this->positionEdit);			//4		
	this->addCtrl(this->positionDown);			//5
	this->addCtrl(this->enterBtn);				//6
	this->addCtrl(this->backBtn);				//7

	this->positionBtn.push_back("����ҽʦ");
	this->positionBtn.push_back("����ҽʦ");
	this->positionBtn.push_back("������ҽʦ");
	this->positionBtn.push_back("ר��");
	this->positionDropDown = new CPullDown(50,22,15,14,this->positionBtn);

}
//��label��eidtbox�е������޸ĳɴ���Ĳ���
void popupAmendDoctorWin::setIdContent(string id)
{
	this->id->setContent(id);
}

void popupAmendDoctorWin::setPositionContent(string position)
{
	this->positionEdit->setContent(position);
}

void popupAmendDoctorWin::showWin()
{
	//��д������system("cls")
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//��ǩת��
	{
		this->ctrlArr[i]->show();
	}
}

int popupAmendDoctorWin::doAction()
{
	switch(this->ctrl_index){
	case 5:
		this->positionDropDown->showWin();
		this->positionDropDown->winRun();
		return (this->positionDropDown->doAction());
	case 6:
	case 7:
		return 14;			//�ص�ҽ����Ϣ��ѯ����
	}

	return 14;			//�Լ�
}

getNumWin::getNumWin(int x,int y,int width,int height)
					:CWindow(x,y,width,height)
{
	this->reminder = new Label(33,17,"��ʾ��");
	this->getNumBtn = new Button(38,23,7,3,"ȡ��");
	this->cencelBtn = new Button(50,23,11,3,"ȡ��ԤԼ");
	this->backBtn = new Button(66,23,7,3,"����");

	this->addCtrl(this->reminder);
	this->addCtrl(this->getNumBtn);
	this->addCtrl(this->cencelBtn);
	this->addCtrl(this->backBtn);
}

void getNumWin::showWin()
{
	//��д������system("cls")
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//��ǩת��
	{
		this->ctrlArr[i]->show();
	}
	int count = 0;
	vector<Appointment*> ::iterator it;
	for(it = CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
	{
		if((*it)->getState()=="δ����")
			count ++;
	}
	CTools::gotoxy(45,19);
	cout <<"��ǰ�Ŷ�����" << count << "��";

}

int getNumWin::doAction()
{
	switch(this->ctrl_index){
	case 1:
		return 1;		//����ȡ��
	case 2:
		return 2;		//����ȡ��
	case 3:
		return 16;
	}
	return 16;
}