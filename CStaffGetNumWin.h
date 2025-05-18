#ifndef _CSTAFFGETNUMWIN_H_
#define _CSTAFFGETNUMWIN_H_

#include "Appointment.h"
#include "CTools.h"
#include "CData.h"
#include "CWindow.h"
#include "CTable.h"
#include "CPullDown.h"
#include <vector>
using namespace std;

class CStaffGetNumWin : public CWindow{
public:
	CStaffGetNumWin(int x,int y, int width, int height);
	void showWin();
	void winRun();
	int doAction();
private:
	Label *printLabel;
	Editbox *timeEdit1, *timeEdit2;
	Button *searchInfo, *backBtn, *oneLine, *twoLine, *threeLine;
	CTable * getNumTable;
	//È¡ºÅµ¯´°
	getNumWin *getWin;
};

#endif