#include "CDoctorSearchStaffWin.h"

extern bool addGetNumD;
//医生的就诊信息查询
CDoctorSearchStaffWin::CDoctorSearchStaffWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->backBtn = new Button(18,30,7,3,"返回");
	//设置表头和表格
	vector<string>tableHead;
	tableHead.push_back("编号");
	tableHead.push_back("就诊用户ID");
	tableHead.push_back("状态");
	this->diagnoseTable = new CTable(18,16,13,tableHead);
	//设置当前页和全部页
	this->diagnoseTable->setpagaIndex(1);
	int pageAll = CData::appointmentVector.size()/3;
//	cout <<pageAll;
	pageAll += CData::appointmentVector.size()%3==0?0:1;
	this->diagnoseTable->setpageAll(pageAll);

	this->diagnoseTable->avec = CData::appointmentVector;		//默认用来打印数据的容器，一开始等于全部数据
	this->diagnoseTable->ait = this->diagnoseTable->avec.begin();	//初始迭代器为最初

	//设置三行修改的按钮
	this->oneLine = new Button (15,18,3,2,"");
	this->twoLine = new Button(15,20,3,2,"");
	this->threeLine = new Button(15,22,3,2, "");

	this->addCtrl(this->diagnoseTable);		//0
	this->addCtrl(this->oneLine);		//1		
	this->addCtrl(this->twoLine);		//2
	this->addCtrl(this->threeLine);		//3
	this->addCtrl(this->backBtn);		//4	
	
	this->writewin = new CDoctorWriteWin(10,5,60,30);
}

void CDoctorSearchStaffWin::showWin()
{
	vector<Appointment*> ::iterator it;

	if(addGetNumD)
	{
		//每次回来前对容器进行清空
		this->diagnoseTable->avec.clear();

		//找到属于自己的取号订单
		
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getDoctor()==CData::nowDoctor->getName()&&(*it)->getRoom()==CData::nowDoctor->getRoom()&&((*it)->getState()=="待就诊"||(*it)->getState()=="已就诊"))
			{
				this->diagnoseTable->avec.push_back((*it));
			}
		}	
		//设置当前页和全部页
		this->diagnoseTable->setpagaIndex(1);
		int pageAll = this->diagnoseTable->avec.size()/3;
		pageAll += this->diagnoseTable->avec.size()%3==0?0:1;
		this->diagnoseTable->setpageAll(pageAll);
		addGetNumD = false;
	}

	//当前页只有程序第一次运行的时候需要设置为1,且初始化自己最初的容器
	//标记，如果登录上来的是不同的用户，count重新置为1
	static string aa = CData::nowDoctor->getId();;
	int static count = 1;
	if(aa!=CData::nowDoctor->getId())
	{
		count = 1;
		aa = CData::nowDoctor->getId();
	}
	if(count ==1)
	{
		this->diagnoseTable->avec.clear();
		this->diagnoseTable->setpagaIndex(1);
		count = 2;
		//找到属于自己的取号订单
		
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getDoctor()==CData::nowDoctor->getName()&&(*it)->getRoom()==CData::nowDoctor->getRoom()&&((*it)->getState()=="待就诊"||(*it)->getState()=="已就诊"))
			{
				this->diagnoseTable->avec.push_back((*it));
			}
		}
	}
	//设置全部页
	int pageAll = this->diagnoseTable->avec.size()/3;
	pageAll += this->diagnoseTable->avec.size()%3==0?0:1;
	this->diagnoseTable->setpageAll(pageAll);

	//如果没有任何预约信息
	if(this->diagnoseTable->avec.size()==0)
	{
		CWindow::showWin();						//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
									//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
		CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
		cout <<"欢迎来到智能门诊预约系统";
		CTools::gotoxy(13,10);
		cout <<"欢迎," << CData::nowDoctor->getName() << ",用户";
		CTools::gotoxy(48,10);
		CTools::printTime();
		CTools::gotoxy(45,13);
		CTools::gotoxy(45,27);
		cout <<"您当前没有任何预约信息";
	}

	else{
		//我在winRun里对当前页设置好了，在doACtion里对当前页和容器都进行了重新存储，这里直接对着容器进行当前页的偏移就可以
		this->diagnoseTable->ait = this->diagnoseTable->avec.begin();
		advance(this->diagnoseTable->ait, 3*(this->diagnoseTable->getpageIndex()-1));
		CWindow::showWin();						//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
									//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
		CTools::gotoxy(45,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
		cout <<"欢迎来到智能门诊预约系统";
		CTools::gotoxy(13,10);
		cout <<"欢迎," << CData::nowDoctor->getName() << ",用户";
		CTools::gotoxy(48,10);
		CTools::printTime();
		this->diagnoseTable->showdiagnoseData();
		this->diagnoseTable->showPage();
		CTools::gotoxy(45,13);
	}
}

