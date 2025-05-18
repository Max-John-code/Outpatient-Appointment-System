#include "CData.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

map<string, CStaff *> CData::staffMap;	//员工列表
CStaff * CData::nowStaff=NULL;		//当前登录
map<string, CDoctor*> CData::doctorMap;	//医生列表
vector<Appointment*> CData::appointmentVector;//预约容器
CDoctor* CData::nowDoctor = NULL;		//当前医生
map<string, CKRoom*> CData::kroomMap ;				//科室容器
vector<CDiagnose*> CData::diagnoseVector;		//就诊容器


void CData::doctor_init()
{
	//1.文件中无内容初始化内容
	//2.文件有内容获取内容
	fstream fd;
	fd.open("./Data//doctor.txt", ios::in|ios::out|ios::app);
	//计算一下文件的大小哈
	fd.seekp(0,ios::end);
	streampos count = fd.tellg();
	if((int)count<=0)//如果文件大小为0
	{
		cout <<"文件无数据" << endl;
		CData::doctorMap["D1001"] = new CDoctor("D1001","陈芹","123456", "内科", "主治医师", "省立医院", "专家");
		CData::doctorMap["D1002"] = new CDoctor("D1002","林辉","123456", "外科", "副主任医师", "省立医院", "精通外科");
		CData::doctorMap["D1003"] = new CDoctor("D1003","张静雯","123456", "眼科", "副主任医师", "省立医院", "资深眼科");
		CData::doctorMap["D1004"] = new CDoctor("D1004", "潇潇", "123456", "皮肤科", "专家", "省立医院", "学识渊博");
		CData::doctorMap["D1005"] = new CDoctor("D1005", "乌云", "123456", "口腔科", "主任医师", "省立医院", "口腔科万事通");

		map<string, CDoctor*>::iterator it;
		for(it = CData::doctorMap.begin();it!=CData::doctorMap.end();++it)
		{
			cout << it->second->getPosition();
			system("pause");
			fd << it->first << " " << it->second->getName() << " " << it->second->getPwd() << " " << it->second->getRoom() << " " << it->second->getPosition() << " " << it->second->getHospital() << " " << it->second->getInfo() << endl;

		}
	}//文件已经存在
	else
	{
		cout << "文件有数据" << endl;
		char buf[256] = {0};
		//定位到开头
		fd.seekg(0, ios::beg);
		char id[20] = {0},name[20]={0},pwd[20]={0},room[20]={0},Info[20]={0},hospital[20]={0}, position[20] = {0};
		while(fd.peek()!=EOF)
		{
			//逐行读取
			fd.getline(buf, 256);
			//cout <<buf;
			//字符串分割
			sscanf(buf, "%s %s %s %s %s %s %s", id, name ,pwd, position, room, hospital, Info);
			//cout << staffid << "-" << name << "-" << pwd <<"-"<< role << endl;
			//从文件中获取数据写入list中
			CData::doctorMap[string(id)] = new CDoctor(id, name, pwd, position, room, hospital, Info);
		}
		//字符串分割
	}
	fd.close();
}

