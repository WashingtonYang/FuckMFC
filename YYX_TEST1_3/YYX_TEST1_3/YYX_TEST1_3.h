
// YYX_TEST1_3.h : YYX_TEST1_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CYYX_TEST1_3App:
// �йش����ʵ�֣������ YYX_TEST1_3.cpp
//

class CYYX_TEST1_3App : public CWinApp
{
public:
	CYYX_TEST1_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CYYX_TEST1_3App theApp;
