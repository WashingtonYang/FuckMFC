
// YYX_EXAM1_1.h : YYX_EXAM1_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CYYX_EXAM1_1App:
// �йش����ʵ�֣������ YYX_EXAM1_1.cpp
//

class CYYX_EXAM1_1App : public CWinApp
{
public:
	CYYX_EXAM1_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CYYX_EXAM1_1App theApp;
