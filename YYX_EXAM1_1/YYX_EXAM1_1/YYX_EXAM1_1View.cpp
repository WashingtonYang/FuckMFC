
// YYX_EXAM1_1View.cpp : CYYX_EXAM1_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "YYX_EXAM1_1.h"
#endif

#include "YYX_EXAM1_1Doc.h"
#include "YYX_EXAM1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYYX_EXAM1_1View

IMPLEMENT_DYNCREATE(CYYX_EXAM1_1View, CView)

BEGIN_MESSAGE_MAP(CYYX_EXAM1_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CYYX_EXAM1_1View 构造/析构

CYYX_EXAM1_1View::CYYX_EXAM1_1View()
{
	// TODO: 在此处添加构造代码

}

CYYX_EXAM1_1View::~CYYX_EXAM1_1View()
{
}

BOOL CYYX_EXAM1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CYYX_EXAM1_1View 绘制

void CYYX_EXAM1_1View::OnDraw(CDC* pDC)
{
	chart.Init();
	chart.OnPaint(pDC);
	CYYX_EXAM1_1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	

	// TODO: 在此处为本机数据添加绘制代码
}


// CYYX_EXAM1_1View 打印

BOOL CYYX_EXAM1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CYYX_EXAM1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CYYX_EXAM1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CYYX_EXAM1_1View 诊断

#ifdef _DEBUG
void CYYX_EXAM1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CYYX_EXAM1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYYX_EXAM1_1Doc* CYYX_EXAM1_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYYX_EXAM1_1Doc)));
	return (CYYX_EXAM1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CYYX_EXAM1_1View 消息处理程序


