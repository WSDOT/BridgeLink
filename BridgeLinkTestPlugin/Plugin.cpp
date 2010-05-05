// Plugin.cpp : Implementation of CPlugin
#include "stdafx.h"
#include "resource.h"
#include "BridgeLinkTestPlugin.h"
#include "Plugin.h"

#include "ChildFrm.h"
#include "BridgeLinkDoc.h"
#include "BridgeLinkView.h"

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
   return TRUE;
}

void CPlugin::Terminate()
{
}

void CPlugin::IntegrateWithUI(BOOL bIntegrate)
{
}

CEAFDocTemplate* CPlugin::CreateDocTemplate()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CEAFDocTemplate* pDocTemplate;
	pDocTemplate = new CEAFDocTemplate(
      IDR_BRIDGETYPE,
      NULL,
		RUNTIME_CLASS(CBridgeLinkDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CBridgeLinkView),
      NULL,1);

   pDocTemplate->SetPlugin(this);
   pDocTemplate->CreateDefaultItem(AfxGetApp()->LoadStandardIcon(IDI_WINLOGO));

   return pDocTemplate;
}

HMENU CPlugin::GetSharedMenuHandle()
{
   return NULL;
}

UINT CPlugin::GetDocumentResourceID()
{
   return IDR_BRIDGETYPE;
}

CString CPlugin::GetName()
{
   return CString("BridgeLink Test Plugin");
}
