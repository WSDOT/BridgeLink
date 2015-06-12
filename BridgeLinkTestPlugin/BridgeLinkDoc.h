// BridgeLinkDoc.h : interface of the CBridgeLinkDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRIDGELINKDOC_H__A5D5FE52_139D_46C7_84CF_35817D298084__INCLUDED_)
#define AFX_BRIDGELINKDOC_H__A5D5FE52_139D_46C7_84CF_35817D298084__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <EAF\EAFDocument.h>

class CBridgeLinkDoc : public CEAFDocument
{
protected: // create from serialization only
	CBridgeLinkDoc();
	DECLARE_DYNCREATE(CBridgeLinkDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBridgeLinkDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

   virtual HRESULT WriteTheDocument(IStructuredSave* pStrSave);
   virtual HRESULT LoadTheDocument(IStructuredLoad* pStrLoad);
   virtual CString GetToolbarSectionName();
   virtual BOOL GetStatusBarMessageString(UINT nID,CString& rMessage) const;
   virtual BOOL GetToolTipMessageString(UINT nID, CString& rMessage) const;

// Implementation
public:
	virtual ~CBridgeLinkDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBridgeLinkDoc)
	afx_msg void OnNewView();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

   virtual HINSTANCE GetResourceInstance();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRIDGELINKDOC_H__A5D5FE52_139D_46C7_84CF_35817D298084__INCLUDED_)
