// Add.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "YYX_TEST2_1.h"
#include "Add.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
using namespace std;


// CAdd �Ի���

IMPLEMENT_DYNAMIC(CAdd, CDialogEx)

CAdd::CAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAdd::IDD, pParent)
{

}

CAdd::~CAdd()
{
}

void CAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADD1, C_Add);
	DDX_Control(pDX, IDC_CANCEL, C_Cancel);
}


BEGIN_MESSAGE_MAP(CAdd, CDialogEx)
	ON_BN_CLICKED(IDC_ADD1, &CAdd::OnBnClickedAdd1)
	ON_BN_CLICKED(IDC_CANCEL, &CAdd::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAdd ��Ϣ�������


void CAdd::OnBnClickedAdd1()
{
	((CEdit *)GetDlgItem(IDC_NUMBER))->GetWindowText(C_Number);
	((CEdit *)GetDlgItem(IDC_NAME))->GetWindowText(C_Name);
	((CEdit *)GetDlgItem(IDC_SEX))->GetWindowText(C_Sex);
	((CEdit *)GetDlgItem(IDC_IDNUMBER))->GetWindowText(C_IDNumber);
	((CEdit *)GetDlgItem(IDC_GRADE))->GetWindowText(C_Grade);
	((CEdit *)GetDlgItem(IDC_DATETIMEPICKER1))->GetWindowText(C_Time);
	((CEdit *)GetDlgItem(IDC_HOBBY))->GetWindowText(C_Hobby);
	if(C_Number=="" || C_Name=="" || C_IDNumber=="" || C_Sex==""){
		MessageBox(_T("��*�ŵı�����д"),_T("waring"),MB_OK);
	}
	else{
		WriteFile();
		CDialog::OnOK();
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CAdd::WriteFile(void)
{
	//��ȡ�������
	
	string mC_Number=CT2A(C_Number.GetString());
	string mC_Name=CT2A(C_Name.GetString());
	string mC_IDNumber=CT2A(C_IDNumber.GetString());
	string mC_Sex=CT2A(C_Sex.GetString());
	string mC_Grade=CT2A(C_Grade.GetString());
	string mC_Time=CT2A(C_Time.GetString());
	string mC_Hobby=CT2A(C_Hobby.GetString());
	
	//д�ļ�
	ofstream file;
	file.open("member.txt",ios::out|ios::app);
	if(file){
		file <<mC_Number<<" "<<mC_Name<<" "<<mC_IDNumber<<" "<<mC_Sex<<" "<<mC_Grade<<" "<<mC_Time<<" "<<mC_Hobby<< "\n";
	}
	else{
		MessageBox(_T("�ļ���ʧ��"),_T("waring"),MB_OK);
	}
}


void CAdd::OnBnClickedCancel()
{
	CDialog::OnOK();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
