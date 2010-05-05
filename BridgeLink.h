// BridgeLink.h : main header file for the BRIDGELINK application
//

#if !defined(AFX_BRIDGELINK_H__0553A0AE_B8F3_454D_9146_0B973C138288__INCLUDED_)
#define AFX_BRIDGELINK_H__0553A0AE_B8F3_454D_9146_0B973C138288__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include <EAF\EAFApp.h>
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp:
// See BridgeLink.cpp for the implementation of this class
//

class CBridgeLinkApp : public CEAFPluginApp
{
public:
	CBridgeLinkApp();
   ~CBridgeLinkApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBridgeLinkApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBridgeLinkApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
   virtual CString GetProductCode();
   virtual LPCTSTR GetRegistryKey();
   virtual OLECHAR* GetAppPluginCategoryName();
   virtual CATID GetAppPluginCategoryID();
   virtual CEAFSplashScreenInfo GetSplashScreenInfo();
   virtual CATID GetComponentInfoCategoryID();
public:
   virtual void OnAbout(void);
   afx_msg void OnManagePlugins();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRIDGELINK_H__0553A0AE_B8F3_454D_9146_0B973C138288__INCLUDED_)
