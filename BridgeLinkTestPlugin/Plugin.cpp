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

// Plugin.cpp : Implementation of CPlugin
#include "stdafx.h"
#include "resource.h"
#include "Plugin.h"

#include "ChildFrm.h"
#include "BridgeLinkDoc.h"
#include "BridgeLinkView.h"

BOOL CPlugin::Init(CEAFApp* pParent)
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   auto plugin = std::dynamic_pointer_cast<WBFL::EAF::IPluginApp>(shared_from_this());
   m_DocumentationImpl.Init(plugin);
   return TRUE;
}

void CPlugin::Terminate()
{
}

void CPlugin::IntegrateWithUI(BOOL bIntegrate)
{
}

std::vector<CEAFDocTemplate*> CPlugin::CreateDocTemplates()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());

   std::vector<CEAFDocTemplate*> templates;

   CEAFDocTemplate* pDocTemplate;
	pDocTemplate = new CEAFDocTemplate(
      IDR_EXAMPLE,
      nullptr,
		RUNTIME_CLASS(CBridgeLinkDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CBridgeLinkView),
      nullptr,1);

	auto pluginApp = std::dynamic_pointer_cast<WBFL::EAF::IPluginApp>(shared_from_this());
	pDocTemplate->SetPluginApp(pluginApp);
    pDocTemplate->CreateDefaultItem(AfxGetApp()->LoadStandardIcon(IDI_WINLOGO));

    templates.push_back(pDocTemplate);
    return templates;
}

HMENU CPlugin::GetSharedMenuHandle()
{
   return nullptr;
}

CString CPlugin::GetName()
{
   return CString("BridgeLink Test Plugin");
}

CString CPlugin::GetDocumentationSetName()
{
   return GetName();
}

CString CPlugin::GetDocumentationURL()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return m_DocumentationImpl.GetDocumentationURL();
}

CString CPlugin::GetDocumentationMapFile()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return m_DocumentationImpl.GetDocumentationMapFile();
}

void CPlugin::LoadDocumentationMap()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return m_DocumentationImpl.LoadDocumentationMap();
}

std::pair<WBFL::EAF::HelpResult,CString> CPlugin::GetDocumentLocation(LPCTSTR lpszDocSetName,UINT nID)
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return m_DocumentationImpl.GetDocumentLocation(lpszDocSetName,nID);
}
