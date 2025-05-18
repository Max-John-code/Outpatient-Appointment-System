#ifndef _CADMINMANAGEDOCTORWIN_H_
#define _CADMINMANAGEDOCTORWIN_H_

#include "CWindow.h"
#include "CPullDown.h"
#include "CData.h"
class CAdminManageDoctorWin:public CWindow{
public:
	CAdminManageDoctorWin(int x,int y, int width, int height);
	void showWin();
	int doAction();

private:								
	Button *addBtn, *searchBtn,*backBtn;
};

#endif