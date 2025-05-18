#include "CData.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

map<string, CStaff *> CData::staffMap;	//Ա���б�
CStaff * CData::nowStaff=NULL;		//��ǰ��¼
map<string, CDoctor*> CData::doctorMap;	//ҽ���б�
vector<Appointment*> CData::appointmentVector;//ԤԼ����
CDoctor* CData::nowDoctor = NULL;		//��ǰҽ��
map<string, CKRoom*> CData::kroomMap ;				//��������
vector<CDiagnose*> CData::diagnoseVector;		//��������


void CData::doctor_init()
{
	//1.�ļ��������ݳ�ʼ������
	//2.�ļ������ݻ�ȡ����
	fstream fd;
	fd.open("./Data//doctor.txt", ios::in|ios::out|ios::app);
	//����һ���ļ��Ĵ�С��
	fd.seekp(0,ios::end);
	streampos count = fd.tellg();
	if((int)count<=0)//����ļ���СΪ0
	{
		cout <<"�ļ�������" << endl;
		CData::doctorMap["D1001"] = new CDoctor("D1001","����","123456", "�ڿ�", "����ҽʦ", "ʡ��ҽԺ", "ר��");
		CData::doctorMap["D1002"] = new CDoctor("D1002","�ֻ�","123456", "���", "������ҽʦ", "ʡ��ҽԺ", "��ͨ���");
		CData::doctorMap["D1003"] = new CDoctor("D1003","�ž���","123456", "�ۿ�", "������ҽʦ", "ʡ��ҽԺ", "�����ۿ�");
		CData::doctorMap["D1004"] = new CDoctor("D1004", "����", "123456", "Ƥ����", "ר��", "ʡ��ҽԺ", "ѧʶԨ��");
		CData::doctorMap["D1005"] = new CDoctor("D1005", "����", "123456", "��ǻ��", "����ҽʦ", "ʡ��ҽԺ", "��ǻ������ͨ");

		map<string, CDoctor*>::iterator it;
		for(it = CData::doctorMap.begin();it!=CData::doctorMap.end();++it)
		{
			cout << it->second->getPosition();
			system("pause");
			fd << it->first << " " << it->second->getName() << " " << it->second->getPwd() << " " << it->second->getRoom() << " " << it->second->getPosition() << " " << it->second->getHospital() << " " << it->second->getInfo() << endl;

		}
	}//�ļ��Ѿ�����
	else
	{
		cout << "�ļ�������" << endl;
		char buf[256] = {0};
		//��λ����ͷ
		fd.seekg(0, ios::beg);
		char id[20] = {0},name[20]={0},pwd[20]={0},room[20]={0},Info[20]={0},hospital[20]={0}, position[20] = {0};
		while(fd.peek()!=EOF)
		{
			//���ж�ȡ
			fd.getline(buf, 256);
			//cout <<buf;
			//�ַ����ָ�
			sscanf(buf, "%s %s %s %s %s %s %s", id, name ,pwd, position, room, hospital, Info);
			//cout << staffid << "-" << name << "-" << pwd <<"-"<< role << endl;
			//���ļ��л�ȡ����д��list��
			CData::doctorMap[string(id)] = new CDoctor(id, name, pwd, position, room, hospital, Info);
		}
		//�ַ����ָ�
	}
	fd.close();
}

