#include "CAdminSearchStaffWin.h"

extern bool addStaff;

CAdminSearchStaffWin::CAdminSearchStaffWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->printLabel = new Label(15,13,"�������û��˺ţ�");
	this->printEdit = new Editbox(31,12,15,3,"", 1, 1, 11);		//�ֻ���11λ
	this->searchInfo = new Button(50,12,7,3,"��ѯ");
	this->backBtn = new Button(15,27,7,3,"����");
	//���ñ�ͷ�ͱ��
	vector<string>tableHead;
	tableHead.push_back("�˺�");
	tableHead.push_back("�����Ϣ");
	this->userTable = new CTable(20,15,20,tableHead);
	//���õ�ǰҳ��ȫ��ҳ
	this->userTable->setpagaIndex(1);
	int pageAll = CData::staffMap.size()/3;
//	cout <<pageAll;
	pageAll += CData::staffMap.size()%3==0?0:1;
	this->userTable->setpageAll(pageAll);

	this->userTable->smap = CData::staffMap;		//Ĭ��������ӡ���ݵ�������һ��ʼ����ȫ������
	this->userTable->it = this->userTable->smap.begin();	//��ʼ������Ϊ���

	this->addCtrl(this->userTable);		//0
	this->addCtrl(this->printLabel);	//1
	this->addCtrl(this->printEdit);		//2
	this->addCtrl(this->searchInfo);	//3
	this->addCtrl(this->backBtn);		//4


}

void CAdminSearchStaffWin::showWin()
{	
	if(addStaff)
	{	//������������������û����ͻ�ȡ���������
		//������������Ϊ��һ��������ҳ��ҲҪ����
		this->userTable->smap = CData::staffMap;
		this->userTable->it = this->userTable->smap.begin();	//��ʼ������Ϊ���
		//���õ�ǰҳ��ȫ��ҳ
		this->userTable->setpagaIndex(1);
		int pageAll = CData::staffMap.size()/3;
	//	cout <<pageAll;
		pageAll += CData::staffMap.size()%3==0?0:1;
		this->userTable->setpageAll(pageAll);
		addStaff = false;
	}
	

	//����winRun��Ե�ǰҳ���ú��ˣ���doACtion��Ե�ǰҳ�����������������´洢������ֱ�Ӷ����������е�ǰҳ��ƫ�ƾͿ���
	this->userTable->it = this->userTable->smap.begin();
	advance(this->userTable->it, 3*(this->userTable->getpageIndex()-1));
	CWindow::showWin();						//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
								//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
	CTools::gotoxy(27,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ,����Ա" ;
    CTools::gotoxy(48,10);
    CTools::printTime();
	this->userTable->showStaffData();
	this->userTable->showPage();

}

void CAdminSearchStaffWin::winRun()
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
			if(this->userTable->getpageIndex()==this->userTable->getpageAll()){
				this->userTable->setpagaIndex(1);
				//ƫ�Ƶ���һҳ
		/*		this->userTable->it = this->userTable->smap.begin();*/
			}
			else{
				this->userTable->setpagaIndex(this->userTable->getpageIndex()+1);
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
			if(this->userTable->getpageIndex()==1)
			{
				this->userTable->setpagaIndex(this->userTable->getpageAll());
			/*	//���е�������ƫ��,ƫ�Ƶ����һҳ�ĵ�һ��
				this->userTable->it = this->userTable->smap.begin();
				advance(this->userTable->it,3*(this->userTable->getpageAll()-1));*/
			}
			else {
				this->userTable->setpagaIndex(this->userTable->getpageIndex()-1);
				//��ǰƫ��3λ
		/*		advance(this->userTable->it, -3);*/
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


int CAdminSearchStaffWin::doAction()
{
	
	switch(this->ctrl_index){
	case 3:{

		//strstr�Ƚϱ༭���ں��û������е��˺�
		//����һ����ʱ���������ģ���������˾�push_back
		//���·��ش˴��ڣ������ѯ��Ľ��
		this->userTable->smap.clear();		//ÿ�ν��������������һ��
		if(this->printEdit->getContent()=="")
		{
			this->userTable->smap = CData::staffMap;
			//����ҳ��
			//��ѯ��ҳ��ǰҳͳһ����Ϊ1�����ں��湲ͬ���֣�����ֻ�����pageAll
			int pageAll = this->userTable->smap.size()/3 + (this->userTable->smap.size()%3==0?0:1);
			this->userTable->setpageAll(pageAll);
			
		}
		else
		{
	//		map<string, CStaff*> ::iterator it;
			for(this->userTable->it=CData::staffMap.begin();this->userTable->it!=CData::staffMap.end();++this->userTable->it)
			{
				if(this->userTable->it->first.find(this->printEdit->getContent())!=-1)
				{
					this->userTable->smap[this->userTable->it->first] = this->userTable->it->second;
				}
			}

			//�����ѯ���Ľ��Ϊ�գ���ôҲ����˵�����ʱ���map����Ȼ�ǿյ�
			if(this->userTable->smap.empty())
			{
				CTools::gotoxy(25,15);
				cout <<"û�в�ѯ���κ��й���Ϣ";
				system("pause");
				
				//��ʾ������Ϣ�ĵ�һҳ	�������ص�һ��ʼ��λ��
				this->userTable->smap = CData::staffMap;
				this->userTable->it = this->userTable->smap.begin();
			}
			//����ҳ��
			//��ѯ��ҳ��ǰҳͳһ����Ϊ1�����ں��湲ͬ���֣�����ֻ�����pageAll
			int pageAll = this->userTable->smap.size()/3 + (this->userTable->smap.size()%3==0?0:1);
			this->userTable->setpageAll(pageAll);
		}

		//��ǰҳȫ������Ϊ1
		this->userTable->setpagaIndex(1);
		return 11;
		}
	case 4:
		return 3;
	default:
		break;
	}
	return 11;
}