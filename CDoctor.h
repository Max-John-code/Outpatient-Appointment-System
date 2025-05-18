#ifndef _CDOCTOR_H_
#define _CDOCTOR_H_

#include <string>
using namespace std;
class CDoctor{
public:
	CDoctor(string id, string name, string pwd, string room, string position, string hospital, string Info);
	string getName();
	string getPwd();
	string getId();
	string getPosition();
	string getRoom();
	string getInfo();
	string getHospital();
	void setPwd(string pwd);
	void setPosition(string position);

private:
	string name;
	string pwd;
	string id;
	string position;
	string room;
	string Info;
	string hospital;
};

#endif