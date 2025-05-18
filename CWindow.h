#pragma warning (disable:4786)
#ifndef _CWINDOW_H_
#define _CWINDOW_H_
#include <vector>
#include "CtrlBase.h"
#include "CButton.h"
#include "CEditbox.h"
#include "CLabel.h"
#include <conio.h>
#include <stdlib.h>
#include "CTable.h"

class CWindow
{
public:
	CWindow(int x,int y,int width, int height);
	virtual ~CWindow();
	void addCtrl(CtrlBase *ctrl);
	virtual void showWin();
	virtual void winRun();
	virtual int doAction() = 0;
protected:
	int x, y,width,height;
	int ctrl_index;
	int ctrlCount;
	vector<CtrlBase*> ctrlArr;
	//CtrlBase *ctrlArr[10];		//基类和派生类是统一类型、所以可以统一管理
private:
};


#endif