void CData::staff_init()
{
	//1.�ļ��������ݳ�ʼ������
	//2.�ļ������ݻ�ȡ����
	fstream fs;
	fs.open("./Data//staff.txt", ios::in|ios::out|ios::app);
	//����һ���ļ��Ĵ�С��
	fs.seekp(0,ios::end);
	streampos count = fs.tellg();
	if((int)count<=0)//����ļ���СΪ0
	{
		cout <<"�ļ�������" << endl;
		CData::staffMap["15020232024"] = new CStaff("15020232024", "����", "123456", 0, "123456789695842367", "����");
		CData::staffMap.insert(make_pair(string("13285984528"), new CStaff("13285984528", "����", "123456", 0, "123456789111213144", "����")));
		CData::staffMap.insert(pair<string, CStaff*>(string("18250772440"), new CStaff("18250772440", "����", "123456", 3004, "987654311144232562", "����")));

		//��ʼ������֮���Ҫд���ļ�����
		map<string, CStaff*>::iterator it;
		for(it = CData::staffMap.begin();it!=CData::staffMap.end();++it)
		{
		//	cout <<(*it)->getId() << " " << (*it)->getName() << " " << (*it)->getPwd() << " " << (*it)->getRole() << endl;
			fs << it->first << " " << it->second->getName() << " " << it->second->getPwd() << " " << it->second->getNum() << " " << it->second->getIdCard() << " " << it->second->getInfo() << endl;

		}
	}
	else{
		cout << "�ļ�������" << endl;
		char buf[256] = {0};
		//��λ����ͷ
		fs.seekg(0, ios::beg);
		int num=0;
		char phoneId[20] = {0},name[10] = {0}, pwd[10] = {0}, Info[10] = {0}, IdCard[20] = {0};
		while(fs.peek()!=EOF)
		{
			//���ж�ȡ
			fs.getline(buf, 256);
			//cout <<buf;
			//�ַ����ָ�
			sscanf(buf, "%s %s %s %d %s %s", phoneId, name ,pwd, &num, IdCard, Info);
			//cout << staffid << "-" << name << "-" << pwd <<"-"<< role << endl;
			//���ļ��л�ȡ����д��list��
			CData::staffMap[string(phoneId)] = new CStaff(phoneId, name, pwd, num, IdCard, Info);
		}
		//�ַ����ָ�
	}
	fs.close();

}
//������û�
void CData::addStaff(CStaff * newstaff)
{
	fstream fs;				//out::д���ļ� app:׷���ļ�
	fs.open("./Data//staff.txt", ios::in|ios::out |ios ::app);
	//�ƶ����ļ�ĩβ
	fs.seekg(0, ios::end);
	fs << newstaff->getPhoneId() << " " << newstaff->getName() << " " << newstaff->getPwd() << " " << newstaff->getNum() << " " << newstaff->getIdCard() << " " << newstaff->getInfo() << endl;
	fs.close();
}

//�����ҽ��
void CData::addDoctor(CDoctor* newdoctor)
{
	fstream fd;
	fd.open("./Data//doctor.txt", ios::in|ios::out|ios::app);
	//�ƶ����ļ�ĩβ
	fd.seekg(0,ios::end);
	fd << newdoctor->getId() << " " << newdoctor->getName() << " " << newdoctor->getPwd() << " " << newdoctor->getRoom() << " " << newdoctor->getPosition() << " " << newdoctor->getHospital() << " " << newdoctor->getInfo() << endl;
	fd.close();
}


//�û��ļ�����
void CData::updataStaff()
{
	fstream fs;
	fs.open("./Data/staff.txt", ios::out|ios::in|ios::trunc);
	fs.seekg(0,ios::beg);

	map<string,CStaff*>::iterator it;
	for(it = CData::staffMap.begin(); it!=CData::staffMap.end(); ++it)
	{
		fs << it->first << " " << it->second->getName() << " " << it->second->getPwd() << " " << it->second->getNum() << " " << it->second->getIdCard() << " " << it->second->getInfo() << endl;

	}
	fs.flush();
	fs.close();
}

//ҽ���ļ�����
void CData::updataDoctor()
{
	fstream fd;
	fd.open("./Data/doctor.txt", ios::out|ios::in|ios::trunc);
	fd.seekg(0,ios::beg);

	map<string,CDoctor*>::iterator it;
	for(it = CData::doctorMap.begin(); it!=CData::doctorMap.end(); ++it)
	{
		fd << it->first << " " << it->second->getName() << " " << it->second->getPwd() << " " << it->second->getRoom() << " " << it->second->getPosition() << " " << it->second->getHospital() << " " << it->second->getInfo() << endl;

	}
	fd.flush();
	fd.close();
}

