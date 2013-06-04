#include "stdafx.h"
#include "resource.h"
#include "AboutDlg.h"


CAboutDlg::CAboutDlg() : CEAFAboutDlg(AfxGetApp()->LoadIcon(IDR_MAINFRAME),IDD_ABOUTBOX)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CEAFAboutDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP

   DDX_Control(pDX,IDC_WSDOT,m_WSDOT);
   DDX_Control(pDX,IDC_TXDOT,m_TxDOT);
   DDX_Control(pDX,IDC_KDOT, m_KDOT);
   DDX_Control(pDX,IDC_BRIDGESIGHT,m_BridgeSight);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CEAFAboutDlg)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CAboutDlg::OnInitDialog() 
{
	CEAFAboutDlg::OnInitDialog();
	

   m_WSDOT.SetURL(_T("http://www.wsdot.wa.gov"));
   m_WSDOT.SetTooltip(_T("http://www.wsdot.wa.gov"));
   m_WSDOT.SizeToContent();

   m_TxDOT.SetURL(_T("http://www.dot.state.tx.us"));
   m_TxDOT.SetTooltip(_T("http://www.dot.state.tx.us"));
   m_TxDOT.SizeToContent();

   m_KDOT.SetURL(_T("http://www.ksdot.org"));
   m_KDOT.SetTooltip(_T("http://www.ksdot.org"));
   m_KDOT.SizeToContent();

   m_BridgeSight.SetURL(_T("http://www.bridgesight.com"));
   m_BridgeSight.SetTooltip(_T("http://www.bridgesight.com"));
   m_BridgeSight.SizeToContent();

   return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
