
// YYX_EXAM1_1View.cpp : CYYX_EXAM1_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CYYX_EXAM1_1View ����/����

CYYX_EXAM1_1View::CYYX_EXAM1_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CYYX_EXAM1_1View::~CYYX_EXAM1_1View()
{
}

BOOL CYYX_EXAM1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CYYX_EXAM1_1View ����

void CYYX_EXAM1_1View::OnDraw(CDC* pDC)
{
	chart.Init();
	chart.OnPaint(pDC);
	CYYX_EXAM1_1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CYYX_EXAM1_1View ��ӡ

BOOL CYYX_EXAM1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CYYX_EXAM1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CYYX_EXAM1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CYYX_EXAM1_1View ���

#ifdef _DEBUG
void CYYX_EXAM1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CYYX_EXAM1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYYX_EXAM1_1Doc* CYYX_EXAM1_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYYX_EXAM1_1Doc)));
	return (CYYX_EXAM1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CYYX_EXAM1_1View ��Ϣ�������


