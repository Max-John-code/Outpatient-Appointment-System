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
private:	//��Ϣ����  �޸�����  ����
	Button *Info,*amendPwd, *backBtn;
};

#endif