void CData::addAppointment(Appointment* app1)
{
	fstream fa;
	fa.open("./Data/appointment.txt", ios::out|ios::in|ios ::app);
	//�ƶ����ļ�ĩβ
	fa.seekg(0, ios::end);

	fa << app1->getId() << " " << app1->getUser() << " " << app1->getyuyueday() << " " << app1->getDay() << " " << app1->getTime() << " " << app1->getHospital() << " " << app1->getRoom() << " " << app1->getDoctor() << " " << app1->getInfo() << " " << app1->getSuggest()<< " " << app1->getState() << endl; 
	fa.close();
}

void CData::appointment_init()
{
	//1.�ļ��������ݾͽ���
	//2.�ļ������ݾͻ�ȡ����
	fstream fa;
	fa.open("./Data//appointment.txt", ios::in|ios::out|ios::app);
	//����һ���ļ��Ĵ�С��
	fa.seekp(0,ios::end);
	streampos count = fa.tellg();
	if((int)count<=0)//����ļ���СΪ0
	{
		cout << "��ǰû���κ�ԤԼ��Ϣ";
		return ;		
	}

	else
	{
		cout << "�ļ�������" << endl;
		char buf[256] = {0};
		//��λ����ͷ
		fa.seekg(0, ios::beg);
		int id=0;
		char user[20] = {0},day[20] = {0}, time[20] = {0}, Info[20] = {0}, hospital[20] = {0};
		char doctor[20] = {0},room[20] = {0}, state[20] = {0}, yuyueday[20] = {0}, suggest[20] = {0};
		while(fa.peek()!=EOF)
		{
			//���ж�ȡ
			fa.getline(buf, 256);
			//cout <<buf;
			//�ַ����ָ�
			sscanf(buf, "%d %s %s %s %s %s %s %s %s %s %s", &id, user ,yuyueday, day, time, hospital, room, doctor, Info, suggest, state);
			//cout << staffid << "-" << name << "-" << pwd <<"-"<< role << endl;
			//���ļ��л�ȡ����д��vector��
			CData::appointmentVector.push_back(new Appointment(id, user ,yuyueday, day, time, hospital, room, doctor, Info, suggest, state));
		}
	}
	fa.close();
}

//ԤԼ�ļ�����
void CData::updataAppointment()
{
	fstream fa;
	fa.open("./Data/appointment.txt", ios::out|ios::in|ios::trunc);
	fa.seekg(0,ios::beg);

	vector<Appointment*>::iterator it;
	for(it = CData::appointmentVector.begin(); it!=CData::appointmentVector.end(); ++it)
	{
		fa << (*it)->getId() << " " << (*it)->getUser() << " " << (*it)->getyuyueday() << " " << (*it)->getDay() << " " << (*it)->getTime() << " " << (*it)->getHospital() << " " << (*it)->getRoom() << " " << (*it)->getDoctor() << " " << (*it)->getInfo() << " " << (*it)->getSuggest()<< " " << (*it)->getState() << endl; 
	}
	fa.flush();
	fa.close();
}


//������ĳ�ʼ��
void CData::diagnose_init()
{
	//1.�ļ��������ݾͽ���
	//2.�ļ������ݾͻ�ȡ����
	fstream fa;
	fa.open("./Data//diagnose.txt", ios::in|ios::out|ios::app);
	//����һ���ļ��Ĵ�С��
	fa.seekp(0,ios::end);
	streampos count = fa.tellg();
	if((int)count<=0)//����ļ���СΪ0
	{
		cout << "��ǰû���κ�ԤԼ��Ϣ";
		return ;		
	}

	else
	{
		cout << "�ļ�������" << endl;
		char buf[256] = {0};
		//��λ����ͷ
		fa.seekg(0, ios::beg);
		int id=0;
		char user[20] = {0},day[20] = {0}, time[20] = {0}, Info[20] = {0}, hospital[20] = {0};
		char doctor[20] = {0},room[20] = {0}, state[20] = {0}, yuyueday[20] = {0}, suggest[20] = {0};
		while(fa.peek()!=EOF)
		{
			//���ж�ȡ
			fa.getline(buf, 256);
			//cout <<buf;
			//�ַ����ָ�
			sscanf(buf, "%d %s %s %s %s %s %s %s %s %s %s", &id, user ,yuyueday, day, time, hospital, room, doctor, Info, suggest, state);
			//cout << staffid << "-" << name << "-" << pwd <<"-"<< role << endl;
			//���ļ��л�ȡ����д��vector��
			CData::diagnoseVector.push_back(new CDiagnose(id, user ,yuyueday, day, time, hospital, room, doctor, Info, suggest, state));
		}
	}
	fa.close();
}

