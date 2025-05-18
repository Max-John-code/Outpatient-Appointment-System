#include "CStaff.h"
#include "string.h"	
#include "CTools.h"
#include <iostream>
#include "CData.h"
#include <list>
using namespace std;
#include <string>

//memset
//普通构造函数 可以通过传参的方式为成员赋值
CStaff::CStaff(string phoneId, string name, string pwd, int num, string IdCard, string Info)
{
	this->phoneId = phoneId;
	this->name = name;
	this->pwd = pwd;
	this->num = num;
	this->IdCard = IdCard;
	this->Info = Info;
}

string CStaff::getPhoneId()
{
	return this->phoneId;
}

string CStaff::getName()
{
	return this->name;
}

string CStaff::getPwd()
{
	return this->pwd;	
}

int CStaff::getNum()
{
	return this->num;
}

string CStaff::getIdCard()
{
	return this->IdCard;
}

string CStaff::getInfo()
{
	return this->Info;
}


void CStaff::setName(string name)
{
	this->name = name;
}

void CStaff::setPwd (string pwd)
{
	this->pwd = pwd;
}

void CStaff::setIdCard(string IdCard)
{
	this->IdCard = IdCard;
}