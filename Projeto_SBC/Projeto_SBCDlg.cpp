
// Projeto_SBCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Projeto_SBC.h"
#include "Projeto_SBCDlg.h"
#include "afxdialogex.h"

#include "CLIPSLink.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProjetoSBCDlg dialog

void CProjetoSBCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_ARQ, m_ARQ);
	DDX_Control(pDX, IDC_OC, m_OC);
	DDX_Control(pDX, IDC_VLC_BR, m_VLC_BR);
	DDX_Control(pDX, IDC_S_I, m_S_I);
	DDX_Control(pDX, IDC_P_I, m_P_I);
	DDX_Control(pDX, IDC_M_C, m_M_C);



	DDX_Text(pDX, IDC_V_E_S, i_V_E_S);
	DDV_MinMaxInt(pDX, i_V_E_S, 0, 9999);
	DDX_Text(pDX, IDC_V_E_T, i_V_E_T);
	DDV_MinMaxInt(pDX, i_V_E_T, 0, 9999);
	DDX_Text(pDX, IDC_V_E_SV, i_V_E_SV);
	DDV_MinMaxInt(pDX, i_V_E_SV, 0, 9999);
	DDX_Text(pDX, IDC_V_E_E, i_V_E_E);
	DDV_MinMaxInt(pDX, i_V_E_E, 0, 9999);
	DDX_Text(pDX, IDC_V_E_C, i_V_E_C);
	DDV_MinMaxInt(pDX, i_V_E_C, 0, 9999);
	DDX_Text(pDX, IDC_V_E_TS, i_V_E_TS);
	DDV_MinMaxInt(pDX, i_V_E_TS, 0, 9999);
	DDX_Text(pDX, IDC_V_E_D, i_V_E_D);
	DDV_MinMaxInt(pDX, i_V_E_D, 0, 9999);
	DDX_Text(pDX, IDC_V_S_C, i_V_S_C);
	DDV_MinMaxInt(pDX, i_V_S_C, 0, 9999);
	DDX_Text(pDX, IDC_V_S_TS, i_V_S_TS);
	DDX_Text(pDX, IDC_V_S_D, i_V_S_D);
	DDV_MinMaxInt(pDX, i_V_S_D, 0, 9999);

}

CProjetoSBCDlg::CProjetoSBCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Projeto_SBC_DIALOG, pParent)
	
	, i_V_E_S(0)
	, i_V_E_T(0)
	, i_V_E_SV(0)
	, i_V_E_E(0)
	, i_V_E_C(0)
	, i_V_E_TS(0)
	, i_V_E_D(0)
	, i_V_S_C(0)
	, i_V_S_TS(0)
	, i_V_S_D(0)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);


}



BEGIN_MESSAGE_MAP(CProjetoSBCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_RUN, &CProjetoSBCDlg::OnBnClickedRun)
//	ON_CBN_SELCHANGE(IDC_ARQ, &CProjetoSBCDlg::OnCbnSelchangeArq)
//ON_EN_CHANGE(IDC_V_E_S, &CProjetoSBCDlg::OnEnChangeVES)
//ON_CBN_SELCHANGE(IDC_COMBOBOXEX1, &CProjetoSBCDlg::OnCbnSelchangeComboboxex1)
END_MESSAGE_MAP()


// CProjetoSBCDlg message handlers

BOOL CProjetoSBCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_ARQ.DeleteTempMap();
	m_ARQ.AddString(_T("Bancada de Teste"));
	m_ARQ.AddString(_T("Célula de Teste"));
	m_ARQ.AddString(_T("Sistema Embarcado"));
	
	m_OC.DeleteTempMap();
	m_OC.AddString(_T("Até U$10K"));
	m_OC.AddString(_T("Entre U$10K e U$50k"));
	m_OC.AddString(_T("Acima de U$50k"));

	m_VLC_BR.DeleteTempMap();
	m_VLC_BR.AddString(_T("Conexão USB"));
	m_VLC_BR.AddString(_T("Ethernet"));
	m_VLC_BR.AddString(_T("Via barramento PXI"));

	m_S_I.DeleteTempMap();
	m_S_I.AddString(_T("Sim"));
	m_S_I.AddString(_T("Não"));
	
	m_P_I.DeleteTempMap();
	m_P_I.AddString(_T("Sim"));
	m_P_I.AddString(_T("Não"));

	m_M_C.DeleteTempMap();
	m_M_C.AddString(_T("Não"));
	m_M_C.AddString(_T("Sim e Não Críticas"));
	m_M_C.AddString(_T("Sim e Críticas"));


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProjetoSBCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	
		CDialogEx::OnSysCommand(nID, lParam);
	
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProjetoSBCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProjetoSBCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CProjetoSBCDlg::OnBnClickedRun()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);


	CCLIPSLink ClipsEnv;
	ClipsEnv.m_ARQ = m_ARQ.GetCurSel();
	ClipsEnv.m_OC = m_OC.GetCurSel();
	ClipsEnv.m_VLC_BR = m_VLC_BR .GetCurSel();
	ClipsEnv.m_S_I = m_S_I.GetCurSel();
	ClipsEnv.m_P_I = m_P_I.GetCurSel();
	ClipsEnv.m_M_C = m_M_C.GetCurSel();
	ClipsEnv.i_V_E_S = i_V_E_S;
	ClipsEnv.i_V_E_T = i_V_E_T;
	ClipsEnv.i_V_E_SV = i_V_E_SV;
	ClipsEnv.i_V_E_E = i_V_E_E;
	ClipsEnv.i_V_E_C = i_V_E_C;
	ClipsEnv.i_V_E_TS = i_V_E_TS;
	ClipsEnv.i_V_E_D = i_V_E_D;
	ClipsEnv.i_V_S_C = i_V_S_C;
	ClipsEnv.i_V_S_TS = i_V_S_TS;
	ClipsEnv.i_V_S_D = i_V_S_D;

	ClipsEnv.runCLIPS();

}

