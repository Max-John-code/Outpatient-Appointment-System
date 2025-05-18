#include "CStaffAmendPwdWin.h"

CStaffAmendPwdWin::CStaffAmendPwdWin(int x, int y, int width, int height)
						:CWindow(x,y,width,height)
{
	this->phoneId = new Label(28,14,"�ֻ����룺");
    this->oldPwd = new Label(28,17,"  ԭ���룺");
    this->newPwd1 = new Label(28,20," �����룺");
	this->newPwd2 = new Label(28,23,"ȷ�����룺");

	this->oldPwdEdit = new Editbox(38,16,21,3,"", 1,0,6);	//���������ֳ���Ϊ6
	this->newPwd1Edit = new Editbox(38,19,21,3,"", 1,0,6);
	this->newPwd2Edit = new Editbox(38,22,21,3,"", 1,0,6 );
	this->enterBtn = new Button(30,27,8,3,"ȷ ��");
	this->backBtn = new Button(45,27,8,3,"�� ��");

	this->addCtrl(this->phoneId);		//0
	this->addCtrl(this->oldPwd);		//1
	this->addCtrl(this->newPwd1);		//2
	this->addCtrl(this->newPwd2);		//3
	this->addCtrl(this->oldPwdEdit);	//4
	this->addCtrl(this->newPwd1Edit);	//5
	this->addCtrl(this->newPwd2Edit);	//6
	this->addCtrl(this->enterBtn);		//7
	this->addCtrl(this->backBtn);		//8
}

void CStaffAmendPwdWin::showWin()
{
								//��������paintWindow֮��Ϳ��Դ�ӡ��������
    							//����������͵�¼���棬һ�������û��Ľ��棬���д��ڶ�����һ��---���⣬��ӭ��ʱ��
	CWindow::showWin();						//�ҾͲ��������ó�һ��Label�ˣ����Label�Ĵ���������ֱ�������6�з����ܼ�
	CTools::gotoxy(27,7);		//��һ���Ĵ����Ǹ߸��õģ����Կ������ó�һ������������ʵҲ��6���������û��������
	cout <<"��ӭ������������ԤԼϵͳ";
	CTools::gotoxy(13,10);
	cout <<"��ӭ," << CData::nowStaff->getName() << ",�û�";
    CTools::gotoxy(48,10);
    CTools::printTime();

	//����������������е����ֻ����ұߴ�ӡ���ֻ�����
	CTools::gotoxy(40,14);
	cout << CData::nowStaff->getPhoneId();
}

int CStaffAmendPwdWin::doAction()
{
	switch(this->ctrl_index){
	case 7:				//��������֤
		if(this->oldPwdEdit->getContent()!=CData::nowStaff->getPwd())
		{
			cout <<"���������";
			system("pause");
			return 8;
		}		//���볤�ȱ���Ϊ6
		if(this->newPwd1Edit->getContent().size()<6)
		{
			cout <<"�����ʽ����";
			system("pause");
			return 8;
		}	//���ܺ�ԭ����һ��
		else if(this->newPwd1Edit->getContent()==CData::nowStaff->getPwd())
		{
			cout << "�����벻�ܺ;�����һ��";
			system("pause");
			return 8;
		}
			//������ȷ������
		if(this->newPwd1Edit->getContent()!=this->newPwd2Edit->getContent())
		{
			cout <<"����������������������������";
			system("pause");
			return 8;
		}

		//����������֤�����µľ����ܹ���ȷ�޸�����Ľ����
		CData::nowStaff->setPwd(this->newPwd1Edit->getContent());
		CData::updataStaff();
		cout <<"�����޸ĳɹ�";
		system("pause");
		return 1;		//�ص���½�������µ�½

	case 8:
		return 6;		//���ظ�������
	}

	return 8;
}