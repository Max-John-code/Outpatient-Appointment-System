#pragma warning (disable:4786)
//�û�ԤԼ�������
#ifndef _CSTAFFAPPOINTMENTMANAGERWIN_H_
#define _CSTAFFAPPOINTMENTMANAGERWIN_H_

#include "CWindow.h"
#include "CData.h"

class CStaffAppointmentManagerWin: public CWindow{
public:
	CStaffAppointmentManagerWin(int x,int y,int width, int height);
	void showWin();
	int doAction();
private:
	Button *outpatient, *vaccine, *vaccineList, *backBtn;
};

#endif