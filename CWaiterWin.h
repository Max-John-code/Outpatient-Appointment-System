#ifndef _CWAITERWIN_H_
#define _CWAITERWIN_H_

#include "CWindow.h"

class WaiterWin:public CWindow{
public:
	WaiterWin(int x, int y,int width, int height);
	int doAction();
};


#endif