#include "CStaffSearchDiagnoseWin.h"

extern bool addGetNumS;

CStaffSearchDiagnoseWin::CStaffSearchDiagnoseWin(int x,int y,int width, int height)
							:CWindow(x,y,width,height)
{
	this->printLabel = new Label(11,13,"��������");
	this->timeEdit1 = new Editbox(23,12,20,3,"", 3, 1, 10);		//2024.4.10
	this->timeEdit2 = new Editbox(48,12,20,3,"", 3, 1, 10);
	this->searchInfo = new Button(70,12,7,3,"��ѯ");
	this->backBtn = new Button(15,27,7,3,"����");

	//���ñ�ͷ�ͱ��
	vector<string>tableHead;
	tableHead.push_back("���");
	tableHead.push_back("����ʱ��");
	tableHead.push_back("ԤԼҽԺ");
	tableHead.push_back("ԤԼ����");
	tableHead.push_back("ҽ��");
	tableHead.push_back("����״̬");
	this->staffDiagnoseTable = new CTable(5,16,11,tableHead);

	this->addCtrl(this->staffDiagnoseTable);		//0
	this->addCtrl(this->printLabel);	//1
	this->addCtrl(this->timeEdit1);		//2
	this->addCtrl(this->timeEdit2);		//3
	this->addCtrl(this->searchInfo);	//4
	this->addCtrl(this->backBtn);		//5
}

