#include "CStaffOutpatientWin.h"

extern bool addAppointment;

CStaffOutpatientWin::CStaffOutpatientWin(int x,int y,int width, int height)
					:CWindow(x,y,width,height)
{
	this->title = new Label(37, 12, "ԤԼ����");
	this->hospitalLabel = new Label(18,14,"ѡ��ҽԺ��");
	this->roomLabel = new Label(18,17, "ѡ����ң�");
	this->doctorLabel = new Label(18,20,"ѡ��ҽ����");
	this->timeLabel = new Label(18,23,"ѡ��ʱ�䣺");
	this->InfoLabel = new Label(18,26," ��   ����");

	this->hospitalEdit = new Editbox(28,13,35,3,"ʡ��ҽԺ", 4,1,0);
	this->roomEdit = new Editbox(28,16,31,3,"",4,1,0);
	this->doctorEdit = new Editbox(28,19,31,3,"", 4, 1, 0);
	this->dayEdit = new Editbox(28,22,14,3,"",3,1,0);
	this->timeEdit = new Editbox(45,22,14,3,"",3,1,0);
	this->InfoEdit = new Editbox(28,25,35,3,"",4,1,20);

	this->enterBtn = new Button(27,29,11,3," ȷ  ��");
	this->backBtn = new Button(44,29,11,3," ȡ  ��");
	this->roompull = new Button(58,16,5,3,"��");
	this->doctorpull = new Button(58,19,5,3,"��");
	this->daypull = new Button(41,22,5,3,"��");
	this->timepull = new Button(58,22,5,3,"��");


	this->addCtrl(this->title);		//0
	this->addCtrl(this->hospitalLabel);		//1
	this->addCtrl(this->roomLabel);		//2
	this->addCtrl(this->doctorLabel);		//3
	this->addCtrl(this->timeLabel);		//4
	this->addCtrl(this->InfoLabel);		//5
	this->addCtrl(this->hospitalEdit);		//6
	this->addCtrl(this->roomEdit);		//7
	this->addCtrl(this->roompull);		//8
	this->addCtrl(this->doctorEdit);		//9
	this->addCtrl(this->doctorpull);		//10
	this->addCtrl(this->dayEdit);		//11
	this->addCtrl(this->daypull);		//12
	this->addCtrl(this->timeEdit);		//13
	this->addCtrl(this->timepull);		//14		
	this->addCtrl(this->InfoEdit);	//15
	this->addCtrl(this->enterBtn);		//16
	this->addCtrl(this->backBtn);		//17

	this->roomContent.push_back("�� ��");
	this->roomContent.push_back("�� ��");
	this->roomContent.push_back("Ƥ����");
	this->roomContent.push_back("�� ��");
	this->roomContent.push_back("��ǻ��");//�������ҵ�������
	this->roomDown = new CPullDown(59,16,11,17,this->roomContent);
/*	//�������ڵ�������
	//��ȡ��ǰʱ��
	time_t currentTime = time(NULL);
//	time_t weekTime = currentTime;
	//����ǰʱ��ת��Ϊ�������ں͸�ʽʱ��
	struct tm*localTime = localtime(&currentTime);
//	struct tm*weekTime = localtime(&weekTime);

	for(int i=1;i<=7;++i)
	{
		currentTime = currentTime+24*60*60;
		localTime = localtime(&currentTime);
		char localDay[20] = {0};		//ʵ��sprintf��Ҫchar *
	//	string localDay = localDay2;
		sprintf(localDay, "%d%,%02d,%02d",1900+localTime->tm_year, 1+localTime->tm_mon, localTime->tm_mday );
		this->dayContent.push_back(localDay);
	}
	this->dayDown = new CPullDown(42,22,16,25,this->dayContent);*/



	//����ʱ��ε�������
	this->timeContent.push_back("8:00-11:00");
	this->timeContent.push_back("14:00-17:00");
	this->timeDown = new CPullDown(59,22,16,11,this->timeContent);

}

void CStaffOutpatientWin::showWin()
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

void CStaffOutpatientWin::clear()
{
	this->roomEdit->setContent("");
	this->doctorEdit->setContent("");
	this->dayEdit->setContent("");
	this->timeEdit->setContent("");
	this->InfoEdit->setContent("");
}

//�ȼ�¼һ�´�ʱ��ʱ�䣬����ԤԼʱ����
		char yuyuetime[20] = {0};

