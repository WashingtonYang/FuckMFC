
// YYX_TEST1_3View.h : CYYX_TEST1_3View 类的接口
//

#pragma once


class CYYX_TEST1_3View : public CView
{
protected: // 仅从序列化创建
	CYYX_TEST1_3View();
	DECLARE_DYNCREATE(CYYX_TEST1_3View)

// 特性
public:
	CYYX_TEST1_3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CYYX_TEST1_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGet10Number();
	afx_msg void Onbubblesort();
	afx_msg void OnSelectionSort();
	afx_msg void OnQuickSort();
	afx_msg void Onstart_01();
	afx_msg void Onstart_02();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	int len;
	int sleeptime;
	int* a;
	bool bubble;
	bool selection;
	bool quick;
	int* p_bubble;
	int last;
	int first;
	int first2;
	int* p_selection;
	int minIndex;
	int pivot;
	int is_sort;
	int is_start;
	int cont;
	int low;
	int high;
	int* p_quick;


	void DisplayNum(void);
	void PenColor(int r, int g, int b, int x, int y);
	int Partition(int low, int high);
	void Copy(int* p);
	void swap(int m, int n, int* p);
	void QuickSort(int low, int high);
	void Equal(int m, int n, int* p);
	void Copy1(int* p);
};

#ifndef _DEBUG  // YYX_TEST1_3View.cpp 中的调试版本
inline CYYX_TEST1_3Doc* CYYX_TEST1_3View::GetDocument() const
   { return reinterpret_cast<CYYX_TEST1_3Doc*>(m_pDocument); }
#endif