void CStaffSearchDiagnoseWin::showWin()
{
	vector<Appointment*> ::iterator it;

	if(addGetNumS)
	{
		//ÿ�λ���ǰ�������������
		this->staffDiagnoseTable->avec.clear();

		//�ҵ������Լ���ȡ�Ŷ���
		
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getUser()==CData::nowStaff->getPhoneId()&&((*it)->getState()=="������"||(*it)->getState()=="�Ѿ���"))
			{
				this->staffDiagnoseTable->avec.push_back((*it));
			}
		}
		//���õ�ǰҳ��ȫ��ҳ
		this->staffDiagnoseTable->setpagaIndex(1);
		int pageAll = this->staffDiagnoseTable->avec.size()/3;
		pageAll += this->staffDiagnoseTable->avec.size()%3==0?0:1;
		this->staffDiagnoseTable->setpageAll(pageAll);
		addGetNumS = false;
	}

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
		this->staffDiagnoseTable->avec.clear();
		this->staffDiagnoseTable->setpagaIndex(1);
		count = 2;
		//�ҵ������Լ���ȡ�Ŷ���
		
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getUser()==CData::nowStaff->getPhoneId()&&((*it)->getState()=="������"||(*it)->getState()=="�Ѿ���"))
			{
				this->staffDiagnoseTable->avec.push_back((*it));
			}
		}
	}
	//����ȫ��ҳ
	int pageAll = this->staffDiagnoseTable->avec.size()/3;
	pageAll += this->staffDiagnoseTable->avec.size()%3==0?0:1;
	this->staffDiagnoseTable->setpageAll(pageAll);

	//���û���κξ�����Ϣ
	if(this->staffDiagnoseTable->avec.size()==0)
	{
		CWindow::showWin();						//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
									//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
		CTools::gotoxy(35,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
		cout <<"��ӭ������������ԤԼϵͳ";
		CTools::gotoxy(3,10);
		cout <<"��ӭ," << CData::nowStaff->getName() << ",�û�";
		CTools::gotoxy(58,10);
		CTools::printTime();
		CTools::gotoxy(45,13);
		cout <<"��";
		CTools::gotoxy(45,27);
		cout <<"����ǰû���κξ�����Ϣ";
	}

	else{
		//����winRun��Ե�ǰҳ���ú��ˣ���doACtion��Ե�ǰҳ�����������������´洢������ֱ�Ӷ����������е�ǰҳ��ƫ�ƾͿ���
		this->staffDiagnoseTable->ait = this->staffDiagnoseTable->avec.begin();
		advance(this->staffDiagnoseTable->ait, 3*(this->staffDiagnoseTable->getpageIndex()-1));
		CWindow::showWin();						//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
									//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
		CTools::gotoxy(35,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
		cout <<"��ӭ������������ԤԼϵͳ";
		CTools::gotoxy(3,10);
		cout <<"��ӭ," << CData::nowStaff->getName() << ",�û�";
		CTools::gotoxy(58,10);
		CTools::printTime();
		this->staffDiagnoseTable->showStaffDiagnoseData();
		this->staffDiagnoseTable->showPage();
		CTools::gotoxy(45,13);
		cout <<"��";
	}
}

void CStaffSearchDiagnoseWin::winRun()
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
			if(this->staffDiagnoseTable->getpageIndex()==this->staffDiagnoseTable->getpageAll()){
				this->staffDiagnoseTable->setpagaIndex(1);
				//ƫ�Ƶ���һҳ
		/*		this->userTable->it = this->userTable->smap.begin();*/
			}
			else{
				this->staffDiagnoseTable->setpagaIndex(this->staffDiagnoseTable->getpageIndex()+1);
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
			if(this->staffDiagnoseTable->getpageIndex()==1)
			{
				this->staffDiagnoseTable->setpagaIndex(this->staffDiagnoseTable->getpageAll());
	
			}
			else {
				this->staffDiagnoseTable->setpagaIndex(this->staffDiagnoseTable->getpageIndex()-1);
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

int CStaffSearchDiagnoseWin::doAction()
{
	int p ;
/*
	//showDataʱ������������ҵĵ�������showDataʱ������ƫ����3�Σ����������Ҹ�ԭһ��
	advance(this->staffDiagnoseTable->dit,-3);*/

	//Ϊ�˵Ȼᰴ����������в�ѯ�������ȸ���ҳ���ȡ��������������
	//�ȸ���ҳ���ҵ�����������
		this->staffDiagnoseTable->ait = this->staffDiagnoseTable->avec.begin();
		advance(this->staffDiagnoseTable->ait,(this->staffDiagnoseTable->getpageIndex()-1)*3);

	switch(this->ctrl_index){
	case 4:{

		//�����༭���ڱ��붼�����ݣ���Ȼ����ʾ���ҷ���
		if(this->timeEdit1->getContent()==""&&this->timeEdit2->getContent()!=""||this->timeEdit2->getContent()==""&&this->timeEdit1->getContent()!="")
		{
			cout <<"��ȷ������ʱ�䶼����д����";
			system("pause");
			return 18;
		}
		if(this->timeEdit1->getContent().size()!=10&&!this->timeEdit1->getContent().empty()||!this->timeEdit2->getContent().empty()&&this->timeEdit2->getContent().size()!=10)
		{
			cout <<"��������ȷ��ʱ���ʽ������2024.04.11";
			system("pause");
			return 18;
		}
		//ǰ��ʱ���С����
		if(this->timeEdit1->getContent()>this->timeEdit2->getContent())
		{
			cout <<"����ʱ����ں�����ʱ�䣬����������";
			system("pause");
			return 18;
		}
		//����һ����ʱ���������ģ���������˾�push_back
		//���·��ش˴��ڣ������ѯ��Ľ��
		this->staffDiagnoseTable->avec.clear();		//ÿ�ν��������������һ��
		if(this->timeEdit1->getContent()==""&&this->timeEdit2->getContent()=="")
		{
			//���´������л�ȡ�����Լ���ԤԼ
			//�ҵ������Լ���ȡ�Ŷ���
			vector<Appointment*> ::iterator it;
			for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
			{
				if((*it)->getUser()==CData::nowStaff->getPhoneId()&&((*it)->getState()=="������"||(*it)->getState()=="�Ѿ���"))
				{
					this->staffDiagnoseTable->avec.push_back((*it));
				}
			}
			//����ҳ��
			//��ѯ��ҳ��ǰҳͳһ����Ϊ1�����ں��湲ͬ���֣�����ֻ�����pageAll
			int pageAll = this->staffDiagnoseTable->avec.size()/3 + (this->staffDiagnoseTable->avec.size()%3==0?0:1);
			this->staffDiagnoseTable->setpageAll(pageAll);
			
		}
		else
		{
	//		map<string, CStaff*> ::diterator dit;
			for(this->staffDiagnoseTable->ait=CData::appointmentVector.begin();this->staffDiagnoseTable->ait!=CData::appointmentVector.end();++this->staffDiagnoseTable->ait)
			{
				if((*this->staffDiagnoseTable->ait)->getDay()>=this->timeEdit1->getContent()&&(*this->staffDiagnoseTable->ait)->getDay()<=this->timeEdit2->getContent()&&(*this->staffDiagnoseTable->ait)->getUser()==CData::nowStaff->getPhoneId()&&((*this->staffDiagnoseTable->ait)->getState()=="������"||(*this->staffDiagnoseTable->ait)->getState()=="�Ѿ���"))
				{
					this->staffDiagnoseTable->avec.push_back((*this->staffDiagnoseTable->ait));
				}
			}

			//�����ѯ���Ľ��Ϊ�գ���ôҲ����˵�����ʱ���map����Ȼ�ǿյ�
			if(this->staffDiagnoseTable->avec.empty())
			{
				CTools::gotoxy(25,15);
				cout <<"û�в�ѯ���κ��й���Ϣ";
				system("pause");

				//��ʾ������Ϣ�ĵ�һҳ	�������ص�һ��ʼ��λ��
				vector<Appointment*> ::iterator it;
				for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
				{
					if((*it)->getUser()==CData::nowStaff->getPhoneId()&&((*it)->getState()=="������"||(*it)->getState()=="�Ѿ���"))
					{
						this->staffDiagnoseTable->avec.push_back((*it));
					}
				}
				this->staffDiagnoseTable->ait = this->staffDiagnoseTable->avec.begin();
			}
			//����ҳ��
			//��ѯ��ҳ��ǰҳͳһ����Ϊ1�����ں��湲ͬ���֣�����ֻ�����pageAll
			int pageAll = this->staffDiagnoseTable->avec.size()/3 + (this->staffDiagnoseTable->avec.size()%3==0?0:1);
			this->staffDiagnoseTable->setpageAll(pageAll);
		}

		//��ǰҳȫ������Ϊ1
		this->staffDiagnoseTable->setpagaIndex(1);
		return 18;
		}
	case 5:

		
	
		return 2;
		
	}
	return 18;
}