int CStaffOutpatientWin::doAction()
{
	
	int p;
	int count = 0;
	switch(this->ctrl_index){
	case 13:
		return 9;	//�����û�ԤԼ��������
	case 8:{				//ѡ�����
		this->roomDown->showWin();
		this->roomDown->winRun();
		switch(this->roomDown->doAction()){
		case 0:	
			this->roomEdit->setContent("���");
			break;
			
		case 1:
			this->roomEdit->setContent("�ڿ�");
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
		default:
			break;
		}
		doctorContent.clear();		//��ֹ�Ұ��¶�ο�����������ҵ�ҽ�����ݱ��������
		map <string , CDoctor*> ::iterator it;	//����һ���ͽ�ջ
		for(it=CData::doctorMap.begin();it!=CData::doctorMap.end();it++)
		{
			if(it->second->getRoom()==this->roomEdit->getContent())
			{
				doctorContent.push_back(it->second->getName());
			}
		}
		//��ջ��ɺ������������
		this->doctorDown = new CPullDown(59,19,11,11,this->doctorContent);
		this->ctrl_index = 10;		//ʹ����ƶ���ѡ��ҽ����ť
		return 10;		//�ص��Լ��������
	}
	case 10:
		//������һ�û��ѡ��Ͳ���ѡ��ҽ��
		if(this->roomEdit->getContent()=="")
		{
			cout <<"����ѡ�����";
			system("pause");
			return 10;			//�ص�ԤԼ����
		}
		this->doctorDown->showWin();
		this->doctorDown->winRun();
		p = this->doctorDown->doAction();
		this->doctorEdit->setContent(this->doctorContent[p]);
		this->ctrl_index = 12;	//ʹ����ƶ���ѡ�����ڰ�ť
		return 10;
	case 12:{
		//����doAction��ȷ��ڹ������ʵʱ��������Ҳſ�ʼ�����7���ʱ��
		//�������ڵ�������
		//��ȡ��ǰʱ��
		time_t currentTime = time(NULL);
	//	time_t weekTime = currentTime;
		//����ǰʱ��ת��Ϊ�������ں͸�ʽʱ��
		struct tm*localTime = localtime(&currentTime);

		//�ȼ�¼һ�´�ʱ��ʱ�䣬����ԤԼʱ����
		sprintf(yuyuetime,"%d-%02d-%02d",1900+localTime->tm_year, 1+localTime->tm_mon, localTime->tm_mday );
	//	struct tm*weekTime = localtime(&weekTime);
		this->dayContent.clear();		//��գ���ֹ��ε�����µĶ��push_back
		for(int i=1;i<=7;++i)
		{
			currentTime = currentTime+24*60*60;
			localTime = localtime(&currentTime);
			char localDay[20] = {0};		//ʵ��sprintf��Ҫchar *
		//	string localDay = localDay2;
			sprintf(localDay, "%d-%02d-%02d",1900+localTime->tm_year, 1+localTime->tm_mon, localTime->tm_mday );
			this->dayContent.push_back(localDay);
		}
		this->dayDown = new CPullDown(42,22,16,23,this->dayContent);

		//�������������ʼ����
		this->dayDown->showWin();
		this->dayDown->winRun();
		p = this->dayDown->doAction();
		this->dayEdit->setContent(this->dayContent[p]);
		this->ctrl_index = 14;		//����ƶ���ѡ��ʱ��ΰ�ť
		return 10;
	}
	case 14:
		this->timeDown->showWin();
		this->timeDown->winRun();
		p = this->timeDown->doAction();
		this->timeEdit->setContent(this->timeContent[p]);
		this->ctrl_index = 15;		//����ƶ���Info

		return 10;
	
	case 16:{
		//��Ϣû����д�����޷����ȷ����ť
		if(this->roomEdit->getContent().empty()||this->dayEdit->getContent().empty()||this->dayEdit->getContent().empty()||this->timeEdit->getContent().empty()||this->InfoEdit->getContent().empty())
		{
			cout <<"�뽫��Ϣ��д����";
			system("pause");
			return 10;
		}
		//һ���û�ֻ��ԤԼһ���һ��ʱ���
		vector<Appointment*> ::iterator it;
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			//ͬһ���û���ͬһ������ͬһ��ʱ���
			if((*it)->getUser()==CData::nowStaff->getName()&&(*it)->getTime()==this->timeEdit->getContent()&&(*it)->getDay()==this->dayEdit->getContent())
			{
				cout <<"�������ظ�ԤԼһ���ͬһ��ʱ���";
				system("pause");
				return 10;			//�ص���ҳ��
			}
		}
		//һ��ҽ������ֻ��ԤԼ2���û�
		//���ݱ༭���ڵ�ҽ���ҵ�ͬһ��ͬһ��ʱ�����ҪԤԼ�����ҽ����Ȼ��������Ѿ�ԤԼ���û���
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getDoctor()==this->doctorEdit->getContent()&&(*it)->getDay()==this->dayEdit->getContent()&&this->timeEdit->getContent()==(*it)->getTime())
			{
				count ++;
			}//0 //1 //2
		}
		cout << "��ҽ����ʱ�����ԤԼ���� "<<count;
	//	system("pause");
		if(count >= 2)//������2��
		{
			cout <<"��ҽ����ǰʱ����Ѿ�ԤԼ����";
			system("pause");

			return 10;		
		}

		int id;
		
		
		//������ʵ��id����
		if(CData::appointmentVector.empty())
		{
			id = 1;
		}
		else
		{
			vector<Appointment*> ::iterator it;
			it = CData::appointmentVector.end()-1;
			id = (*it)->getId()+1;
		}
		//����һ����ʱ�������ڴ������
		Appointment* app1 = new Appointment(id, CData::nowStaff->getPhoneId(),yuyuetime, this->dayEdit->getContent(),this->timeEdit->getContent(),this->hospitalEdit->getContent(),this->roomEdit->getContent(),this->doctorEdit->getContent(),this->InfoEdit->getContent(), "��ҽ����д����", "δ����");
		CData::appointmentVector.push_back(app1);
		//д���ļ�
		CData::addAppointment(app1);
		cout <<"ԤԼ�ɹ�";
		system("pause");
		addAppointment = true;
		this->clear();
		return 9;		//�ص��û�ԤԼ���Ĺ������
		//
	}
	case 17:
		this->clear();
		return 9;
	}
	
		

	
	return 9;
}