#if !defined(AFX_BRIDGELINKVIEW2_H__536620BD_A422_4A74_880F_39C6CAEE3834__INCLUDED_)
#define AFX_BRIDGELINKVIEW2_H__536620BD_A422_4A74_880F_39C6CAEE3834__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BridgeLinkView2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBridgeLinkView2 view

class CBridgeLinkView2 : public CView
{
protected:
	CBridgeLinkView2();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CBridgeLinkView2)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBridgeLinkView2)
	protected:
	virtual void OnDraw(CDC* pDC) override;      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBridgeLinkView2();
#ifdef _DEBUG
	virtual void AssertValid() const override;
	virtual void Dump(CDumpContext& dc) const override;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CBridgeLinkView2)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRIDGELINKVIEW2_H__536620BD_A422_4A74_880F_39C6CAEE3834__INCLUDED_)
