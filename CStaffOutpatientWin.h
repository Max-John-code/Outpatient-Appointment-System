#pragma warning (disable:4786)
#ifndef _CSTAFFOUTPATIENTWIN_H_
#define _CSTAFFOUTPATIENTWIN_H_

#include "CWindow.h"
#include "CTools.h"
#include "CData.h"
#include "CPullDown.h"
#include "Appointment.h"
#include <vector>
using namespace std;

class CStaffOutpatientWin:public CWindow{
public:
	CStaffOutpatientWin(int x,int y,int width, int height);
	void showWin();
	int doAction();
	void clear();
private:
	Label *title, *hospitalLabel, *roomLabel, *doctorLabel, *timeLabel, *InfoLabel;
	Editbox *hospitalEdit, *roomEdit, *doctorEdit, *dayEdit, *timeEdit, *InfoEdit;
	Button *enterBtn, *backBtn, *roompull, *doctorpull, *daypull, *timepull;
	vector<string> roomContent, doctorContent, timeContent, dayContent;
	CPullDown * roomDown, *doctorDown, *timeDown, *dayDown;
};

#endif