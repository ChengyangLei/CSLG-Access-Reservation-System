
// ������ѧԺ�Ž�ԤԼϵͳ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C������ѧԺ�Ž�ԤԼϵͳApp:
// �йش����ʵ�֣������ ������ѧԺ�Ž�ԤԼϵͳ.cpp
//

class C������ѧԺ�Ž�ԤԼϵͳApp : public CWinApp
{
public:
	C������ѧԺ�Ž�ԤԼϵͳApp();

	// ��д
public:
	virtual BOOL InitInstance();

	// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C������ѧԺ�Ž�ԤԼϵͳApp theApp;