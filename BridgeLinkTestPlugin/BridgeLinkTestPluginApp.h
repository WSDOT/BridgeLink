#ifndef INCLUDED_APP_H_
#define INCLUDED_APP_H_

#include <EAF\EAFDocTemplate.h>
class CBridgeLinkTestPluginApp : public CWinApp
{
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBridgeLinkTestPluginApp)
	public:
    virtual BOOL InitInstance() override;
    virtual int ExitInstance() override;
 	 virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) override;

	//}}AFX_VIRTUAL

	//{{AFX_MSG(CBridgeLinkTestPluginApp)
	afx_msg void OnNewView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
   CEAFDocTemplate* m_pSecondaryViewTemplate;
   HMENU m_hSharedMenu;
};

#endif // INCLUDED_APP_H_