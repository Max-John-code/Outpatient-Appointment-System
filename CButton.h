#ifndef _CBUTTON_H_
#define _CBUTTON_H_
#include "CtrlBase.h"

class Button:public CtrlBase{
public:
	Button(int x,int y,int width, int height, string content);
	~Button();
	void show();
protected:
private:
};

#endif