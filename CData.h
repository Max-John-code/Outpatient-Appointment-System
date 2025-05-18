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
public:	//��̬��Ա	���ݹ���	Ա������Ʒ��̨��������
	
	
	//---------------�û���
	static void staff_init();
	static CStaff * nowStaff;	//��ǰ�û�
	static map<string, CStaff *> staffMap;	//�û�
	static void addStaff(CStaff * newstaff);//����û�
	static void updataStaff();	//�����û�
	
	//---------------ҽ����
	static void doctor_init();	//��ʼ��
	static map<string, CDoctor*> doctorMap;	//ҽ��
	static CDoctor* nowDoctor;	//��ǰҽ��
	static void updataDoctor();	//����ҽ��
	static void addDoctor(CDoctor* newdoctor);//���ҽ��

	//ԤԼ��
	static vector<Appointment*> appointmentVector;
	static void addAppointment(Appointment* app1);
	static void appointment_init();		//��ʼ��
	static void updataAppointment();	//����ԤԼ��

	//������
	static vector<CDiagnose*> diagnoseVector;
	static void adddiagnoseVector(CDiagnose* dia);	//���
	static void diagnose_init();
	static void updataDiagnose();		//���¾���

	//������
	static void kroom_init();
	static map<string, CKRoom*> kroomMap;	//����
	static void addKRoom();			//��ӿ���

//	static map<int, CStaff*> staffMap;
};


#endif