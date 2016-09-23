// ConfigureBridgeLinkDlg.cpp : implementation file
//

#include "stdafx.h"
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
   if ( result == IDOK )
   {
      NotifyExtensionPages();
   }

   return result;
}

void CConfigureBridgeLinkDlg::Init(std::map<IDType,IBridgeLinkConfigurationCallback*>& configurationPageCallbacks)
{
   m_psh.dwFlags |= PSH_HASHELP | PSH_NOAPPLYNOW;

   m_BridgeLinkPage.m_psp.dwFlags  |= PSP_HASHELP;
   AddPage( &m_BridgeLinkPage );

   std::map<IDType,IBridgeLinkConfigurationCallback*>::iterator iter(configurationPageCallbacks.begin());
   std::map<IDType,IBridgeLinkConfigurationCallback*>::iterator end(configurationPageCallbacks.end());
   for ( ; iter != end; iter++ )
   {
      IBridgeLinkConfigurationCallback* pCallback = iter->second;
      CPropertyPage* pPage = pCallback->CreatePropertyPage();
      m_vExtensionPages.push_back( std::make_pair(pCallback,pPage) );
      if ( pPage )
      {
         AddPage(pPage);
      }
   }
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
	if( pPage != NULL )
	{
		//ASSERT_VALID(pPage);
		return pPage->SendMessage( WM_KICKIDLE, wp, lp );
	}
	else
   {
		return 0;
   }
}