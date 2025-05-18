#include "CStaffOutpatientWin.h"

extern bool addAppointment;

CStaffOutpatientWin::CStaffOutpatientWin(int x,int y,int width, int height)
					:CWindow(x,y,width,height)
{
	this->title = new Label(37, 12, "预约门诊");
	this->hospitalLabel = new Label(18,14,"选择医院：");
	this->roomLabel = new Label(18,17, "选择科室：");
	this->doctorLabel = new Label(18,20,"选择医生：");
	this->timeLabel = new Label(18,23,"选择时间：");
	this->InfoLabel = new Label(18,26," 描   述：");

	this->hospitalEdit = new Editbox(28,13,35,3,"省立医院", 4,1,0);
	this->roomEdit = new Editbox(28,16,31,3,"",4,1,0);
	this->doctorEdit = new Editbox(28,19,31,3,"", 4, 1, 0);
	this->dayEdit = new Editbox(28,22,14,3,"",3,1,0);
	this->timeEdit = new Editbox(45,22,14,3,"",3,1,0);
	this->InfoEdit = new Editbox(28,25,35,3,"",4,1,20);

	this->enterBtn = new Button(27,29,11,3," 确  定");
	this->backBtn = new Button(44,29,11,3," 取  消");
	this->roompull = new Button(58,16,5,3,"▼");
	this->doctorpull = new Button(58,19,5,3,"▼");
	this->daypull = new Button(41,22,5,3,"▼");
	this->timepull = new Button(58,22,5,3,"▼");


	this->addCtrl(this->title);		//0
	this->addCtrl(this->hospitalLabel);		//1
	this->addCtrl(this->roomLabel);		//2
	this->addCtrl(this->doctorLabel);		//3
	this->addCtrl(this->timeLabel);		//4
	this->addCtrl(this->InfoLabel);		//5
	this->addCtrl(this->hospitalEdit);		//6
	this->addCtrl(this->roomEdit);		//7
	this->addCtrl(this->roompull);		//8
	this->addCtrl(this->doctorEdit);		//9
	this->addCtrl(this->doctorpull);		//10
	this->addCtrl(this->dayEdit);		//11
	this->addCtrl(this->daypull);		//12
	this->addCtrl(this->timeEdit);		//13
	this->addCtrl(this->timepull);		//14		
	this->addCtrl(this->InfoEdit);	//15
	this->addCtrl(this->enterBtn);		//16
	this->addCtrl(this->backBtn);		//17

	this->roomContent.push_back("外 科");
	this->roomContent.push_back("内 科");
	this->roomContent.push_back("皮肤科");
	this->roomContent.push_back("眼 科");
	this->roomContent.push_back("口腔科");//构建科室的下拉框
	this->roomDown = new CPullDown(59,16,11,17,this->roomContent);
/*	//构建日期的下拉框
	//获取当前时间
	time_t currentTime = time(NULL);
//	time_t weekTime = currentTime;
	//将当前时间转换为本地日期和格式时间
	struct tm*localTime = localtime(&currentTime);
//	struct tm*weekTime = localtime(&weekTime);

	for(int i=1;i<=7;++i)
	{
		currentTime = currentTime+24*60*60;
		localTime = localtime(&currentTime);
		char localDay[20] = {0};		//实现sprintf需要char *
	//	string localDay = localDay2;
		sprintf(localDay, "%d%,%02d,%02d",1900+localTime->tm_year, 1+localTime->tm_mon, localTime->tm_mday );
		this->dayContent.push_back(localDay);
	}
	this->dayDown = new CPullDown(42,22,16,25,this->dayContent);*/



	//构建时间段的下拉框
	this->timeContent.push_back("8:00-11:00");
	this->timeContent.push_back("14:00-17:00");
	this->timeDown = new CPullDown(59,22,16,11,this->timeContent);

}

void CStaffOutpatientWin::showWin()
{
								//在清屏和paintWindow之后就可以打印以下内容
    							//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
	CWindow::showWin();						//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
	CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎," << CData::nowStaff->getName() << ",用户";
    CTools::gotoxy(48,10);
    CTools::printTime();
}

void CStaffOutpatientWin::clear()
{
	this->roomEdit->setContent("");
	this->doctorEdit->setContent("");
	this->dayEdit->setContent("");
	this->timeEdit->setContent("");
	this->InfoEdit->setContent("");
}

//先记录一下此时的时间，存入预约时间中
		char yuyuetime[20] = {0};

