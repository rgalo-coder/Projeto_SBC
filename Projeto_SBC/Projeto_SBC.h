
// Projeto_SBC.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProjetoSBCApp:
// See Projeto_SBC.cpp for the implementation of this class
//

class CProjetoSBCApp : public CWinApp
{
public:
	CProjetoSBCApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CProjetoSBCApp theApp;
