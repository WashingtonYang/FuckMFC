
// YYX_EXAM1_1View.h : CYYX_EXAM1_1View 类的接口
//
#include "Chart.h"
#pragma once


class CYYX_EXAM1_1View : public CView
{
protected: // 仅从序列化创建
	CYYX_EXAM1_1View();
	DECLARE_DYNCREATE(CYYX_EXAM1_1View)

// 特性
public:
	CYYX_EXAM1_1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	Chart chart;
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CYYX_EXAM1_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG  // YYX_EXAM1_1View.cpp 中的调试版本
inline CYYX_EXAM1_1Doc* CYYX_EXAM1_1View::GetDocument() const
   { return reinterpret_cast<CYYX_EXAM1_1Doc*>(m_pDocument); }
#endif