int CStaffOutpatientWin::doAction()
{
	
	int p;
	int count = 0;
	switch(this->ctrl_index){
	case 13:
		return 9;	//返回用户预约管理中心
	case 8:{				//选择科室
		this->roomDown->showWin();
		this->roomDown->winRun();
		switch(this->roomDown->doAction()){
		case 0:	
			this->roomEdit->setContent("外科");
			break;
			
		case 1:
			this->roomEdit->setContent("内科");
			break;
		case 2:
			this->roomEdit->setContent("皮肤科");
			break;
		case 3:
			this->roomEdit->setContent("眼科");
			break;
		case 4:
			this->roomEdit->setContent("口腔科");
			break;
		default:
			break;
		}
		doctorContent.clear();		//防止我按下多次科室下拉框后我的医生内容被反复添加
		map <string , CDoctor*> ::iterator it;	//科室一样就进栈
		for(it=CData::doctorMap.begin();it!=CData::doctorMap.end();it++)
		{
			if(it->second->getRoom()==this->roomEdit->getContent())
			{
				doctorContent.push_back(it->second->getName());
			}
		}
		//进栈完成后添加至下拉框
		this->doctorDown = new CPullDown(59,19,11,11,this->doctorContent);
		this->ctrl_index = 10;		//使光标移动到选择医生按钮
		return 10;		//回到自己这个界面
	}
	case 10:
		//如果科室还没有选择就不能选择医生
		if(this->roomEdit->getContent()=="")
		{
			cout <<"请先选择科室";
			system("pause");
			return 10;			//回到预约界面
		}
		this->doctorDown->showWin();
		this->doctorDown->winRun();
		p = this->doctorDown->doAction();
		this->doctorEdit->setContent(this->doctorContent[p]);
		this->ctrl_index = 12;	//使光标移动到选择日期按钮
		return 10;
	case 12:{
		//放在doAction里比放在构造里更实时，点击了我才开始计算后7天的时间
		//构建日期的下拉框
		//获取当前时间
		time_t currentTime = time(NULL);
	//	time_t weekTime = currentTime;
		//将当前时间转换为本地日期和格式时间
		struct tm*localTime = localtime(&currentTime);

		//先记录一下此时的时间，存入预约时间中
		sprintf(yuyuetime,"%d-%02d-%02d",1900+localTime->tm_year, 1+localTime->tm_mon, localTime->tm_mday );
	//	struct tm*weekTime = localtime(&weekTime);
		this->dayContent.clear();		//清空，防止多次点击导致的多次push_back
		for(int i=1;i<=7;++i)
		{
			currentTime = currentTime+24*60*60;
			localTime = localtime(&currentTime);
			char localDay[20] = {0};		//实现sprintf需要char *
		//	string localDay = localDay2;
			sprintf(localDay, "%d-%02d-%02d",1900+localTime->tm_year, 1+localTime->tm_mon, localTime->tm_mday );
			this->dayContent.push_back(localDay);
		}
		this->dayDown = new CPullDown(42,22,16,23,this->dayContent);

		//构建好下拉框后开始操作
		this->dayDown->showWin();
		this->dayDown->winRun();
		p = this->dayDown->doAction();
		this->dayEdit->setContent(this->dayContent[p]);
		this->ctrl_index = 14;		//光标移动到选择时间段按钮
		return 10;
	}
	case 14:
		this->timeDown->showWin();
		this->timeDown->winRun();
		p = this->timeDown->doAction();
		this->timeEdit->setContent(this->timeContent[p]);
		this->ctrl_index = 15;		//光标移动到Info

		return 10;
	
	case 16:{
		//信息没有填写完整无法点击确定按钮
		if(this->roomEdit->getContent().empty()||this->dayEdit->getContent().empty()||this->dayEdit->getContent().empty()||this->timeEdit->getContent().empty()||this->InfoEdit->getContent().empty())
		{
			cout <<"请将信息填写完整";
			system("pause");
			return 10;
		}
		//一个用户只能预约一天的一个时间段
		vector<Appointment*> ::iterator it;
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			//同一个用户且同一个日期同一个时间段
			if((*it)->getUser()==CData::nowStaff->getName()&&(*it)->getTime()==this->timeEdit->getContent()&&(*it)->getDay()==this->dayEdit->getContent())
			{
				cout <<"您不能重复预约一天的同一个时间段";
				system("pause");
				return 10;			//回到该页面
			}
		}
		//一个医生至多只能预约2个用户
		//根据编辑框内的医生找到同一天同一个时间段我要预约的这个医生，然后计算他已经预约的用户数
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getDoctor()==this->doctorEdit->getContent()&&(*it)->getDay()==this->dayEdit->getContent()&&this->timeEdit->getContent()==(*it)->getTime())
			{
				count ++;
			}//0 //1 //2
		}
		cout << "此医生该时间段以预约人数 "<<count;
	//	system("pause");
		if(count >= 2)//超出了2个
		{
			cout <<"该医生当前时间段已经预约满了";
			system("pause");

			return 10;		
		}

		int id;
		
		
		//遍历，实现id自增
		if(CData::appointmentVector.empty())
		{
			id = 1;
		}
		else
		{
			vector<Appointment*> ::iterator it;
			it = CData::appointmentVector.end()-1;
			id = (*it)->getId()+1;
		}
		//创建一个临时对象用于传入参数
		Appointment* app1 = new Appointment(id, CData::nowStaff->getPhoneId(),yuyuetime, this->dayEdit->getContent(),this->timeEdit->getContent(),this->hospitalEdit->getContent(),this->roomEdit->getContent(),this->doctorEdit->getContent(),this->InfoEdit->getContent(), "待医生填写建议", "未就诊");
		CData::appointmentVector.push_back(app1);
		//写入文件
		CData::addAppointment(app1);
		cout <<"预约成功";
		system("pause");
		addAppointment = true;
		this->clear();
		return 9;		//回到用户预约中心管理界面
		//
	}
	case 17:
		this->clear();
		return 9;
	}
	
		

	
	return 9;
}