#pragma warning (disable:4786)
//管理员医生查询界面
#ifndef _CADMINSEARCHDOCTOR_H_
#define _CADMINSEARCHDOCTOR_H_
#include "CTable.h"
#include <map>
#include "CData.h"
#include "CDoctor.h"
#include <string.h>
//#include "CTABLE.H"
#include "CWindow.h"
#include <vector>
#include <string>
#include "CPullDown.h"
using namespace std;

class CAdminSearchDoctorWin:public CWindow{
public:
	CAdminSearchDoctorWin(int x,int y, int width, int height);
	void showWin();
	void winRun();
	int doAction();
private:
	Label *printLabel;
	Editbox *printEdit;
	Button *searchInfo, *backBtn, *oneLine, *twoLine, *threeLine;
	CTable * doctorTable;
	//修改信息弹窗
	popupAmendDoctorWin *amendWin;
	
};

#endif