//��Ӿ���
void CData::adddiagnoseVector(CDiagnose* dia)
{
	fstream fa;
	fa.open("./Data/diagnose.txt", ios::out|ios::in|ios ::app);
	//�ƶ����ļ�ĩβ
	fa.seekg(0, ios::end);

	fa << dia->getId() << " " << dia->getUser() << " " << dia->getyuyueday() << " " << dia->getDay() << " " << dia->getTime() << " " << dia->getHospital() << " " << dia->getRoom() << " " << dia->getDoctor() << " " << dia->getInfo() << " " << dia->getSuggest()<< " " << dia->getState() << endl; 
	fa.close();
}

//���¾���
void CData::updataDiagnose()
{
	fstream fa;
	fa.open("./Data/diagnose.txt", ios::out|ios::in|ios::trunc);
	fa.seekg(0,ios::beg);

	vector<CDiagnose*>::iterator it;
	for(it = CData::diagnoseVector.begin(); it!=CData::diagnoseVector.end(); ++it)
	{
		fa << (*it)->getId() << " " << (*it)->getUser() << " " << (*it)->getyuyueday() << " " << (*it)->getDay() << " " << (*it)->getTime() << " " << (*it)->getHospital() << " " << (*it)->getRoom() << " " << (*it)->getDoctor() << " " << (*it)->getInfo() << " " << (*it)->getSuggest()<< " " << (*it)->getState() << endl; 
	}
	fa.flush();
	fa.close();
}

void CData::kroom_init()
{
	//1.�ļ��������ݾͽ���
	//2.�ļ������ݾͻ�ȡ����
	fstream fk;
	fk.open("./Data//kroom.txt", ios::in|ios::out|ios::app);
	//����һ���ļ��Ĵ�С��
	fk.seekp(0,ios::end);
	streampos count = fk.tellg();
	if((int)count<=0)//����ļ���СΪ0
	{
		cout << "��ǰû���κο���";
		CData::kroomMap["k1001"] = new CKRoom("k1001","�ڿ�", "ҩ������");
		CData::kroomMap.insert(make_pair(string("k1002"), new CKRoom("k1002", "���", "��������")));
		CData::kroomMap.insert(pair<string, CKRoom*>(string("k1003"), new CKRoom("k1003", "Ƥ����", "Ƥ������")));
		CData::kroomMap["k1004"] = new CKRoom("k1004","�ۿ�", "�۲�ר��");
		CData::kroomMap["k1005"] = new CKRoom("k1005","��ǻ��", "��ǻ����");

		//��ʼ������֮���Ҫд���ļ�����
		map<string, CKRoom*>::iterator it;
		for(it = CData::kroomMap.begin();it!=CData::kroomMap.end();++it)
		{
		//	cout <<(*it)->getId() << " " << (*it)->getName() << " " << (*it)->getPwd() << " " << (*it)->getRole() << endl;
			fk << it->first << " " << it->second->getName() << " " << it->second->getInfo() << endl;

		}		
	}

	else
	{
		cout << "�ļ�������" << endl;
		char buf[256] = {0};
		//��λ����ͷ
		fk.seekg(0, ios::beg);
		char id[20] = {0},name[20] = {0},Info[20] = {0};
		while(fk.peek()!=EOF)
		{
			//���ж�ȡ
			fk.getline(buf, 256);
			//cout <<buf;
			//�ַ����ָ�
			sscanf(buf, "%s %s %s", id, name ,Info);
			//cout << staffid << "-" << name << "-" << pwd <<"-"<< role << endl;
			//���ļ��л�ȡ����д��vector��
			CData::kroomMap[string(id)] = new CKRoom(id, name, Info);
		}
	}
	fk.close();
}