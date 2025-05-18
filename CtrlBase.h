#ifndef _CTRLBASE_H_
#define _CTRLBASE_H_
#define LABEL 1
#define EDITBOX 2
#define BUTTON 3
#define TABLE 4
#pragma warning (disable:4786)
#include <string.h>
#include "CTools.h"
#include <iostream>
using namespace std;
#include <string>

//有Label Edit Button抽象出这些类中公有属性+行为-->控件基类
class CtrlBase
{
public:
	CtrlBase(int x,int y,int width, int height,int ctrlType, string content);
	~CtrlBase();
	virtual void show();	//显示函数
	virtual void editKeyListen(char ch);	
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	string getContent();	//显示内容
	void setContent(string ch);
	int getCtrlType();
protected:
	int x,y,width,height;
	string content;
	int ctrlType;			//控件类型	
private:
};


#endif