void CDoctorSearchStaffWin::winRun()
{
	for(int i=this->ctrl_index;i<this->ctrlArr.size();++i)
	{
		if(this->ctrlArr[i]->getCtrlType()==EDITBOX)
		{
			CTools::gotoxy(this->ctrlArr[i]->getX()+2+(this->ctrlArr[i]->getContent().size()),
				this->ctrlArr[i]->getY()+1);
			break;
		}
		else if(this->ctrlArr[i]->getCtrlType()==BUTTON)
		{
			CTools::gotoxy(this->ctrlArr[i]->getX()+2,this->ctrlArr[i]->getY()+1);
			break;
		}
	}
	int key=0;
	while(1)
	{
		key = CTools::getKey();
		//key=getch();			//key有四种情况-上下键 回车 其他
		switch(key)
		{
			case KEY_UP:
				i--;
				if(i<0)
				{
					i=this->ctrlArr.size()-1;			//防止越界
				}
				while(1)							//不知道循环多少次用while
				{
					if(this->ctrlArr[i]->getCtrlType()==EDITBOX)
					{
						CTools::gotoxy(this->ctrlArr[i]->getX()+2+(this->ctrlArr[i]->getContent().size()),this->ctrlArr[i]->getY()+1);
						break;//编辑框里可能还有文本 光标必须停在文本后面
					}
					else if(this->ctrlArr[i]->getCtrlType()==BUTTON)
					{
						CTools::gotoxy(this->ctrlArr[i]->getX()+2,this->ctrlArr[i]->getY()+1);
						break;
					}
					i--;
					if(i<0)
					{
						i=this->ctrlArr.size()-1;//防止越界
					}
				}	
			break;							//一个case结束一定要有break
		case KEY_DOWN:
				i++;
				if(i==this->ctrlArr.size())
				{
					i=0;					//防止越界
				}
				while(1)					//不知道循环多少次用while
				{
					if(this->ctrlArr[i]->getCtrlType()==EDITBOX)
					{
						CTools::gotoxy(this->ctrlArr[i]->getX()+2+(this->ctrlArr[i]->getContent().size()),this->ctrlArr[i]->getY()+1);
						break;//编辑框里可能还有文本 光标必须停在文本后面
					}
					else if(this->ctrlArr[i]->getCtrlType()==BUTTON)
					{
						CTools::gotoxy(this->ctrlArr[i]->getX()+2,this->ctrlArr[i]->getY()+1);
						break;
					}
					i++;
					if(i==this->ctrlArr.size())
					{
						i=0;				//防止越界
					}
				}	
			break;							//一个case结束一定要有break
		case KEY_ENTER:						//enter 窗口切换
			if(this->ctrlArr[i]->getCtrlType()==BUTTON)
			{
				this->ctrl_index=i;			//记录选中的按钮下标
				return ;					//窗口运行结束
			}
			break;

		//不一样的地方在这里
		case KEY_RIGHT:

			//如果页码已经最后一页，回到第一页
			if(this->diagnoseTable->getpageIndex()==this->diagnoseTable->getpageAll()){
				this->diagnoseTable->setpagaIndex(1);
				//偏移到第一页
		/*		this->userTable->it = this->userTable->smap.begin();*/
			}
			else{
				this->diagnoseTable->setpagaIndex(this->diagnoseTable->getpageIndex()+1);
				//往后移动3位
		/*		advance(this->userTable->it, 3);*/
			}

			//我只要按下一次查询按钮随后的每一次左右键，都会进行查询，这也导致我在那之后无法翻页
			//因为enter一次我的crtl_index就等于按钮的下标了，所以之后每一次进入我的doAction就会执行对应的case操作，
			//那么我在按左右键的时候将ctrl_index清零即可
			this->ctrl_index = 0;

			return ;
		case KEY_LEFT:
			//如果页码已经是第一页，回到最后一页
			if(this->diagnoseTable->getpageIndex()==1)
			{
				this->diagnoseTable->setpagaIndex(this->diagnoseTable->getpageAll());
	
			}
			else {
				this->diagnoseTable->setpagaIndex(this->diagnoseTable->getpageIndex()-1);
			}
			//我只要按下一次查询按钮随后的每一次左右键，都会进行查询，这也导致我在那之后无法翻页
			//因为enter一次我的crtl_index就等于按钮的下标了，所以之后每一次进入我的doAction就会执行对应的case操作，
//			//那么我在按左右键的时候将ctrl_index清零即可
			this->ctrl_index = 0;
			
			return ;

		default:							//其他按键
			if(this->ctrlArr[i]->getCtrlType()==EDITBOX)
			{
				this->ctrlArr[i]->editKeyListen((char)key);
			}
			break;
		}								
	}						
}

