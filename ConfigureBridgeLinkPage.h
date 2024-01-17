///////////////////////////////////////////////////////////////////////
// BridgeLink - BridgeLink Extensible Application Framework
// Copyright © 1999-2024  Washington State Department of Transportation
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


// CConfigureBridgeLinkPage dialog

class CConfigureBridgeLinkPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CConfigureBridgeLinkPage)

public:
	CConfigureBridgeLinkPage();
	virtual ~CConfigureBridgeLinkPage();

   CString m_strEngineer;
   CString m_strCompany;
   BOOL m_bAutoSave;
   int m_AutoSaveInterval;

// Dialog Data
	enum { IDD = IDD_CONFIGURE_BRIDGELINK };

   virtual LRESULT OnWizardNext() override;
   virtual LRESULT OnWizardBack() override;

protected:
	virtual void DoDataExchange(CDataExchange* pDX) override;    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
   afx_msg void OnHelp();
public:
   virtual BOOL OnInitDialog() override;
   afx_msg void OnBnClickedAutosave();
};
