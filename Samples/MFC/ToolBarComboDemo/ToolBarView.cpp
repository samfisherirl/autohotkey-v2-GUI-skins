// ToolBarView.cpp : implementation of the CToolBarView class
//

#include "stdafx.h"
#include "ToolBar.h"

#include "ToolBarDoc.h"
#include "ToolBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolBarView

IMPLEMENT_DYNCREATE(CToolBarView, CView)

BEGIN_MESSAGE_MAP(CToolBarView, CView)
	//{{AFX_MSG_MAP(CToolBarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolBarView construction/destruction

CToolBarView::CToolBarView()
{
	// TODO: add construction code here

}

CToolBarView::~CToolBarView()
{
}

BOOL CToolBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CToolBarView drawing

void CToolBarView::OnDraw(CDC* pDC)
{
	CToolBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CToolBarView printing

BOOL CToolBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CToolBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CToolBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CToolBarView diagnostics

#ifdef _DEBUG
void CToolBarView::AssertValid() const
{
	CView::AssertValid();
}

void CToolBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolBarDoc* CToolBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolBarDoc)));
	return (CToolBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToolBarView message handlers
