#ifndef _CMANAGERWIN_H_
#define _CMANAGERWIN_H_
#include "CWindow.h"

class CManagerWin : public CWindow{
public:
	CManagerWin(int x, int y,int width, int height);
	int doAction();
private:
	Label *title;
	Button *usermanager, *doctormanager, *roommanager, *dataBtn, *backBtn;
};

#endif