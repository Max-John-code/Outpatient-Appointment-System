#pragma warning (disable:4786)
#ifndef _CDATA_H_
#define _CDATA_H_
#include <iostream>
using namespace std;
#include "CStaff.h"
#include "CDoctor.h"
#include "Appointment.h"
#include <list>
#include <map>
#include <vector>
#include "CKRoom.h"
#include "CDiagnose.h"

class CData{
public:	//静态成员	数据共享	员工、菜品、台桌、订单
	
	
	//---------------用户的
	static void staff_init();
	static CStaff * nowStaff;	//当前用户
	static map<string, CStaff *> staffMap;	//用户
	static void addStaff(CStaff * newstaff);//添加用户
	static void updataStaff();	//更新用户
	
	//---------------医生的
	static void doctor_init();	//初始化
	static map<string, CDoctor*> doctorMap;	//医生
	static CDoctor* nowDoctor;	//当前医生
	static void updataDoctor();	//更新医生
	static void addDoctor(CDoctor* newdoctor);//添加医生

	//预约类
	static vector<Appointment*> appointmentVector;
	static void addAppointment(Appointment* app1);
	static void appointment_init();		//初始化
	static void updataAppointment();	//更新预约类

	//就诊类
	static vector<CDiagnose*> diagnoseVector;
	static void adddiagnoseVector(CDiagnose* dia);	//添加
	static void diagnose_init();
	static void updataDiagnose();		//更新就诊

	//科室类
	static void kroom_init();
	static map<string, CKRoom*> kroomMap;	//科室
	static void addKRoom();			//添加科室

//	static map<int, CStaff*> staffMap;
};


#endif