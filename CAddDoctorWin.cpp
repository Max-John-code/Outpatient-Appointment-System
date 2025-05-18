#include "CAddDoctorWin.h"

extern bool addDoctor;

CAddDoctorWin::CAddDoctorWin(int x,int y,int width, int height)
					:CWindow(x,y,width,height)
{
	this->id = new Label(25,12,"医生 ID：");
	this->name = new Label(25,15, "医生姓名：");
	this->hospital = new Label(25,18,"所属医院：");
	this->room = new Label(25,21,"所属科室：");
	this->position = new Label(25,24,"医生职位：");
	this->Info = new Label(25,27,"简介：");
	
	this->nameEdit = new Editbox(36,14,25,3,"",4,1,6);
	this->hospitalEdit = new Editbox(36,17,25,3,"省立医院",4,1,0);
	this->roomEdit = new Editbox(36,20,25,3,"",4,1,0);
	this->roomBtn = new Button(56,20,5,3,"▼");
	this->postionEdit = new Editbox(36,23,25,3,"",4,1,0);
	this->positionBtn = new Button(56,23,5,3,"▼");
	this->InfoEdit = new Editbox(36,26,25,3,"",4,1,20);

	this->entetBtn = new Button(33,30,7,3,"确定");
	this->backBtn = new Button(50,30,7,3,"返回");

	this->addCtrl(this->id);			//0
	this->addCtrl(this->name);			//1
	this->addCtrl(this->hospital);		//2
	this->addCtrl(this->room);			//3
	this->addCtrl(this->position);		//4
	this->addCtrl(this->Info);			//5
	this->addCtrl(this->nameEdit);		//6
	this->addCtrl(this->hospitalEdit);	//7
	this->addCtrl(this->roomEdit);		//8
	this->addCtrl(this->roomBtn);		//9
	this->addCtrl(this->postionEdit);	//10
	this->addCtrl(this->positionBtn);	//11
	this->addCtrl(this->InfoEdit);		//12
	this->addCtrl(this->entetBtn);		//13
	this->addCtrl(this->backBtn);		//14

	this->roomContent.push_back("内科");
	this->roomContent.push_back("外科");
	this->roomContent.push_back("皮肤科");
	this->roomContent.push_back("眼科");
	this->roomContent.push_back("口腔科");
	this->roomDown = new CPullDown(57,20,11,17,this->roomContent);

	this->positionContent.push_back("专家");
	this->positionContent.push_back("主任医师");
	this->positionContent.push_back("副主任医师");
	this->positionContent.push_back("主治医师");
	this->positionDown = new CPullDown(57,23,15,14, this->positionContent);

}

void CAddDoctorWin::showWin()
{
	CWindow::showWin();
	CTools::gotoxy(27,7);	
	cout <<"欢迎来到智能门诊预约系统";
	CTools::gotoxy(13,10);
	cout <<"欢迎，管理员";
    CTools::gotoxy(48,10);
    CTools::printTime();
	CTools::gotoxy(36,12);		//rbegin来获取反向迭代器
	iDD = (CData::doctorMap.rbegin()->first);	//进行转换
	iDD.erase(0,1);
	int idd = CTools::str2int(iDD);
	++idd;
	iDD = CTools::int2str(idd);
	iDD = "D" + iDD;
	cout <<iDD;
}

int CAddDoctorWin::doAction()
{
	switch(this->ctrl_index){
	case 9:
		this->roomDown->showWin();
		this->roomDown->winRun();
		switch(this->roomDown->doAction()){
		case 0:	
			this->roomEdit->setContent("内科");
			break;
		case 1:
			this->roomEdit->setContent("外科");
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
		}
		return 13;
	case 11:
		this->positionDown->showWin();
		this->positionDown->winRun();
		switch(this->positionDown->doAction()){
		case 0:
			this->postionEdit->setContent("专家");
			break;
		case 1:
			this->postionEdit->setContent("主任医师");
			break;
		case 2:
			this->postionEdit->setContent("副主任医师");
			break;
		case 3:
			this->postionEdit->setContent("主治医师");
			break;

		}
		return 13;
	case 13:{
		//所有编辑框不能为空
		if(this->nameEdit->getContent()==""||this->roomEdit->getContent()==""||this->postionEdit->getContent()==""||this->InfoEdit->getContent()=="")
		{
			cout <<"请将信息填写完成";
			system("pause");
			return 13;
		}
		cout <<"新增医生成功";
		system("pause");
		CDoctor* newdoctor = new CDoctor(this->iDD, this->nameEdit->getContent(), "123456", this->roomEdit->getContent(), this->postionEdit->getContent(),this->hospitalEdit->getContent(), this->InfoEdit->getContent() );
		CData::doctorMap[newdoctor->getId()] = new CDoctor(*newdoctor);
		CData::addDoctor(newdoctor);
		addDoctor = true;
		//表单清空
		this->nameEdit->setContent("");
		this->roomEdit->setContent("");
		this->postionEdit->setContent("");
		this->InfoEdit->setContent("");
		}
	case 14:
		return 12;				//12管理员医生管理主界面
	}

	return 13;
}