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


//如果新增加了用户和医生就对他们进行更改，然后各自的showWin重新获取容器数据
bool addStaff = false;
bool addDoctor = false;
bool addAppointment = false;
bool addGetNumD = false;
bool addGetNumS = false;

int main()
{
	srand(time(NULL));	//time和rand()可以写在不同的cpp文件里，但是一个程序只能有一个srand(time(NULL))，所以这里直接放在main，整个程序只使用一次
	CData::appointment_init();		
/*	vector<Appointment*> ::iterator it;
	for(it = CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		cout <<(*it)->getDoctor();
	system("pause");*/
	CData::doctor_init();
	CData::staff_init();//数据初始化
	CData::kroom_init();
	//目前实现了界面的切换，我完成了2个用户
	//admins 123456	这是管理员界面
	//lily 123456		这是经理界面
	int p = 0;

	vector<CWindow*> winArr;
	winArr.push_back(new mainWin(10,5,60,30));		//0
	winArr.push_back(new loginWin(10,5,60,30));		//1
	winArr.push_back(new CStaffWin(10,5,60,30));	//2
	winArr.push_back(new AdminWin(10,5,60,30));	//3				//管理员界面
	winArr.push_back(new CDoctorWin(10,5,60,30));	//4
	winArr.push_back(new CSignupWin(10,5,60,30));	//5
	winArr.push_back(new CStaffPersonalCenterWin(10,5,60,30));		//6用户中心
	winArr.push_back(new CStaffAmendInfoWin(10,5,60,30));			//7信息完善
	winArr.push_back(new CStaffAmendPwdWin(10,5,60,30));			//8用户修改密码
	winArr.push_back(new CStaffAppointmentManagerWin(10,5,60,30));	//9用户预约管理中心
	winArr.push_back(new CStaffOutpatientWin(10,5,60,30));			//10预约门诊界面
	winArr.push_back(new CAdminSearchStaffWin(10,5,60,30));			//11管理员查询用户
	winArr.push_back(new CAdminManageDoctorWin(10,5,60,30));		//12管理员医生管理主界面
	winArr.push_back(new CAddDoctorWin(10,5,60,30));				//13新增医生界面
	winArr.push_back(new CAdminSearchDoctorWin(1,5,80,30));		//14管理员查询医生查询界面
	winArr.push_back(new CAdminSearchRoomWin(10,5,60,30));		//15科室查询界面
	winArr.push_back(new CStaffGetNumWin(1,5,110,30));			//16用户取号界面
	winArr.push_back(new CDoctorSearchStaffWin(10,5,60,30));		//17医生就诊界面
//	winArr.push_back(new CDoctorWriteWin(10,5,60,30));			//18填写就诊界面
	winArr.push_back(new CStaffSearchDiagnoseWin(1,5,80,30));		//18用户就诊界面
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