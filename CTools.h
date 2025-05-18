#pragma warning (disable:4786)
//��gotoxy,paintwindow����
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
    ��������gotoxy(int x, int y)
    �������ܣ�ʵ�ֹ��Ķ�λ
    ����������x�����У�y������
    ��������ֵ����
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
	�������ƣ�paintWindow
	�������ã���ӡһ������
	����������int startX,int startY    ��ʼλ��
			  int width,int height     ���ڿ��
	�������أ���
	*/
	static void paintWindow(int startX,int startY,int width,int height);
	/*
	�������ƣ�getKey
	�������ã���ȡ�����ϵ�ֵ
	������������
	�������أ���
	*/
	static void  str2charArr(string str, char *s2);
	static int str2int(string str);
	static string int2str(int num);

	static int getKey();

	static void paintTable(int startX,int startY,int row,int col, int col_width);

	static void printTime();
};
#endif