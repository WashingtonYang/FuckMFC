#pragma once
#include "Resource.h"
#include "afxwin.h"


// CAdd �Ի���

class CAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CAdd)

public:
	CAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdd();

// �Ի�������
	enum { IDD = IDD_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CButton C_Add;
	CButton C_Cancel;
	CString C_Number;
	CString C_Name;
	CString C_IDNumber;
	CString C_Sex;
	CString C_Grade;
	CString C_Time;
	CString C_Hobby;
	struct member{
	CString C_Number;
	CString C_Name;
	CString C_IDNumber;
	CString C_Sex;
	CString C_Grade;
	CString C_Time;
	CString C_Hobby;
	}m;

	afx_msg void OnBnClickedAdd1();
	void WriteFile(void);
	afx_msg void OnBnClickedCancel();
};