void CData::staff_init()
{
	//1.文件中无内容初始化内容
	//2.文件有内容获取内容
	fstream fs;
	fs.open("./Data//staff.txt", ios::in|ios::out|ios::app);
	//计算一下文件的大小哈
	fs.seekp(0,ios::end);
	streampos count = fs.tellg();
	if((int)count<=0)//如果文件大小为0
	{
		cout <<"文件无数据" << endl;
		CData::staffMap["15020232024"] = new CStaff("15020232024", "许烨", "123456", 0, "123456789695842367", "健康");
		CData::staffMap.insert(make_pair(string("13285984528"), new CStaff("13285984528", "琳琳", "123456", 0, "123456789111213144", "健康")));
		CData::staffMap.insert(pair<string, CStaff*>(string("18250772440"), new CStaff("18250772440", "莉莉", "123456", 3004, "987654311144232562", "患病")));

		//初始化完了之后就要写到文件里面
		map<string, CStaff*>::iterator it;
		for(it = CData::staffMap.begin();it!=CData::staffMap.end();++it)
		{
		//	cout <<(*it)->getId() << " " << (*it)->getName() << " " << (*it)->getPwd() << " " << (*it)->getRole() << endl;
			fs << it->first << " " << it->second->getName() << " " << it->second->getPwd() << " " << it->second->getNum() << " " << it->second->getIdCard() << " " << it->second->getInfo() << endl;

		}
	}
	else{
		cout << "文件有数据" << endl;
		char buf[256] = {0};
		//定位到开头
		fs.seekg(0, ios::beg);
		int num=0;
		char phoneId[20] = {0},name[10] = {0}, pwd[10] = {0}, Info[10] = {0}, IdCard[20] = {0};
		while(fs.peek()!=EOF)
		{
			//逐行读取
			fs.getline(buf, 256);
			//cout <<buf;
			//字符串分割
			sscanf(buf, "%s %s %s %d %s %s", phoneId, name ,pwd, &num, IdCard, Info);
			//cout << staffid << "-" << name << "-" << pwd <<"-"<< role << endl;
			//从文件中获取数据写入list中
			CData::staffMap[string(phoneId)] = new CStaff(phoneId, name, pwd, num, IdCard, Info);
		}
		//字符串分割
	}
	fs.close();

}
//添加新用户
void CData::addStaff(CStaff * newstaff)
{
	fstream fs;				//out::写入文件 app:追加文件
	fs.open("./Data//staff.txt", ios::in|ios::out |ios ::app);
	//移动到文件末尾
	fs.seekg(0, ios::end);
	fs << newstaff->getPhoneId() << " " << newstaff->getName() << " " << newstaff->getPwd() << " " << newstaff->getNum() << " " << newstaff->getIdCard() << " " << newstaff->getInfo() << endl;
	fs.close();
}

//添加新医生
void CData::addDoctor(CDoctor* newdoctor)
{
	fstream fd;
	fd.open("./Data//doctor.txt", ios::in|ios::out|ios::app);
	//移动到文件末尾
	fd.seekg(0,ios::end);
	fd << newdoctor->getId() << " " << newdoctor->getName() << " " << newdoctor->getPwd() << " " << newdoctor->getRoom() << " " << newdoctor->getPosition() << " " << newdoctor->getHospital() << " " << newdoctor->getInfo() << endl;
	fd.close();
}


//用户文件更新
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

//医生文件更新
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
	//移动到文件末尾
	fa.seekg(0, ios::end);

	fa << app1->getId() << " " << app1->getUser() << " " << app1->getyuyueday() << " " << app1->getDay() << " " << app1->getTime() << " " << app1->getHospital() << " " << app1->getRoom() << " " << app1->getDoctor() << " " << app1->getInfo() << " " << app1->getSuggest()<< " " << app1->getState() << endl; 
	fa.close();
}

void CData::appointment_init()
{
	//1.文件中无内容就结束
	//2.文件有内容就获取内容
	fstream fa;
	fa.open("./Data//appointment.txt", ios::in|ios::out|ios::app);
	//计算一下文件的大小哈
	fa.seekp(0,ios::end);
	streampos count = fa.tellg();
	if((int)count<=0)//如果文件大小为0
	{
		cout << "当前没有任何预约信息";
		return ;		
	}

	else
	{
		cout << "文件有数据" << endl;
		char buf[256] = {0};
		//定位到开头
		fa.seekg(0, ios::beg);
		int id=0;
		char user[20] = {0},day[20] = {0}, time[20] = {0}, Info[20] = {0}, hospital[20] = {0};
		char doctor[20] = {0},room[20] = {0}, state[20] = {0}, yuyueday[20] = {0}, suggest[20] = {0};
		while(fa.peek()!=EOF)
		{
			//逐行读取
			fa.getline(buf, 256);
			//cout <<buf;
			//字符串分割
			sscanf(buf, "%d %s %s %s %s %s %s %s %s %s %s", &id, user ,yuyueday, day, time, hospital, room, doctor, Info, suggest, state);
			//cout << staffid << "-" << name << "-" << pwd <<"-"<< role << endl;
			//从文件中获取数据写入vector中
			CData::appointmentVector.push_back(new Appointment(id, user ,yuyueday, day, time, hospital, room, doctor, Info, suggest, state));
		}
	}
	fa.close();
}

//预约文件更新
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


