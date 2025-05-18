#include "CSignupWin.h"
#include <stdlib.h>
#include <iomanip>		
#include <sstream>

extern bool addStaff;

CSignupWin::CSignupWin(int x,int y,int width, int height)
				:CWindow(x,y,width,height)
{
	this->title = new Label(38,10,"ע�����");
	this->numtitle = new Label(25,15,"�ֻ��ţ�");
	this->pwdtitle = new Label(25,20,"��֤�룺");
	this->numEdit = new Editbox(35,14,15,3,"", 1,1,11);
	this->pwdEdit = new Editbox(35,19,15,3,"", 1,1,6);
	this->getNumBtn = new Button(52,19,13,3,"��ȡ��֤��");
	this->signupBtn = new Button(33,25,8,3,"ע ��");
	this->backBtn = new Button(50,25,8,3,"�� ��");
	//����һ����ǩ����¼��֤�룬�����ʱ�򲻻ᱻ���ڻ��Ƹ���ס
	this->showNumLabel = new Label(40,23,"");		//û�а�����֤�밴ťʱ����Ҫ���κ�����
	
	this->addCtrl(this->title);		//0
	this->addCtrl(this->numtitle);	//1	
	this->addCtrl(this->pwdtitle);	//2
	this->addCtrl(this->numEdit);		//3
	this->addCtrl(this->pwdEdit);		//4��֤��
	this->addCtrl(this->getNumBtn);	//5
	this->addCtrl(this->signupBtn);	//6
	this->addCtrl(this->backBtn);		//7
	this->addCtrl(this->showNumLabel); // 8
}
/*
void CSignupWin::showWin()
{
	system("cls");
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//��ǩת��
	{
		this->ctrlArr[i]->show();
	}

}*/

void CSignupWin::clear()
{
	this->numEdit->setContent("");
	this->pwdEdit->setContent("");
}

int CSignupWin::doAction()
{
	switch(this->ctrl_index){
	case 5:{		//��������֤��ʱ�Ϳ��Զ��ֻ��ŵĸ�ʽ�����ж�
		//�ֻ��ű�����11λ���ұ�����1��ͷ
		if(this->numEdit->getContent().size()!=11||this->numEdit->getContent().at(0)!='1')
		{
			cout <<"�ֻ��Ÿ�ʽ����ȷ������������";
			system("pause");
			system("cls");
			return 5;			//�ص���ҳ��
		}
		//��֤�ֻ����Ƿ��Ѵ���
		map<string,CStaff*> ::iterator it;
		it = CData::staffMap.find(this->numEdit->getContent());
		if(it!=CData::staffMap.end())
		{
			cout <<"ע��ʧ�ܣ��û��Ѵ���";
			system("pause");
			return 5;		
		}

		int randnum = rand()%1000000;		//123
		stringstream ss;					//string��
		ss << setw(6) << setfill('0') << randnum;		//��randnumת��Ϊ6λstring����������0��䣩
		this->b = ss.str();//string��ת����string
		this->showNumLabel->setContent("�û���֤��Ϊ��"+ this->b);	//���˱�ǩ������
		return 5;
	}
	case 6:{
		//��֤�벻��Ϊ��
		//�����Ѿ��жϹ�����ܻ�ȡ��֤�����Ҫ�ֻ��Ÿ�ʽ��ȷ����������Ͳ���Ҫ�ٽ����ֻ��ŵĸ�ʽ�ж���
		if(this->pwdEdit->getContent().empty())
		{
			cout <<"��֤�벻��Ϊ��";
			system("pause");
			system("cls");
			return 5;
		}

		
		else
		{
			if(this->pwdEdit->getContent()==this->b)
			{
				cout <<"ע��ɹ�";
				system("pause");		//ע��ɹ���map���
				//����һ��CStaffָ�����ڴ�������
				CStaff* newStaff = new CStaff(this->numEdit->getContent(), this->numEdit->getContent(), "123456", 0, "������", "������");
				CData::staffMap[newStaff->getPhoneId()] = new CStaff(this->numEdit->getContent(), this->numEdit->getContent(), "123456", 0, "������", "������");
				cout <<newStaff->getPhoneId() << "   " << newStaff->getPwd();
				system("pause");
				//�ļ�׷��д��
				CData::addStaff(newStaff);
				addStaff = true;
				this->clear();
				return 1;		//�ص���½����
			}
			else
			{
				cout <<"ע��ʧ�ܣ���֤�����";
				system("pause");
				return 5;		//����ע�����
			}
		}
	}
		
	case 7:
		this->clear();
		return 0;
	}
	return 0;
}


