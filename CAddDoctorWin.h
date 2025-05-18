#ifndef _CADDDOCTORWIN_H_
#define _CADDDOCTORWIN_H_

#include "CWindow.h"
#include "CPullDown.h"
#include "CData.h"
#include "CTools.h"

class CAddDoctorWin:public CWindow{
public:
	CAddDoctorWin(int x,int y, int width, int height);
	void showWin();
	int doAction();

private:								//简介
	Label *id, *name, *hospital, *room, *position, *Info;
	Editbox *nameEdit, *hospitalEdit, *roomEdit, *postionEdit, *InfoEdit;
	Button *entetBtn, *backBtn, *roomBtn, *positionBtn;
	
	string iDD;		//定义一个sring类型，这样到时候新增的时候赋值用
	//下拉框和内容数组
	vector<string> roomContent, positionContent;
	CPullDown *roomDown, *positionDown;
};

#endif