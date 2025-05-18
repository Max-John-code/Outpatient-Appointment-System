#include "CStaffSearchDiagnoseWin.h"

extern bool addGetNumS;

CStaffSearchDiagnoseWin::CStaffSearchDiagnoseWin(int x,int y,int width, int height)
							:CWindow(x,y,width,height)
{
	this->printLabel = new Label(11,13,"就诊日期");
	this->timeEdit1 = new Editbox(23,12,20,3,"", 3, 1, 10);		//2024.4.10
	this->timeEdit2 = new Editbox(48,12,20,3,"", 3, 1, 10);
	this->searchInfo = new Button(70,12,7,3,"查询");
	this->backBtn = new Button(15,27,7,3,"返回");

	//设置表头和表格
	vector<string>tableHead;
	tableHead.push_back("编号");
	tableHead.push_back("就诊时间");
	tableHead.push_back("预约医院");
	tableHead.push_back("预约科室");
	tableHead.push_back("医生");
	tableHead.push_back("就诊状态");
	this->staffDiagnoseTable = new CTable(5,16,11,tableHead);

	this->addCtrl(this->staffDiagnoseTable);		//0
	this->addCtrl(this->printLabel);	//1
	this->addCtrl(this->timeEdit1);		//2
	this->addCtrl(this->timeEdit2);		//3
	this->addCtrl(this->searchInfo);	//4
	this->addCtrl(this->backBtn);		//5
}

