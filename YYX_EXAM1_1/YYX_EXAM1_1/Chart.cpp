#include "stdafx.h"
#include "Chart.h"
#include "math.h"


Chart::Chart(void)
{
	sum=0;
	x1=392;
	y1=330;
	r=100;
}


Chart::~Chart(void)
{
}


void Chart::Init(void)
{
	consume.Init();
	diet.Init();
	amu.Init();
	cloth.Init();
	edu.Init();
	loan.Init();
}

void Chart::OnPaint(CDC* pDC)
{
	CFont Font;
	Font.CreatePointFont(100,TEXT("����"));

	CBitmap bitmap3;//�����Ƚ���һ��λͼ����
	bitmap3.LoadBitmap(311);
	BITMAP bmp3;
	bitmap3.GetBitmap(&bmp3);//������ǽ�λͼ�����е�ͼ�����ϷŽ�����ṹ����
	CDC dcCom3;//������׼DC���ڻ���λͼ
	dcCom3.CreateCompatibleDC(pDC);
	dcCom3.SelectObject(&bitmap3);
	//CRect rect;
	//GetClientRect(&rect);

	pDC->Ellipse(200,200,400,400);
	sum=sum+diet.money;
	CBrush br1(RGB(diet.R,diet.G,diet.B));
	pDC->SelectObject(&br1);
	x2=int(r*cos(sum*3.14*2)+300);
    y2=int(-r*sin(sum*3.14*2)+300);
	pDC->Pie(200,200,400,400,x1,y1,x2,y2);
	pDC->StretchBlt((x1+x2)/2,(y1+y2)/2,30,30,&dcCom3,0,0, bmp3.bmWidth,bmp3.bmHeight,SRCCOPY);
	x1=x2;
	y1=y2;
	pDC->Rectangle(500,50,520,70);
	pDC->TextOutW(530,50,TEXT("�Է�"));


	CBitmap bitmap4;//�����Ƚ���һ��λͼ����
	bitmap4.LoadBitmap(315);
	BITMAP bmp4;
	bitmap4.GetBitmap(&bmp4);//������ǽ�λͼ�����е�ͼ�����ϷŽ�����ṹ����
	CDC dcCom4;//������׼DC���ڻ���λͼ
	dcCom4.CreateCompatibleDC(pDC);
	dcCom4.SelectObject(&bitmap4);

	sum=sum+amu.money;
	CBrush br2(RGB(amu.R,amu.G,amu.B));
	pDC->SelectObject(&br2);
	x2=int(r*cos(sum*3.14*2)+300);
    y2=int(-r*sin(sum*3.14*2)+300);
	pDC->Pie(200,200,400,400,x1,y1,x2,y2);
	pDC->StretchBlt((x1+x2)/2,(y1+y2)/2,30,30,&dcCom4,0,0, bmp4.bmWidth,bmp4.bmHeight,SRCCOPY);
	x1=x2;
	y1=y2;
	pDC->Rectangle(500,90,520,110);
	pDC->TextOutW(530,90,TEXT("����"));

	CBitmap bitmap5;//�����Ƚ���һ��λͼ����
	bitmap5.LoadBitmap(314);
	BITMAP bmp5;
	bitmap5.GetBitmap(&bmp5);//������ǽ�λͼ�����е�ͼ�����ϷŽ�����ṹ����
	CDC dcCom5;//������׼DC���ڻ���λͼ
	dcCom5.CreateCompatibleDC(pDC);
	dcCom5.SelectObject(&bitmap5);

	sum=sum+cloth.money;
	CBrush br3(RGB(cloth.R,cloth.G,cloth.B));
	pDC->SelectObject(&br3);
	x2=int(r*cos(sum*3.14*2)+300);
    y2=int(-r*sin(sum*3.14*2)+300);
	pDC->Pie(200,200,400,400,x1,y1,x2,y2);
	pDC->StretchBlt((x1+x2)/2,(y1+y2)/2,30,30,&dcCom5,0,0, bmp5.bmWidth,bmp5.bmHeight,SRCCOPY);
	x1=x2;
	y1=y2;
	pDC->Rectangle(500,130,520,150);
	pDC->TextOutW(530,130,TEXT("�·�"));


	CBitmap bitmap6;//�����Ƚ���һ��λͼ����
	bitmap6.LoadBitmap(313);
	BITMAP bmp6;
	bitmap6.GetBitmap(&bmp6);//������ǽ�λͼ�����е�ͼ�����ϷŽ�����ṹ����
	CDC dcCom6;//������׼DC���ڻ���λͼ
	dcCom6.CreateCompatibleDC(pDC);
	dcCom6.SelectObject(&bitmap6);

	sum=sum+edu.money;
	CBrush br4(RGB(edu.R,edu.G,edu.B));
	pDC->SelectObject(&br4);
	x2=int(r*cos(sum*3.14*2)+300);
    y2=int(-r*sin(sum*3.14*2)+300);
	pDC->Pie(200,200,400,400,x1,y1,x2,y2);
	pDC->StretchBlt((x1+x2)/2,(y1+y2)/2,30,30,&dcCom6,0,0, bmp5.bmWidth,bmp5.bmHeight,SRCCOPY);
	x1=x2;
	y1=y2;
	sum=sum+loan.money;
	pDC->Rectangle(500,170,520,190);
	pDC->TextOutW(530,170,TEXT("����"));

	CBitmap bitmap7;//�����Ƚ���һ��λͼ����
	bitmap7.LoadBitmap(312);
	BITMAP bmp7;
	bitmap7.GetBitmap(&bmp7);//������ǽ�λͼ�����е�ͼ�����ϷŽ�����ṹ����
	CDC dcCom7;//������׼DC���ڻ���λͼ
	dcCom7.CreateCompatibleDC(pDC);
	dcCom7.SelectObject(&bitmap7);

	CBrush br5(RGB(loan.R,loan.G,loan.B));
	pDC->SelectObject(&br5);
	x2=int(r*cos(sum*3.14*2)+300);
    y2=int(-r*sin(sum*3.14*2)+300);
	pDC->Pie(200,200,400,400,x1,y1,x2,y2);
	pDC->StretchBlt((x1+x2)/2,(y1+y2)/2,30,30,&dcCom7,0,0, bmp5.bmWidth,bmp5.bmHeight,SRCCOPY);
	x1=x2;
	y1=y2;
	pDC->Rectangle(500,210,520,230);
	pDC->TextOutW(530,210,TEXT("����"));




}