
// YYX_TEST1_3View.cpp : CYYX_TEST1_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CYYX_TEST1_3View 构造/析构

CYYX_TEST1_3View::CYYX_TEST1_3View()
{
	// TODO: 在此处添加构造代码

}

CYYX_TEST1_3View::~CYYX_TEST1_3View()
{
}

BOOL CYYX_TEST1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CYYX_TEST1_3View 绘制

void CYYX_TEST1_3View::OnDraw(CDC* pDC)
{
	CYYX_TEST1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CFont font;
	font.CreatePointFont(1000,TEXT("楷体"));
	pDC->TextOutW(500,200,TEXT("选择生成随机数，选择排序方式，选择开始方式后开始"));
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CYYX_TEST1_3View 打印

BOOL CYYX_TEST1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CYYX_TEST1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CYYX_TEST1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CYYX_TEST1_3View 诊断

#ifdef _DEBUG
void CYYX_TEST1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CYYX_TEST1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYYX_TEST1_3Doc* CYYX_TEST1_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYYX_TEST1_3Doc)));
	return (CYYX_TEST1_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CYYX_TEST1_3View 消息处理程序


void CYYX_TEST1_3View::OnGet10Number()
{
	len=10;
	sleeptime=800;
	a=new int[len];
	for(int i=0;i<10;i++){
		a[i]=rand()%60;
	}
	DisplayNum();
	// TODO: 在此添加命令处理程序代码
}


void CYYX_TEST1_3View::Onbubblesort()
{
	cont=0;
	is_sort=1;
	// TODO: 在此添加命令处理程序代码
}


void CYYX_TEST1_3View::OnSelectionSort()
{
	cont=0;
	is_sort=2;
	// TODO: 在此添加命令处理程序代码
}


void CYYX_TEST1_3View::OnQuickSort()
{
	cont=0;
	is_sort=3;
	// TODO: 在此添加命令处理程序代码
}


void CYYX_TEST1_3View::Onstart_01()
{
	is_start=0;
	if(is_sort==1)
	{
		bubble=FALSE;
		selection=FALSE;
		quick=FALSE;
		if (!(bubble || selection || quick))//当没有一个为true时
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
		if (!bubble || selection || quick)//当没有一个为true时
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
		if (!(bubble || selection || quick))//当没有一个为true时
		{
			quick = TRUE;
			selection = FALSE;
			bubble= FALSE;
			p_quick = new int[len];
			Copy(p_quick);
			QuickSort(low, high);
			MessageBox(L"快速排序结束！");
			quick = FALSE;
		}
	}
	// TODO: 在此添加命令处理程序代码
}


void CYYX_TEST1_3View::Onstart_02()
{
	is_start=2;
	// TODO: 在此添加命令处理程序代码
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
		else if (!(bubble || selection || quick))//当没有一个为true时
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
		else if (!bubble || selection || quick)//当没有一个为true时
		{
			bubble=FALSE;
			selection=FALSE;
			quick=FALSE;
			if (!bubble || selection || quick)//当没有一个为true时
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
		if (!(bubble || selection || quick))//当没有一个为true时
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
			MessageBox(L"快速排序结束！");
			quick = FALSE;
		}
	}
	cont++;
	// TODO: 在此添加命令处理程序代码
}


