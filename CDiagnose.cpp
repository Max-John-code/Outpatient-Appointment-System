#include "CDiagnose.h"

CDiagnose::CDiagnose(int id, string user, string yuyueday, string  day, string time, string hospital, string room,
		string doctor, string Info, string suggest, string state)
{
	this->id = id;
	this->user = user;
	this->day = day;
	this->time = time;
	this->hospital = hospital;
	this->room = room;
	this->doctor = doctor;
	this->Info = Info;
	this->state = state;
	this->yuyueday = yuyueday;
	this->suggest = suggest;
}

string CDiagnose::getyuyueday()
{
	return this->yuyueday;
}

string CDiagnose::getSuggest()
{
	return this->suggest;
}

int CDiagnose::getId()
{
	return this->id;
}

string CDiagnose::getUser()
{
	return this->user;
}

string CDiagnose::getDay()
{
	return this->day;
}

string CDiagnose::getTime()
{
	return this->time;
}

string CDiagnose::getHospital()
{
	return this->hospital;
}

string CDiagnose::getRoom()
{
	return this->room;
}

string CDiagnose::getDoctor()
{
	return this->doctor;
}

string CDiagnose::getInfo()
{
	return this->Info;
}

string CDiagnose::getState()
{
	return this->state;
}