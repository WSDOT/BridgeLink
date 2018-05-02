// Plugin.cpp : Implementation of CPlugin
#include "stdafx.h"
#include "resource.h"
#include "BridgeLinkTestPlugin_i.h"
#include "Plugin.h"

#include "ChildFrm.h"
#include "BridgeLinkDoc.h"
#include "BridgeLinkView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CPlugin
HRESULT CPlugin::FinalConstruct()
{
   return S_OK;
}

void CPlugin::FinalRelease()
{
}

BOOL CPlugin::Init(CEAFApp* pParent)
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   m_DocumentationImpl.Init(this);
   return TRUE;
}

void CPlugin::Terminate()
{
}

void CPlugin::IntegrateWithUI(BOOL bIntegrate)
{
}

std::vector<CEAFDocTemplate*> CPlugin::CreateDocTemplates()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());

   std::vector<CEAFDocTemplate*> templates;

   CEAFDocTemplate* pDocTemplate;
	pDocTemplate = new CEAFDocTemplate(
      IDR_EXAMPLE,
      nullptr,
		RUNTIME_CLASS(CBridgeLinkDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CBridgeLinkView),
      nullptr,1);

   pDocTemplate->SetPlugin(this);
   pDocTemplate->CreateDefaultItem(AfxGetApp()->LoadStandardIcon(IDI_WINLOGO));

   templates.push_back(pDocTemplate);
   return templates;
}

HMENU CPlugin::GetSharedMenuHandle()
{
   return nullptr;
}

CString CPlugin::GetName()
{
   return CString("BridgeLink Test Plugin");
}

CString CPlugin::GetDocumentationSetName()
{
   return GetName();
}

CString CPlugin::GetDocumentationURL()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return m_DocumentationImpl.GetDocumentationURL();
}

CString CPlugin::GetDocumentationMapFile()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return m_DocumentationImpl.GetDocumentationMapFile();
}

void CPlugin::LoadDocumentationMap()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return m_DocumentationImpl.LoadDocumentationMap();
}

eafTypes::HelpResult CPlugin::GetDocumentLocation(LPCTSTR lpszDocSetName,UINT nID,CString& strURL)
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   return m_DocumentationImpl.GetDocumentLocation(lpszDocSetName,nID,strURL);
}
