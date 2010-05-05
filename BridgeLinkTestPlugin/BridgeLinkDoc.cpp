// BridgeLinkDoc.cpp : implementation of the CBridgeLinkDoc class
//

#include "stdafx.h"
#include "resource.h"
#include "BridgeLinkTestPluginApp.h"
#include "BridgeLinkDoc.h"

#include <EAF\EAFMainFrame.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
