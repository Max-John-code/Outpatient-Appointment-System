#include "CtrlBase.h"
#include <iostream>
using namespace std;

CtrlBase::CtrlBase(int x,int y,int width, int height,int ctrlType, string content)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->ctrlType = ctrlType;
	this->content = content;

}
CtrlBase::~CtrlBase()
{
	
}

void CtrlBase::show()
{
	CTools::gotoxy(x, y);
	cout << content;
}

int CtrlBase::getX()
{
	return x;
}
int CtrlBase::getY()
{
	return y;
}
void CtrlBase::setX(int x)
{
	this->x = x;
}
void CtrlBase::setY(int y)
{
	this->y = y;
}

string CtrlBase::getContent()	//获取内容
{
	return content;
}

void CtrlBase::setContent(string ch)	//修改内容
{
	//strcpy(this->content, ch);
	this->content = ch;
}

int CtrlBase::getCtrlType()
{
	return this->ctrlType;
}

void CtrlBase::editKeyListen(char ch)
{

}