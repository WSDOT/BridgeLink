// ConfigureBridgeLinkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "BridgeLink.h"
#include "ConfigureBridgeLinkDlg.h"




// CConfigureBridgeLinkDlg

IMPLEMENT_DYNAMIC(CConfigureBridgeLinkDlg, CPropertySheet)

CConfigureBridgeLinkDlg::CConfigureBridgeLinkDlg(std::map<IDType,IBridgeLinkConfigurationCallback*>& configurationPageCallbacks,CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(_T("Configure BridgeLink"), pParentWnd, iSelectPage)
{
   Init(configurationPageCallbacks);
}

CConfigureBridgeLinkDlg::~CConfigureBridgeLinkDlg()
{
   DestroyExtensionPages();
}

INT_PTR CConfigureBridgeLinkDlg::DoModal()
{
   INT_PTR result = CPropertySheet::DoModal();
   if ( result == ID_WIZFINISH )
   {
      NotifyExtensionPages();
      result = IDOK;
   }

   return result;
}

void CConfigureBridgeLinkDlg::Init(std::map<IDType,IBridgeLinkConfigurationCallback*>& configurationPageCallbacks)
{
   //AFX_MANAGE_STATE(AfxGetStaticModuleState());
   m_psh.dwFlags |= PSH_HASHELP | PSH_NOAPPLYNOW | PSH_WIZARD97 /*| PSH_HEADER*/ | PSH_WATERMARK;
   m_psh.pszbmWatermark = MAKEINTRESOURCE(IDB_CONFIGURATION_WATERMARK);
   //m_psh.pszbmHeader = MAKEINTRESOURCE(IDB_CONFIGURATION_HEADER);
   m_psh.hInstance = AfxGetInstanceHandle(); 
   
   SetWizardMode();

   m_Pages.reserve(configurationPageCallbacks.size() + 1);

   AddPage( &m_BridgeLinkPage );
   m_Pages.push_back((LRESULT)m_BridgeLinkPage.m_psp.pszTemplate);

   std::map<IDType,IBridgeLinkConfigurationCallback*>::iterator iter(configurationPageCallbacks.begin());
   std::map<IDType,IBridgeLinkConfigurationCallback*>::iterator end(configurationPageCallbacks.end());
   for ( ; iter != end; iter++ )
   {
      IBridgeLinkConfigurationCallback* pCallback = iter->second;
      CPropertyPage* pPage = pCallback->CreatePropertyPage();
      m_vExtensionPages.emplace_back(pCallback,pPage);
      if ( pPage )
      {
         AddPage(pPage);
         m_Pages.push_back((LRESULT)pPage->m_psp.pszTemplate);
      }
   }
   m_CurrentPage = m_Pages.begin();
}


void CConfigureBridgeLinkDlg::DestroyExtensionPages()
{
   std::vector<std::pair<IBridgeLinkConfigurationCallback*,CPropertyPage*>>::iterator pageIter(m_vExtensionPages.begin());
   std::vector<std::pair<IBridgeLinkConfigurationCallback*,CPropertyPage*>>::iterator pageIterEnd(m_vExtensionPages.end());
   for ( ; pageIter != pageIterEnd; pageIter++ )
   {
      CPropertyPage* pPage = pageIter->second;
      if ( pPage )
      {
         delete pPage;
      }
   }
   m_vExtensionPages.clear();
}


void CConfigureBridgeLinkDlg::NotifyExtensionPages()
{
   std::vector<std::pair<IBridgeLinkConfigurationCallback*,CPropertyPage*>>::iterator pageIter(m_vExtensionPages.begin());
   std::vector<std::pair<IBridgeLinkConfigurationCallback*,CPropertyPage*>>::iterator pageIterEnd(m_vExtensionPages.end());
   for ( ; pageIter != pageIterEnd; pageIter++ )
   {
      IBridgeLinkConfigurationCallback* pCallback = pageIter->first;
      CPropertyPage* pPage = pageIter->second;
      pCallback->OnOK(pPage);
   }
}

BEGIN_MESSAGE_MAP(CConfigureBridgeLinkDlg, CPropertySheet)
	ON_MESSAGE(WM_KICKIDLE,OnKickIdle)
END_MESSAGE_MAP()

BOOL CConfigureBridgeLinkDlg::OnInitDialog()
{
   BOOL bResult = CPropertySheet::OnInitDialog();

   SetTitle(_T("Configure BridgeLink"));

   if ( m_Pages.size() == 0 )
   {
      SetWizardButtons(PSWIZB_FINISH);
   }
   else
   {
      SetWizardButtons(PSWIZB_NEXT);
   }

   return bResult;
}

LRESULT CConfigureBridgeLinkDlg::GetNextPage()
{
   m_CurrentPage++;

   if ( IsLastPage() )
   {
      SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
   }
   else
   {
      SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);
   }

   return *m_CurrentPage;
}

LRESULT CConfigureBridgeLinkDlg::GetBackPage()
{
   m_CurrentPage--;

   if ( IsFirstPage() )
   {
      SetWizardButtons(PSWIZB_NEXT);
   }
   else
   {
      SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);
   }
   
   return *m_CurrentPage;
}

bool CConfigureBridgeLinkDlg::IsLastPage()
{
   return (m_CurrentPage == m_Pages.end()-1 ? true : false );
}

bool CConfigureBridgeLinkDlg::IsFirstPage()
{
   return (m_CurrentPage == m_Pages.begin() ? true : false);
}

// CConfigureBridgeLinkDlg message handlers
LRESULT CConfigureBridgeLinkDlg::OnKickIdle(WPARAM wp, LPARAM lp)
{
   // The CPropertySheet::OnKickIdle method calls GetActivePage()
   // which doesn't work with extension pages. Since GetActivePage
   // is not virtual, we have to replace the implementation of
   // OnKickIdle.
   // The same problem exists with OnCommandHelp

	ASSERT_VALID(this);

	CPropertyPage* pPage = GetPage(GetActiveIndex());

	/* Forward the message on to the active page of the property sheet */
	if( pPage != nullptr )
	{
		//ASSERT_VALID(pPage);
		return pPage->SendMessage( WM_KICKIDLE, wp, lp );
	}
	else
   {
		return 0;
   }
}