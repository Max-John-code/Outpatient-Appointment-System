//������
#ifndef _CDIAGNOSE_H_
#define _CDIAGNOSE_H_

#include <string>
using namespace std;

class CDiagnose{
public:
	CDiagnose(int id, string user, string yuyueday, string  day, string time, string hospital, string room,
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
private:
	int id;
	string user;
	string yuyueday;		//���ԤԼ�����ʱ��
	string day;		//ԤԼʱ��
	string time;		//ʱ���
	string hospital;
	string room;
	string doctor;
	string Info;	//������Ϣ
	string suggest;	//ҽ������
	string state;	//����״̬
};

#endif