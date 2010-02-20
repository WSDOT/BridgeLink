// BridgeLinkTestPlugin.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f BridgeLinkTestPluginps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include <EAF\EAFAppPlugin.h>
#include "BridgeLinkTestPlugin.h"

#include "BridgeLinkTestPlugin_i.c"
#include "Plugin.h"


#include "..\BridgeLinkCATID.h"
#include <System\ComCatMgr.h>

#include "BridgeLinkTestPluginApp.h"

#include <EAF\EAFDocTemplate.h>
#include "BridgeLinkDoc.h"
#include "ChildFrame2.h"
#include "BridgeLinkView2.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_Plugin, CPlugin)
END_OBJECT_MAP()

BEGIN_MESSAGE_MAP(CBridgeLinkTestPluginApp, CWinApp)
	//{{AFX_MSG_MAP(CBridgeLinkTestPluginApp)
//	ON_COMMAND(ID_NEW_VIEW, OnNewView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CBridgeLinkTestPluginApp theApp;

BOOL CBridgeLinkTestPluginApp::InitInstance()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());

   // Using a shared menu
   // See MSKB Article ID: Q118435, "Sharing Menus Between MDI Child Windows"
   m_hSharedMenu = NULL; /*::LoadMenu( m_hInstance, MAKEINTRESOURCE(IDR_???) );*/

   m_pSecondaryViewTemplate = new CEAFDocTemplate(
      IDR_BRIDGETYPE,
		RUNTIME_CLASS(CBridgeLinkDoc),
		RUNTIME_CLASS(CChildFrame2), // custom MDI child frame
		RUNTIME_CLASS(CBridgeLinkView2),
      m_hSharedMenu,2); // only create 2 of this type of view


   _Module.Init(ObjectMap, m_hInstance, &LIBID_BRIDGELINKTESTPLUGINLib);
   return CWinApp::InitInstance();
}

int CBridgeLinkTestPluginApp::ExitInstance()
{
   delete m_pSecondaryViewTemplate;

   // if the doc template uses a shared menu, destroy it here
   // release the shared menu
   //::DestroyMenu( m_hSharedMenu );

   _Module.Term();
   return CWinApp::ExitInstance();
}

BOOL CBridgeLinkTestPluginApp::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
   // in order scan the message map for this plugin, the module state must be set
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return CWinApp::OnCmdMsg(nID,nCode,pExtra,pHandlerInfo);
}

void CBridgeLinkTestPluginApp::OnNewView() 
{
   AfxMessageBox("Handling OnNewView from CBridgeLinkTestPluginApp");	
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return (AfxDllCanUnloadNow()==S_OK && _Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib

   HRESULT hr = _Module.RegisterServer(TRUE);
   if ( FAILED(hr) )
      return hr;

   sysComCatMgr::RegWithCategory(CLSID_Plugin, CATID_BridgeLink, true);

   return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
   sysComCatMgr::RegWithCategory(CLSID_Plugin, CATID_BridgeLink, false);

    return _Module.UnregisterServer(TRUE);
}
