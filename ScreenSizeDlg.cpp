///////////////////////////////////////////////////////////////////////
// BridgeLink - BridgeLink Extensible Application Framework
// Copyright © 1999-2019  Washington State Department of Transportation
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


// ScreenSizeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BridgeLink.h"
#include "ScreenSizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScreenSizeDlg dialog


CScreenSizeDlg::CScreenSizeDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(CScreenSizeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScreenSizeDlg)
	m_Height = 0;
	m_Width = 0;
	//}}AFX_DATA_INIT
}


void CScreenSizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScreenSizeDlg)
	DDX_Text(pDX, IDC_HEIGHT, m_Height);
	DDV_MinMaxLong(pDX, m_Height, 20, 50000);
	DDX_Text(pDX, IDC_WIDTH, m_Width);
	DDV_MinMaxLong(pDX, m_Width, 20, 50000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScreenSizeDlg, CDialog)
	//{{AFX_MSG_MAP(CScreenSizeDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScreenSizeDlg message handlers
