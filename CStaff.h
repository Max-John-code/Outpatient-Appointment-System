#ifndef _CSTAFF_H_
#define _CSTAFF_H_
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string>
//�궨�� role
/*#define ADMIN 1
#define MANAGER 2
#define WAITER 3*/
//Ա���� ��Ա������id name pwd role
//���У�id name role
//�ඨ�壺class ����������ĸ��д��{};
class CStaff
{	
public:
	//��ͨ���캯�� 2�������ϲ������
	CStaff(string phoneId, string name, string pwd, int num, string IdCard, string Info);

	string getPhoneId();
	string getName();
	string getPwd();
	string getIdCard();
	int getNum();
	string getInfo();;
	void setName(string name);
	void setPwd(string pwd);
	void setIdCard(string IdCard);
private:
	//��Ա����
	string phoneId;			//�ֻ���
	string name;
	string pwd;
	string Info;	//������Ϣ
	int num;		//ȡ��
	string IdCard;	//���֤
};
#endif