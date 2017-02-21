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

#include "ConfigureBridgeLinkDlg.h"


// This is the range of command IDs for all plug-in commands... all means all commands added
// to the menus of the BridgeLink executable program, the AppPlugin document and view menus, 
// and plugin supplied menus, toolbars, and accelerator tables. This is the range of commands
// that non-unique command IDs, provide by external components, get mapped into.
#define BRIDGELINK_FIRST_PLUGIN_COMMAND 0xADFF // the first plugin command will map to this command ID
#define BRIDGELINK_LAST_PLUGIN_COMMAND  0xDFFF // this is the end of the command range that MFC lets us use
#define BRIDGELINK_TOTAL_PLUGIN_COMMAND_COUNT (BRIDGELINK_LAST_PLUGIN_COMMAND-BRIDGELINK_FIRST_PLUGIN_COMMAND) // this is the total number of plug in commands that we will support
// we are reserving 12,800 command IDs for plug-in commands. Assuming each plugin reserves 256 (0x0100) commands, we can support a total of 50 plugins

// BridgeLink itself can accept plug-in commands. We have to carve out a little bit of the range defined above for our use.
#define BRIDGELINK_PLUGIN_COMMAND_COUNT 0x0100 // we'll reserve 256 command IDs for direct BridgeLink plug-in commands

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
   ON_COMMAND(ID_HELP,OnHelp)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
   ON_COMMAND(IDM_CONFIGURE_BRIDGELINK, &CBridgeLinkApp::OnConfigure)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp construction

CBridgeLinkApp::CBridgeLinkApp()
{
   m_CallbackID = 0;
}

CBridgeLinkApp::~CBridgeLinkApp()
{
}

void CBridgeLinkApp::GetUserInfo(CString* pstrEngineer,CString* pstrCompany)
{
   CString strDefaultCompany  = GetLocalMachineString(_T("Options"),_T("CompanyName"), _T("Your Company"));
   CString strDefaultEngineer = GetLocalMachineString(_T("Options"),_T("EngineerName"),_T("Your Name"));
   *pstrEngineer = GetProfileString(_T("Options"),_T("EngineerName"), strDefaultEngineer);
   *pstrCompany  = GetProfileString(_T("Options"),_T("CompanyName"), strDefaultCompany);
}

void CBridgeLinkApp::SetUserInfo(const CString& strEngineer,const CString& strCompany)
{
   VERIFY(WriteProfileString(_T("Options"), _T("EngineerName"), strEngineer));
   VERIFY(WriteProfileString(_T("Options"), _T("CompanyName"),  strCompany));
}

IDType CBridgeLinkApp::Register(IBridgeLinkConfigurationCallback* pCallback)
{
   IDType key = m_CallbackID++;
   m_ConfigurationCallbacks.insert(std::make_pair(key,pCallback));
   return key;
}

bool CBridgeLinkApp::UnregisterCallback(IDType ID)
{
   std::map<IDType,IBridgeLinkConfigurationCallback*>::iterator found = m_ConfigurationCallbacks.find(ID);
   if ( found == m_ConfigurationCallbacks.end() )
   {
      return false;
   }

   m_ConfigurationCallbacks.erase(found);

   return true;
}

void CBridgeLinkApp::OnFirstRun()
{
   Configure();
}

void CBridgeLinkApp::Configure()
{
   CConfigureBridgeLinkDlg dlg(m_ConfigurationCallbacks);

   GetUserInfo(&dlg.m_BridgeLinkPage.m_strEngineer,&dlg.m_BridgeLinkPage.m_strCompany);

   INT_PTR results = dlg.DoModal();
   if ( results == IDOK )
   {
      SetUserInfo(dlg.m_BridgeLinkPage.m_strEngineer,dlg.m_BridgeLinkPage.m_strCompany);
   }
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

CString CBridgeLinkApp::GetDocumentationRootLocation()
{
   if ( UseOnlineDocumentation() )
   {
      // NOTE: The following approach allows third party distributers to use their own server for documentation.
      // Their installer should write the documentation root location to HKLM\Settings\DocumentationRoot.
      // This value will be the default when the documenation root setting is read for a specific user from HKCU\Settings\DocumentationRoot
      // If the HKCU value isn't found, the default from HKLM is used.

      // Get the default location for the documentation root from the local machine registry hive
      // If not present, use the WSDOT location
      CString strDefaultDocumentationRootLocation = GetLocalMachineString(_T("Settings"),_T("DocumentationRoot"), _T("http://www.wsdot.wa.gov/eesc/bridge/software/Documentation/"));

      // Get the user's setting, using the local machine setting as the default if not present
      CString strDocumentationRootLocation = GetProfileString(_T("Settings"),_T("DocumentationRoot"),strDefaultDocumentationRootLocation);
      return strDocumentationRootLocation;
   }
   else
   {
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

      CString strLocation;
      strLocation.Format(_T("%sDocs\\"),str);
      return strLocation;
   }
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

OLECHAR* CBridgeLinkApp::GetPluginCategoryName()
{
   return _T("BridgeLink Plugin");
}

CATID CBridgeLinkApp::GetPluginCategoryID()
{
   return CATID_BridgeLinkPlugin;
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
		return nullptr;
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
   UINT nCommands = GetPluginCommandManager()->ReserveCommandIDRange(BRIDGELINK_PLUGIN_COMMAND_COUNT);
   ATLASSERT(nCommands == BRIDGELINK_PLUGIN_COMMAND_COUNT);

   // user can dbl-click on a file to open
   EnableShellOpen();

   if ( !CEAFPluginApp::InitInstance() )
   {
      return FALSE;
   }

   // Must be done after call to base class InitInstance because OLE has not been
   // initialized yet.
   //sysComCatMgr::CreateCategory(_T("BridgeLink Application Plugin"),CATID_BridgeLinkAppPlugin); // this is done by the base class
   sysComCatMgr::CreateCategory(_T("BridgeLink Components"),CATID_BridgeLinkComponentInfo);

   // Need to let drag and drop messages through
   // See http://helgeklein.com/blog/2010/03/how-to-enable-drag-and-drop-for-an-elevated-mfc-application-on-vistawindows-7/
   ::ChangeWindowMessageFilter(WM_DROPFILES,MSGFLT_ADD);
   ::ChangeWindowMessageFilter(WM_COPYDATA, MSGFLT_ADD);
   ::ChangeWindowMessageFilter(0x0049,      MSGFLT_ADD);

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
      pFrame->SetWindowPos(nullptr,0,0,cx,cy,SWP_NOMOVE | SWP_NOZORDER);
   }
}

void CBridgeLinkApp::OnHelp()
{
   // do nothing... just need this so MFC doesn't hide help buttons
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
   CString strDefault(_T("http://www.wsdot.wa.gov/eesc/bridge/software/index.cfm?fuseaction=software_detail&software_id=69"));
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

   if ( hInstance <= (HINSTANCE)HINSTANCE_ERROR )
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

   if ( hInstance <= (HINSTANCE)HINSTANCE_ERROR)
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

   if ( hInstance <= (HINSTANCE)HINSTANCE_ERROR )
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

   if ( hInstance <= (HINSTANCE)HINSTANCE_ERROR )
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

void CBridgeLinkApp::OnConfigure()
{
   Configure();
}
