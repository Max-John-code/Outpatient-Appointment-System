#ifndef _CSTAFF_H_
#define _CSTAFF_H_
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string>
//宏定义 role
/*#define ADMIN 1
#define MANAGER 2
#define WAITER 3*/
//员工类 成员变量：id name pwd role
//公有：id name role
//类定义：class 类名（首字母大写）{};
class CStaff
{	
public:
	//普通构造函数 2个及以上参数组成
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
	//成员变量
	string phoneId;			//手机号
	string name;
	string pwd;
	string Info;	//就诊信息
	int num;		//取号
	string IdCard;	//身份证
};
#endif