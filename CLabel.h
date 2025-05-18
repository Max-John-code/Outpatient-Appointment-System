#ifndef _CLABEL_H_
#define _CLABEL_H_
#include "CtrlBase.h"
#include "CTools.h"
#include <iostream>
using namespace std;
#include <string>

class Label:public CtrlBase
{
public:
	Label(int x,int y,string content);
	~Label();

private:
};


#endif