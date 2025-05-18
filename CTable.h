#pragma warning (disable:4786)
#ifndef _CTABLE_H_
#define _CTABLE_H_

#include "CtrlBase.h"
#include <vector>
using namespace std;
#include "CTools.h"
#include <map>
#include "CData.h"
#include "Appointment.h"

class CTable:public CtrlBase{
public:
	CTable(int x,int y,int col_width, vector<string>tableHead);
	~CTable();
	//显示用户数据
	void showStaffData();
	//显示医生数据
	void showDoctorData();
	//显示科室数据
	void showKRoomData();
	//显示取号数据
	void showGetNumData();
	//医生显示就诊数据
	void showdiagnoseData();
	//用户查看就诊数据
	void showStaffDiagnoseData();
	void show();
	void showPage();
	void setpagaIndex(int d);
	void setpageAll(int d);
	int getpageIndex();
	int getpageAll();
	//用于存储的容器和迭代器
	map<string, CStaff*> ::iterator it;
	map<string, CStaff*> smap;	
	//医生的map
	map<string, CDoctor*> dmap;
	map<string, CDoctor*> ::iterator dit;
	//科室的map
	map<string, CKRoom*> kmap;
	map<string, CKRoom*> ::iterator kit;
	//预约的容器
	vector<Appointment*> avec;
	vector<Appointment*> ::iterator ait;
private:
	int col_width;
	vector <string> tableHead;
	int pageIndex;
	int pageAll;
};

#endif