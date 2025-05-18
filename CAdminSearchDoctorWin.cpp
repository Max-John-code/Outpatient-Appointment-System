#include "CAdminSearchDoctorWin.h"

extern bool addDoctor;

CAdminSearchDoctorWin::CAdminSearchDoctorWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->printLabel = new Label(15,13,"请输入医生id：");
	this->printEdit = new Editbox(29,12,20,3,"", 3, 1, 5);		//医生账号最多4位
	this->searchInfo = new Button(50,12,7,3,"查询");
	this->backBtn = new Button(15,27,7,3,"返回");
	//设置表头和表格
	vector<string>tableHead;
	tableHead.push_back("医生ID");
	tableHead.push_back("医生姓名");
	tableHead.push_back("职位");
	tableHead.push_back("所属科室");
	tableHead.push_back("所属医院");
	tableHead.push_back("简介");
	this->doctorTable = new CTable(5,16,11,tableHead);
	//设置当前页和全部页
	this->doctorTable->setpagaIndex(1);
	int pageAll = CData::doctorMap.size()/3;
//	cout <<pageAll;
	pageAll += CData::doctorMap.size()%3==0?0:1;
	this->doctorTable->setpageAll(pageAll);

	this->doctorTable->dmap = CData::doctorMap;		//默认用来打印数据的容器，一开始等于全部数据
	this->doctorTable->dit = this->doctorTable->dmap.begin();	//初始迭代器为最初

	//设置三行修改的按钮
	this->oneLine = new Button (2,18,3,2,"");
	this->twoLine = new Button(2,20,3,2,"");
	this->threeLine = new Button(2,22,3,2, "");

	this->addCtrl(this->doctorTable);		//0
	this->addCtrl(this->printLabel);	//1
	this->addCtrl(this->printEdit);		//2
	this->addCtrl(this->searchInfo);	//3
	this->addCtrl(this->oneLine);		//4			
	this->addCtrl(this->twoLine);		//5
	this->addCtrl(this->threeLine);		//6
	this->addCtrl(this->backBtn);		//7

	this->amendWin = new popupAmendDoctorWin(10,15,60,15);

	
	
}

void CAdminSearchDoctorWin::showWin()
{	
	if(addDoctor)
	{
		this->doctorTable->dmap = CData::doctorMap;		//默认用来打印数据的容器，一开始等于全部数据
		this->doctorTable->dit = this->doctorTable->dmap.begin();	//初始迭代器为最初
		//设置当前页和全部页
		this->doctorTable->setpagaIndex(1);
		int pageAll = CData::doctorMap.size()/3;
	//	cout <<pageAll;
		pageAll += CData::doctorMap.size()%3==0?0:1;
		this->doctorTable->setpageAll(pageAll);
		addDoctor = false;
	}

	//我在winRun里对当前页设置好了，在doACtion里对当前页和容器都进行了重新存储，这里直接对着容器进行当前页的偏移就可以
	this->doctorTable->dit = this->doctorTable->dmap.begin();
	advance(this->doctorTable->dit, 3*(this->doctorTable->getpageIndex()-1));
	CWindow::showWin();						//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
								//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
	CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎,管理员" ;
    CTools::gotoxy(48,10);
    CTools::printTime();
	this->doctorTable->showDoctorData();
	this->doctorTable->showPage();

}

