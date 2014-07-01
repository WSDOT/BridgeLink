///////////////////////////////////////////////////////////////////////
// BridgeLink - BridgeLink Extensible Application Framework
// Copyright © 1999-2014  Washington State Department of Transportation
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

// BridgeLink.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"

#include <initguid.h>

#include "BridgeLink.h"
#include "AboutDlg.h"

#include "BridgeLinkCATID.h"

#include "BridgeLinkCommandIDs.h"
#include "ScreenSizeDlg.h"
#include "MainFrm.h"


// This is the range of command IDs for all plug-in commands... all means all commands added
// to the menus of the BridgeLink executable program, the AppPlugin document and view menus, 
// and plugin supplied menus, toolbars, and accelerator tables
#define BRIDGELINK_FIRST_PLUGIN_COMMAND 0x8200
#define BRIDGELINK_LAST_PLUGIN_COMMAND  (BRIDGELINK_FIRST_PLUGIN_COMMAND+0x0100)
#define BRIDGELINK_PLUGIN_COMMAND_COUNT (BRIDGELINK_LAST_PLUGIN_COMMAND-BRIDGELINK_FIRST_PLUGIN_COMMAND)

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp

BEGIN_MESSAGE_MAP(CBridgeLinkApp, CEAFPluginApp)
	//{{AFX_MSG_MAP(CBridgeLinkApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_HELP_JOINARPLIST, OnHelpJoinArpList)
	ON_COMMAND(ID_HELP_INET_WSDOT, OnHelpInetWsdot)
	ON_COMMAND(ID_HELP_INET_BRIDGELINK, OnHelpInetBridgeLink)
   ON_COMMAND(ID_HELP_INET_ARP, OnHelpInetARP)
   ON_COMMAND(ID_SCREEN_SIZE,OnScreenSize)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp construction

CBridgeLinkApp::CBridgeLinkApp()
{
   SetHelpMode(afxHTMLHelp);
}

CBridgeLinkApp::~CBridgeLinkApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBridgeLinkApp object

CBridgeLinkApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp initialization
CString CBridgeLinkApp::GetProductCode()
{
   // Return the Product Code from InstallShield
   // This code uniquely identifies BridgeLink so do not change it
#if defined _WIN64
   return "{88563058-642A-455E-9001-A0BD8B71A793}";
#else
   return "{E95DA66F-6C17-48D1-8B16-40EAB5D2424C}";
#endif
}

LPCTSTR CBridgeLinkApp::GetRegistryKey()
{
   return _T("Washington State Department of Transportation");
}

OLECHAR* CBridgeLinkApp::GetAppPluginCategoryName()
{
   return _T("BridgeLink Application Plugin");
}

CATID CBridgeLinkApp::GetAppPluginCategoryID()
{
   return CATID_BridgeLinkAppPlugin;
}

CEAFSplashScreenInfo CBridgeLinkApp::GetSplashScreenInfo()
{
   CBitmap bmp;
   CEAFSplashScreenInfo info;

   VERIFY(bmp.LoadBitmap(IDB_SPLASH));
   info.m_hBitmap = bmp;
   info.m_TextColor = WHITE; // color of the information text drawn onto the splash screen
   info.m_TextFormat = DT_TOP | DT_LEFT | DT_SINGLELINE | DT_MODIFYSTRING | DT_END_ELLIPSIS | DT_WORDBREAK;
   info.m_TextRect = CRect(120,110,515,315); // rectangle on the splash screen bitmap where text is written

   bmp.Detach();

   return info;
}

CMDIFrameWnd* CBridgeLinkApp::CreateMainFrame()
{
   // don't call base class, the functionality is being replaced
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
   {
      delete pMainFrame;
		return NULL;
   }

   // files can be opened with drag and drop
   pMainFrame->DragAcceptFiles(TRUE);

   return pMainFrame;
}

CATID CBridgeLinkApp::GetComponentInfoCategoryID()
{
   return CATID_BridgeLinkComponentInfo;
}


