#include "CAdminSearchDoctorWin.h"

extern bool addDoctor;

CAdminSearchDoctorWin::CAdminSearchDoctorWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->printLabel = new Label(15,13,"������ҽ��id��");
	this->printEdit = new Editbox(29,12,20,3,"", 3, 1, 5);		//ҽ���˺����4λ
	this->searchInfo = new Button(50,12,7,3,"��ѯ");
	this->backBtn = new Button(15,27,7,3,"����");
	//���ñ�ͷ�ͱ��
	vector<string>tableHead;
	tableHead.push_back("ҽ��ID");
	tableHead.push_back("ҽ������");
	tableHead.push_back("ְλ");
	tableHead.push_back("��������");
	tableHead.push_back("����ҽԺ");
	tableHead.push_back("���");
	this->doctorTable = new CTable(5,16,11,tableHead);
	//���õ�ǰҳ��ȫ��ҳ
	this->doctorTable->setpagaIndex(1);
	int pageAll = CData::doctorMap.size()/3;
//	cout <<pageAll;
	pageAll += CData::doctorMap.size()%3==0?0:1;
	this->doctorTable->setpageAll(pageAll);

	this->doctorTable->dmap = CData::doctorMap;		//Ĭ��������ӡ���ݵ�������һ��ʼ����ȫ������
	this->doctorTable->dit = this->doctorTable->dmap.begin();	//��ʼ������Ϊ���

	//���������޸ĵİ�ť
	this->oneLine = new Button (2,18,3,2,"");
	this->twoLine = new Button(2,20,3,2,"");
	this->threeLine = new Button(2,22,3,2, "");

	this->addCtrl(this->doctorTable);		//0
	this->addCtrl(this->printLabel);	//1
	this->addCtrl(this->printEdit);		//2
	this->addCtrl(this->searchInfo);	//3
	this->addCtrl(this->oneLine);		//4			
	this->addCtrl(this->twoLine);		//5
	this->addCtrl(this->threeLine);		//6
	this->addCtrl(this->backBtn);		//7

	this->amendWin = new popupAmendDoctorWin(10,15,60,15);

	
	
}

