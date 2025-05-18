#include "CButton.h"
#include <iostream>
using namespace std;

Button::Button(int x,int y,int width, int height, 
			   string content):CtrlBase(x, y, width, height, BUTTON, content)
			
{

}
Button::~Button()
{
	
}

void Button::show()			//ÖØÐ´
{
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	CTools::gotoxy(this->x+2, this->y+1);
	cout << this->content;
}
