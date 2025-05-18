#include "CAdminSearchRoomWin.h"


CAdminSearchRoomWin::CAdminSearchRoomWin(int x, int y, int width, int height)
					:CWindow(x,y,width,height)
{
	this->printLabel = new Label(15,13,"请输入科室ID：");
	this->printEdit = new Editbox(31,12,15,3,"", 3, 1, 11);		//数字和字母结合
	this->searchInfo = new Button(50,12,7,3,"查询");
	this->backBtn = new Button(15,27,7,3,"返回");
	//设置表头和表格
	vector<string>tableHead;
	tableHead.push_back("科室ID");
	tableHead.push_back("科室名称");
	tableHead.push_back("科室说明");
	this->roomTable = new CTable(20,15,12,tableHead);
	//设置当前页和全部页
	this->roomTable->setpagaIndex(1);
	int pageAll = CData::kroomMap.size()/3;
//	cout <<pageAll;
	pageAll += CData::kroomMap.size()%3==0?0:1;
	this->roomTable->setpageAll(pageAll);

	this->roomTable->kmap = CData::kroomMap;		//默认用来打印数据的容器，一开始等于全部数据
	this->roomTable->kit = this->roomTable->kmap.begin();	//初始迭代器为最初

	this->addCtrl(this->roomTable);		//0
	this->addCtrl(this->printLabel);	//1
	this->addCtrl(this->printEdit);		//2
	this->addCtrl(this->searchInfo);	//3
	this->addCtrl(this->backBtn);		//4


}

void CAdminSearchRoomWin::showWin()
{	/*
	if(addStaff)
	{	//如果这次运行有添加新用户，就获取最近的数据
		//迭代器重新置为第一个，而且页码也要更新
		this->roomTable->kmap = CData::kroomMap;
		this->roomTable->it = this->roomTable->kmap.begin();	//初始迭代器为最初
		//设置当前页和全部页
		this->roomTable->setpagaIndex(1);
		int pageAll = CData::kroomMap.size()/3;
	//	cout <<pageAll;
		pageAll += CData::kroomMap.size()%3==0?0:1;
		this->roomTable->setpageAll(pageAll);
		addStaff = false;
	}*/
	

	//我在winRun里对当前页设置好了，在doACtion里对当前页和容器都进行了重新存储，这里直接对着容器进行当前页的偏移就可以
	this->roomTable->kit = this->roomTable->kmap.begin();
	advance(this->roomTable->kit, 3*(this->roomTable->getpageIndex()-1));
	CWindow::showWin();						//除了主界面和登录界面，一旦进入用户的界面，所有窗口都有这一段---标题，欢迎，时间
								//我就不打算设置成一个Label了，相比Label的创建这样子直接输出的6行反而很简单
	CTools::gotoxy(27,7);		//这一串的代码是高复用的，可以考虑设置成一个函数但是其实也就6行我这里就没有设置了
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎,管理员" ;
    CTools::gotoxy(48,10);
    CTools::printTime();
	this->roomTable->showKRoomData();
	this->roomTable->showPage();

}

void CAdminSearchRoomWin::winRun()
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
			if(this->roomTable->getpageIndex()==this->roomTable->getpageAll()){
				this->roomTable->setpagaIndex(1);
				//偏移到第一页
		/*		this->roomTable->it = this->roomTable->kmap.begin();*/
			}
			else{
				this->roomTable->setpagaIndex(this->roomTable->getpageIndex()+1);
				//往后移动3位
		/*		advance(this->roomTable->it, 3);*/
			}

			//我只要按下一次查询按钮随后的每一次左右键，都会进行查询，这也导致我在那之后无法翻页
			//因为enter一次我的crtl_index就等于按钮的下标了，所以之后每一次进入我的doAction就会执行对应的case操作，
			//那么我在按左右键的时候将ctrl_index清零即可
			this->ctrl_index = 0;

			return ;
		case KEY_LEFT:
			//如果页码已经是第一页，回到最后一页
			if(this->roomTable->getpageIndex()==1)
			{
				this->roomTable->setpagaIndex(this->roomTable->getpageAll());
			/*	//进行迭代器的偏移,偏移到最后一页的第一个
				this->roomTable->it = this->roomTable->kmap.begin();
				advance(this->roomTable->it,3*(this->roomTable->getpageAll()-1));*/
			}
			else {
				this->roomTable->setpagaIndex(this->roomTable->getpageIndex()-1);
				//往前偏移3位
		/*		advance(this->roomTable->it, -3);*/
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


int CAdminSearchRoomWin::doAction()
{
	
	switch(this->ctrl_index){
	case 3:{

		//strstr比较编辑框内和用户容器中的账号
		//创建一个临时容器，如果模糊搜索到了就push_back
		//重新返回此窗口，输出查询后的结果
		this->roomTable->kmap.clear();		//每次进来都先重新清空一遍
		if(this->printEdit->getContent()=="")
		{
			this->roomTable->kmap = CData::kroomMap;
			//更新页码
			//查询后翻页当前页统一更新为1，放在后面共同部分，这里只需更新pageAll
			int pageAll = this->roomTable->kmap.size()/3 + (this->roomTable->kmap.size()%3==0?0:1);
			this->roomTable->setpageAll(pageAll);
			
		}
		else
		{
	//		map<string, CStaff*> ::iterator it;
			for(this->roomTable->kit=CData::kroomMap.begin();this->roomTable->kit!=CData::kroomMap.end();++this->roomTable->kit)
			{
				if(this->roomTable->kit->first.find(this->printEdit->getContent())!=-1)
				{
					this->roomTable->kmap[this->roomTable->kit->first] = this->roomTable->kit->second;
				}
			}

			//如果查询到的结果为空，那么也就是说，这个时候的map里显然是空的
			if(this->roomTable->kmap.empty())
			{
				CTools::gotoxy(25,15);
				cout <<"没有查询到任何有关信息";
				system("pause");
				
				//显示所有信息的第一页	迭代器回到一开始的位置
				this->roomTable->kmap = CData::kroomMap;
				this->roomTable->kit = this->roomTable->kmap.begin();
			}
			//更新页码
			//查询后翻页当前页统一更新为1，放在后面共同部分，这里只需更新pageAll
			int pageAll = this->roomTable->kmap.size()/3 + (this->roomTable->kmap.size()%3==0?0:1);
			this->roomTable->setpageAll(pageAll);
		}

		//当前页全部更新为1
		this->roomTable->setpagaIndex(1);
		return 15;
		}
	case 4:
		//返回时将编辑框中内容清空
		this->printEdit->setContent("");
		//重新获取所有的容器
		this->roomTable->kmap = CData::kroomMap;
		//迭代器回到一开始的位置
		this->roomTable->kit = this->roomTable->kmap.begin();
		//页码回到第一页
		this->roomTable->setpagaIndex(1);
		return 3;
	default:
		break;
	}
	return 15;
}