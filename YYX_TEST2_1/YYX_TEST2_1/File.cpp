#include "stdafx.h"
#include "File.h"


File::File(void)
{
	
}


File::~File(void)
{
}


void File::WriteFile(void)
{
	//��ȡ�������
	member m;
	m.C_Number=add.C_Number;
	m.C_Name=add.C_Name;
	m.C_IDNumber=add.C_IDNumber;
	m.C_Sex=add.C_Sex;
	m.C_Grade=add.C_Grade;
	m.C_Time=add.C_Time;
	m.C_Hobby=add.C_Hobby;
	//д�ļ�
	CFile file;
	if(file.Open(_T("member.txt"),CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate)){
		file.Write(&m,sizeof(m));
		file.Close();
	}
	else{
		MessageBox(NULL,_T("�ļ���ʧ��"),_T("waring"),MB_OK);
	}
}
