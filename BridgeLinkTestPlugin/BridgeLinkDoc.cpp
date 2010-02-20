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

IMPLEMENT_DYNCREATE(CBridgeLinkDoc, CDocument)

BEGIN_MESSAGE_MAP(CBridgeLinkDoc, CDocument)
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
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkDoc serialization

void CBridgeLinkDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkDoc diagnostics

#ifdef _DEBUG
void CBridgeLinkDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBridgeLinkDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
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
