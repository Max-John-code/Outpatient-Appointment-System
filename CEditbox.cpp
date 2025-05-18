#include "CEditbox.h"
#include "CTools.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <string>
using namespace std;

Editbox::Editbox(int x,int y,int width, int height,string content,int inputType, 
			int mode, int maxlen)
			:CtrlBase(x,y,width,height,EDITBOX, content)			//为父类的构造函数传参，自动调用父类的构造函数
{
	this->mode = mode;
	this->inputType = inputType;
	this->maxlen = maxlen;
}

Editbox::~Editbox()
{
	
}

int Editbox::getMode()
{
	return this->mode;
}

int Editbox::getInputType()
{
	return this->inputType;
}

int Editbox::getMaxlen()
{
	return this->maxlen;
}

void Editbox::setMaxLen(int maxlen)
{
	this->maxlen = maxlen;
}

void Editbox::show()		//从父类中定义的函数进行重定义
{
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	CTools::gotoxy(this->x+2, this->y+1);
	if(this->mode==1)
		cout << this->content;
	else
	{
		for(int i=0;i<this->content.size(); ++i)
		{
			putchar('*');
		}
	}
}

void Editbox::setMode()
{
	if(this->mode==1)
		mode = 0;
	else
		mode = 1;
}

void Editbox::editKeyListen(char ch)	//监听编辑框的输入
{
	//int len = strlen(this->content);
	int len = this->content.size();
	if((ch>='0'&&ch<='9')&&(this->inputType==1 || this->inputType==3)||
		   (ch>='a'&&ch<='z')&&(this->inputType==2 || this->inputType==3)||
		   (ch>='A'&&ch<='Z'||ch=='-')&&(this->inputType==2 || this->inputType==3))
	{
		if(len<this->maxlen)
		{
			this->mode==1?putch(ch):putch('*');
			this->content += ch;
			//this->content[len++] = ch;
			//str[len++] = ch;
		}
	}/*
	else if(ch=='\b')     //回删键
	{
		if(len>0)
		{
			printf("\b \b");
			len--;
			//删除后，要将去除的值从数组中换成'\0'
		//	str[len]='\0';
			this->content[len] = '\0';
		}
	}*/
	else if(this->inputType==4 )			//汉字2个字节
	{
		if(unsigned char (ch)>=0xA1 && unsigned char(ch)<=0xFE&&this->maxlen>0)
		{
			char ch2 = getch();			//获取第二个字节
			if(unsigned char (ch2)>=0xA1 && unsigned char(ch2)<=0xFE)
			{
				if(this->mode==1)		//明文
				{
					cout << ch <<ch2;
				}
				else if(this->mode==0)
					cout << "**";
				this->content += ch;
				this->content += ch2;
				//this->content[len++] = ch;
				//this->content[len++] = ch2;
			}
		}
		else if(ch=='\b' && len >0 &&maxlen>0)
		{
			printf("\b \b\b \b");
			this->content.erase(this->content.size()-1, 1);
			this->content.erase(this->content.size()-1, 1);
			//this->content[--len] = '\0';
			//this->content[--len] = '\0';
		}
	}
	else if(len > 0)
	{
		if(ch=='\b')
		{
			printf("\b \b");
			this->content.erase(this->content.size()-1,1);

		}
	}
}

