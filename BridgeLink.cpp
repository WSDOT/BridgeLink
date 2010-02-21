// BridgeLink.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include <initguid.h>

#include "BridgeLink.h"
#include "AboutDlg.h"

#include "BridgeLinkCATID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp

BEGIN_MESSAGE_MAP(CBridgeLinkApp, CEAFApp)
	//{{AFX_MSG_MAP(CBridgeLinkApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
   ON_COMMAND(ID_MANAGE_PLUGINS, &CBridgeLinkApp::OnManagePlugins)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp construction

CBridgeLinkApp::CBridgeLinkApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

CBridgeLinkApp::~CBridgeLinkApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBridgeLinkApp object

CBridgeLinkApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp initialization
LPCTSTR CBridgeLinkApp::GetRegistryKey()
{
   return _T("Washington State Department of Transportation");
}

OLECHAR* CBridgeLinkApp::GetAppPluginCategoryName()
{
   CString strName("BridgeLink Plug-in");
   return strName.AllocSysString();
}

CATID CBridgeLinkApp::GetAppPluginCategoryID()
{
   return CATID_BridgeLink;
}

CEAFSplashScreenInfo CBridgeLinkApp::GetSplashScreenInfo()
{
   CBitmap bmp;
   CEAFSplashScreenInfo info;
   bmp.LoadBitmap(IDB_SPLASH);
   info.m_hBitmap = bmp;
   info.m_TextColor = RGB(0,0,0);
   info.m_BgColor = RGB(255,255,255);
   info.m_Rect = CRect(5,300,515,315);

   bmp.Detach();

   return info;
}

CATID CBridgeLinkApp::GetComponentInfoCategoryID()
{
   return CLSID_NULL;
}

BOOL CBridgeLinkApp::InitInstance()
{
   CEAFSplashScreen::SetTimeout(5000);
   return CEAFApp::InitInstance();
}

BOOL CBridgeLinkApp::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
   // I'm not sure why, but this method is required in order to call the base class method
   // (even though this is a virtual method). All CEAFApp-derived classes must implement this
   // method
   return CEAFApp::OnCmdMsg(nID,nCode,pExtra,pHandlerInfo);
}


/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkApp message handlers


void CBridgeLinkApp::OnAbout(void)
{
   CAboutDlg dlg;
   dlg.DoModal();
}

void CBridgeLinkApp::OnManagePlugins()
{
   GetAppPluginManager()->ManagePlugins();
}
