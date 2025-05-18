#include "CKRoom.h"

CKRoom::CKRoom(string id, string name, string Info)
{
	this->id = id;
	this->name = name;
	this->Info = Info;
}

string CKRoom::getId()
{
	return this->id;
}

string CKRoom::getName()
{
	return this->name;
}

string CKRoom::getInfo()
{
	return this->Info;
}