BOOL CBridgeLinkApp::InitInstance()
{
   //_crtBreakAlloc = 6058895; // causes program to break at a specific memory allocation

   // Tip of the Day
   // Get the names of all the *.tip files in the application folder
   std::vector<CString> strTipFiles;
   CFileFind finder;
   CString str(GetAppLocation());
#if defined _DEBUG
#if defined _WIN64
   str.Replace(_T("RegFreeCOM\\x64\\Debug\\"),_T(""));
#else
   str.Replace(_T("RegFreeCOM\\Win32\\Debug\\"),_T(""));
#endif
#else
   // in a real release, the path doesn't contain RegFreeCOM\\Release, but that's
   // ok... the replace will fail and the string wont be altered.
#if defined _WIN64
   str.Replace(_T("RegFreeCOM\\x64\\Release\\"),_T(""));
#else
   str.Replace(_T("RegFreeCOM\\Win32\\Release\\"),_T(""));
#endif
#endif
   str += CString(_T("*.tip"));
   BOOL bWorking = finder.FindFile(str);
   while ( bWorking )
   {
      bWorking = finder.FindNextFile();
      CString strTipFile = finder.GetFilePath();
      strTipFiles.push_back(strTipFile);
   }
   EnableTipOfTheDay(strTipFiles);
   
   // Reserve the total range of command IDs that can be used for ALL BridgeLink App Plugins.
   // ALL means all commands added to the menus of the main executable, the 
   // EAFAppPlugin document and view menus, and plugin supplied menus,
   // toolbars, and accelerator tables
   CEAFPluginCommandManager::ReserveTotalCommandIDRange(BRIDGELINK_FIRST_PLUGIN_COMMAND,BRIDGELINK_LAST_PLUGIN_COMMAND);

   // Reserve BRIDGELINK_PLUGIN_COMMAND_COUNT command IDs for commands that get added
   // to the main application
   GetPluginCommandManager()->ReserveCommandIDRange(BRIDGELINK_PLUGIN_COMMAND_COUNT);

   // user can dbl-click on a file to open
   EnableShellOpen();

   // Help file defaults to the location of the application
   // In our development environment, it is in the \ARP\BridgeLink folder
   //
   // Change help file name
   CString strHelpFile(m_pszHelpFilePath);
#if defined _DEBUG
#if defined _WIN64
   strHelpFile.Replace(_T("RegFreeCOM\\x64\\Debug\\"),_T(""));
#else
   strHelpFile.Replace(_T("RegFreeCOM\\Win32\\Debug\\"),_T(""));
#endif
#else
   // in a real release, the path doesn't contain RegFreeCOM\\Release, but that's
   // ok... the replace will fail and the string wont be altered.
#if defined _WIN64
   strHelpFile.Replace(_T("RegFreeCOM\\x64\\Release\\"),_T(""));
#else
   strHelpFile.Replace(_T("RegFreeCOM\\Win32\\Release\\"),_T(""));
#endif
#endif
   free((void*)m_pszHelpFilePath);
   m_pszHelpFilePath = _tcsdup(strHelpFile);

   if ( !CEAFPluginApp::InitInstance() )
   {
      return FALSE;
   }

   // Must be done after call to base class InitInstance because OLE has not been
   // initialized yet.
   //sysComCatMgr::CreateCategory(_T("BridgeLink Application Plugin"),CATID_BridgeLinkAppPlugin); // this is done by the base class
   sysComCatMgr::CreateCategory(_T("BridgeLink Components"),CATID_BridgeLinkComponentInfo);

	return TRUE;
}

int CBridgeLinkApp::ExitInstance() 
{
   return CEAFApp::ExitInstance();
}


/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp message handlers

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp commands

CString CBridgeLinkApp::GetVersion(bool bIncludeBuildNumber) const
{
   CString strExe( m_pszExeName );
   strExe += _T(".exe");

   CVersionInfo verInfo;
   verInfo.Load(strExe);
   
   CString strVersion = verInfo.GetProductVersionAsString();

#if defined _DEBUG || defined _BETA_VERSION
   // always include the build number in debug and beta versions
   bIncludeBuildNumber = true;
#endif

   if (!bIncludeBuildNumber)
   {
      // remove the build number
      int pos = strVersion.ReverseFind(_T('.')); // find the last '.'
      strVersion = strVersion.Left(pos);
   }

   return strVersion;
}

CString CBridgeLinkApp::GetVersionString(bool bIncludeBuildNumber) const
{
   CString str(_T("Version "));
   str += GetVersion(bIncludeBuildNumber);
#if defined _BETA_VERSION
   str += CString(_T(" BETA"));
#endif

   str += CString(_T(" - Built on "));
   str += CString(__DATE__);
   return str;
}

void CBridgeLinkApp::RegistryInit()
{
   // Application wide settings go under BridgeLink
   // Each application plug in will create it's own hive in the registry
   // We need to tweek the name here because this is actually the BridgeLink.exe
   free((void*)m_pszProfileName);
   m_pszProfileName = _tcsdup(_T("BridgeLink"));

   CEAFPluginApp::RegistryInit();
}

void CBridgeLinkApp::RegistryExit()
{
   CEAFPluginApp::RegistryExit();
}

void CBridgeLinkApp::OnScreenSize()
{
   CEAFMainFrame* pFrame = EAFGetMainFrame();
   CScreenSizeDlg dlg;
   CRect rClient;
   pFrame->GetWindowRect(&rClient);
   dlg.m_Height = rClient.Height();
   dlg.m_Width  = rClient.Width();

   if ( dlg.DoModal() == IDOK )
   {
      int cx = dlg.m_Width;
      int cy = dlg.m_Height;
      pFrame->SetWindowPos(NULL,0,0,cx,cy,SWP_NOMOVE | SWP_NOZORDER);
   }
}

