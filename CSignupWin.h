#pragma warning (disable:4786)
#ifndef _CSIGNUPWIN_H_
#define _CSIGNUPWIN_H_

#include "CWindow.h"
#include "CStaff.h"
#include "CData.h"
#include <fstream>

class CSignupWin:public CWindow{
public:
	CSignupWin(int x,int y,int width, int height);
//	void showWin();
//	void winRun();
	int doAction();
	void clear();
protected:
private:			//��֤��			��ʾ��֤��ı�ǩ
	Label *title, *numtitle, *pwdtitle, *showNumLabel;
	Editbox *numEdit, *pwdEdit;
	Button *backBtn,*signupBtn, *getNumBtn;
	string b;	//��¼���ɵ������ת���ɵ��ַ���
};


#endif