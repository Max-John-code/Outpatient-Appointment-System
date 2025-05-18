#include "CAdminSearchStaffWin.h"

extern bool addStaff;

CAdminSearchStaffWin::CAdminSearchStaffWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->printLabel = new Label(15,13,"请输入用户账号：");
	this->printEdit = new Editbox(31,12,15,3,"", 1, 1, 11);		//手机号11位
	this->searchInfo = new Button(50,12,7,3,"查询");
	this->backBtn = new Button(15,27,7,3,"返回");
	//设置表头和表格
	vector<string>tableHead;
	tableHead.push_back("账号");
	tableHead.push_back("身份信息");
	this->userTable = new CTable(20,15,20,tableHead);
	//设置当前页和全部页
	this->userTable->setpagaIndex(1);
	int pageAll = CData::staffMap.size()/3;
//	cout <<pageAll;
	pageAll += CData::staffMap.size()%3==0?0:1;
	this->userTable->setpageAll(pageAll);

	this->userTable->smap = CData::staffMap;		//默认用来打印数据的容器，一开始等于全部数据
	this->userTable->it = this->userTable->smap.begin();	//初始迭代器为最初

	this->addCtrl(this->userTable);		//0
	this->addCtrl(this->printLabel);	//1
	this->addCtrl(this->printEdit);		//2
	this->addCtrl(this->searchInfo);	//3
	this->addCtrl(this->backBtn);		//4


}

void CAdminSearchStaffWin::showWin()
{	
	if(addStaff)
	{	//如果这次运行有添加新用户，就获取最近的数据
		//迭代器重新置为第一个，而且页码也要更新
		this->userTable->smap = CData::staffMap;
		this->userTable->it = this->userTable->smap.begin();	//初始迭代器为最初
		//设置当前页和全部页
		this->userTable->setpagaIndex(1);
		int pageAll = CData::staffMap.size()/3;
	//	cout <<pageAll;
		pageAll += CData::staffMap.size()%3==0?0:1;
		this->userTable->setpageAll(pageAll);
		addStaff = false;
	}
	

	//我在winRun里对当前页设置好了，在doACtion里对当前页和容器都进行了重新存储，这里直接对着容器进行当前页的偏移就可以
	this->userTable->it = this->userTable->smap.begin();
	advance(this->userTable->it, 3*(this->userTable->getpageIndex()-1));
	CWindow::showWin();						//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
								//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
	CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎,管理员" ;
    CTools::gotoxy(48,10);
    CTools::printTime();
	this->userTable->showStaffData();
	this->userTable->showPage();

}

void CAdminSearchStaffWin::winRun()
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
			if(this->userTable->getpageIndex()==this->userTable->getpageAll()){
				this->userTable->setpagaIndex(1);
				//偏移到第一页
		/*		this->userTable->it = this->userTable->smap.begin();*/
			}
			else{
				this->userTable->setpagaIndex(this->userTable->getpageIndex()+1);
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
			if(this->userTable->getpageIndex()==1)
			{
				this->userTable->setpagaIndex(this->userTable->getpageAll());
			/*	//进行迭代器的偏移,偏移到最后一页的第一个
				this->userTable->it = this->userTable->smap.begin();
				advance(this->userTable->it,3*(this->userTable->getpageAll()-1));*/
			}
			else {
				this->userTable->setpagaIndex(this->userTable->getpageIndex()-1);
				//往前偏移3位
		/*		advance(this->userTable->it, -3);*/
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


int CAdminSearchStaffWin::doAction()
{
	
	switch(this->ctrl_index){
	case 3:{

		//strstr比较编辑框内和用户容器中的账号
		//创建一个临时容器，如果模糊搜索到了就push_back
		//重新返回此窗口，输出查询后的结果
		this->userTable->smap.clear();		//每次进来都先重新清空一遍
		if(this->printEdit->getContent()=="")
		{
			this->userTable->smap = CData::staffMap;
			//更新页码
			//查询后翻页当前页统一更新为1，放在后面共同部分，这里只需更新pageAll
			int pageAll = this->userTable->smap.size()/3 + (this->userTable->smap.size()%3==0?0:1);
			this->userTable->setpageAll(pageAll);
			
		}
		else
		{
	//		map<string, CStaff*> ::iterator it;
			for(this->userTable->it=CData::staffMap.begin();this->userTable->it!=CData::staffMap.end();++this->userTable->it)
			{
				if(this->userTable->it->first.find(this->printEdit->getContent())!=-1)
				{
					this->userTable->smap[this->userTable->it->first] = this->userTable->it->second;
				}
			}

			//如果查询到的结果为空，那么也就是说，这个时候的map里显然是空的
			if(this->userTable->smap.empty())
			{
				CTools::gotoxy(25,15);
				cout <<"没有查询到任何有关信息";
				system("pause");
				
				//显示所有信息的第一页	迭代器回到一开始的位置
				this->userTable->smap = CData::staffMap;
				this->userTable->it = this->userTable->smap.begin();
			}
			//更新页码
			//查询后翻页当前页统一更新为1，放在后面共同部分，这里只需更新pageAll
			int pageAll = this->userTable->smap.size()/3 + (this->userTable->smap.size()%3==0?0:1);
			this->userTable->setpageAll(pageAll);
		}

		//当前页全部更新为1
		this->userTable->setpagaIndex(1);
		return 11;
		}
	case 4:
		return 3;
	default:
		break;
	}
	return 11;
}