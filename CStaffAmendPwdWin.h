#pragma warning (disable:4786)
#ifndef _CSTAFFAMENDPWDWIN_H_
#define _CSTAFFAMENDPWDWIN_H_

#include "CWindow.h"
#include "CData.h"

class CStaffAmendPwdWin: public CWindow
{
public:
	CStaffAmendPwdWin(int x, int y, int width, int height);
	void showWin();
	int doAction();
private:
	Label *phoneId, *oldPwd, *newPwd1, *newPwd2;
	Editbox *oldPwdEdit, *newPwd1Edit, *newPwd2Edit;
	Button *enterBtn, *backBtn;
};

#endif