#include "CAdminSearchRoomWin.h"


CAdminSearchRoomWin::CAdminSearchRoomWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->printLabel = new Label(15,13,"���������ID��");
	this->printEdit = new Editbox(31,12,15,3,"", 3, 1, 11);		//���ֺ���ĸ���
	this->searchInfo = new Button(50,12,7,3,"��ѯ");
	this->backBtn = new Button(15,27,7,3,"����");
	//���ñ�ͷ�ͱ��
	vector<string>tableHead;
	tableHead.push_back("����ID");
	tableHead.push_back("��������");
	tableHead.push_back("����˵��");
	this->roomTable = new CTable(20,15,12,tableHead);
	//���õ�ǰҳ��ȫ��ҳ
	this->roomTable->setpagaIndex(1);
	int pageAll = CData::kroomMap.size()/3;
//	cout <<pageAll;
	pageAll += CData::kroomMap.size()%3==0?0:1;
	this->roomTable->setpageAll(pageAll);

	this->roomTable->kmap = CData::kroomMap;		//Ĭ��������ӡ���ݵ�������һ��ʼ����ȫ������
	this->roomTable->kit = this->roomTable->kmap.begin();	//��ʼ������Ϊ���

	this->addCtrl(this->roomTable);		//0
	this->addCtrl(this->printLabel);	//1
	this->addCtrl(this->printEdit);		//2
	this->addCtrl(this->searchInfo);	//3
	this->addCtrl(this->backBtn);		//4


}

void CAdminSearchRoomWin::showWin()
{	/*
	if(addStaff)
	{	//������������������û����ͻ�ȡ���������
		//������������Ϊ��һ��������ҳ��ҲҪ����
		this->roomTable->kmap = CData::kroomMap;
		this->roomTable->it = this->roomTable->kmap.begin();	//��ʼ������Ϊ���
		//���õ�ǰҳ��ȫ��ҳ
		this->roomTable->setpagaIndex(1);
		int pageAll = CData::kroomMap.size()/3;
	//	cout <<pageAll;
		pageAll += CData::kroomMap.size()%3==0?0:1;
		this->roomTable->setpageAll(pageAll);
		addStaff = false;
	}*/
	

	//����winRun��Ե�ǰҳ���ú��ˣ���doACtion��Ե�ǰҳ�����������������´洢������ֱ�Ӷ����������е�ǰҳ��ƫ�ƾͿ���
	this->roomTable->kit = this->roomTable->kmap.begin();
	advance(this->roomTable->kit, 3*(this->roomTable->getpageIndex()-1));
	CWindow::showWin();						//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
								//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
	CTools::gotoxy(27,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ,����Ա" ;
    CTools::gotoxy(48,10);
    CTools::printTime();
	this->roomTable->showKRoomData();
	this->roomTable->showPage();

}

void CAdminSearchRoomWin::winRun()
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
			if(this->roomTable->getpageIndex()==this->roomTable->getpageAll()){
				this->roomTable->setpagaIndex(1);
				//ƫ�Ƶ���һҳ
		/*		this->roomTable->it = this->roomTable->kmap.begin();*/
			}
			else{
				this->roomTable->setpagaIndex(this->roomTable->getpageIndex()+1);
				//�����ƶ�3λ
		/*		advance(this->roomTable->it, 3);*/
			}

			//��ֻҪ����һ�β�ѯ��ť����ÿһ�����Ҽ���������в�ѯ����Ҳ����������֮���޷���ҳ
			//��Ϊenterһ���ҵ�crtl_index�͵��ڰ�ť���±��ˣ�����֮��ÿһ�ν����ҵ�doAction�ͻ�ִ�ж�Ӧ��case������
			//��ô���ڰ����Ҽ���ʱ��ctrl_index���㼴��
			this->ctrl_index = 0;

			return ;
		case KEY_LEFT:
			//���ҳ���Ѿ��ǵ�һҳ���ص����һҳ
			if(this->roomTable->getpageIndex()==1)
			{
				this->roomTable->setpagaIndex(this->roomTable->getpageAll());
			/*	//���е�������ƫ��,ƫ�Ƶ����һҳ�ĵ�һ��
				this->roomTable->it = this->roomTable->kmap.begin();
				advance(this->roomTable->it,3*(this->roomTable->getpageAll()-1));*/
			}
			else {
				this->roomTable->setpagaIndex(this->roomTable->getpageIndex()-1);
				//��ǰƫ��3λ
		/*		advance(this->roomTable->it, -3);*/
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


int CAdminSearchRoomWin::doAction()
{
	
	switch(this->ctrl_index){
	case 3:{

		//strstr�Ƚϱ༭���ں��û������е��˺�
		//����һ����ʱ���������ģ���������˾�push_back
		//���·��ش˴��ڣ������ѯ��Ľ��
		this->roomTable->kmap.clear();		//ÿ�ν��������������һ��
		if(this->printEdit->getContent()=="")
		{
			this->roomTable->kmap = CData::kroomMap;
			//����ҳ��
			//��ѯ��ҳ��ǰҳͳһ����Ϊ1�����ں��湲ͬ���֣�����ֻ�����pageAll
			int pageAll = this->roomTable->kmap.size()/3 + (this->roomTable->kmap.size()%3==0?0:1);
			this->roomTable->setpageAll(pageAll);
			
		}
		else
		{
	//		map<string, CStaff*> ::iterator it;
			for(this->roomTable->kit=CData::kroomMap.begin();this->roomTable->kit!=CData::kroomMap.end();++this->roomTable->kit)
			{
				if(this->roomTable->kit->first.find(this->printEdit->getContent())!=-1)
				{
					this->roomTable->kmap[this->roomTable->kit->first] = this->roomTable->kit->second;
				}
			}

			//�����ѯ���Ľ��Ϊ�գ���ôҲ����˵�����ʱ���map����Ȼ�ǿյ�
			if(this->roomTable->kmap.empty())
			{
				CTools::gotoxy(25,15);
				cout <<"û�в�ѯ���κ��й���Ϣ";
				system("pause");
				
				//��ʾ������Ϣ�ĵ�һҳ	�������ص�һ��ʼ��λ��
				this->roomTable->kmap = CData::kroomMap;
				this->roomTable->kit = this->roomTable->kmap.begin();
			}
			//����ҳ��
			//��ѯ��ҳ��ǰҳͳһ����Ϊ1�����ں��湲ͬ���֣�����ֻ�����pageAll
			int pageAll = this->roomTable->kmap.size()/3 + (this->roomTable->kmap.size()%3==0?0:1);
			this->roomTable->setpageAll(pageAll);
		}

		//��ǰҳȫ������Ϊ1
		this->roomTable->setpagaIndex(1);
		return 15;
		}
	case 4:
		//����ʱ���༭�����������
		this->printEdit->setContent("");
		//���»�ȡ���е�����
		this->roomTable->kmap = CData::kroomMap;
		//�������ص�һ��ʼ��λ��
		this->roomTable->kit = this->roomTable->kmap.begin();
		//ҳ��ص���һҳ
		this->roomTable->setpagaIndex(1);
		return 3;
	default:
		break;
	}
	return 15;
}