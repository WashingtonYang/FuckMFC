#pragma once
#include "Resource.h"
#include "afxwin.h"

// CFix �Ի���

class CFix : public CDialogEx
{
	DECLARE_DYNAMIC(CFix)

public:
	CFix(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFix();

// �Ի�������
	enum { IDD = IDD_Fix };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFix();
	void ReFile(void);
	CString C_Number;
	CString C_Name;
	CString C_IDNumber;
	CString C_Sex;
	CString C_Grade;
	CString C_Time;
	CString C_Hobby;
	afx_msg void OnBnClickedButton1();
};
