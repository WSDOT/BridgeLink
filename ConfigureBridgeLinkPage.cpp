///////////////////////////////////////////////////////////////////////
// BridgeLink - BridgeLink Extensible Application Framework
// Copyright � 1999-2017  Washington State Department of Transportation
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

// ConfigureBridgeLinkPage.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "BridgeLink.h"
#include "ConfigureBridgeLinkPage.h"
#include "ConfigureBridgeLinkDlg.h"
#include "BridgeLink.hh"


// CConfigureBridgeLinkPage dialog

IMPLEMENT_DYNAMIC(CConfigureBridgeLinkPage, CPropertyPage)

CConfigureBridgeLinkPage::CConfigureBridgeLinkPage()
	: CPropertyPage(CConfigureBridgeLinkPage::IDD)
{
   m_psp.dwFlags |= PSP_USETITLE | PSP_DEFAULT | PSP_HASHELP | PSP_HIDEHEADER;
   m_psp.pszTitle = _T("Configure BridgeLink");
}

CConfigureBridgeLinkPage::~CConfigureBridgeLinkPage()
{
}

void CConfigureBridgeLinkPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
   DDX_Text(pDX,IDC_ENGINEER,m_strEngineer);
   DDX_Text(pDX,IDC_COMPANY,m_strCompany);
}


BEGIN_MESSAGE_MAP(CConfigureBridgeLinkPage, CPropertyPage)
   ON_COMMAND(ID_HELP,OnHelp)
END_MESSAGE_MAP()


// CConfigureBridgeLinkPage message handlers

void CConfigureBridgeLinkPage::OnHelp()
{
   CEAFApp* pApp = EAFGetApp();
   EAFHelp( pApp->m_pszAppName, IDH_CONFIGURE_BRIDGELINK );
}

LRESULT CConfigureBridgeLinkPage::OnWizardNext()
{
   if ( !UpdateData() )
      return -1;

   CConfigureBridgeLinkDlg* pParent = (CConfigureBridgeLinkDlg*)GetParent();
   return pParent->GetNextPage();
   //return CPropertyPage::OnWizardNext();
}

LRESULT CConfigureBridgeLinkPage::OnWizardBack()
{
   CConfigureBridgeLinkDlg* pParent = (CConfigureBridgeLinkDlg*)GetParent();
   return pParent->GetBackPage();

//   return CPropertyPage::OnWizardBack();
}

BOOL CConfigureBridgeLinkPage::OnInitDialog()
{
   CPropertyPage::OnInitDialog();

   // TODO:  Add extra initialization here

   return TRUE;  // return TRUE unless you set the focus to a control
   // EXCEPTION: OCX Property Pages should return FALSE
}