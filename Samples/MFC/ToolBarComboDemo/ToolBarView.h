// ToolBarView.h : interface of the CToolBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBARVIEW_H__76CF28EC_005F_11D7_8F58_00E04C0BECE6__INCLUDED_)
#define AFX_TOOLBARVIEW_H__76CF28EC_005F_11D7_8F58_00E04C0BECE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CToolBarView : public CView
{
protected: // create from serialization only
	CToolBarView();
	DECLARE_DYNCREATE(CToolBarView)

// Attributes
public:
	CToolBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolBarView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CToolBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CToolBarView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ToolBarView.cpp
inline CToolBarDoc* CToolBarView::GetDocument()
   { return (CToolBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLBARVIEW_H__76CF28EC_005F_11D7_8F58_00E04C0BECE6__INCLUDED_)
