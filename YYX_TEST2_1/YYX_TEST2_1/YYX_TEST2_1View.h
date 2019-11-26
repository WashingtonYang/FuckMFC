
// YYX_TEST2_1View.h : CYYX_TEST2_1View 类的接口
//

#pragma once

#include "resource.h"
#include "Add.h"
#include "Search.h"
#include "Fix.h"
#include "afxcmn.h"

class CYYX_TEST2_1View : public CFormView
{
protected: // 仅从序列化创建
	CYYX_TEST2_1View();
	DECLARE_DYNCREATE(CYYX_TEST2_1View)

public:
	enum{ IDD = IDD_YYX_TEST2_1_FORM };

// 特性
public:
	CYYX_TEST2_1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CYYX_TEST2_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

	int sum;//计算列表中的列值
	int is_select;//判断是否选中
	CString C_Number;
	CString C_Name;
	CString C_IDNumber;
	CString C_Sex;
	CString C_Grade;
	CString C_Time;
	CString C_Hobby;
	
	
	
	afx_msg void OnSearch();
};

#ifndef _DEBUG  // YYX_TEST2_1View.cpp 中的调试版本
inline CYYX_TEST2_1Doc* CYYX_TEST2_1View::GetDocument() const
   { return reinterpret_cast<CYYX_TEST2_1Doc*>(m_pDocument); }
#endif