void CAdminSearchDoctorWin::winRun()
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
			if(this->doctorTable->getpageIndex()==this->doctorTable->getpageAll()){
				this->doctorTable->setpagaIndex(1);
				//偏移到第一页
		/*		this->userTable->it = this->userTable->smap.begin();*/
			}
			else{
				this->doctorTable->setpagaIndex(this->doctorTable->getpageIndex()+1);
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
			if(this->doctorTable->getpageIndex()==1)
			{
				this->doctorTable->setpagaIndex(this->doctorTable->getpageAll());
	
			}
			else {
				this->doctorTable->setpagaIndex(this->doctorTable->getpageIndex()-1);
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


int CAdminSearchDoctorWin::doAction()
{
	int p ;
/*
	//showData时输出三次数据我的迭代器在showData时就往后偏移了3次，所以这里我复原一下
	advance(this->doctorTable->dit,-3);*/

	//为了等会按三个方框进行查询，这是先根据页码获取迭代器迭代数据
	//先根据页码找到迭代器数据
		this->doctorTable->dit = this->doctorTable->dmap.begin();
		advance(this->doctorTable->dit,(this->doctorTable->getpageIndex()-1)*3);

	switch(this->ctrl_index){
	case 3:{

		//strstr比较编辑框内和用户容器中的账号
		//创建一个临时容器，如果模糊搜索到了就push_back
		//重新返回此窗口，输出查询后的结果
		this->doctorTable->dmap.clear();		//每次进来都先重新清空一遍
		if(this->printEdit->getContent()=="")
		{
			this->doctorTable->dmap = CData::doctorMap;
			//更新页码
			//查询后翻页当前页统一更新为1，放在后面共同部分，这里只需更新pageAll
			int pageAll = this->doctorTable->dmap.size()/3 + (this->doctorTable->dmap.size()%3==0?0:1);
			this->doctorTable->setpageAll(pageAll);
			
		}
		else
		{
	//		map<string, CStaff*> ::diterator dit;
			for(this->doctorTable->dit=CData::doctorMap.begin();this->doctorTable->dit!=CData::doctorMap.end();++this->doctorTable->dit)
			{
				if(this->doctorTable->dit->first.find(this->printEdit->getContent())!=-1)
				{
					this->doctorTable->dmap[this->doctorTable->dit->first] = this->doctorTable->dit->second;
				}
			}

			//如果查询到的结果为空，那么也就是说，这个时候的map里显然是空的
			if(this->doctorTable->dmap.empty())
			{
				CTools::gotoxy(25,15);
				cout <<"没有查询到任何有关信息";
				system("pause");

				//显示所有信息的第一页	迭代器回到一开始的位置
				this->doctorTable->dmap = CData::doctorMap;
				this->doctorTable->dit = this->doctorTable->dmap.begin();
			}
			//更新页码
			//查询后翻页当前页统一更新为1，放在后面共同部分，这里只需更新pageAll
			int pageAll = this->doctorTable->dmap.size()/3 + (this->doctorTable->dmap.size()%3==0?0:1);
			this->doctorTable->setpageAll(pageAll);
		}

		//当前页全部更新为1
		this->doctorTable->setpagaIndex(1);
		return 14;
		}
	case 4:
		//获取第一行医生的信息
		this->amendWin->setPositionContent(this->doctorTable->dit->second->getPosition());
		this->amendWin->setIdContent(this->doctorTable->dit->second->getId());
		this->amendWin->showWin();
		this->amendWin->winRun();
		p = this->amendWin->doAction();

		break;
	case 5:
		
		//判断是否越界
		if((this->doctorTable->getpageIndex()-1)*3+2 > this->doctorTable->dmap.size())
		{
			cout <<"这一行没有数据";
			system("pause");
			break;
		}
		//获取第二行医生的信息
		advance(this->doctorTable->dit, 1);
		this->amendWin->setIdContent(this->doctorTable->dit->second->getId());
		this->amendWin->setPositionContent(this->doctorTable->dit->second->getPosition());
		this->amendWin->showWin();
		this->amendWin->winRun();
		p = this->amendWin->doAction();

		break;
	case 6:
		//判断是否越界
		if(this->doctorTable->getpageIndex()*3 > this->doctorTable->dmap.size())
		{
			cout <<"这一行没有数据";
			system("pause");
			break;
		}
		
		//获取第三行医生的信息
		advance(this->doctorTable->dit, 2);
		this->amendWin->setIdContent(this->doctorTable->dit->second->getId());
		this->amendWin->setPositionContent(this->doctorTable->dit->second->getPosition());
		this->amendWin->showWin();
		this->amendWin->winRun();
		p = this->amendWin->doAction();

		break;
	case 7:
		return 12;
	default:
		break;
	}
	//根据修改窗口的返回值修改信息，后写入文件
	switch(p){
	case 0:
		this->doctorTable->dit->second->setPosition("主治医师");
		break;
	case 1:
		this->doctorTable->dit->second->setPosition("主任医师");
		break;
	case 2:
		this->doctorTable->dit->second->setPosition("副主任医师");
		break;
	case 3:
		this->doctorTable->dit->second->setPosition("专家");
		break;
	default:
		return 14;
	}
	CData::updataDoctor();

	return 14;
}