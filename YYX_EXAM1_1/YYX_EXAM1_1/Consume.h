#pragma once


// Consume

class Consume : public CWnd
{
	DECLARE_DYNAMIC(Consume)

public:
	Consume();
	virtual ~Consume();
	float money;
	CString name;
	int R,G,B;
	
	

	

protected:
	DECLARE_MESSAGE_MAP()

public:
	void OnPaint(CDC* pDC);
	void Init(void);
};


