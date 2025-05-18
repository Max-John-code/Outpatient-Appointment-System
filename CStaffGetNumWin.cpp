#include "CStaffGetNumWin.h"

extern bool addAppointment;
extern bool addGetNumS;
extern bool addGetNumD;

CStaffGetNumWin::CStaffGetNumWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->printLabel = new Label(11,13,"�����������");
	this->timeEdit1 = new Editbox(23,12,20,3,"", 3, 1, 10);		//2024.4.10
	this->timeEdit2 = new Editbox(48,12,20,3,"", 3, 1, 10);
	this->searchInfo = new Button(70,12,7,3,"��ѯ");
	this->backBtn = new Button(15,27,7,3,"����");
	//���ñ�ͷ�ͱ��
	vector<string>tableHead;
	tableHead.push_back("ԤԼ���");
	tableHead.push_back("ԤԼʱ��");
	tableHead.push_back("ԤԼ����ʱ��");
	tableHead.push_back("ԤԼҽԺ");
	tableHead.push_back("ԤԼ����");
	tableHead.push_back("ԤԼҽ��");
	tableHead.push_back("����״̬");
	this->getNumTable = new CTable(5,16,13,tableHead);
/*	//���õ�ǰҳ��ȫ��ҳ
	this->getNumTable->setpagaIndex(1);
	int pageAll = CData::appointmentVector.size()/3;
//	cout <<pageAll;
	pageAll += CData::appointmentVector.size()%3==0?0:1;
	this->getNumTable->setpageAll(pageAll);

//	this->getNumTable->avec = CData::appointmentVector;		//Ĭ��������ӡ���ݵ�������һ��ʼ����ȫ������
//	this->getNumTable->ait = this->getNumTable->avec.begin();	//��ʼ������Ϊ���
*/
	//���������޸ĵİ�ť
	this->oneLine = new Button (2,18,3,2,"");
	this->twoLine = new Button(2,20,3,2,"");
	this->threeLine = new Button(2,22,3,2, "");

	this->addCtrl(this->getNumTable);		//0
	this->addCtrl(this->printLabel);	//1
	this->addCtrl(this->timeEdit1);		//2
	this->addCtrl(this->timeEdit2);		//3
	this->addCtrl(this->searchInfo);	//4
	this->addCtrl(this->oneLine);		//5			
	this->addCtrl(this->twoLine);		//6
	this->addCtrl(this->threeLine);		//7
	this->addCtrl(this->backBtn);		//8

	this->getWin = new getNumWin(30,15,50,15);

	
	
}

