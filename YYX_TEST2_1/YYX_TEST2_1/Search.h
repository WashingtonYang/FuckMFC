#pragma once
#include "afxwin.h"
#include "afxdtctl.h"


// CSearch �Ի���

class CSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CSearch)

public:
	CSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSearch();

// �Ի�������
	enum { IDD = IDD_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString C_Number;
	CString C_Name;
	CString C_IDNumber;
	CString C_Sex;
	CString C_Grade;
	CString C_Time;
	CString C_Hobby;

	CButton C_Search;
	

	afx_msg void OnBnClickedButton2();
	void SelectFile(void);
	afx_msg void OnBnClickedButton1();
};
