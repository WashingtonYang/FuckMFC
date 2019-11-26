
// YYX_TEST1_3View.h : CYYX_TEST1_3View ��Ľӿ�
//

#pragma once


class CYYX_TEST1_3View : public CView
{
protected: // �������л�����
	CYYX_TEST1_3View();
	DECLARE_DYNCREATE(CYYX_TEST1_3View)

// ����
public:
	CYYX_TEST1_3Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CYYX_TEST1_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // YYX_TEST1_3View.cpp �еĵ��԰汾
inline CYYX_TEST1_3Doc* CYYX_TEST1_3View::GetDocument() const
   { return reinterpret_cast<CYYX_TEST1_3Doc*>(m_pDocument); }
#endif