void CStaffGetNumWin::showWin()
{	vector<Appointment*> ::iterator it;
	if(addAppointment)
	{
		//ÿ�λ���ǰ�������������
		this->getNumTable->avec.clear();

		//�ҵ������Լ���ȡ�Ŷ���
		
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getUser()==CData::nowStaff->getPhoneId()&&(*it)->getState()=="δ����")
			{
				this->getNumTable->avec.push_back((*it));
			}
		}
		//���õ�ǰҳ��ȫ��ҳ
		this->getNumTable->setpagaIndex(1);
		int pageAll = this->getNumTable->avec.size()/3;
		pageAll += this->getNumTable->avec.size()%3==0?0:1;
		this->getNumTable->setpageAll(pageAll);
		addAppointment = false;
	}



	
	//	cout <<pageAll;
		
	//��ǰҳֻ�г����һ�����е�ʱ����Ҫ����Ϊ1,�ҳ�ʼ���Լ����������
	//��ǣ������¼�������ǲ�ͬ���û���count������Ϊ1
	static string aa = CData::nowStaff->getPhoneId();
	int static count = 1;
	if(aa!=CData::nowStaff->getPhoneId())
	{
		count = 1;
		aa = CData::nowStaff->getPhoneId();
	}
	if(count ==1)
	{
		this->getNumTable->avec.clear();
		this->getNumTable->setpagaIndex(1);
		count = 2;
		//�ҵ������Լ���ȡ�Ŷ���
		
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getUser()==CData::nowStaff->getPhoneId()&&(*it)->getState()=="δ����")
			{
				this->getNumTable->avec.push_back((*it));
			}
		}
	}
	//����ȫ��ҳ
	int pageAll = this->getNumTable->avec.size()/3;
	pageAll += this->getNumTable->avec.size()%3==0?0:1;
	this->getNumTable->setpageAll(pageAll);

	//���û���κ�ԤԼ��Ϣ
	if(this->getNumTable->avec.size()==0)
	{
		CWindow::showWin();						//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
									//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
		CTools::gotoxy(45,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
		cout <<"��ӭ������������ԤԼϵͳ";
		CTools::gotoxy(13,10);
		cout <<"��ӭ," << CData::nowStaff->getName() << ",�û�";
		CTools::gotoxy(78,10);
		CTools::printTime();
		CTools::gotoxy(45,13);
		cout <<"��";
		CTools::gotoxy(45,27);
		cout <<"����ǰû���κ�ԤԼ��Ϣ";
	}

	else{
		//����winRun��Ե�ǰҳ���ú��ˣ���doACtion��Ե�ǰҳ�����������������´洢������ֱ�Ӷ����������е�ǰҳ��ƫ�ƾͿ���
		this->getNumTable->ait = this->getNumTable->avec.begin();
		advance(this->getNumTable->ait, 3*(this->getNumTable->getpageIndex()-1));
		CWindow::showWin();						//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
									//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
		CTools::gotoxy(45,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
		cout <<"��ӭ������������ԤԼϵͳ";
		CTools::gotoxy(13,10);
		cout <<"��ӭ," << CData::nowStaff->getName() << ",�û�";
		CTools::gotoxy(78,10);
		CTools::printTime();
		this->getNumTable->showGetNumData();
		this->getNumTable->showPage();
		CTools::gotoxy(45,13);
		cout <<"��";
	}
}

void CStaffGetNumWin::winRun()
{
	for(int i=this->ctrl_index;i<this->ctrlArr.size();++i)
	{
		if(this->ctrlArr[i]->getCtrlType()==EDITBOX)
		{
			CTools::gotoxy(this->ctrlArr[i]->getX()+2+(this->ctrlArr[i]->getContent().size()),
				this->ctrlArr[i]->getY()+1);
			break;
		}
		else if(this->ctrlArr[i]->getCtrlType()==BUTTON)
		{
			CTools::gotoxy(this->ctrlArr[i]->getX()+2,this->ctrlArr[i]->getY()+1);
			break;
		}
	}
	int key=0;
	while(1)
	{
		key = CTools::getKey();
		//key=getch();			//key���������-���¼� �س� ����
		switch(key)
		{
			case KEY_UP:
				i--;
				if(i<0)
				{
					i=this->ctrlArr.size()-1;			//��ֹԽ��
				}
				while(1)							//��֪��ѭ�����ٴ���while
				{
					if(this->ctrlArr[i]->getCtrlType()==EDITBOX)
					{
						CTools::gotoxy(this->ctrlArr[i]->getX()+2+(this->ctrlArr[i]->getContent().size()),this->ctrlArr[i]->getY()+1);
						break;//�༭������ܻ����ı� ������ͣ���ı�����
					}
					else if(this->ctrlArr[i]->getCtrlType()==BUTTON)
					{
						CTools::gotoxy(this->ctrlArr[i]->getX()+2,this->ctrlArr[i]->getY()+1);
						break;
					}
					i--;
					if(i<0)
					{
						i=this->ctrlArr.size()-1;//��ֹԽ��
					}
				}	
			break;							//һ��case����һ��Ҫ��break
		case KEY_DOWN:
				i++;
				if(i==this->ctrlArr.size())
				{
					i=0;					//��ֹԽ��
				}
				while(1)					//��֪��ѭ�����ٴ���while
				{
					if(this->ctrlArr[i]->getCtrlType()==EDITBOX)
					{
						CTools::gotoxy(this->ctrlArr[i]->getX()+2+(this->ctrlArr[i]->getContent().size()),this->ctrlArr[i]->getY()+1);
						break;//�༭������ܻ����ı� ������ͣ���ı�����
					}
					else if(this->ctrlArr[i]->getCtrlType()==BUTTON)
					{
						CTools::gotoxy(this->ctrlArr[i]->getX()+2,this->ctrlArr[i]->getY()+1);
						break;
					}
					i++;
					if(i==this->ctrlArr.size())
					{
						i=0;				//��ֹԽ��
					}
				}	
			break;							//һ��case����һ��Ҫ��break
		case KEY_ENTER:						//enter �����л�
			if(this->ctrlArr[i]->getCtrlType()==BUTTON)
			{
				this->ctrl_index=i;			//��¼ѡ�еİ�ť�±�
				return ;					//�������н���
			}
			break;

		//��һ���ĵط�������
		case KEY_RIGHT:

			//���ҳ���Ѿ����һҳ���ص���һҳ
			if(this->getNumTable->getpageIndex()==this->getNumTable->getpageAll()){
				this->getNumTable->setpagaIndex(1);
				//ƫ�Ƶ���һҳ
		/*		this->userTable->it = this->userTable->smap.begin();*/
			}
			else{
				this->getNumTable->setpagaIndex(this->getNumTable->getpageIndex()+1);
				//�����ƶ�3λ
		/*		advance(this->userTable->it, 3);*/
			}

			//��ֻҪ����һ�β�ѯ��ť����ÿһ�����Ҽ���������в�ѯ����Ҳ����������֮���޷���ҳ
			//��Ϊenterһ���ҵ�crtl_index�͵��ڰ�ť���±��ˣ�����֮��ÿһ�ν����ҵ�doAction�ͻ�ִ�ж�Ӧ��case������
			//��ô���ڰ����Ҽ���ʱ��ctrl_index���㼴��
			this->ctrl_index = 0;

			return ;
		case KEY_LEFT:
			//���ҳ���Ѿ��ǵ�һҳ���ص����һҳ
			if(this->getNumTable->getpageIndex()==1)
			{
				this->getNumTable->setpagaIndex(this->getNumTable->getpageAll());
	
			}
			else {
				this->getNumTable->setpagaIndex(this->getNumTable->getpageIndex()-1);
			}
			//��ֻҪ����һ�β�ѯ��ť����ÿһ�����Ҽ���������в�ѯ����Ҳ����������֮���޷���ҳ
			//��Ϊenterһ���ҵ�crtl_index�͵��ڰ�ť���±��ˣ�����֮��ÿһ�ν����ҵ�doAction�ͻ�ִ�ж�Ӧ��case������
//			//��ô���ڰ����Ҽ���ʱ��ctrl_index���㼴��
			this->ctrl_index = 0;
			
			return ;

		default:							//��������
			if(this->ctrlArr[i]->getCtrlType()==EDITBOX)
			{
				this->ctrlArr[i]->editKeyListen((char)key);
			}
			break;
		}								
	}						
}


int CStaffGetNumWin::doAction()
{
	int p ;
/*
	//showDataʱ������������ҵĵ�������showDataʱ������ƫ����3�Σ����������Ҹ�ԭһ��
	advance(this->getNumTable->dit,-3);*/

	//Ϊ�˵Ȼᰴ����������в�ѯ�������ȸ���ҳ���ȡ��������������
	//�ȸ���ҳ���ҵ�����������
		this->getNumTable->ait = this->getNumTable->avec.begin();
		advance(this->getNumTable->ait,(this->getNumTable->getpageIndex()-1)*3);

	switch(this->ctrl_index){
	case 4:{

		//�����༭���ڱ��붼�����ݣ���Ȼ����ʾ���ҷ���
		if(this->timeEdit1->getContent()==""&&this->timeEdit2->getContent()!=""||this->timeEdit2->getContent()==""&&this->timeEdit1->getContent()!="")
		{
			cout <<"��ȷ������ʱ�䶼����д����";
			system("pause");
			return 16;
		}
		if(this->timeEdit1->getContent().size()!=10&&!this->timeEdit1->getContent().empty()||!this->timeEdit2->getContent().empty()&&this->timeEdit2->getContent().size()!=10)
		{
			cout <<"��������ȷ��ʱ���ʽ������2024.04.11";
			system("pause");
			return 16;
		}
		//ǰ��ʱ���С����
		if(this->timeEdit1->getContent()>this->timeEdit2->getContent())
		{
			cout <<"����ʱ����ں�����ʱ�䣬����������";
			system("pause");
			return 16;
		}
		//����һ����ʱ���������ģ���������˾�push_back
		//���·��ش˴��ڣ������ѯ��Ľ��
		this->getNumTable->avec.clear();		//ÿ�ν��������������һ��
		if(this->timeEdit1->getContent()==""&&this->timeEdit2->getContent()=="")
		{
			//���´������л�ȡ�����Լ���ԤԼ
			//�ҵ������Լ���ȡ�Ŷ���
			vector<Appointment*> ::iterator it;
			for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
			{
				if((*it)->getUser()==CData::nowStaff->getPhoneId()&&(*it)->getState()=="δ����")
				{
					this->getNumTable->avec.push_back((*it));
				}
			}
			//����ҳ��
			//��ѯ��ҳ��ǰҳͳһ����Ϊ1�����ں��湲ͬ���֣�����ֻ�����pageAll
			int pageAll = this->getNumTable->avec.size()/3 + (this->getNumTable->avec.size()%3==0?0:1);
			this->getNumTable->setpageAll(pageAll);
			
		}
		else
		{
	//		map<string, CStaff*> ::diterator dit;
			for(this->getNumTable->ait=CData::appointmentVector.begin();this->getNumTable->ait!=CData::appointmentVector.end();++this->getNumTable->ait)
			{
				if((*this->getNumTable->ait)->getDay()>=this->timeEdit1->getContent()&&(*this->getNumTable->ait)->getDay()<=this->timeEdit2->getContent()&&(*this->getNumTable->ait)->getUser()==CData::nowStaff->getPhoneId()&&(*this->getNumTable->ait)->getState()=="δ����")
				{
					this->getNumTable->avec.push_back((*this->getNumTable->ait));
				}
			}

			//�����ѯ���Ľ��Ϊ�գ���ôҲ����˵�����ʱ���map����Ȼ�ǿյ�
			if(this->getNumTable->avec.empty())
			{
				CTools::gotoxy(25,15);
				cout <<"û�в�ѯ���κ��й���Ϣ";
				system("pause");

				//��ʾ������Ϣ�ĵ�һҳ	�������ص�һ��ʼ��λ��
				vector<Appointment*> ::iterator it;
				for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
				{
					if((*it)->getUser()==CData::nowStaff->getPhoneId()&&(*it)->getState()=="δ����")
					{
						this->getNumTable->avec.push_back((*it));
					}
				}
				this->getNumTable->ait = this->getNumTable->avec.begin();
			}
			//����ҳ��
			//��ѯ��ҳ��ǰҳͳһ����Ϊ1�����ں��湲ͬ���֣�����ֻ�����pageAll
			int pageAll = this->getNumTable->avec.size()/3 + (this->getNumTable->avec.size()%3==0?0:1);
			this->getNumTable->setpageAll(pageAll);
		}

		//��ǰҳȫ������Ϊ1
		this->getNumTable->setpagaIndex(1);
		return 16;
		}
		//��ȡ��һ��ԤԼ����Ϣ
		

		break;
	case 5:
		//��ȡ��һ��ԤԼ����Ϣ
		this->getWin->showWin();
		this->getWin->winRun();
		p = this->getWin->doAction();
		
		break;
	case 6:
		//�ж��Ƿ�Խ��
		if(this->getNumTable->getpageIndex()*3-1 > this->getNumTable->avec.size())
		{
			cout <<"��һ��û������";
			system("pause");
			break;
		}

		//��ȡ�ڶ���ԤԼ����Ϣ
		advance(this->getNumTable->ait,1);
		this->getWin->showWin();
		this->getWin->winRun();
		p = this->getWin->doAction();
		break;
	case 7:
		//�ж��Ƿ�Խ��
		if(this->getNumTable->getpageIndex()*3 > this->getNumTable->avec.size())
		{
			cout <<"��һ��û������";
			system("pause");
			break;
		}


		//��ȡ������ԤԼ����Ϣ
		advance(this->getNumTable->ait,2);
		this->getWin->showWin();
		this->getWin->winRun();
		p = this->getWin->doAction();

		break;
	case 8:
		return 2;
	default:
		break;
	}
	//�����޸Ĵ��ڵķ���ֵ�޸���Ϣ����д���ļ�
	switch(p){
	case 1:{
		//ȡ��
		//��������Ϣ��Ϊ��ԤԼ

	//	CDiagnose* newdiagnose = new CDiagnose((*this->getNumTable->ait)->getId(),(*this->getNumTable->ait)->getUser(), (*this->getNumTable->ait)->getyuyueday(), (*this->getNumTable->ait)->getDay(), (*this->getNumTable->ait)->getTime(),
	//		(*this->getNumTable->ait)->getHospital(), (*this->getNumTable->ait)->getRoom(), (*this->getNumTable->ait)->getDoctor(), (*this->getNumTable->ait)->getInfo(), (*this->getNumTable->ait)->getSuggest(), "������");
	//	CData::adddiagnoseVector(newdiagnose);		//��ӽ��ļ�
		//��������CData�����������һ�������޸�״̬����
		vector<Appointment*> ::iterator it;
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getId()==(*this->getNumTable->ait)->getId())
			{
				break;
			}
		}
		(*it)->setState("������");
		cout <<"ȡ�ųɹ�";
		system("pause");
		addGetNumS = true;
		addGetNumD = true;
		CData::updataAppointment();		//����ԤԼ��

		//Ϊ����һ�ε�show�����»�ȡ��������
		//��ʾ������Ϣ�ĵ�һҳ	�������ص�һ��ʼ��λ��
	//	vector<Appointment*> ::iterator it;
		//��������
		this->getNumTable->avec.clear();
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getUser()==CData::nowStaff->getPhoneId()&&(*it)->getState()=="δ����")
			{
				this->getNumTable->avec.push_back((*it));
			}
		}
		this->getNumTable->ait = this->getNumTable->avec.begin();
			//����ҳ��
		int pageAll = this->getNumTable->avec.size()/3 + (this->getNumTable->avec.size()%3==0?0:1);
		this->getNumTable->setpageAll(pageAll);
		this->getNumTable->setpagaIndex(1);

		break;
		}
	case 2:
		{
		//��������CData�����������һ�������޸�״̬����
		vector<Appointment*> ::iterator it;
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getId()==(*this->getNumTable->ait)->getId())
			{
				break;
			}
		}
		(*it)->setState("ȡ������");
		cout <<"ȡ���ɹ�";
		system("pause");
		CData::updataAppointment();		//����ԤԼ��

		//Ϊ����һ�ε�show�����»�ȡ��������
		//��ʾ������Ϣ�ĵ�һҳ	�������ص�һ��ʼ��λ��
	//	vector<Appointment*> ::iterator it;
		//��������
		this->getNumTable->avec.clear();
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getUser()==CData::nowStaff->getPhoneId()&&(*it)->getState()=="δ����")
			{
				this->getNumTable->avec.push_back((*it));
			}
		}
		this->getNumTable->ait = this->getNumTable->avec.begin();
			//����ҳ��
		int pageAll = this->getNumTable->avec.size()/3 + (this->getNumTable->avec.size()%3==0?0:1);
		this->getNumTable->setpageAll(pageAll);
		this->getNumTable->setpagaIndex(1);

		break;
		}
	default:
		break;
	}
	//�����ļ�

	return 16;
}