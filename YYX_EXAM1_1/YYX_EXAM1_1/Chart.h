#pragma once
#include "consume.h"
#include "Diet.h"
#include "Amusement.h"
#include "Cloth.h"
#include "Education.h"
#include "Loan.h"
class Chart
{
public:
	Chart(void);
	~Chart(void);

	Consume consume;
	Diet diet;
	Amusement amu;
	Cloth cloth;
	Education edu;
	Loan loan;
	int x1,x2;
	int y1,y2;
	int r;
	float sum;
	
	void Init(void);
	void OnPaint(CDC* pDC);
};

