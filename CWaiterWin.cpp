#include "CWaiterWin.h"
#include <iostream>
using namespace std;

WaiterWin::WaiterWin(int x,int y,int width,int height)
					:CWindow(x,y,width,height)
{
	Label *waitertitle = new Label(37,7,"����Ա���ܽ���");
	Button *tablebtn = new Button(34,8,20,3,"  ��   ��");
	Button *orderbtn = new Button(34,11,20,3, "��    ��");
	Button *moneybtn = new Button(34,14,20,3,"Ӫҵ���ѯ");
	Button *checkbtn = new Button(34,17,20,3,"����/δ�򵥲�ѯ");
	Button *removebtn = new Button(34,20,20,3,"  ע   ��");
	Button *exitbtn = new Button(34,23,20,3,"  ��   ��");
	this->ctrl_index = 2;
	this->addCtrl(waitertitle);
	this->addCtrl(tablebtn);		//	1
	this->addCtrl(orderbtn);		//2
	this->addCtrl(moneybtn);		//3
	this->addCtrl(checkbtn);		//4
	this->addCtrl(removebtn);		//5
	this->addCtrl(exitbtn);			//6
}

int WaiterWin::doAction()
{
	switch(this->ctrl_index){
	case 1:
		return 6;
	case 2:
		return 7;
	case 5:
		
	case 6:
		return 0;
	}
	return 3;
}