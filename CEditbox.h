#ifndef _Editbox_H_
#define _Editbox_H_
#include"CtrlBase.h"

class Editbox:public CtrlBase{
public:
	Editbox(int x,int y,int width, int height,string  content,int inputType, 
			int mode, int maxlen);
	~Editbox();
	int getMode();
	int getInputType();
	int getMaxlen();
	void show();
	void editKeyListen(char ch);
	void setMaxLen(int maxlen);
	void setMode();
protected:
private:
	//独有的属性+行为
	int mode;
	int inputType;
	int maxlen;
	
};

#endif