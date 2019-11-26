
// YYX_TEST1_3View.cpp : CYYX_TEST1_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "YYX_TEST1_3.h"
#endif

#include "YYX_TEST1_3Doc.h"
#include "YYX_TEST1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYYX_TEST1_3View

IMPLEMENT_DYNCREATE(CYYX_TEST1_3View, CView)

BEGIN_MESSAGE_MAP(CYYX_TEST1_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CYYX_TEST1_3View::OnGet10Number)
	ON_COMMAND(ID_32772, &CYYX_TEST1_3View::Onbubblesort)
	ON_COMMAND(ID_32773, &CYYX_TEST1_3View::OnSelectionSort)
	ON_COMMAND(ID_32774, &CYYX_TEST1_3View::OnQuickSort)
	ON_COMMAND(ID_32775, &CYYX_TEST1_3View::Onstart_01)
	ON_COMMAND(ID_32776, &CYYX_TEST1_3View::Onstart_02)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CYYX_TEST1_3View ����/����

CYYX_TEST1_3View::CYYX_TEST1_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CYYX_TEST1_3View::~CYYX_TEST1_3View()
{
}

BOOL CYYX_TEST1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CYYX_TEST1_3View ����

void CYYX_TEST1_3View::OnDraw(CDC* pDC)
{
	CYYX_TEST1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CFont font;
	font.CreatePointFont(1000,TEXT("����"));
	pDC->TextOutW(500,200,TEXT("ѡ�������������ѡ������ʽ��ѡ��ʼ��ʽ��ʼ"));
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CYYX_TEST1_3View ��ӡ

BOOL CYYX_TEST1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CYYX_TEST1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CYYX_TEST1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CYYX_TEST1_3View ���

#ifdef _DEBUG
void CYYX_TEST1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CYYX_TEST1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYYX_TEST1_3Doc* CYYX_TEST1_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYYX_TEST1_3Doc)));
	return (CYYX_TEST1_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CYYX_TEST1_3View ��Ϣ�������


void CYYX_TEST1_3View::OnGet10Number()
{
	len=10;
	sleeptime=800;
	a=new int[len];
	for(int i=0;i<10;i++){
		a[i]=rand()%60;
	}
	DisplayNum();
	// TODO: �ڴ���������������
}


void CYYX_TEST1_3View::Onbubblesort()
{
	cont=0;
	is_sort=1;
	// TODO: �ڴ���������������
}


void CYYX_TEST1_3View::OnSelectionSort()
{
	cont=0;
	is_sort=2;
	// TODO: �ڴ���������������
}


void CYYX_TEST1_3View::OnQuickSort()
{
	cont=0;
	is_sort=3;
	// TODO: �ڴ���������������
}


void CYYX_TEST1_3View::Onstart_01()
{
	is_start=0;
	if(is_sort==1)
	{
		bubble=FALSE;
		selection=FALSE;
		quick=FALSE;
		if (!(bubble || selection || quick))//��û��һ��Ϊtrueʱ
		{
			bubble = TRUE;
			selection = FALSE;
			quick = FALSE;
			p_bubble = new int[len];
			Copy(p_bubble);
			last = len - 1;
			first = 0;
			SetTimer(1, 100, NULL);
		}
	}
	else if(is_sort==2)
	{
		bubble=FALSE;
		selection=FALSE;
		quick=FALSE;
		if (!bubble || selection || quick)//��û��һ��Ϊtrueʱ
		{
			selection = TRUE;
			bubble = FALSE;
			quick = FALSE;
			p_selection = new int[len];
			Copy(p_selection);
			minIndex = 0;
			first2 = 1;
			first = 0;
			SetTimer(2, 100, NULL);
		}
	}
	else if(is_sort==3)
	{
		bubble=FALSE;
		selection=FALSE;
		quick=FALSE;
		low = 0;
		high = len - 1;
		if (!(bubble || selection || quick))//��û��һ��Ϊtrueʱ
		{
			quick = TRUE;
			selection = FALSE;
			bubble= FALSE;
			p_quick = new int[len];
			Copy(p_quick);
			QuickSort(low, high);
			MessageBox(L"�������������");
			quick = FALSE;
		}
	}
	// TODO: �ڴ���������������
}


void CYYX_TEST1_3View::Onstart_02()
{
	is_start=2;
	// TODO: �ڴ���������������
	if(is_sort==1)
	{
		bubble=FALSE;
		selection=FALSE;
		quick=FALSE;
		if(cont!=0)
		{
			selection = FALSE;
			bubble = TRUE;
			quick = FALSE;
			p_bubble = new int[len];
			Copy(p_bubble);
			SetTimer(1, 100, NULL);
		}
		else if (!(bubble || selection || quick))//��û��һ��Ϊtrueʱ
		{
			bubble = TRUE;
			selection = FALSE;
			quick = FALSE;
			p_bubble = new int[len];
			Copy(p_bubble);
			Copy1(p_bubble);
			last = len - 1;
			first = 0;
			SetTimer(1, 100, NULL);
		}
	}
	else if(is_sort==2)
	{
		bubble=FALSE;
		selection=FALSE;
		quick=FALSE;
		
		if(cont!=0)
		{
			selection = TRUE;
			bubble = FALSE;
			quick = FALSE;
			p_selection = new int[len];
			Copy(p_selection);
			SetTimer(2, 100, NULL);
		}
		else if (!bubble || selection || quick)//��û��һ��Ϊtrueʱ
		{
			bubble=FALSE;
			selection=FALSE;
			quick=FALSE;
			if (!bubble || selection || quick)//��û��һ��Ϊtrueʱ
			{
				selection = TRUE;
				bubble = FALSE;
				quick = FALSE;
				p_selection = new int[len];
				Copy(p_selection);
				Copy1(p_selection);
				minIndex = 0;
				first2 = 1;
				first = 0;
				SetTimer(2, 100, NULL);
			}
		}
	}
	else if(is_sort==3)
	{
		bubble=FALSE;
		selection=FALSE;
		quick=FALSE;
		
		if(cont!=0)
		{
			quick = TRUE;
			selection = FALSE;
			bubble= FALSE;
			p_quick = new int[len];
			Copy(p_quick);
			SetTimer(2, 100, NULL);
		}
		if (!(bubble || selection || quick))//��û��һ��Ϊtrueʱ
		{
			low = 0;
			high = len - 1;
			quick = TRUE;
			selection = FALSE;
			bubble= FALSE;
			p_quick = new int[len];
			Copy(p_quick);
			Copy1(p_quick);
			QuickSort(low, high);
			MessageBox(L"�������������");
			quick = FALSE;
		}
	}
	cont++;
	// TODO: �ڴ���������������
}


void CYYX_TEST1_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
	case 1:
		if(bubble)//�ж��Ƿ�Ϊð��
		{
			if (last == 0)//�ж�ð�ݽ���
			{
				PenColor(0, 255, 0, p_bubble[last] ,30 );//����
				KillTimer(1);//������ʱ��
				MessageBox(L"ð��������ɣ�");
				bubble = FALSE;
			}
			else if (first == last)//�ж�һ�ֵ�ð�ݺ����Ƿ����
			{
				PenColor(0, 255, 0,p_bubble[last] ,last * 50 + 30);
				last--;
				first = 0;
				if(is_start==2) //�ж��Ƿ�Ϊ��������
				{
					Copy1(p_bubble);//���浥�����е�ֵ
					KillTimer(1);//������ʱ��
				}
			}
			else
			{
				PenColor(255, 0, 0,p_bubble[first] , first * 50 + 30); 
				Sleep(sleeptime);
				if (p_bubble[first] > p_bubble[first + 1])//�жϵ�ǰ��ֵ�Ƿ�Ⱥ����ֵ��
				{
					swap(first, first + 1,p_bubble); //���������»����ҽ���ֵ��
					PenColor(255, 0, 0,p_bubble[first+1] ,first  * 50 + 30);
					PenColor(255, 255, 255,p_bubble[first + 1],first * 50 + 30);
					PenColor(0, 0, 0,p_bubble[first],first * 50 + 30);
					first++;
				}
				else
				{
					PenColor(0, 0, 0, p_bubble[first],first * 50 + 30);
					first++;
					PenColor(255, 0, 0,p_bubble[first],first * 50 + 30);
				}
				
			}
		}
		else
		{
			KillTimer(1);
			MessageBox(L"������");
			bubble = FALSE;
		}
		break;
	case 2:
		if (selection)//�ж��Ƿ�Ϊѡ������
		{
			if (first == len)//�ж�ѡ�������Ƿ����
			{
				KillTimer(2);
				MessageBox(L"ѡ�����������");
				selection = FALSE;
			}
			else if (first < len)
			{
				if (first2<len)
				{
					PenColor(255, 0, 0,p_selection[first2],first2 * 50 + 30);//��
					Sleep(sleeptime);
					PenColor(0, 0, 0,p_selection[first2], first2 * 50 + 30);//��
					if (p_selection[first2]<p_selection[minIndex])minIndex = first2;
					first2++;
				}
				else
				{
					if (minIndex == first)//������һ��ѡ������û�н���
					{
						PenColor(0, 255, 0,p_selection[first2], first * 50 + 30);//��
						first++;
						minIndex = first;
						first2 = minIndex + 1;
					}
					else //һ��ѡ���������
					{
						swap(minIndex, first,p_selection);
						PenColor(255, 255, 255,60,first * 50 + 30);//��

						PenColor(0, 255, 0, p_selection[first],first * 50 + 30);//��

						PenColor(0, 0, 0,p_selection[first], minIndex * 50 + 30);//��

						first++;
						minIndex = first;
						first2 = minIndex + 1;
						Sleep(sleeptime);
						if(is_start==2) //�ж��Ƿ�Ϊ��������
						{
							Copy1(p_selection);
							KillTimer(2);
						}
					}
				}
			}
		}
		else
		{
			KillTimer(2);
			MessageBox(L"������");
			selection = FALSE;
		}
		break;
	default:
		break;
	}
	CView::OnTimer(nIDEvent);
}