void CStaffSearchDiagnoseWin::showWin()
{
	vector<Appointment*> ::iterator it;

	if(addGetNumS)
	{
		//每次回来前对容器进行清空
		this->staffDiagnoseTable->avec.clear();

		//找到属于自己的取号订单
		
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getUser()==CData::nowStaff->getPhoneId()&&((*it)->getState()=="待就诊"||(*it)->getState()=="已就诊"))
			{
				this->staffDiagnoseTable->avec.push_back((*it));
			}
		}
		//设置当前页和全部页
		this->staffDiagnoseTable->setpagaIndex(1);
		int pageAll = this->staffDiagnoseTable->avec.size()/3;
		pageAll += this->staffDiagnoseTable->avec.size()%3==0?0:1;
		this->staffDiagnoseTable->setpageAll(pageAll);
		addGetNumS = false;
	}

	//当前页只有程序第一次运行的时候需要设置为1,且初始化自己最初的容器
	//标记，如果登录上来的是不同的用户，count重新置为1
	static string aa = CData::nowStaff->getPhoneId();
	int static count = 1;
	if(aa!=CData::nowStaff->getPhoneId())
	{
		count = 1;
		aa = CData::nowStaff->getPhoneId();
	}
	if(count ==1)
	{
		this->staffDiagnoseTable->avec.clear();
		this->staffDiagnoseTable->setpagaIndex(1);
		count = 2;
		//找到属于自己的取号订单
		
		for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
		{
			if((*it)->getUser()==CData::nowStaff->getPhoneId()&&((*it)->getState()=="待就诊"||(*it)->getState()=="已就诊"))
			{
				this->staffDiagnoseTable->avec.push_back((*it));
			}
		}
	}
	//设置全部页
	int pageAll = this->staffDiagnoseTable->avec.size()/3;
	pageAll += this->staffDiagnoseTable->avec.size()%3==0?0:1;
	this->staffDiagnoseTable->setpageAll(pageAll);

	//如果没有任何就诊信息
	if(this->staffDiagnoseTable->avec.size()==0)
	{
		CWindow::showWin();						//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
									//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
		CTools::gotoxy(35,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
		cout <<"欢迎来到智能门诊预约系统";
		CTools::gotoxy(3,10);
		cout <<"欢迎," << CData::nowStaff->getName() << ",用户";
		CTools::gotoxy(58,10);
		CTools::printTime();
		CTools::gotoxy(45,13);
		cout <<"至";
		CTools::gotoxy(45,27);
		cout <<"您当前没有任何就诊信息";
	}

	else{
		//我在winRun里对当前页设置好了，在doACtion里对当前页和容器都进行了重新存储，这里直接对着容器进行当前页的偏移就可以
		this->staffDiagnoseTable->ait = this->staffDiagnoseTable->avec.begin();
		advance(this->staffDiagnoseTable->ait, 3*(this->staffDiagnoseTable->getpageIndex()-1));
		CWindow::showWin();						//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
									//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
		CTools::gotoxy(35,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
		cout <<"欢迎来到智能门诊预约系统";
		CTools::gotoxy(3,10);
		cout <<"欢迎," << CData::nowStaff->getName() << ",用户";
		CTools::gotoxy(58,10);
		CTools::printTime();
		this->staffDiagnoseTable->showStaffDiagnoseData();
		this->staffDiagnoseTable->showPage();
		CTools::gotoxy(45,13);
		cout <<"至";
	}
}

void CStaffSearchDiagnoseWin::winRun()
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
			if(this->staffDiagnoseTable->getpageIndex()==this->staffDiagnoseTable->getpageAll()){
				this->staffDiagnoseTable->setpagaIndex(1);
				//偏移到第一页
		/*		this->userTable->it = this->userTable->smap.begin();*/
			}
			else{
				this->staffDiagnoseTable->setpagaIndex(this->staffDiagnoseTable->getpageIndex()+1);
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
			if(this->staffDiagnoseTable->getpageIndex()==1)
			{
				this->staffDiagnoseTable->setpagaIndex(this->staffDiagnoseTable->getpageAll());
	
			}
			else {
				this->staffDiagnoseTable->setpagaIndex(this->staffDiagnoseTable->getpageIndex()-1);
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

int CStaffSearchDiagnoseWin::doAction()
{
	int p ;
/*
	//showData时输出三次数据我的迭代器在showData时就往后偏移了3次，所以这里我复原一下
	advance(this->staffDiagnoseTable->dit,-3);*/

	//为了等会按三个方框进行查询，这是先根据页码获取迭代器迭代数据
	//先根据页码找到迭代器数据
		this->staffDiagnoseTable->ait = this->staffDiagnoseTable->avec.begin();
		advance(this->staffDiagnoseTable->ait,(this->staffDiagnoseTable->getpageIndex()-1)*3);

	switch(this->ctrl_index){
	case 4:{

		//两个编辑框内必须都有内容，不然就提示并且返回
		if(this->timeEdit1->getContent()==""&&this->timeEdit2->getContent()!=""||this->timeEdit2->getContent()==""&&this->timeEdit1->getContent()!="")
		{
			cout <<"请确保两个时间都有填写内容";
			system("pause");
			return 18;
		}
		if(this->timeEdit1->getContent().size()!=10&&!this->timeEdit1->getContent().empty()||!this->timeEdit2->getContent().empty()&&this->timeEdit2->getContent().size()!=10)
		{
			cout <<"请输入正确的时间格式，例如2024.04.11";
			system("pause");
			return 18;
		}
		//前后时间大小问题
		if(this->timeEdit1->getContent()>this->timeEdit2->getContent())
		{
			cout <<"输入时间大于后输入时间，请重新输入";
			system("pause");
			return 18;
		}
		//创建一个临时容器，如果模糊搜索到了就push_back
		//重新返回此窗口，输出查询后的结果
		this->staffDiagnoseTable->avec.clear();		//每次进来都先重新清空一遍
		if(this->timeEdit1->getContent()==""&&this->timeEdit2->getContent()=="")
		{
			//重新从容器中获取属于自己的预约
			//找到属于自己的取号订单
			vector<Appointment*> ::iterator it;
			for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
			{
				if((*it)->getUser()==CData::nowStaff->getPhoneId()&&((*it)->getState()=="待就诊"||(*it)->getState()=="已就诊"))
				{
					this->staffDiagnoseTable->avec.push_back((*it));
				}
			}
			//更新页码
			//查询后翻页当前页统一更新为1，放在后面共同部分，这里只需更新pageAll
			int pageAll = this->staffDiagnoseTable->avec.size()/3 + (this->staffDiagnoseTable->avec.size()%3==0?0:1);
			this->staffDiagnoseTable->setpageAll(pageAll);
			
		}
		else
		{
	//		map<string, CStaff*> ::diterator dit;
			for(this->staffDiagnoseTable->ait=CData::appointmentVector.begin();this->staffDiagnoseTable->ait!=CData::appointmentVector.end();++this->staffDiagnoseTable->ait)
			{
				if((*this->staffDiagnoseTable->ait)->getDay()>=this->timeEdit1->getContent()&&(*this->staffDiagnoseTable->ait)->getDay()<=this->timeEdit2->getContent()&&(*this->staffDiagnoseTable->ait)->getUser()==CData::nowStaff->getPhoneId()&&((*this->staffDiagnoseTable->ait)->getState()=="待就诊"||(*this->staffDiagnoseTable->ait)->getState()=="已就诊"))
				{
					this->staffDiagnoseTable->avec.push_back((*this->staffDiagnoseTable->ait));
				}
			}

			//如果查询到的结果为空，那么也就是说，这个时候的map里显然是空的
			if(this->staffDiagnoseTable->avec.empty())
			{
				CTools::gotoxy(25,15);
				cout <<"没有查询到任何有关信息";
				system("pause");

				//显示所有信息的第一页	迭代器回到一开始的位置
				vector<Appointment*> ::iterator it;
				for(it=CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
				{
					if((*it)->getUser()==CData::nowStaff->getPhoneId()&&((*it)->getState()=="待就诊"||(*it)->getState()=="已就诊"))
					{
						this->staffDiagnoseTable->avec.push_back((*it));
					}
				}
				this->staffDiagnoseTable->ait = this->staffDiagnoseTable->avec.begin();
			}
			//更新页码
			//查询后翻页当前页统一更新为1，放在后面共同部分，这里只需更新pageAll
			int pageAll = this->staffDiagnoseTable->avec.size()/3 + (this->staffDiagnoseTable->avec.size()%3==0?0:1);
			this->staffDiagnoseTable->setpageAll(pageAll);
		}

		//当前页全部更新为1
		this->staffDiagnoseTable->setpagaIndex(1);
		return 18;
		}
	case 5:

		
	
		return 2;
		
	}
	return 18;
}