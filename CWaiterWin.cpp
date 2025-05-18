#include "CWaiterWin.h"
#include <iostream>
using namespace std;

WaiterWin::WaiterWin(int x,int y,int width,int height)
					:CWindow(x,y,width,height)
{
	Label *waitertitle = new Label(37,7,"服务员功能界面");
	Button *tablebtn = new Button(34,8,20,3,"  开   桌");
	Button *orderbtn = new Button(34,11,20,3, "点    菜");
	Button *moneybtn = new Button(34,14,20,3,"营业额查询");
	Button *checkbtn = new Button(34,17,20,3,"已买/未买单查询");
	Button *removebtn = new Button(34,20,20,3,"  注   销");
	Button *exitbtn = new Button(34,23,20,3,"  退   出");
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