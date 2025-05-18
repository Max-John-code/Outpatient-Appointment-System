#include "CStaffAmendInfoWin.h"

CStaffAmendInfoWin::CStaffAmendInfoWin(int x,int y,int width, int height)
        :CWindow(x,y,width,height)
{   
    this->phoneNum = new Label(28,14,"�ֻ����룺");
    this->nameLabel = new Label(28,17,"  ��  ����");
    this->IdCardLabel = new Label(28,21,"���֤�ţ�");
	this->nameEdit = new Editbox(38,16,21,3,"", 4,1,6);
	this->IdCardEdit = new Editbox(38,20,21,3,"",3,1,18);
	this->EnterBtn = new Button(30,26,8,3,"ȷ ��");
	this->backBtn = new Button(45,26,8,3,"�� ��");

    this->addCtrl(this->phoneNum);		//0
    this->addCtrl(this->nameLabel);		//1
    this->addCtrl(this->IdCardLabel);	//2
	this->addCtrl(this->nameEdit);		//3
	this->addCtrl(this->IdCardEdit);	//4

	this->addCtrl(this->EnterBtn);		//5
	this->addCtrl(this->backBtn);		//6
}

void CStaffAmendInfoWin::showWin()
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

int CStaffAmendInfoWin::doAction()
{
	switch(this->ctrl_index){
	case 5:
		//���жϣ����ֲ���Ϊ�գ�Ϊ��Ҫ����ʾ
		if(this->nameEdit->getContent().size()==0)
		{
			cout <<"���ֲ���Ϊ�գ�����������";
			system("pause");
			return 7;
		}
		//���֤����18λҪ��ʾ��ʽ����ȷ
		if(this->IdCardEdit->getContent().size()!=18)
		{
			cout <<"���֤���벻��18λ����ʽ����ȷ������������";
			system("pause");
			return 7;
		}
		//�޸����ֺ����֤�ţ���д���ļ�
		CData::nowStaff->setName(this->nameEdit->getContent());
		CData::nowStaff->setIdCard(this->IdCardEdit->getContent());
		CData::updataStaff();
		cout <<"�޸ĳɹ�";
		system("pause");
		return 6;//�ص���������������
	case 6:
		return 6;
	}
    return 6;
}
