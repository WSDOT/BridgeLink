// BridgeLinkView.cpp : implementation of the CBridgeLinkView class
//

#include "stdafx.h"

#include "BridgeLinkDoc.h"
#include "BridgeLinkView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView

IMPLEMENT_DYNCREATE(CBridgeLinkView, CView)

BEGIN_MESSAGE_MAP(CBridgeLinkView, CView)
	//{{AFX_MSG_MAP(CBridgeLinkView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView construction/destruction

CBridgeLinkView::CBridgeLinkView()
{
	// TODO: add construction code here

}

CBridgeLinkView::~CBridgeLinkView()
{
}

BOOL CBridgeLinkView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView drawing

void CBridgeLinkView::OnDraw(CDC* pDC)
{
	CBridgeLinkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
   pDC->TextOut(0,0,"CBridgeLinkView");
}

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView printing

BOOL CBridgeLinkView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBridgeLinkView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBridgeLinkView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView diagnostics

#ifdef _DEBUG
void CBridgeLinkView::AssertValid() const
{
	CView::AssertValid();
}

void CBridgeLinkView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBridgeLinkDoc* CBridgeLinkView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBridgeLinkDoc)));
	return (CBridgeLinkDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView message handlers