void CAdminSearchDoctorWin::showWin()
{	
	if(addDoctor)
	{
		this->doctorTable->dmap = CData::doctorMap;		//Ĭ��������ӡ���ݵ�������һ��ʼ����ȫ������
		this->doctorTable->dit = this->doctorTable->dmap.begin();	//��ʼ������Ϊ���
		//���õ�ǰҳ��ȫ��ҳ
		this->doctorTable->setpagaIndex(1);
		int pageAll = CData::doctorMap.size()/3;
	//	cout <<pageAll;
		pageAll += CData::doctorMap.size()%3==0?0:1;
		this->doctorTable->setpageAll(pageAll);
		addDoctor = false;
	}

	//����winRun��Ե�ǰҳ���ú��ˣ���doACtion��Ե�ǰҳ�����������������´洢������ֱ�Ӷ����������е�ǰҳ��ƫ�ƾͿ���
	this->doctorTable->dit = this->doctorTable->dmap.begin();
	advance(this->doctorTable->dit, 3*(this->doctorTable->getpageIndex()-1));
	CWindow::showWin();						//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
								//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
	CTools::gotoxy(27,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ,����Ա" ;
    CTools::gotoxy(48,10);
    CTools::printTime();
	this->doctorTable->showDoctorData();
	this->doctorTable->showPage();

}

void CAdminSearchDoctorWin::winRun()
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
			if(this->doctorTable->getpageIndex()==this->doctorTable->getpageAll()){
				this->doctorTable->setpagaIndex(1);
				//ƫ�Ƶ���һҳ
		/*		this->userTable->it = this->userTable->smap.begin();*/
			}
			else{
				this->doctorTable->setpagaIndex(this->doctorTable->getpageIndex()+1);
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
			if(this->doctorTable->getpageIndex()==1)
			{
				this->doctorTable->setpagaIndex(this->doctorTable->getpageAll());
	
			}
			else {
				this->doctorTable->setpagaIndex(this->doctorTable->getpageIndex()-1);
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


int CAdminSearchDoctorWin::doAction()
{
	int p ;
/*
	//showDataʱ������������ҵĵ�������showDataʱ������ƫ����3�Σ����������Ҹ�ԭһ��
	advance(this->doctorTable->dit,-3);*/

	//Ϊ�˵Ȼᰴ����������в�ѯ�������ȸ���ҳ���ȡ��������������
	//�ȸ���ҳ���ҵ�����������
		this->doctorTable->dit = this->doctorTable->dmap.begin();
		advance(this->doctorTable->dit,(this->doctorTable->getpageIndex()-1)*3);

	switch(this->ctrl_index){
	case 3:{

		//strstr�Ƚϱ༭���ں��û������е��˺�
		//����һ����ʱ���������ģ���������˾�push_back
		//���·��ش˴��ڣ������ѯ��Ľ��
		this->doctorTable->dmap.clear();		//ÿ�ν��������������һ��
		if(this->printEdit->getContent()=="")
		{
			this->doctorTable->dmap = CData::doctorMap;
			//����ҳ��
			//��ѯ��ҳ��ǰҳͳһ����Ϊ1�����ں��湲ͬ���֣�����ֻ�����pageAll
			int pageAll = this->doctorTable->dmap.size()/3 + (this->doctorTable->dmap.size()%3==0?0:1);
			this->doctorTable->setpageAll(pageAll);
			
		}
		else
		{
	//		map<string, CStaff*> ::diterator dit;
			for(this->doctorTable->dit=CData::doctorMap.begin();this->doctorTable->dit!=CData::doctorMap.end();++this->doctorTable->dit)
			{
				if(this->doctorTable->dit->first.find(this->printEdit->getContent())!=-1)
				{
					this->doctorTable->dmap[this->doctorTable->dit->first] = this->doctorTable->dit->second;
				}
			}

			//�����ѯ���Ľ��Ϊ�գ���ôҲ����˵�����ʱ���map����Ȼ�ǿյ�
			if(this->doctorTable->dmap.empty())
			{
				CTools::gotoxy(25,15);
				cout <<"û�в�ѯ���κ��й���Ϣ";
				system("pause");

				//��ʾ������Ϣ�ĵ�һҳ	�������ص�һ��ʼ��λ��
				this->doctorTable->dmap = CData::doctorMap;
				this->doctorTable->dit = this->doctorTable->dmap.begin();
			}
			//����ҳ��
			//��ѯ��ҳ��ǰҳͳһ����Ϊ1�����ں��湲ͬ���֣�����ֻ�����pageAll
			int pageAll = this->doctorTable->dmap.size()/3 + (this->doctorTable->dmap.size()%3==0?0:1);
			this->doctorTable->setpageAll(pageAll);
		}

		//��ǰҳȫ������Ϊ1
		this->doctorTable->setpagaIndex(1);
		return 14;
		}
	case 4:
		//��ȡ��һ��ҽ������Ϣ
		this->amendWin->setPositionContent(this->doctorTable->dit->second->getPosition());
		this->amendWin->setIdContent(this->doctorTable->dit->second->getId());
		this->amendWin->showWin();
		this->amendWin->winRun();
		p = this->amendWin->doAction();

		break;
	case 5:
		
		//�ж��Ƿ�Խ��
		if((this->doctorTable->getpageIndex()-1)*3+2 > this->doctorTable->dmap.size())
		{
			cout <<"��һ��û������";
			system("pause");
			break;
		}
		//��ȡ�ڶ���ҽ������Ϣ
		advance(this->doctorTable->dit, 1);
		this->amendWin->setIdContent(this->doctorTable->dit->second->getId());
		this->amendWin->setPositionContent(this->doctorTable->dit->second->getPosition());
		this->amendWin->showWin();
		this->amendWin->winRun();
		p = this->amendWin->doAction();

		break;
	case 6:
		//�ж��Ƿ�Խ��
		if(this->doctorTable->getpageIndex()*3 > this->doctorTable->dmap.size())
		{
			cout <<"��һ��û������";
			system("pause");
			break;
		}
		
		//��ȡ������ҽ������Ϣ
		advance(this->doctorTable->dit, 2);
		this->amendWin->setIdContent(this->doctorTable->dit->second->getId());
		this->amendWin->setPositionContent(this->doctorTable->dit->second->getPosition());
		this->amendWin->showWin();
		this->amendWin->winRun();
		p = this->amendWin->doAction();

		break;
	case 7:
		return 12;
	default:
		break;
	}
	//�����޸Ĵ��ڵķ���ֵ�޸���Ϣ����д���ļ�
	switch(p){
	case 0:
		this->doctorTable->dit->second->setPosition("����ҽʦ");
		break;
	case 1:
		this->doctorTable->dit->second->setPosition("����ҽʦ");
		break;
	case 2:
		this->doctorTable->dit->second->setPosition("������ҽʦ");
		break;
	case 3:
		this->doctorTable->dit->second->setPosition("ר��");
		break;
	default:
		return 14;
	}
	CData::updataDoctor();

	return 14;
}