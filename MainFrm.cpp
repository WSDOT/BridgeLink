///////////////////////////////////////////////////////////////////////
// BridgeLink - BridgeLink Extensible Application Framework
// Copyright © 1999-2021  Washington State Department of Transportation
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


// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "BridgeLink.h"
#include "MainFrm.h"
#include "Resource.h"
#include "BridgeLink.hh"

#include "StartPageWndProvider.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CEAFMainFrame)

BEGIN_MESSAGE_MAP(CMainFrame, CEAFMainFrame)
   //{{AFX_MSG_MAP(CMainFrame)
   ON_WM_CREATE()
   //ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
   ON_COMMAND(ID_HELP_FINDER,OnHelpFinder)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame() :
CEAFMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
   if (CEAFMainFrame::OnCreate(lpCreateStruct) == -1)
      return -1;

   // Need to set the icon here so that GetIcon wont fail
   CWinApp* pApp = AfxGetApp();
   HICON hIcon = pApp->LoadIcon(IDR_MAINFRAME);
   SetIcon(hIcon,TRUE);
   SetIcon(hIcon,FALSE);
   
   return 0;
}

//void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam)
//{
//    if(nID == SC_CLOSE)
//    {
//       // Prompt user if he really wants to quit, but only if document is not dirty.
//       // Otherwise, MFC will give it's version of  "do you want to save?"
//       CDocument* pdocument = (CDocument*)GetDocument();
//       if (pdocument!=nullptr)
//       {
//          if (FALSE==pdocument->IsModified())
//          {
//             int st = AfxMessageBox("Do you really want to quit?",MB_YESNO);
//             if (st!=IDYES)
//             {
//                return; // don't quit
//             }
//          }
//       }
//    }
//
//    CEAFMainFrame::OnSysCommand(nID, lParam);
//}


/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
   CEAFMainFrame::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
   CEAFMainFrame::Dump(dc);
}
#endif //_DEBUG


CEAFStartPageWnd* CMainFrame::CreateStartPage()
{
   HKEY key;
   LONG result = ::RegOpenKeyEx(HKEY_CURRENT_USER,_T("SOFTWARE\\Washington State Department of Transportation\\BridgeLink\\Settings"),0,KEY_QUERY_VALUE,&key);
   if ( result != ERROR_SUCCESS )
   {
      return nullptr;
   }

   TCHAR strCLSID[MAX_PATH];
   DWORD size = MAX_PATH;
   DWORD type;
   result = ::RegQueryValueEx(key,_T("StartPageProvider"),0,&type,(LPBYTE)&strCLSID[0],&size);
   if ( result != ERROR_SUCCESS )
   {
      return nullptr;
   }

   ::RegCloseKey(key);

   CLSID clsid;
   HRESULT hr = ::CLSIDFromString(strCLSID,&clsid);
   if ( hr != NOERROR )
   {
      return nullptr;
   }

   CComPtr<IStartPageWndProvider> provider;
   if ( FAILED(provider.CoCreateInstance(clsid)) )
   {
      return nullptr;
   }

   return provider->CreateStartPage();
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnHelpFinder()
{
   EAFHelp(AfxGetAppName(), IDH_BRIDGELINK);
} 