CString CBridgeLinkApp::GetWsdotUrl()
{
//   CString url = GetProfileString(_T("Settings"), _T("WsdotUrl"), _T("http://www.wsdot.wa.gov"));

   CString strDefault(_T("http://www.wsdot.wa.gov"));

   HKEY key;
   LONG result = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\Washington State Department of Transportation\\BridgeLink\\Settings"),0,KEY_QUERY_VALUE,&key);
   if ( result != ERROR_SUCCESS )
   {
      return strDefault;
   }

   TCHAR url[MAX_PATH];
   DWORD size = MAX_PATH;
   DWORD type;
   result = ::RegQueryValueEx(key,_T("WsdotUrl"),0,&type,(LPBYTE)&url[0],&size);
   if ( result != ERROR_SUCCESS )
   {
      return strDefault;
   }

   ::RegCloseKey(key);

   return url;
}

CString CBridgeLinkApp::GetWsdotBridgeUrl()
{
//   CString url = GetProfileString(_T("Settings"), _T("WsdotBridgeUrl"), _T("http://www.wsdot.wa.gov/eesc/bridge"));

   CString strDefault(_T("http://www.wsdot.wa.gov/eesc/bridge"));

   HKEY key;
   LONG result = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\Washington State Department of Transportation\\BridgeLink\\Settings"),0,KEY_QUERY_VALUE,&key);
   if ( result != ERROR_SUCCESS )
   {
      return strDefault;
   }

   TCHAR url[MAX_PATH];
   DWORD size = MAX_PATH;
   DWORD type;
   result = ::RegQueryValueEx(key,_T("WsdotBridgeUrl"),0,&type,(LPBYTE)&url[0],&size);
   if ( result != ERROR_SUCCESS )
   {
      return strDefault;
   }

   ::RegCloseKey(key);

   return url;
}

CString CBridgeLinkApp::GetBridgeLinkUrl()
{
   // NOTE: If URL isn't found in the registry, just go to the main software page.
//   CString url = GetProfileString(_T("Settings"), _T("BridgeLinkUrl"), _T("http://www.wsdot.wa.gov/eesc/bridge"));
#pragma Reminder("UPDATE: make this link go to the BridgeLink page")
   CString strDefault(_T("http://www.wsdot.wa.gov/eesc/bridge/software/index.cfm?fuseaction=software_detail&software_id=47"));

   HKEY key;
   LONG result = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\Washington State Department of Transportation\\BridgeLink\\Settings"),0,KEY_QUERY_VALUE,&key);
   if ( result != ERROR_SUCCESS )
   {
      return strDefault;
   }

   TCHAR url[MAX_PATH];
   DWORD size = MAX_PATH;
   DWORD type;
   result = ::RegQueryValueEx(key,_T("BridgeLinkUrl"),0,&type,(LPBYTE)&url[0],&size);
   if ( result != ERROR_SUCCESS )
   {
      return strDefault;
   }

   ::RegCloseKey(key);

   return url;
}

void CBridgeLinkApp::OnHelpInetWsdot() 
{
   HINSTANCE hInstance = ::ShellExecute(m_pMainWnd->GetSafeHwnd(),
                                        _T("open"),
                                        GetWsdotUrl(),
                                         0,0,SW_SHOWDEFAULT);

   if ( (INT)hInstance < 32 )
   {
      AfxMessageBox(IDS_E_ONLINERESOURCES);
   }
}

void CBridgeLinkApp::OnHelpJoinArpList()
{
   HINSTANCE hInstance = ::ShellExecute(m_pMainWnd->GetSafeHwnd(),
                                        _T("open"),
										_T("http://www.pgsuper.com/drupal/forum"),
                                         0,0,SW_SHOWDEFAULT);

   if ( (INT)hInstance < 32 )
   {
      AfxMessageBox(IDS_E_ONLINERESOURCES);
   }
}

void CBridgeLinkApp::OnHelpInetARP()
{
   HINSTANCE hInstance = ::ShellExecute(m_pMainWnd->GetSafeHwnd(),
                                        _T("open"),
                                        _T("http://wsdot.wa.gov/eesc/bridge/alternateroute"),
                                         0,0,SW_SHOWDEFAULT);

   if ( (INT)hInstance < 32 )
   {
      AfxMessageBox(IDS_E_ONLINERESOURCES);
   }
}

void CBridgeLinkApp::OnHelpInetBridgeLink() 
{
   HINSTANCE hInstance = ::ShellExecute(m_pMainWnd->GetSafeHwnd(),
                                        _T("open"),
                                        GetBridgeLinkUrl(),
                                        0,0,SW_SHOWDEFAULT);

   if ( (INT)hInstance < 32 )
   {
      AfxMessageBox(IDS_E_ONLINERESOURCES);
   }
}

// App command to run the dialog
void CBridgeLinkApp::OnAppAbout()
{
   CAboutDlg dlg;
   dlg.DoModal();
}

BOOL CBridgeLinkApp::OnCmdMsg(UINT nID,int nCode,void* pExtra,AFX_CMDHANDLERINFO* pHandlerInfo)
{
   // For some reason, this method is needed otherwise the base class version
   // doesn't get called... even though the base class method is virtual
   return CEAFPluginApp::OnCmdMsg(nID,nCode,pExtra,pHandlerInfo);
}
