// Search.cpp : 实现文件
//

#include "stdafx.h"
#include "YYX_TEST2_1.h"
#include "Search.h"
#include "afxdialogex.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


// CSearch 对话框

IMPLEMENT_DYNAMIC(CSearch, CDialogEx)

CSearch::CSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSearch::IDD, pParent)
{

}

CSearch::~CSearch()
{
}

void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, C_Search);
}


BEGIN_MESSAGE_MAP(CSearch, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CSearch::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSearch::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSearch 消息处理程序


void CSearch::OnBnClickedButton2()
{
	((CEdit *)GetDlgItem(IDC_EDIT1))->GetWindowText(C_Number);
	((CEdit *)GetDlgItem(IDC_EDIT2))->GetWindowText(C_Name);
	((CEdit *)GetDlgItem(IDC_COMBO1))->GetWindowText(C_Sex);
	((CEdit *)GetDlgItem(IDC_EDIT3))->GetWindowText(C_IDNumber);
	((CEdit *)GetDlgItem(IDC_DATETIMEPICKER1))->GetWindowText(C_Time);
	((CEdit *)GetDlgItem(IDC_EDIT4))->GetWindowText(C_Hobby);

	if(C_Number=="" || C_Name=="" || C_IDNumber=="" || C_Sex==""){
		MessageBox(_T("带*号的必须填写"),_T("waring"),MB_OK);
	}
	else{
		CDialog::OnOK();
	}// TODO: 在此添加控件通知处理程序代码
}



void CSearch::OnBnClickedButton1()
{
	CDialog::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}
