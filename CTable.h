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
	//��ʾ�û�����
	void showStaffData();
	//��ʾҽ������
	void showDoctorData();
	//��ʾ��������
	void showKRoomData();
	//��ʾȡ������
	void showGetNumData();
	//ҽ����ʾ��������
	void showdiagnoseData();
	//�û��鿴��������
	void showStaffDiagnoseData();
	void show();
	void showPage();
	void setpagaIndex(int d);
	void setpageAll(int d);
	int getpageIndex();
	int getpageAll();
	//���ڴ洢�������͵�����
	map<string, CStaff*> ::iterator it;
	map<string, CStaff*> smap;	
	//ҽ����map
	map<string, CDoctor*> dmap;
	map<string, CDoctor*> ::iterator dit;
	//���ҵ�map
	map<string, CKRoom*> kmap;
	map<string, CKRoom*> ::iterator kit;
	//ԤԼ������
	vector<Appointment*> avec;
	vector<Appointment*> ::iterator ait;
private:
	int col_width;
	vector <string> tableHead;
	int pageIndex;
	int pageAll;
};

#endif