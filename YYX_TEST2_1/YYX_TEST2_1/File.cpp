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
	//获取添加数据
	member m;
	m.C_Number=add.C_Number;
	m.C_Name=add.C_Name;
	m.C_IDNumber=add.C_IDNumber;
	m.C_Sex=add.C_Sex;
	m.C_Grade=add.C_Grade;
	m.C_Time=add.C_Time;
	m.C_Hobby=add.C_Hobby;
	//写文件
	CFile file;
	if(file.Open(_T("member.txt"),CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate)){
		file.Write(&m,sizeof(m));
		file.Close();
	}
	else{
		MessageBox(NULL,_T("文件打开失败"),_T("waring"),MB_OK);
	}
}
