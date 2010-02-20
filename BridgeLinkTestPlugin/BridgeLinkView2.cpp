// BridgeLinkView2.cpp : implementation file
//

#include "stdafx.h"
#include "bridgelinktestplugin.h"
#include "BridgeLinkView2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView2

IMPLEMENT_DYNCREATE(CBridgeLinkView2, CView)

CBridgeLinkView2::CBridgeLinkView2()
{
}

CBridgeLinkView2::~CBridgeLinkView2()
{
}


BEGIN_MESSAGE_MAP(CBridgeLinkView2, CView)
	//{{AFX_MSG_MAP(CBridgeLinkView2)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView2 drawing

void CBridgeLinkView2::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
   pDC->TextOut(0,0,"CBridgeLinkView2");
}

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView2 diagnostics

#ifdef _DEBUG
void CBridgeLinkView2::AssertValid() const
{
	CView::AssertValid();
}

void CBridgeLinkView2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView2 message handlers