//就诊类的初始化
void CData::diagnose_init()
{
	//1.文件中无内容就结束
	//2.文件有内容就获取内容
	fstream fa;
	fa.open("./Data//diagnose.txt", ios::in|ios::out|ios::app);
	//计算一下文件的大小哈
	fa.seekp(0,ios::end);
	streampos count = fa.tellg();
	if((int)count<=0)//如果文件大小为0
	{
		cout << "当前没有任何预约信息";
		return ;		
	}

	else
	{
		cout << "文件有数据" << endl;
		char buf[256] = {0};
		//定位到开头
		fa.seekg(0, ios::beg);
		int id=0;
		char user[20] = {0},day[20] = {0}, time[20] = {0}, Info[20] = {0}, hospital[20] = {0};
		char doctor[20] = {0},room[20] = {0}, state[20] = {0}, yuyueday[20] = {0}, suggest[20] = {0};
		while(fa.peek()!=EOF)
		{
			//逐行读取
			fa.getline(buf, 256);
			//cout <<buf;
			//字符串分割
			sscanf(buf, "%d %s %s %s %s %s %s %s %s %s %s", &id, user ,yuyueday, day, time, hospital, room, doctor, Info, suggest, state);
			//cout << staffid << "-" << name << "-" << pwd <<"-"<< role << endl;
			//从文件中获取数据写入vector中
			CData::diagnoseVector.push_back(new CDiagnose(id, user ,yuyueday, day, time, hospital, room, doctor, Info, suggest, state));
		}
	}
	fa.close();
}

//添加就诊
void CData::adddiagnoseVector(CDiagnose* dia)
{
	fstream fa;
	fa.open("./Data/diagnose.txt", ios::out|ios::in|ios ::app);
	//移动到文件末尾
	fa.seekg(0, ios::end);

	fa << dia->getId() << " " << dia->getUser() << " " << dia->getyuyueday() << " " << dia->getDay() << " " << dia->getTime() << " " << dia->getHospital() << " " << dia->getRoom() << " " << dia->getDoctor() << " " << dia->getInfo() << " " << dia->getSuggest()<< " " << dia->getState() << endl; 
	fa.close();
}

//更新就诊
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
	//1.文件中无内容就结束
	//2.文件有内容就获取内容
	fstream fk;
	fk.open("./Data//kroom.txt", ios::in|ios::out|ios::app);
	//计算一下文件的大小哈
	fk.seekp(0,ios::end);
	streampos count = fk.tellg();
	if((int)count<=0)//如果文件大小为0
	{
		cout << "当前没有任何科室";
		CData::kroomMap["k1001"] = new CKRoom("k1001","内科", "药物治疗");
		CData::kroomMap.insert(make_pair(string("k1002"), new CKRoom("k1002", "外科", "手术治疗")));
		CData::kroomMap.insert(pair<string, CKRoom*>(string("k1003"), new CKRoom("k1003", "皮肤科", "皮肤疾病")));
		CData::kroomMap["k1004"] = new CKRoom("k1004","眼科", "眼病专科");
		CData::kroomMap["k1005"] = new CKRoom("k1005","口腔科", "口腔疾病");

		//初始化完了之后就要写到文件里面
		map<string, CKRoom*>::iterator it;
		for(it = CData::kroomMap.begin();it!=CData::kroomMap.end();++it)
		{
		//	cout <<(*it)->getId() << " " << (*it)->getName() << " " << (*it)->getPwd() << " " << (*it)->getRole() << endl;
			fk << it->first << " " << it->second->getName() << " " << it->second->getInfo() << endl;

		}		
	}

	else
	{
		cout << "文件有数据" << endl;
		char buf[256] = {0};
		//定位到开头
		fk.seekg(0, ios::beg);
		char id[20] = {0},name[20] = {0},Info[20] = {0};
		while(fk.peek()!=EOF)
		{
			//逐行读取
			fk.getline(buf, 256);
			//cout <<buf;
			//字符串分割
			sscanf(buf, "%s %s %s", id, name ,Info);
			//cout << staffid << "-" << name << "-" << pwd <<"-"<< role << endl;
			//从文件中获取数据写入vector中
			CData::kroomMap[string(id)] = new CKRoom(id, name, Info);
		}
	}
	fk.close();
}