void CYYX_TEST1_3View::DisplayNum(void)
{
	CDC *pDC =GetDC();
	CString str;
	for (int i = 0;i < len;i++)
	{
		pDC->FillSolidRect(CRect(30, i * 50 + 10, 50, i * 50 + 30), RGB(255, 255, 255));//���Ǿ������������
		PenColor(255, 255, 255, 60, i * 50 + 30);//�����ϴε�ͼ��
		PenColor(0, 0, 0, a[i], i * 50 + 30);//��ͼ
		str.Format(TEXT("%d"), a[i]);
		pDC->TextOutW(30, i * 50 + 10, str);//����λ��
		//pDC->FillSolidRect(CRect(300, 300, 400, 350), RGB(0, 255, 255));//���Ǿ������������
	}
	ReleaseDC(pDC);
}


void CYYX_TEST1_3View::PenColor(int r, int g, int b, int x, int y)
{
	CDC *pDC =GetDC();
	CPen pPen;
	
	pPen.CreatePen(PS_SOLID, 10, RGB(r, g, b)); //��ɫ�ıʿ��Ϊ10
	pDC->SelectObject(&pPen);//�滻Ϊ�����pPen
	pDC->MoveTo(40,y);//����CDC�ĳ�Ա��������
	pDC->LineTo((x+40)*5, y);
	ReleaseDC(pDC);//�ͷ�DC
}


