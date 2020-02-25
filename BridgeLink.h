///////////////////////////////////////////////////////////////////////
// BridgeLink - BridgeLink Extensible Application Framework
// Copyright © 1999-2020  Washington State Department of Transportation
//                        Bridge and Structures Office
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the Alternate Route Open Source License as 
// published by the Washington State Department of Transportation, 
// Bridge and Structures Office.
//
// This program is distributed in the hope that it will be useful, but 
// distribution is AS IS, WITHOUT ANY WARRANTY; without even the implied 
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See 
// the Alternate Route Open Source License for more details.
//
// You should have received a copy of the Alternate Route Open Source 
// License along with this program; if not, write to the Washington 
// State Department of Transportation, Bridge and Structures Office, 
// P.O. Box  47340, Olympia, WA 98503, USA or e-mail 
// Bridge_Support@wsdot.wa.gov
///////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp:
// See BridgeLink.cpp for the implementation of this class
//

#include <BridgeLinkConfiguration.h>

interface IBridgeLink
{
   virtual void GetUserInfo(CString* pstrEngineer,CString* pstrCompany) = 0;
   virtual void SetUserInfo(const CString& strEngineer,const CString& strCompany) = 0;
   virtual IDType Register(IBridgeLinkConfigurationCallback* pCallback) = 0;
   virtual bool UnregisterCallback(IDType ID) = 0;
};

class CBridgeLinkApp : public CEAFPluginApp, public IBridgeLink
{
public:
	CBridgeLinkApp();
   ~CBridgeLinkApp();

// IBridgeLink
   virtual void GetUserInfo(CString* pstrEngineer,CString* pstrCompany) override;
   virtual void SetUserInfo(const CString& strEngineer,const CString& strCompany) override;
   virtual IDType Register(IBridgeLinkConfigurationCallback* pCallback) override;
   virtual bool UnregisterCallback(IDType ID) override;

   virtual void OnFirstRun() override;
   void Configure();

// CEAFPluginApp overrides
public:
   virtual OLECHAR* GetAppPluginCategoryName() override;
   virtual CATID GetAppPluginCategoryID() override;
   virtual OLECHAR* GetPluginCategoryName() override;
   virtual CATID GetPluginCategoryID() override;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBridgeLinkApp)
	public:
	virtual BOOL InitInstance() override;
	virtual int ExitInstance() override;
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBridgeLinkApp)
	afx_msg void OnAppAbout();
	afx_msg void OnHelpJoinArpList();
	afx_msg void OnHelpInetWsdot();
	afx_msg void OnHelpInetBridgeLink();
   afx_msg void OnHelpInetARP();
   afx_msg void OnScreenSize();
   afx_msg void OnConfigureUpdateUI(CCmdUI* pCmdUI);
   afx_msg void OnConfigure();
   afx_msg void OnHelp();
	//}}AFX_MSG
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) override;
	DECLARE_MESSAGE_MAP()

protected:
   virtual CEAFSplashScreenInfo GetSplashScreenInfo() override;
   virtual LPCTSTR GetRegistryKey() override;
   virtual CMDIFrameWnd* CreateMainFrame() override;
   virtual CATID GetComponentInfoCategoryID() override;
   virtual CString GetProductCode() override;
   virtual CString GetDocumentationRootLocation() override;

public:
   CString GetVersion(bool bIncludeBuildNumber) const;
   CString GetVersionString(bool bIncludeBuildNumber) const;

   // URL's
   CString GetWsdotUrl();
   CString GetWsdotBridgeUrl();
   CString GetBridgeLinkUrl();

private:
   virtual void RegistryInit() override; // All registry initialization goes here
   virtual void RegistryExit() override; // All registry cleanup goes here

   IDType m_CallbackID;
   std::map<IDType,IBridgeLinkConfigurationCallback*> m_ConfigurationCallbacks;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRIDGELINK_H__0553A0AE_B8F3_454D_9146_0B973C138288__INCLUDED_)
