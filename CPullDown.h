#pragma warning (disable:4786)
#ifndef _CPULLDOWN_H_
#define _CPULLDOWN_H_
#include "CWindow.h"
#include <vector>
#include <string>
#include <iostream>
#include "CPullDown.h"
using namespace std;

class CPullDown:public CWindow{
public:
	CPullDown(int x, int y, int width, int height,vector<string> btnContent);
	void showWin();
	int doAction();
private:
	Button *btn;
};

class popupWin: public CWindow{
public:
	popupWin(int x,int y,int width, int height);
	void showWin();
	int doAction();
private:
	Button *yesBtn,*noBtn;
};

//修改医生弹窗
class popupAmendDoctorWin: public CWindow{
public:
	popupAmendDoctorWin(int x,int y,int width, int height);
	void showWin();
	int doAction();

	//需要在查询的doAction中修改职位和获取id，用public函数
	void setIdContent(string id);
	void setPositionContent(string position);
private:
	Label *reminder,*doctorid, *id, *position;
	Editbox *positionEdit;
	Button *enterBtn, *backBtn, *positionDown;
	vector<string> positionBtn;
	CPullDown *positionDropDown;
};

//取号弹窗
class getNumWin : public CWindow{
public:
	getNumWin(int x,int y,int width, int height);
	void showWin();
	int doAction();
private:
	Label *reminder;
	Button *getNumBtn, *cencelBtn, *backBtn;
};

#endif