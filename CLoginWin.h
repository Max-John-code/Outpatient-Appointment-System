#ifndef _CLOGINWIN_H_
#define _CLOGINWIN_H_

#include "CPullDown.h"
#include "CWindow.h"
#include "CStaff.h"
#include "CDoctor.h"
#include <iostream>
using namespace std;
#include <vector>
#include <string>



class loginWin:public CWindow{
public:
	loginWin(int x,int y,int width, int height);
//	void winRun();
	int doAction();
	int Jude();
	void clear();

protected:
private:
	Label *title, *usertitle, *pwdtitle, *roletitle;
	Editbox *nameEdit, *pwdEdit, *roleEdit;
	Button *loginBtn,*signupBtn, *backBtn, *roleBtn, *changeBtn;
	vector<string> btnContent;
	CPullDown *roleDown;
};


#endif