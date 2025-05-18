#include "CDoctorSearchStaffWin.h"

extern bool addGetNumD;
//ҽ���ľ�����Ϣ��ѯ
CDoctorSearchStaffWin::CDoctorSearchStaffWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->backBtn = new Button(18,30,7,3,"����");
	//���ñ�ͷ�ͱ��
	vector<string>tableHead;
	tableHead.push_back("���");
	tableHead.push_back("�����û�ID");
	tableHead.push_back("״̬");
	this->diagnoseTable = new CTable(18,16,13,tableHead);
	//���õ�ǰҳ��ȫ��ҳ
	this->diagnoseTable->setpagaIndex(1);
	int pageAll = CData::appointmentVector.size()/3;
//	cout <<pageAll;
	pageAll += CData::appointmentVector.size()%3==0?0:1;
	this->diagnoseTable->setpageAll(pageAll);

	this->diagnoseTable->avec = CData::appointmentVector;		//Ĭ��������ӡ���ݵ�������һ��ʼ����ȫ������
	this->diagnoseTable->ait = this->diagnoseTable->avec.begin();	//��ʼ������Ϊ���

	//���������޸ĵİ�ť
	this->oneLine = new Button (15,18,3,2,"");
	this->twoLine = new Button(15,20,3,2,"");
	this->threeLine = new Button(15,22,3,2, "");

	this->addCtrl(this->diagnoseTable);		//0
	this->addCtrl(this->oneLine);		//1		
	this->addCtrl(this->twoLine);		//2
	this->addCtrl(this->threeLine);		//3
	this->addCtrl(this->backBtn);		//4	
	
	this->writewin = new CDoctorWriteWin(10,5,60,30);
}

