//医生就诊信息填写
#ifndef _CDOCTORWRITEWIN_H_
#define _CDOCTORWRITEWIN_H_

#include "CWindow.h"
class CDoctorWriteWin:public CWindow{
public:
	CDoctorWriteWin(int x,int y,int width, int height);
	void showWin();
	int doAction();
	void setShowId(string id);
	string getDiagnoseEidt();
	void setyuyueEdit(string str);
private:
	Label *id,*yuyueInfo, *diagnoseInfo, *showid;
	Editbox *yuyueEdit, *diagnoseEdit;
	Button *enterBtn, *backBtn;
	
};

#endif