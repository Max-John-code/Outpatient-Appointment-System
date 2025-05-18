#ifndef _MAINWIN_H_
#define _MAINWIN_H_
#include "CPullDown.h"
#include "CWindow.h"

class mainWin:public CWindow{

public:
	mainWin(int x,int y,int width, int height);
	~mainWin();
//	void winRun();
	int doAction();
protected:
private:
	Label *title, *nametitle;
	Button *loginBtn,*signupBtn, *exitBtn;
	popupWin *exitWin;//ÍË³öÐ¡µ¯´°
};

#endif