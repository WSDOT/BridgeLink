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

// BridgeLinkView2.cpp : implementation file
//

#include "stdafx.h"
#include "BridgeLinkView2.h"


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
