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

//��Label Edit Button�������Щ���й�������+��Ϊ-->�ؼ�����
class CtrlBase
{
public:
	CtrlBase(int x,int y,int width, int height,int ctrlType, string content);
	~CtrlBase();
	virtual void show();	//��ʾ����
	virtual void editKeyListen(char ch);	
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	string getContent();	//��ʾ����
	void setContent(string ch);
	int getCtrlType();
protected:
	int x,y,width,height;
	string content;
	int ctrlType;			//�ؼ�����	
private:
};


#endif