void CDoctorSearchStaffWin::showWin()
{
	vector<Appointment*> ::iterator it;

	if(addGetNumD)
	{
		//ÿ�λ���ǰ�������������
		this->diagnoseTable->avec.clear();

		//�ҵ������Լ���ȡ�Ŷ���
		
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getDoctor()==CData::nowDoctor->getName()&&(*it)->getRoom()==CData::nowDoctor->getRoom()&&((*it)->getState()=="������"||(*it)->getState()=="�Ѿ���"))
			{
				this->diagnoseTable->avec.push_back((*it));
			}
		}	
		//���õ�ǰҳ��ȫ��ҳ
		this->diagnoseTable->setpagaIndex(1);
		int pageAll = this->diagnoseTable->avec.size()/3;
		pageAll += this->diagnoseTable->avec.size()%3==0?0:1;
		this->diagnoseTable->setpageAll(pageAll);
		addGetNumD = false;
	}

	//��ǰҳֻ�г����һ�����е�ʱ����Ҫ����Ϊ1,�ҳ�ʼ���Լ����������
	//��ǣ������¼�������ǲ�ͬ���û���count������Ϊ1
	static string aa = CData::nowDoctor->getId();;
	int static count = 1;
	if(aa!=CData::nowDoctor->getId())
	{
		count = 1;
		aa = CData::nowDoctor->getId();
	}
	if(count ==1)
	{
		this->diagnoseTable->avec.clear();
		this->diagnoseTable->setpagaIndex(1);
		count = 2;
		//�ҵ������Լ���ȡ�Ŷ���
		
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getDoctor()==CData::nowDoctor->getName()&&(*it)->getRoom()==CData::nowDoctor->getRoom()&&((*it)->getState()=="������"||(*it)->getState()=="�Ѿ���"))
			{
				this->diagnoseTable->avec.push_back((*it));
			}
		}
	}
	//����ȫ��ҳ
	int pageAll = this->diagnoseTable->avec.size()/3;
	pageAll += this->diagnoseTable->avec.size()%3==0?0:1;
	this->diagnoseTable->setpageAll(pageAll);

	//���û���κ�ԤԼ��Ϣ
	if(this->diagnoseTable->avec.size()==0)
	{
		CWindow::showWin();						//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
									//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
		CTools::gotoxy(27,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
		cout <<"��ӭ������������ԤԼϵͳ";
		CTools::gotoxy(13,10);
		cout <<"��ӭ," << CData::nowDoctor->getName() << ",�û�";
		CTools::gotoxy(48,10);
		CTools::printTime();
		CTools::gotoxy(45,13);
		CTools::gotoxy(45,27);
		cout <<"����ǰû���κ�ԤԼ��Ϣ";
	}

	else{
		//����winRun��Ե�ǰҳ���ú��ˣ���doACtion��Ե�ǰҳ�����������������´洢������ֱ�Ӷ����������е�ǰҳ��ƫ�ƾͿ���
		this->diagnoseTable->ait = this->diagnoseTable->avec.begin();
		advance(this->diagnoseTable->ait, 3*(this->diagnoseTable->getpageIndex()-1));
		CWindow::showWin();						//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
									//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
		CTools::gotoxy(45,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
		cout <<"��ӭ������������ԤԼϵͳ";
		CTools::gotoxy(13,10);
		cout <<"��ӭ," << CData::nowDoctor->getName() << ",�û�";
		CTools::gotoxy(48,10);
		CTools::printTime();
		this->diagnoseTable->showdiagnoseData();
		this->diagnoseTable->showPage();
		CTools::gotoxy(45,13);
	}
}

void CDoctorSearchStaffWin::winRun()
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
			if(this->diagnoseTable->getpageIndex()==this->diagnoseTable->getpageAll()){
				this->diagnoseTable->setpagaIndex(1);
				//ƫ�Ƶ���һҳ
		/*		this->userTable->it = this->userTable->smap.begin();*/
			}
			else{
				this->diagnoseTable->setpagaIndex(this->diagnoseTable->getpageIndex()+1);
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
			if(this->diagnoseTable->getpageIndex()==1)
			{
				this->diagnoseTable->setpagaIndex(this->diagnoseTable->getpageAll());
	
			}
			else {
				this->diagnoseTable->setpagaIndex(this->diagnoseTable->getpageIndex()-1);
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

int CDoctorSearchStaffWin::doAction()
{
	int p = 0;
	this->diagnoseTable->ait = this->diagnoseTable->avec.begin();
	advance(this->diagnoseTable->ait,(this->diagnoseTable->getpageIndex()-1)*3);
	switch(this->ctrl_index)
	{
	case 1:
		this->writewin->setShowId((*this->diagnoseTable->ait)->getUser());
	//	this->writewin->setShowId("11111111111");
		this->writewin->setyuyueEdit((*this->diagnoseTable->ait)->getInfo());
		this->writewin->showWin();
		this->writewin->winRun();
		p = this->writewin->doAction();
		break;
	case 2:
		//�ж��Ƿ�Խ��
		if((this->diagnoseTable->getpageIndex()-1)*3+2 > this->diagnoseTable->avec.size())
		{
			cout <<"��һ��û������";
			system("pause");
			break;
		}
		//��ƫ��
		advance(this->diagnoseTable->ait,1);
		this->writewin->setShowId((*this->diagnoseTable->ait)->getUser());
		this->writewin->setyuyueEdit((*this->diagnoseTable->ait)->getInfo());
		this->writewin->showWin();
		this->writewin->winRun();
		p = this->writewin->doAction();
		break;
	case 3:
		if(this->diagnoseTable->getpageIndex()*3 > this->diagnoseTable->avec.size())
		{
			cout <<"��һ��û������";
			system("pause");
			break;
		}
		//��ƫ��
		advance(this->diagnoseTable->ait,2);
		this->writewin->setShowId((*this->diagnoseTable->ait)->getUser());
		this->writewin->setyuyueEdit((*this->diagnoseTable->ait)->getInfo());
		this->writewin->showWin();
		this->writewin->winRun();
		p = this->writewin->doAction();
		break;
	case 4:
		return 4;
	}
	switch(p)
	{
	case 5:
			(*this->diagnoseTable->ait)->setSuggest(this->writewin->getDiagnoseEidt());
		(*this->diagnoseTable->ait)->setState("�Ѿ���");
		//�����ļ�
		CData::updataAppointment();
		break;
	case 6:
		break;

	}
	
	return 17;
}