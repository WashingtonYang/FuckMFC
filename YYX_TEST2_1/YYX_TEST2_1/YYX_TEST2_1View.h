
// YYX_TEST2_1View.h : CYYX_TEST2_1View ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "Add.h"
#include "Search.h"
#include "Fix.h"
#include "afxcmn.h"

class CYYX_TEST2_1View : public CFormView
{
protected: // �������л�����
	CYYX_TEST2_1View();
	DECLARE_DYNCREATE(CYYX_TEST2_1View)

public:
	enum{ IDD = IDD_YYX_TEST2_1_FORM };

// ����
public:
	CYYX_TEST2_1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CYYX_TEST2_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAdd();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnAdd();
	afx_msg void OnBnClickedFix();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedDelete();

	CAdd add;
	CSearch search;
	CFix fix;
	
	CTreeCtrl C_Tree;
	HTREEITEM Member;
	HTREEITEM SeniorMember;
	HTREEITEM IntermediateMember;
	HTREEITEM JuniorMember;
	CListCtrl M_List;
	
	
	void InitTree(void);
	void InitList(int sum);
	void ReadFile(void);
	void Show(void);

	int sum;//�����б��е���ֵ
	int is_select;//�ж��Ƿ�ѡ��
	CString C_Number;
	CString C_Name;
	CString C_IDNumber;
	CString C_Sex;
	CString C_Grade;
	CString C_Time;
	CString C_Hobby;
	
	
	
	afx_msg void OnSearch();
};

#ifndef _DEBUG  // YYX_TEST2_1View.cpp �еĵ��԰汾
inline CYYX_TEST2_1Doc* CYYX_TEST2_1View::GetDocument() const
   { return reinterpret_cast<CYYX_TEST2_1Doc*>(m_pDocument); }
#endif

