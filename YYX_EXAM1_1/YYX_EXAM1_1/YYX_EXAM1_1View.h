
// YYX_EXAM1_1View.h : CYYX_EXAM1_1View ��Ľӿ�
//
#include "Chart.h"
#pragma once


class CYYX_EXAM1_1View : public CView
{
protected: // �������л�����
	CYYX_EXAM1_1View();
	DECLARE_DYNCREATE(CYYX_EXAM1_1View)

// ����
public:
	CYYX_EXAM1_1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	Chart chart;
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CYYX_EXAM1_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG  // YYX_EXAM1_1View.cpp �еĵ��԰汾
inline CYYX_EXAM1_1Doc* CYYX_EXAM1_1View::GetDocument() const
   { return reinterpret_cast<CYYX_EXAM1_1Doc*>(m_pDocument); }
#endif

