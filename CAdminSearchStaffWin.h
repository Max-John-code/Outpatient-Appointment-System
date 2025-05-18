#pragma warning (disable:4786)
//管理员用户查询界面
#ifndef _CADMINSEARCHSTAFF_H_
#define _CADMINSEARCHSTAFF_H_
#include "CTable.h"
#include <map>
#include "CData.h"
#include "CStaff.h"
#include <string.h>
//#include "CTABLE.H"
#include "CWindow.h"
#include <vector>
#include <string>
using namespace std;

class CAdminSearchStaffWin:public CWindow{
public:
	CAdminSearchStaffWin(int x,int y, int width, int height);
	void showWin();
	void winRun();
	int doAction();
private:
	Label *printLabel;
	Editbox *printEdit;
	Button *searchInfo, *backBtn;
	CTable * userTable;
};

#endif