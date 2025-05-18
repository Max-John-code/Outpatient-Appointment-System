//科室类
#ifndef _CKROOM_H_
#define _CKROOM_H_

//#include <vector>
#include <string>
using namespace std;

class CKRoom{
public:
	CKRoom(string id, string name, string Info);
	string getId();
	string getName();
	string getInfo();
private:
	string id,name,Info;//说明
};

#endif