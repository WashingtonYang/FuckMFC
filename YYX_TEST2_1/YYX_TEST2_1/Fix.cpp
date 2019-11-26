// Fix.cpp : 实现文件
//

#include "stdafx.h"
#include "YYX_TEST2_1.h"
#include "Fix.h"
#include "afxdialogex.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


// CFix 对话框

IMPLEMENT_DYNAMIC(CFix, CDialogEx)

CFix::CFix(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFix::IDD, pParent)
{

}

CFix::~CFix()
{
}

void CFix::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFix, CDialogEx)
	ON_BN_CLICKED(IDC_FIX, &CFix::OnBnClickedFix)
	ON_BN_CLICKED(IDC_BUTTON1, &CFix::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFix 消息处理程序


void CFix::OnBnClickedFix()
{
	((CEdit *)GetDlgItem(IDC_NUMBER))->GetWindowText(C_Number);
	((CEdit *)GetDlgItem(IDC_NAME))->GetWindowText(C_Name);
	((CEdit *)GetDlgItem(IDC_SEX))->GetWindowText(C_Sex);
	((CEdit *)GetDlgItem(IDC_IDNUMBER))->GetWindowText(C_IDNumber);
	((CEdit *)GetDlgItem(IDC_GRADE))->GetWindowText(C_Grade);
	((CEdit *)GetDlgItem(IDC_DATETIMEPICKER1))->GetWindowText(C_Time);
	((CEdit *)GetDlgItem(IDC_HOBBY))->GetWindowText(C_Hobby);
	if(C_Number=="" || C_Name=="" || C_IDNumber=="" || C_Sex==""){
		MessageBox(_T("带*号的必须填写"),_T("waring"),MB_OK);
	}
	else{
		ReFile();
		CDialog::OnOK();
	}

	// TODO: 在此添加控件通知处理程序代码
}


void CFix::ReFile(void)
{
	int flag=0;
	string mC_Number=CT2A(C_Number.GetString());
	string mC_Name=CT2A(C_Name.GetString());
	string mC_IDNumber=CT2A(C_IDNumber.GetString());
	string mC_Sex=CT2A(C_Sex.GetString());
	string mC_Grade=CT2A(C_Grade.GetString());
	string mC_Time=CT2A(C_Time.GetString());
	string mC_Hobby=CT2A(C_Hobby.GetString());

	fstream  f("member.txt");//创建一个fstream文件流对象
    string  line; //读取每一行
	string data="";
	string::size_type idx;
	
    while(getline(f,line))//会自动把\n换行符去掉 
    {
		string ber=line.substr(0,4);
		idx=ber.find(mC_Number);
		if(idx==string::npos)
		{
			data+=line;
			data+='\n';
		}
		else
		{
			flag=1;
			MessageBox(_T("修改成功"));
			data+=mC_Number+" "+mC_Name+" "+mC_IDNumber+" "+mC_Sex+" "+mC_Grade+" "+mC_Time+" "+mC_Hobby;
			data+='\n';
		}
    }
	if (flag)
	{
		f.close();
		//写入文件
		ofstream out;
		out.open("member.txt");
		out.flush();
		out<<data;
		out.close();
	}
	else{
		MessageBox(_T("请输入正确的会员号查询"));
	}
}


void CFix::OnBnClickedButton1()
{
	CDialog::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}
