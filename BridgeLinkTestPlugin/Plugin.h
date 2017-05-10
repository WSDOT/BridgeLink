// Plugin.h : Declaration of the CPlugin

#ifndef __PLUGIN_H_
#define __PLUGIN_H_

#include "resource.h"       // main symbols
#include <EAF\EAFAppPlugIn.h>
#include <EAF\EAFAppPluginDocumentationImpl.h>

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
   virtual BOOL Init(CEAFApp* pParent) override;
   virtual void Terminate() override;
   virtual void IntegrateWithUI(BOOL bIntegrate) override;
   virtual std::vector<CEAFDocTemplate*> CreateDocTemplates() override;
   virtual HMENU GetSharedMenuHandle() override;
   virtual CString GetName() override;
   virtual CString GetDocumentationSetName() override;
   virtual CString GetDocumentationURL() override;
   virtual CString GetDocumentationMapFile() override;
   virtual void LoadDocumentationMap() override;
   virtual eafTypes::HelpResult GetDocumentLocation(LPCTSTR lpszDocSetName,UINT nID,CString& strURL) override;

private:

   CEAFAppPluginDocumentationImpl m_DocumentationImpl;
};

#endif //__PLUGIN_H_
