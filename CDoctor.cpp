#include "CDoctor.h"
#include <iostream>
using namespace std;
																			//ËùÊôÖ°Î»					¼ò½é
CDoctor::CDoctor(string id, string name, string pwd, string room, string position, string hospital, string Info)
{
	this->id = id;
	this->name = name;
	this->pwd = pwd;
	this->room = room;
	this->Info = Info;
	this->position = position;
	this->hospital = hospital;
}

string CDoctor::getId()
{
	return this->id;
}

string CDoctor::getName()
{
	return this->name;
}

string CDoctor::getPwd()
{
	return this->pwd;
}

string CDoctor::getRoom()
{
	return this->room;
}

string CDoctor::getInfo()
{
	return this->Info;
}

string CDoctor::getHospital()
{
	return this->hospital;
}

string CDoctor::getPosition()
{
	return this->position;
}

void CDoctor::setPwd(string pwd)
{
	this->pwd = pwd;
}

void CDoctor::setPosition(string position)
{
	this->position = position;
}