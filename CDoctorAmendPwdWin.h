#ifndef _CDOCCTORAMENDPWDWIN_H_
#define _CDOCCTORAMENDPWDWIN_H_
#include "CWindow.h"

class CDoctorAmendPwdWin: public CWindow
{
public:
	CDoctorAmendPwdWin(int x, int y, int width, int height);
	void showWin();
	int doAction();
private:
	Label *phoneId, *oldPwd, *newPwd1, *newPwd2;
	Editbox *oldPwdEdit, *newPwd1Edit, *newPwd2Edit;
	Button *enterBtn, *backBtn;
};

#endif