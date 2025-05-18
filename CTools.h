#pragma warning (disable:4786)
//存gotoxy,paintwindow函数
#ifndef _CTOOLS_H_
#define _CTOOLS_H_
#define KEY_UP	72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT	77
#define KEY_ENTER	13
#define KEY_ESC		7
#include<windows.h>
/*
    函数名：gotoxy(int x, int y)
    函数功能：实现光标的定位
    函数参数：x代表列，y代表行
    函数返回值：无
*/

#include<string>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class CTools{
public:
	static void gotoxy(int x, int y);
	/*
	函数名称：paintWindow
	函数作用：打印一个窗口
	函数参数：int startX,int startY    起始位置
			  int width,int height     窗口宽高
	函数返回：无
	*/
	static void paintWindow(int startX,int startY,int width,int height);
	/*
	函数名称：getKey
	函数作用：获取键盘上的值
	函数参数：无
	函数返回：无
	*/
	static void  str2charArr(string str, char *s2);
	static int str2int(string str);
	static string int2str(int num);

	static int getKey();

	static void paintTable(int startX,int startY,int row,int col, int col_width);

	static void printTime();
};
#endif