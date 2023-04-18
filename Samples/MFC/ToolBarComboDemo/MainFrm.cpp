// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ToolBar.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const int SNAP_WIDTH=120; //the width of the combo box
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_CBN_SELENDOK(ID_TOOL_ZOOM, OnSelectZoomed)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

//	CreateComboBox(IDP_PLACEHOLDER2);
    int index = 0;
	RECT rect;

	//找到指定的工具项
    while(m_wndToolBar.GetItemID(index)!=ID_TOOL_ZOOM)
		index++;

    //设置指定工具项的宽度并获取新的区域  80是宽度
    m_wndToolBar.SetButtonInfo(index, ID_TOOL_ZOOM, TBBS_SEPARATOR, 80);
    m_wndToolBar.GetItemRect(index, &rect);

    //设置位置
    rect.top+=2;
    rect.bottom += 200;

    // 创建并显示
    if (!m_wndToolBar.m_wndZoom.Create(WS_CHILD|WS_VISIBLE | CBS_AUTOHSCROLL | 
                                       CBS_DROPDOWNLIST | CBS_HASSTRINGS ,
                                       rect, &m_wndToolBar, ID_TOOL_ZOOM))
    {
       TRACE0("Failed to create combo-box\n");
       return FALSE;
    }
    m_wndToolBar.m_wndZoom.ShowWindow(SW_SHOW);
    
	//填充内容
	m_wndToolBar.m_wndZoom.AddString("25%");
	m_wndToolBar.m_wndZoom.AddString("50%");
	m_wndToolBar.m_wndZoom.AddString("75%");
    m_wndToolBar.m_wndZoom.AddString("100%");
    m_wndToolBar.m_wndZoom.AddString("125%");
    m_wndToolBar.m_wndZoom.AddString("150%");
    m_wndToolBar.m_wndZoom.AddString("175%");
    m_wndToolBar.m_wndZoom.AddString("200%");
    m_wndToolBar.m_wndZoom.SetCurSel(3);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
BOOL CMainFrame::CreateComboBox(UINT nID)
{
    int index = 0;
	RECT rect;

	//找到指定的工具
    while(m_wndToolBar.GetItemID(index)!=nID)
		index++;

    //设置指定工具的宽度并获取新的区域
    m_wndToolBar.SetButtonInfo(index, nID, TBBS_SEPARATOR, SNAP_WIDTH);
    m_wndToolBar.GetItemRect(index, &rect);

    //设置位置
    rect.top+=2;
    rect.bottom += 200;

    // 创建并显示
    if (!m_wndToolBar.m_wndZoom.Create(WS_CHILD|WS_VISIBLE | CBS_AUTOHSCROLL | 
                                       CBS_DROPDOWNLIST | CBS_HASSTRINGS ,
                                       rect, &m_wndToolBar, nID))
    {
       TRACE0("Failed to create combo-box\n");
       return FALSE;
    }
    m_wndToolBar.m_wndZoom.ShowWindow(SW_SHOW);
	
	return TRUE;
}



void CMainFrame::OnSelectZoomed()
{
	CString strContent;
	m_wndToolBar.m_wndZoom.GetWindowText(strContent);
	AfxMessageBox(strContent);
}
