#include "CTABLE.H"

CTable::CTable(int x,int y,int col_width, vector<string>tableHead)
:CtrlBase(x,y,width,height, TABLE, "")
{
	this->col_width = col_width;
	this->tableHead = tableHead;
}

void CTable::show()
{
	//cout << this->x << " " << this->y << " " << this->col_width  << " " << this->tableHead.size();
	//void CTools::paintTable(int startX,int startY,int row,int col, int col_width)
	CTools::paintTable(this->x, this->y, 4, this->tableHead.size(), this->col_width);
	for(int i=0;i<this->tableHead.size();++i)
	{
		CTools::gotoxy(this->x+2+i*(1+this->col_width),this->y+1);
		cout << tableHead[i];
	}
	
}



void CTable::showStaffData()
{
	//it���ⲿ�������ˣ����������͵�����������ֱ������Ϳ���
/*
	//�����ѯ����û���κ���Ϣ��
	if(this->smap.empty())
	{
		CTools::gotoxy(30,15);
		cout <<"û�в�ѯ���κ��й���Ϣ";
		system("pause");

		//��ʾ������Ϣ�ĵ�һҳ	�������ص�һ��ʼ��λ��
		this->smap = CData::staffMap;
		this->it = this->smap.begin();
	}*/
	for(int i=0;i<3&&this->it!=this->smap.end();++i,++this->it){
		CTools::gotoxy(this->x+2,this->y+1+2*(1+i));
		cout <<this->it->first;
		CTools::gotoxy(this->x+2+this->col_width+1, this->y+1+2*(1+i));
		cout <<this->it->second->getIdCard();
	}
}

void CTable::showDoctorData()
{
	//it���ⲿ�������ˣ����������͵�����������ֱ������Ϳ���

	for(int i=0;i<3&&this->dit!=this->dmap.end();++i,++this->dit){
		CTools::gotoxy(this->x+2,this->y+1+2*(1+i));
		cout <<this->dit->first;
		//��ӡ����
		CTools::gotoxy(this->x+2+this->col_width+1, this->y+1+2*(1+i));
		cout <<this->dit->second->getName();
		//��ӡְλ
		CTools::gotoxy(this->x+2+(this->col_width+1)*2, this->y+1+2*(1+i));
		cout <<this->dit->second->getPosition();
		//��ӡ����
		CTools::gotoxy(this->x+2+(this->col_width+1)*3, this->y+1+2*(1+i));
		cout <<this->dit->second->getRoom();
		//��ӡҽԺ
		CTools::gotoxy(this->x+2+(this->col_width+1)*4, this->y+1+2*(1+i));
		cout <<this->dit->second->getHospital();
		//��ӡ���
		CTools::gotoxy(this->x+2+(this->col_width+1)*5, this->y+1+2*(1+i));
		cout <<this->dit->second->getInfo();
	}
}

void CTable::showKRoomData()
{
	//it���ⲿ�������ˣ����������͵�����������ֱ������Ϳ���
/*
	//�����ѯ����û���κ���Ϣ��
	if(this->smap.empty())
	{
		CTools::gotoxy(30,15);
		cout <<"û�в�ѯ���κ��й���Ϣ";
		system("pause");

		//��ʾ������Ϣ�ĵ�һҳ	�������ص�һ��ʼ��λ��
		this->smap = CData::staffMap;
		this->it = this->smap.begin();
	}*/
	for(int i=0;i<3&&this->kit!=this->kmap.end();++i,++this->kit){
		CTools::gotoxy(this->x+2,this->y+1+2*(1+i));
		cout <<this->kit->first;
		CTools::gotoxy(this->x+2+this->col_width+1, this->y+1+2*(1+i));
		cout <<this->kit->second->getName();
		CTools::gotoxy(this->x+2+(this->col_width+1)*2,this->y+1+2*(1+i));
		cout <<this->kit->second->getInfo();
	}
}

void CTable::showGetNumData()
{
	for(int i=0;i<3&&this->ait!=this->avec.end();++i,++this->ait){
	CTools::gotoxy(this->x+2,this->y+1+2*(1+i));
	cout <<(*this->ait)->getId();
	CTools::gotoxy(this->x+2+this->col_width+1, this->y+1+2*(1+i));
	cout <<(*this->ait)->getyuyueday();
	CTools::gotoxy(this->x+2+(this->col_width+1)*2,this->y+1+2*(1+i));
	cout <<(*this->ait)->getDay();
	CTools::gotoxy(this->x+2+(this->col_width+1)*3,this->y+1+2*(1+i));
	cout <<(*this->ait)->getHospital();
	CTools::gotoxy(this->x+2+(this->col_width+1)*4,this->y+1+2*(1+i));
	cout <<(*this->ait)->getRoom();
	CTools::gotoxy(this->x+2+(this->col_width+1)*5,this->y+1+2*(1+i));
	cout <<(*this->ait)->getDoctor();
	CTools::gotoxy(this->x+2+(this->col_width+1)*6,this->y+1+2*(1+i));
	cout <<(*this->ait)->getState();
	}
}

void CTable::showdiagnoseData()
{
	for(int i=0;i<3&&this->ait!=this->avec.end();++i,++this->ait){
	CTools::gotoxy(this->x+2,this->y+1+2*(1+i));
	cout <<(*this->ait)->getId();
	CTools::gotoxy(this->x+2+this->col_width+1, this->y+1+2*(1+i));
	cout <<(*this->ait)->getUser();
	CTools::gotoxy(this->x+2+(this->col_width+1)*2,this->y+1+2*(1+i));
	cout <<(*this->ait)->getState();
	}
}

//�û������ѯ
void CTable::showStaffDiagnoseData()
{
	for(int i=0;i<3&&this->ait!=this->avec.end();++i,++this->ait){
	CTools::gotoxy(this->x+2,this->y+1+2*(1+i));
	cout <<(*this->ait)->getId();
	CTools::gotoxy(this->x+2+this->col_width+1, this->y+1+2*(1+i));
	cout <<(*this->ait)->getDay();
	CTools::gotoxy(this->x+2+(this->col_width+1)*2,this->y+1+2*(1+i));
	cout <<(*this->ait)->getHospital();
	CTools::gotoxy(this->x+2+(this->col_width+1)*3,this->y+1+2*(1+i));
	cout <<(*this->ait)->getRoom();
	CTools::gotoxy(this->x+2+(this->col_width+1)*4,this->y+1+2*(1+i));
	cout <<(*this->ait)->getDoctor();
	CTools::gotoxy(this->x+2+(this->col_width+1)*5,this->y+1+2*(1+i));
	cout <<(*this->ait)->getState();
	}
}

void CTable::setpagaIndex(int d)
{
	this->pageIndex = d;
}

void CTable::setpageAll(int d)
{
	this->pageAll = d;
}

void CTable::showPage()
{
	CTools::gotoxy(this->col_width*(this->tableHead.size())+this->x, this->y+9);
	cout << this->getpageIndex() <<  "/" << this->getpageAll();
	CTools::gotoxy(this->col_width*(this->tableHead.size())+this->x-5, this->y+11);
	cout <<"��/�����з�ҳ";
}

int CTable::getpageIndex()
{
	return this->pageIndex;
}

int CTable::getpageAll()
{
	return this->pageAll;
}