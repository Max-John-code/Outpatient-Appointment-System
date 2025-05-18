#include "CWindow.h"
#include "CtrlBase.h"
#include <iostream>
using namespace std;

CWindow::CWindow(int x,int y,int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->ctrlCount = 0;
	for(int i=0;i<this->ctrlArr.size();++i){
		this->ctrlArr[i] = NULL;
	}
	this->ctrl_index = 0;
}

CWindow::~CWindow()
{
	for(int i=0;i<this->ctrlArr.size();++i){
		delete this->ctrlArr[i];
	}
}

void CWindow::addCtrl(CtrlBase *ctrl)
{
	this->ctrlArr.push_back(ctrl);
}

void CWindow::showWin()
{
	system("cls");
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//��ǩת��
	{
		this->ctrlArr[i]->show();
	
	}
//	CTools::gotoxy(55,32);
//	cout << "OMO240107";

}

void CWindow::winRun()
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
		default:							//��������
			if(this->ctrlArr[i]->getCtrlType()==EDITBOX)
			{
				this->ctrlArr[i]->editKeyListen((char)key);
			}
			break;
		}								
	}									

}


