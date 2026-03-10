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

// BridgeLinkDoc.cpp : implementation of the CBridgeLinkDoc class
//

#include "stdafx.h"
#include "resource.h"
#include "BridgeLinkTestPluginApp.h"
#include "BridgeLinkDoc.h"

#include <EAF\EAFMainFrame.h>

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkDoc

IMPLEMENT_DYNCREATE(CBridgeLinkDoc, CEAFDocument)

BEGIN_MESSAGE_MAP(CBridgeLinkDoc, CEAFDocument)
	//{{AFX_MSG_MAP(CBridgeLinkDoc)
	ON_COMMAND(ID_NEW_VIEW, OnNewView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkDoc construction/destruction

CBridgeLinkDoc::CBridgeLinkDoc()
{
	// TODO: add one-time construction code here

   EnableUIHints(FALSE); // not using UIHints feature
}

CBridgeLinkDoc::~CBridgeLinkDoc()
{
}

BOOL CBridgeLinkDoc::OnNewDocument()
{
	if (!CEAFDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

HRESULT CBridgeLinkDoc::WriteTheDocument(IStructuredSave* pStrSave)
{
   return S_OK;
}

HRESULT CBridgeLinkDoc::LoadTheDocument(IStructuredLoad* pStrLoad)
{
   return S_OK;
}

CString CBridgeLinkDoc::GetToolbarSectionName()
{
   return "BridgeLinkTest";
}

BOOL CBridgeLinkDoc::GetStatusBarMessageString(UINT nID,CString& rMessage) const
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return __super::GetStatusBarMessageString(nID,rMessage);
}

BOOL CBridgeLinkDoc::GetToolTipMessageString(UINT nID, CString& rMessage) const
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return __super::GetToolTipMessageString(nID,rMessage);
}

void CBridgeLinkDoc::LoadDocumentSettings()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   __super::LoadDocumentSettings();
}

void CBridgeLinkDoc::SaveDocumentSettings()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   __super::SaveDocumentSettings();
}

CString CBridgeLinkDoc::GetDocumentationRootLocation()
{
   CEAFApp* pApp = EAFGetApp();
   return pApp->GetDocumentationRootLocation();
}

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkDoc diagnostics

#ifdef _DEBUG
void CBridgeLinkDoc::AssertValid() const
{
	CEAFDocument::AssertValid();
}

void CBridgeLinkDoc::Dump(CDumpContext& dc) const
{
	CEAFDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkDoc commands

void CBridgeLinkDoc::OnNewView() 
{
   CBridgeLinkTestPluginApp* pApp;
   {
      AFX_MANAGE_STATE(AfxGetStaticModuleState());
      pApp = (CBridgeLinkTestPluginApp*)AfxGetApp();
   }

   CEAFMainFrame* pMainFrame = (CEAFMainFrame*)AfxGetMainWnd();
   pMainFrame->CreateOrActivateFrame( pApp->m_pSecondaryViewTemplate );
}

HINSTANCE CBridgeLinkDoc::GetResourceInstance()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return AfxGetInstanceHandle();
}