int CDoctorSearchStaffWin::doAction()
{
	int p = 0;
	this->diagnoseTable->ait = this->diagnoseTable->avec.begin();
	advance(this->diagnoseTable->ait,(this->diagnoseTable->getpageIndex()-1)*3);
	switch(this->ctrl_index)
	{
	case 1:
		this->writewin->setShowId((*this->diagnoseTable->ait)->getUser());
	//	this->writewin->setShowId("11111111111");
		this->writewin->setyuyueEdit((*this->diagnoseTable->ait)->getInfo());
		this->writewin->showWin();
		this->writewin->winRun();
		p = this->writewin->doAction();
		break;
	case 2:
		//判断是否越界
		if((this->diagnoseTable->getpageIndex()-1)*3+2 > this->diagnoseTable->avec.size())
		{
			cout <<"这一行没有数据";
			system("pause");
			break;
		}
		//先偏移
		advance(this->diagnoseTable->ait,1);
		this->writewin->setShowId((*this->diagnoseTable->ait)->getUser());
		this->writewin->setyuyueEdit((*this->diagnoseTable->ait)->getInfo());
		this->writewin->showWin();
		this->writewin->winRun();
		p = this->writewin->doAction();
		break;
	case 3:
		if(this->diagnoseTable->getpageIndex()*3 > this->diagnoseTable->avec.size())
		{
			cout <<"这一行没有数据";
			system("pause");
			break;
		}
		//先偏移
		advance(this->diagnoseTable->ait,2);
		this->writewin->setShowId((*this->diagnoseTable->ait)->getUser());
		this->writewin->setyuyueEdit((*this->diagnoseTable->ait)->getInfo());
		this->writewin->showWin();
		this->writewin->winRun();
		p = this->writewin->doAction();
		break;
	case 4:
		return 4;
	}
	switch(p)
	{
	case 5:
			(*this->diagnoseTable->ait)->setSuggest(this->writewin->getDiagnoseEidt());
		(*this->diagnoseTable->ait)->setState("已就诊");
		//更新文件
		CData::updataAppointment();
		break;
	case 6:
		break;

	}
	
	return 17;
}