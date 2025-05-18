#ifndef _CSTAFFWIN_H_
#define _CSTAFFWIN_H_
#include "CWindow.h"
#include "CData.h"
#include "CTools.h"

class CStaffWin:public CWindow{
public:
	CStaffWin(int x, int y, int width, int height);
	void showWin();
	int doAction();
private:
	Button *center, *tekeNum, *appointment, *diagnoseInfo, *backBtn;
};

#endif