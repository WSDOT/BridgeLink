///////////////////////////////////////////////////////////////////////
// BridgeLink Example - BridgeLink Application Framework Example
// Copyright © 1999-2025  Washington State Department of Transportation
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

// BridgeLinkTestPlugin.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f BridgeLinkTestPluginps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include <EAF\PluginApp.h>
#include "Plugin.h"


#include "..\Include\BridgeLinkCATID.h"

#include "BridgeLinkTestPluginApp.h"

#include <EAF\EAFDocTemplate.h>
#include "BridgeLinkDoc.h"
#include "ChildFrame2.h"
#include "BridgeLinkView2.h"
#include "ComponentInfo.h"

#include <CLSID.h>
#include <EAF\ComponentModule.h>
WBFL::EAF::ComponentModule Module_;

EAF_BEGIN_OBJECT_MAP(ObjectMap2)
   EAF_OBJECT_ENTRY(CLSID_BridgeLinkExampleComponentInfo, CBridgeLinkExampleComponentInfo)
   EAF_OBJECT_ENTRY(CLSID_BridgeLinkExamplePluginApp, CPlugin)
EAF_END_OBJECT_MAP()

BEGIN_MESSAGE_MAP(CBridgeLinkTestPluginApp, CWinApp)
	//{{AFX_MSG_MAP(CBridgeLinkTestPluginApp)
//	ON_COMMAND(ID_NEW_VIEW, OnNewView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CBridgeLinkTestPluginApp theApp;

BOOL CBridgeLinkTestPluginApp::InitInstance()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());

   // Using a shared menu
   // See MSKB Article ID: Q118435, "Sharing Menus Between MDI Child Windows"
   m_hSharedMenu = nullptr; /*::LoadMenu( m_hInstance, MAKEINTRESOURCE(IDR_???) );*/

   m_pSecondaryViewTemplate = new CEAFDocTemplate(
      IDR_EXAMPLE,
      nullptr,
		RUNTIME_CLASS(CBridgeLinkDoc),
		RUNTIME_CLASS(CChildFrame2), // custom MDI child frame
		RUNTIME_CLASS(CBridgeLinkView2),
      m_hSharedMenu,2); // only create 2 of this type of view


   Module_.Init(ObjectMap2);
   return CWinApp::InitInstance();
}

int CBridgeLinkTestPluginApp::ExitInstance()
{
   delete m_pSecondaryViewTemplate;

   // if the doc template uses a shared menu, destroy it here
   // release the shared menu
   //::DestroyMenu( m_hSharedMenu );

   Module_.Term();
   return CWinApp::ExitInstance();
}

BOOL CBridgeLinkTestPluginApp::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
   // in order scan the message map for this plugin, the module state must be set
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return CWinApp::OnCmdMsg(nID,nCode,pExtra,pHandlerInfo);
}

void CBridgeLinkTestPluginApp::OnNewView() 
{
   AfxMessageBox(_T("Handling OnNewView from CBridgeLinkTestPluginApp"));
}
