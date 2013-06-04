#pragma once

#include <EAF\EAFAboutDlg.h>
#include <afxlinkctrl.h>

class CAboutDlg : public CEAFAboutDlg
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

   CMFCLinkCtrl m_WSDOT;
   CMFCLinkCtrl m_TxDOT;
   CMFCLinkCtrl m_KDOT;
   CMFCLinkCtrl m_BridgeSight;
};
