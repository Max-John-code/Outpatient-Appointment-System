#include "CPullDown.h"


CPullDown::CPullDown(int x, int y, int width, int height,vector<string> btnContent)
			:CWindow(x,y,width,height)
{		//将btn容器添加进控件容器中
	for(int i=0;i<btnContent.size();++i)
	{
		this->btn = new Button(x+1,1+y+3*i,width-2,3,btnContent[i]);
		this->addCtrl(this->btn);
	}

}

void CPullDown::showWin()
{		//重写，不用system("cls")
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//标签转换
	{
		this->ctrlArr[i]->show();
	}
}

int CPullDown::doAction()
{
	return this->ctrl_index;
}


//--------------popupWin类

popupWin::popupWin(int x,int y,int width,int height)
			:CWindow(x,y,width,height)
{
	this->yesBtn = new Button(28,25,8,3," Yes");
	this->noBtn = new Button(45,25,8,3," No");

	this->addCtrl(this->yesBtn);
	this->addCtrl(this->noBtn);
}

void popupWin::showWin()
{	//重写，不用system("cls")
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//标签转换
	{
		this->ctrlArr[i]->show();
	}
	//移动到一个合适的位置进行打印是否需要退出
	CTools::gotoxy(this->x+this->width/3,this->y+2);
	cout << "你确定要退出吗";
}

int popupWin::doAction()
{
	switch(this->ctrl_index){
	case 0:
		cout <<"谢谢您本次的使用" << endl;
	//	system("pause");
		exit(0);
	case 1:
		return 0;	//返回主界面
	}
	return 0;
}

//---------popupAmendDoctorWin类

popupAmendDoctorWin::popupAmendDoctorWin(int x,int y,int width,int height)
			:CWindow(x,y,width,height)
{
	this->reminder = new Label(13,17,"提示：修改职位");
	this->doctorid = new Label(26,19,"医生ID：");
	//医生修改界面的时候会在外部调用对id进行setContent
	this->id = new Label(35,19,"");
	this->position = new Label(26,23,"职  位：");
	//一样在外部进行选中的时候对它进行setContent
	this->positionEdit = new Editbox(35,22,18,3,"", 4,1,0);
	//下拉框
	this->positionDown = new Button(50,22,5,3,"▼");
	this->enterBtn = new Button(28,26,9,3," 确定");
	this->backBtn = new Button(44,26,9,3," 返回");

	this->addCtrl(this->reminder);				//0
	this->addCtrl(this->doctorid);				//1
	this->addCtrl(this->id);					//2
	this->addCtrl(this->position);				//3
	this->addCtrl(this->positionEdit);			//4		
	this->addCtrl(this->positionDown);			//5
	this->addCtrl(this->enterBtn);				//6
	this->addCtrl(this->backBtn);				//7

	this->positionBtn.push_back("主治医师");
	this->positionBtn.push_back("主任医师");
	this->positionBtn.push_back("副主任医师");
	this->positionBtn.push_back("专家");
	this->positionDropDown = new CPullDown(50,22,15,14,this->positionBtn);

}
//讲label和eidtbox中的内容修改成传入的参数
void popupAmendDoctorWin::setIdContent(string id)
{
	this->id->setContent(id);
}

void popupAmendDoctorWin::setPositionContent(string position)
{
	this->positionEdit->setContent(position);
}

void popupAmendDoctorWin::showWin()
{
	//重写，不用system("cls")
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//标签转换
	{
		this->ctrlArr[i]->show();
	}
}

int popupAmendDoctorWin::doAction()
{
	switch(this->ctrl_index){
	case 5:
		this->positionDropDown->showWin();
		this->positionDropDown->winRun();
		return (this->positionDropDown->doAction());
	case 6:
	case 7:
		return 14;			//回到医生信息查询界面
	}

	return 14;			//自己
}

getNumWin::getNumWin(int x,int y,int width,int height)
					:CWindow(x,y,width,height)
{
	this->reminder = new Label(33,17,"提示：");
	this->getNumBtn = new Button(38,23,7,3,"取号");
	this->cencelBtn = new Button(50,23,11,3,"取消预约");
	this->backBtn = new Button(66,23,7,3,"返回");

	this->addCtrl(this->reminder);
	this->addCtrl(this->getNumBtn);
	this->addCtrl(this->cencelBtn);
	this->addCtrl(this->backBtn);
}

void getNumWin::showWin()
{
	//重写，不用system("cls")
	CTools::paintWindow(this->x, this->y, this->width, this->height);
	for(int i=0;i<this->ctrlArr.size();++i)//标签转换
	{
		this->ctrlArr[i]->show();
	}
	int count = 0;
	vector<Appointment*> ::iterator it;
	for(it = CData::appointmentVector.begin();it!=CData::appointmentVector.end();++it)
	{
		if((*it)->getState()=="未就诊")
			count ++;
	}
	CTools::gotoxy(45,19);
	cout <<"当前排队人数" << count << "人";

}

int getNumWin::doAction()
{
	switch(this->ctrl_index){
	case 1:
		return 1;		//代表取号
	case 2:
		return 2;		//代表取消
	case 3:
		return 16;
	}
	return 16;
}