void CYYX_TEST1_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1:
		if(bubble)//判断是否为冒泡
		{
			if (last == 0)//判断冒泡结束
			{
				PenColor(0, 255, 0, p_bubble[last] ,30 );//画线
				KillTimer(1);//结束定时器
				MessageBox(L"冒泡排序完成！");
				bubble = FALSE;
			}
			else if (first == last)//判断一轮的冒泡函数是否结束
			{
				PenColor(0, 255, 0,p_bubble[last] ,last * 50 + 30);
				last--;
				first = 0;
				if(is_start==2) //判断是否为单步进行
				{
					Copy1(p_bubble);//保存单步进行的值
					KillTimer(1);//结束定时器
				}
			}
			else
			{
				PenColor(255, 0, 0,p_bubble[first] , first * 50 + 30); 
				Sleep(sleeptime);
				if (p_bubble[first] > p_bubble[first + 1])//判断当前的值是否比后面的值大
				{
					swap(first, first + 1,p_bubble); //将数字重新绘制且交换值。
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
			MessageBox(L"结束！");
			bubble = FALSE;
		}
		break;
	case 2:
		if (selection)//判断是否为选择排序
		{
			if (first == len)//判断选择排序是否结束
			{
				KillTimer(2);
				MessageBox(L"选择排序结束！");
				selection = FALSE;
			}
			else if (first < len)
			{
				if (first2<len)
				{
					PenColor(255, 0, 0,p_selection[first2],first2 * 50 + 30);//红
					Sleep(sleeptime);
					PenColor(0, 0, 0,p_selection[first2], first2 * 50 + 30);//黑
					if (p_selection[first2]<p_selection[minIndex])minIndex = first2;
					first2++;
				}
				else
				{
					if (minIndex == first)//如果相等一轮选择排序，没有结束
					{
						PenColor(0, 255, 0,p_selection[first2], first * 50 + 30);//红
						first++;
						minIndex = first;
						first2 = minIndex + 1;
					}
					else //一轮选择排序结束
					{
						swap(minIndex, first,p_selection);
						PenColor(255, 255, 255,60,first * 50 + 30);//白

						PenColor(0, 255, 0, p_selection[first],first * 50 + 30);//绿

						PenColor(0, 0, 0,p_selection[first], minIndex * 50 + 30);//黑

						first++;
						minIndex = first;
						first2 = minIndex + 1;
						Sleep(sleeptime);
						if(is_start==2) //判断是否为单步排序
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
			MessageBox(L"结束！");
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
		pDC->FillSolidRect(CRect(30, i * 50 + 10, 50, i * 50 + 30), RGB(255, 255, 255));//覆盖矩形区域的数字
		PenColor(255, 255, 255, 60, i * 50 + 30);//清理上次的图像
		PenColor(0, 0, 0, a[i], i * 50 + 30);//画图
		str.Format(TEXT("%d"), a[i]);
		pDC->TextOutW(30, i * 50 + 10, str);//数字位置
		//pDC->FillSolidRect(CRect(300, 300, 400, 350), RGB(0, 255, 255));//覆盖矩形区域的数字
	}
	ReleaseDC(pDC);
}


void CYYX_TEST1_3View::PenColor(int r, int g, int b, int x, int y)
{
	CDC *pDC =GetDC();
	CPen pPen;
	
	pPen.CreatePen(PS_SOLID, 10, RGB(r, g, b)); //黑色的笔宽度为10
	pDC->SelectObject(&pPen);//替换为定义的pPen
	pDC->MoveTo(40,y);//利用CDC的成员函数画线
	pDC->LineTo((x+40)*5, y);
	ReleaseDC(pDC);//释放DC
}


int CYYX_TEST1_3View::Partition(int low, int high)
{
	int temp;//存放轴值的临时变量
	int i = low, j = high;
	temp = p_quick[low];
	while (i < j)
	{
		while ((i < j) && temp <= p_quick[j])j--;
		if (i<j)
		{
			Equal(i, p_quick[j],p_quick);
			PenColor(255,255, 255, 60, i * 50 + 30);//白
			PenColor(0,255 , 0, p_quick[i], i * 50 + 30);//绿
			Sleep(500);
			i++;
		}
		while ((i < j) && p_quick[i] < temp)i++;
		if (i<j)
		{
			Equal(j, p_quick[i],p_quick);
			PenColor( 0,255, 0, p_quick[j],j * 50 + 30);//绿
			Sleep(500);
			j--;
		}
	}
	Equal(i, temp,p_quick);
	PenColor(255, 255, 255, 60, i * 50 + 30);//白
	PenColor(0,255 , 0, p_quick[i], i * 50 + 30);//绿
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
	pDC->FillSolidRect(CRect(30, m * 50 + 10, 50, m * 50 + 30), RGB(255, 255, 255));//覆盖矩形区域的数字
	str.Format(TEXT("%d"),p[n]);
	pDC->TextOutW(30, m * 50 + 10, str);//数字位置
	pDC->FillSolidRect(CRect(30, n * 50 + 10, 50, n * 50 + 30), RGB(255, 255, 255));//覆盖矩形区域的数字
	str.Format(TEXT("%d"), p[m]);
	pDC->TextOutW(30, n * 50 + 10, str);//数字位置
	
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
	pDC->FillSolidRect(CRect(30, m * 50 + 10, 50, m * 50 + 30), RGB(255, 255, 255));//覆盖矩形区域的数字
	str.Format(TEXT("%d"), n);
	pDC->TextOutW(30, m * 50 + 10, str);//数字位置

	p[m] = n;
}


void CYYX_TEST1_3View::Copy1(int* p)
{
	for(int i=0;i<len;i++)
	{
		a[i]=p[i];
	}
}
