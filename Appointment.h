#pragma warning (disable:4786)
#ifndef _APPOINTMENT_H_
#define _APPOINTMENT_H_

#include <string>
using namespace std;

class Appointment{
public:
	Appointment(int id, string user, string yuyueday, string  day, string time, string hospital, string room,
		string doctor, string Info, string suggest, string state);
	int getId();
	string getUser();
	string getDay();
	string getTime();
	string getHospital();
	string getRoom();
	string getDoctor();
	string getInfo();
	string getState();
	string getSuggest();
	string getyuyueday();
	void setState(string str);
	void setSuggest(string str);
private:
	int id;
	string user;
	string yuyueday;		//完成预约那天的时间
	string day;		//预约时间
	string time;		//时间段
	string hospital;
	string room;
	string doctor;
	string Info;	//就诊信息
	string suggest;	//医生建议
	string state;	//就诊状态
};

#endif