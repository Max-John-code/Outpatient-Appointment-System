#ifndef _CSTAFFPERSONALCENTERWIN_H_
#define _CSTAFFPERSONALCENTERWIN_H_
#include "CWindow.h"
#include "CTools.h"
#include "CData.h"

class CStaffPersonalCenterWin:public CWindow{
public:
	CStaffPersonalCenterWin(int x,int y,int width, int height);
	int doAction();
	void showWin();
private:	//信息完善  修改密码  返回
	Button *Info,*amendPwd, *backBtn;
};

#endif