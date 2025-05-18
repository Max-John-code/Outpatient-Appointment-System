#ifndef _CADMINSEARCHROOM_H_
#define _CADMINSEARCHROOM_H_

#include "CTable.h"
#include <map>
#include "CData.h"
#include "CKRoom.h"
#include <string.h>
#include "CWindow.h"
#include <string>
using namespace std;

class CAdminSearchRoomWin:public CWindow{
public:
	CAdminSearchRoomWin(int x,int y, int width, int height);
	void showWin();
	void winRun();
	int doAction();
private:
	Label *printLabel;
	Editbox *printEdit;
	Button *searchInfo, *backBtn;
	CTable * roomTable;
};

#endif