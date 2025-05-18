#include "Appointment.h"

Appointment::Appointment(int id, string user, string yuyueday, string  day, string time, string hospital, string room,
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

string Appointment::getyuyueday()
{
	return this->yuyueday;
}

string Appointment::getSuggest()
{
	return this->suggest;
}

void Appointment::setState(string str)
{
	this->state = str;
}

void Appointment::setSuggest(string str)
{
	this->suggest = str;
}

int Appointment::getId()
{
	return this->id;
}

string Appointment::getUser()
{
	return this->user;
}

string Appointment::getDay()
{
	return this->day;
}

string Appointment::getTime()
{
	return this->time;
}

string Appointment::getHospital()
{
	return this->hospital;
}

string Appointment::getRoom()
{
	return this->room;
}

string Appointment::getDoctor()
{
	return this->doctor;
}

string Appointment::getInfo()
{
	return this->Info;
}

string Appointment::getState()
{
	return this->state;
}