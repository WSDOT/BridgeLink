///////////////////////////////////////////////////////////////////////
// BridgeLink - BridgeLink Extensible Application Framework
// Copyright © 1999-2017  Washington State Department of Transportation
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

#pragma once

#include "ConfigureBridgeLinkPage.h"

// CConfigureBridgeLinkDlg


class CConfigureBridgeLinkDlg : public CPropertySheet, public IBridgeLinkConfigurationParent
{
	DECLARE_DYNAMIC(CConfigureBridgeLinkDlg)

public:
	CConfigureBridgeLinkDlg(std::map<IDType,IBridgeLinkConfigurationCallback*>& configurationPageCallbacks, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	virtual ~CConfigureBridgeLinkDlg();

   CConfigureBridgeLinkPage m_BridgeLinkPage;

   virtual INT_PTR DoModal() override;
   virtual BOOL OnInitDialog() override;

   // IBridgeLinkConfigurationParent
   virtual LRESULT GetBackPage() override;
   virtual LRESULT GetNextPage() override;

protected:
   std::vector<LRESULT> m_Pages;
   std::vector<LRESULT>::iterator m_CurrentPage;

   DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnKickIdle(WPARAM, LPARAM);

   bool IsLastPage();
   bool IsFirstPage();
   void Init(std::map<IDType,IBridgeLinkConfigurationCallback*>& configurationPageCallbacks);
   void DestroyExtensionPages();
   void NotifyExtensionPages();
   std::vector<std::pair<IBridgeLinkConfigurationCallback*,CPropertyPage*>> m_vExtensionPages;
};


