
// YYX_TEST2_1.h : YYX_TEST2_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CYYX_TEST2_1App:
// �йش����ʵ�֣������ YYX_TEST2_1.cpp
//

class CYYX_TEST2_1App : public CWinAppEx
{
public:
	CYYX_TEST2_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CYYX_TEST2_1App theApp;
