#ifndef _CDOCTORSEARCHSTAFFWIN_H_
#define _CDOCTORSEARCHSTAFFWIN_H_

#include "CDoctorWriteWin.h"
#include "CWindow.h"
#include "CTable.h"
class CDoctorSearchStaffWin :public CWindow{
public:
	CDoctorSearchStaffWin(int x,int y, int width, int height);
	void showWin();
	void winRun();
	int doAction();
private:
	Button *backBtn, *oneLine, *twoLine, *threeLine;
	CTable * diagnoseTable;

	CDoctorWriteWin *writewin;	//ÃÓ–¥ΩÁ√Ê
};

#endif