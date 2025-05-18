#ifndef _CDOCTORWIN_H_
#define _CDOCTORWIN_H_

#include "CWindow.h"
#include "CData.h"

class CDoctorWin:public CWindow{
public:
	CDoctorWin(int x,int y,int width, int height);
	void showWin();
	int doAction();
private:
	Button *uesrtitle, *diagnoseInfoSearch,*backBtn;

};

#endif