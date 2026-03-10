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

// BridgeLinkView.cpp : implementation of the CBridgeLinkView class
//

#include "stdafx.h"

#include "BridgeLinkDoc.h"
#include "BridgeLinkView.h"

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
