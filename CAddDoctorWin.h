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

private:								//���
	Label *id, *name, *hospital, *room, *position, *Info;
	Editbox *nameEdit, *hospitalEdit, *roomEdit, *postionEdit, *InfoEdit;
	Button *entetBtn, *backBtn, *roomBtn, *positionBtn;
	
	string iDD;		//����һ��sring���ͣ�������ʱ��������ʱ��ֵ��
	//���������������
	vector<string> roomContent, positionContent;
	CPullDown *roomDown, *positionDown;
};

#endif