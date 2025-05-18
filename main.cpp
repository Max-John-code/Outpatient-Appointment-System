#pragma warning (disable:4786)
#include <iostream>

#include "CtrlBase.h"
#include "CEditbox.h"
#include "CButton.h"
#include "CLoginWin.h"
#include "CAdminWin.h"
#include "CData.h"
#include "CManagerWin.h"
#include "CWaiterWin.h"
#include "CSignupWin.h"
#include "mainWin.h"
#include "CStaffWin.h"
#include "CPullDown.h"
#include "CManagerWin.h"
#include "CSignupWin.h"
#include "CDoctorWin.h"
#include "CStaffPersonalCenterWin.h"
#include "CStaffAmendInfoWin.h"
#include "CStaffAmendPwdWin.h"
#include "CStaffAppointmentManagerWin.h"
#include "CStaffOutpatientWin.h"
#include "CAdminSearchStaffWin.h"
#include "CAdminManageDoctorWin.h"
#include "CAddDoctorWin.h"
#include "CAdminSearchDoctorWin.h"
#include "CAdminSearchRoomWin.h"
#include "CStaffGetNumWin.h"
#include "CDoctorSearchStaffWin.h"
#include "CDoctorWriteWin.h"
#include <time.h>
#include "CStaffSearchDiagnoseWin.h"
#include "CDoctorAmendPwdWin.h"
#include <vector>
using namespace std;


//������������û���ҽ���Ͷ����ǽ��и��ģ�Ȼ����Ե�showWin���»�ȡ��������
bool addStaff = false;
bool addDoctor = false;
bool addAppointment = false;
bool addGetNumD = false;
bool addGetNumS = false;

int main()
{
	srand(time(NULL));	//time��rand()����д�ڲ�ͬ��cpp�ļ������һ������ֻ����һ��srand(time(NULL))����������ֱ�ӷ���main����������ֻʹ��һ��
	CData::appointment_init();		
/*	vector<Appointment*> ::iterator it;
	for(it = CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		cout <<(*it)->getDoctor();
	system("pause");*/
	CData::doctor_init();
	CData::staff_init();//���ݳ�ʼ��
	CData::kroom_init();
	//Ŀǰʵ���˽�����л����������2���û�
	//admins 123456	���ǹ���Ա����
	//lily 123456		���Ǿ������
	int p = 0;

	vector<CWindow*> winArr;
	winArr.push_back(new mainWin(10,5,60,30));		//0
	winArr.push_back(new loginWin(10,5,60,30));		//1
	winArr.push_back(new CStaffWin(10,5,60,30));	//2
	winArr.push_back(new AdminWin(10,5,60,30));	//3				//����Ա����
	winArr.push_back(new CDoctorWin(10,5,60,30));	//4
	winArr.push_back(new CSignupWin(10,5,60,30));	//5
	winArr.push_back(new CStaffPersonalCenterWin(10,5,60,30));		//6�û�����
	winArr.push_back(new CStaffAmendInfoWin(10,5,60,30));			//7��Ϣ����
	winArr.push_back(new CStaffAmendPwdWin(10,5,60,30));			//8�û��޸�����
	winArr.push_back(new CStaffAppointmentManagerWin(10,5,60,30));	//9�û�ԤԼ��������
	winArr.push_back(new CStaffOutpatientWin(10,5,60,30));			//10ԤԼ�������
	winArr.push_back(new CAdminSearchStaffWin(10,5,60,30));			//11����Ա��ѯ�û�
	winArr.push_back(new CAdminManageDoctorWin(10,5,60,30));		//12����Աҽ������������
	winArr.push_back(new CAddDoctorWin(10,5,60,30));				//13����ҽ������
	winArr.push_back(new CAdminSearchDoctorWin(1,5,80,30));		//14����Ա��ѯҽ����ѯ����
	winArr.push_back(new CAdminSearchRoomWin(10,5,60,30));		//15���Ҳ�ѯ����
	winArr.push_back(new CStaffGetNumWin(1,5,110,30));			//16�û�ȡ�Ž���
	winArr.push_back(new CDoctorSearchStaffWin(10,5,60,30));		//17ҽ���������
//	winArr.push_back(new CDoctorWriteWin(10,5,60,30));			//18��д�������
	winArr.push_back(new CStaffSearchDiagnoseWin(1,5,80,30));		//18�û��������
	//	CTools::paintTable(10,5,3,10,15);
	winArr.push_back(new CDoctorAmendPwdWin(10,5,60,30));
	while(1){
		winArr[p]->showWin();
		winArr[p]->winRun();
		p = winArr[p]->doAction();
	}
/*	CAdminSearchStaffWin* w1 = new CAdminSearchStaffWin(10,5,60,30);
	while(1){
		w1->showWin();
		w1->winRun();
		w1->doAction();
	}	*/
		return 0;
}