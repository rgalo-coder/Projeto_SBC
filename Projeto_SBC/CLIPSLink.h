#pragma once


//#include "Projeto_SBCDlg.h"

class CCLIPSLink
{

public:


	virtual int runCLIPS();

	int m_ARQ;
	int m_OC;
	int m_VLC_BR;
	int m_S_I;
	int m_P_I;
	int m_M_C;
	int i_V_E_S;
	int i_V_E_T;
	int i_V_E_SV;
	int i_V_E_E;
	int i_V_E_C;
	int i_V_E_TS;
	int i_V_E_D;
	int i_V_S_C;
	int i_V_S_TS;
	int i_V_S_D;

	void AssertIntValue(int var, CString CLIPSVariable, char* AssertInput);


};