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

#ifndef INCLUDED_APP_H_
#define INCLUDED_APP_H_

#include <EAF\EAFDocTemplate.h>
class CBridgeLinkTestPluginApp : public CWinApp
{
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBridgeLinkTestPluginApp)
	public:
    virtual BOOL InitInstance() override;
    virtual int ExitInstance() override;
 	 virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) override;

	//}}AFX_VIRTUAL

	//{{AFX_MSG(CBridgeLinkTestPluginApp)
	afx_msg void OnNewView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
   CEAFDocTemplate* m_pSecondaryViewTemplate;
   HMENU m_hSharedMenu;
};

#endif // INCLUDED_APP_H_