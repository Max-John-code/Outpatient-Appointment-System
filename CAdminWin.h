#pragma warning (disable:4786)
#ifndef _CADMINWIN_H_
#define _CADMINWIN_H_

#include "CWindow.h"
class AdminWin:public CWindow
{
public:
	AdminWin(int x,int y,int width,int height);
//	~AdminWin();
	void showWin();
	int doAction();
protected:
private:
	Label *admintitle;
	Button *usermanager, *doctormanager, *roommanager, *dataBtn, *backBtn;
};
#endif
