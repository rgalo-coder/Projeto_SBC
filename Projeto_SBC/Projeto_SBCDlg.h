
// Projeto_SBCDlg.h : header file
//

#pragma once


// CProjetoSBCDlg dialog
class CProjetoSBCDlg : public CDialogEx
{
// Construction
public:
	CProjetoSBCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Projeto_SBC_DIALOG };
#endif

	protected:

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedRun();
//	afx_msg void OnCbnSelchangeArq();
//	afx_msg void OnEnChangeVES();
	CComboBox m_ARQ;
	CComboBox m_OC;
	CComboBox m_VLC_BR;
	CComboBox m_S_I;
	CComboBox m_P_I;
	CComboBox m_M_C;
		
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
//	afx_msg void OnCbnSelchangeComboboxex1();
	
};