int CYYX_TEST1_3View::Partition(int low, int high)
{
	int temp;//�����ֵ����ʱ����
	int i = low, j = high;
	temp = p_quick[low];
	while (i < j)
	{
		while ((i < j) && temp <= p_quick[j])j--;
		if (i<j)
		{
			Equal(i, p_quick[j],p_quick);
			PenColor(255,255, 255, 60, i * 50 + 30);//��
			PenColor(0,255 , 0, p_quick[i], i * 50 + 30);//��
			Sleep(500);
			i++;
		}
		while ((i < j) && p_quick[i] < temp)i++;
		if (i<j)
		{
			Equal(j, p_quick[i],p_quick);
			PenColor( 0,255, 0, p_quick[j],j * 50 + 30);//��
			Sleep(500);
			j--;
		}
	}
	Equal(i, temp,p_quick);
	PenColor(255, 255, 255, 60, i * 50 + 30);//��
	PenColor(0,255 , 0, p_quick[i], i * 50 + 30);//��
	Sleep(500);
	return i;
}


void CYYX_TEST1_3View::Copy(int* p)
{
	for(int i=0;i<len;i++)
	{
		p[i]=a[i];
	}
}


void CYYX_TEST1_3View::swap(int m, int n, int* p)
{
	CDC *pDC = GetDC();
	CString str;
	pDC->FillSolidRect(CRect(30, m * 50 + 10, 50, m * 50 + 30), RGB(255, 255, 255));//���Ǿ������������
	str.Format(TEXT("%d"),p[n]);
	pDC->TextOutW(30, m * 50 + 10, str);//����λ��
	pDC->FillSolidRect(CRect(30, n * 50 + 10, 50, n * 50 + 30), RGB(255, 255, 255));//���Ǿ������������
	str.Format(TEXT("%d"), p[m]);
	pDC->TextOutW(30, n * 50 + 10, str);//����λ��
	
	int temp =p[m];
	p[m] =p[n];
	p[n]= temp;
}


void CYYX_TEST1_3View::QuickSort(int low, int high)
{
	if (high <= low)return;
	pivot = Partition(low, high);
	QuickSort(low, pivot - 1);
	QuickSort(pivot + 1, high);
}


void CYYX_TEST1_3View::Equal(int m, int n, int* p)
{
	CDC *pDC = GetDC();
	CString str;
	pDC->FillSolidRect(CRect(30, m * 50 + 10, 50, m * 50 + 30), RGB(255, 255, 255));//���Ǿ������������
	str.Format(TEXT("%d"), n);
	pDC->TextOutW(30, m * 50 + 10, str);//����λ��

	p[m] = n;
}


void CYYX_TEST1_3View::Copy1(int* p)
{
	for(int i=0;i<len;i++)
	{
		a[i]=p[i];
	}
}
