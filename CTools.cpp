#include"CTools.h"
#include<string.h>
#include<conio.h>
//#include"CWindows.h"

void CTools::gotoxy(int x, int y)//形参
{
    HANDLE hOut;
    COORD pos = {x, y};
	// 光标的起始位（第1列，第3行） 0是第1列 2是第3行
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
	//printf("定位光标位置搜索(%d,%d)\n",pos.X,pos.Y);
}
void CTools::paintWindow(int startX,int startY,int width,int height)
{
	int a=0;
	//制作边框
	int i=0,j=1;
	//第一行
	gotoxy(startX,startY);
	printf("┌");
	for(i=0;i<width-2;i++)  //除去头尾两个
	{
		printf("─");
	}
	printf("┐");
	//中间
	for(j=1;j<=height-2;j++)
	{
		gotoxy(startX,startY+j);
		printf("│");
		for(i=0;i<width-2;i++)  //除去头尾两个
		{
			printf(" ");
		}
		printf("│");
	}
	//最后一行
	gotoxy(startX,startY+height-1);
	printf("└");
	for(i=0;i<width-2;i++)  //除去头尾两个
	{
		printf("─");
	}
	printf("┘");
}
int CTools::getKey()
{
	int key = 0;
	key = getch();
	if(224==key||key==-32)
	{
		key = getch();
		switch(key)
		{
		case 72:
			return KEY_UP;
		case 75:
			return KEY_LEFT;
		case 77:
			return KEY_RIGHT;
		case 80:
			return KEY_DOWN; 
		printf("%d\n", key); 
		}
	}
	else if(key==13)
	{
		return KEY_ENTER;
	}
	else if(key==27)
	{
		return KEY_ESC;
	}
	return key;
}

void CTools::paintTable(int startX,int startY,int row,int col, int col_width)
{
	int i=0,j=0,k=0,m=0, line = 0;
	CTools::gotoxy( startX, startY);
	//第一行
	printf("┌");	
	for(i=0;i<col;i++)
	{
		for(j=0;j<col_width;j++)
		{
			printf("─");
		}
		printf("┬");
	}
	printf("\b┐");
	++line;
	for(k=0;k<row;k++)
	{
		gotoxy(startX, startY+line);
		printf("│");
		for(i=0;i<col;i++)
		{
			for(j=0;j<col_width;j++)
			{
				printf(" ");
			}
			printf("│");
		}
		++line;
		gotoxy(startX, startY+line);
		printf("├");
		for(i=0;i<col;i++)
		{
			for(j=0;j<col_width;j++)
				printf("─");
			printf("┼");
		}
		printf("\b┤");
		++line;
	}
	//最后一行
	gotoxy(startX, startY+line-1);
	printf("└");
	for(i=0;i<col;i++)
	{
		for(j=0;j<col_width;j++)
		{
			printf("─");
		}
		printf("┴");
	}
	printf("\b┘");


}


void CTools::str2charArr(string str, char *s2)
{
	strcpy(s2, str.c_str());	//获取C风格的const char*数据传给char[]
}

int CTools::str2int(string str)
{
	char s2[20];
	strcpy(s2, str.c_str());	//获取C风格的const char*数据传给char[]
	return atoi(s2);
}

string CTools::int2str(int num)
{
	char s4[20];
	sprintf(s4, "%d", num);
	string s5(s4);
	return s5;
}

void CTools::printTime()
{
	time_t currentTime;	//定义存放当前时间的变量

	//获取当前时间
	currentTime = time(NULL);

	//将当前时间转换为本地日期和格式时间
	struct tm*localTime = localtime(&currentTime);
/*
	printf("当前时间：%d.%d.%d %02d:%02d:%02d\n",
		(1900+localTime->tm_year),
		(1+localTime->tm_mon),
		(localTime->tm_mday),
		localTime->tm_hour,
		localTime->tm_min,
		localTime->tm_sec);*/
	printf("当前时间：%d-%02d-%02d\n",
		(1900+localTime->tm_year),
		(1+localTime->tm_mon),
		(localTime->tm_mday));

}