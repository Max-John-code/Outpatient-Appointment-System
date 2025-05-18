#pragma warning (disable:4786)
#ifndef _CSTAFFAMENDINFO_H_
#define _CSTAFFAMENDINFO_H_
#include "CWindow.h"
#include "CData.h"
#include "CTools.h"
#include <string>
using namespace std;
//–≈œ¢ÕÍ…∆
class CStaffAmendInfoWin : public CWindow{
public:
	CStaffAmendInfoWin(int x,int y,int width, int height);
	void showWin();
	int doAction();
private:
	Label *phoneNum, *nameLabel,*IdCardLabel;
	Editbox *nameEdit, *IdCardEdit;
	Button *EnterBtn, *backBtn;

};


#endif