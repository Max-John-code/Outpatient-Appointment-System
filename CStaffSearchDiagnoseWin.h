//用户就诊信息查询

#ifndef _CSTAFFSEARCHDIAGNOSE_H_
#define _CSTAFFSEARCHDIAGNOSE_H_
#include "CWindow.h"

class CStaffSearchDiagnoseWin : public CWindow{
public:
	CStaffSearchDiagnoseWin(int x,int y, int width, int height);
	void showWin();
	void winRun();
	int doAction();
private:
	Label *printLabel;
	Editbox *timeEdit1, *timeEdit2;
	Button *searchInfo, *backBtn;
	CTable * staffDiagnoseTable;

};

#endif