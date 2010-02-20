// Plugin.h : Declaration of the CPlugin

#ifndef __PLUGIN_H_
#define __PLUGIN_H_

#include "resource.h"       // main symbols
#include <EAF\EAFAppPlugIn.h>

/////////////////////////////////////////////////////////////////////////////
// CPlugin
class ATL_NO_VTABLE CPlugin : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPlugin, &CLSID_Plugin>,
	public IEAFAppPlugin
{
public:
	CPlugin()
	{
	}

   HRESULT FinalConstruct();
   void FinalRelease();

DECLARE_REGISTRY_RESOURCEID(IDR_PLUGIN)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPlugin)
	COM_INTERFACE_ENTRY(IEAFAppPlugin)
END_COM_MAP()

// IEAFAppPlugin
public:
   virtual BOOL Init(CEAFApp* pParent);
   virtual void Terminate();
   virtual void IntegrateWithUI(BOOL bIntegrate);
   virtual CEAFDocTemplate* CreateDocTemplate();
   virtual HMENU GetSharedMenuHandle();
   virtual UINT GetDocumentResourceID();
   virtual CString GetName();
};

#endif //__PLUGIN_H_
