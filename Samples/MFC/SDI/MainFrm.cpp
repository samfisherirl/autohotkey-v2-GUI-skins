// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "SDI.h"

#include "MainFrm.h"
#include ".\mainfrm.h"
#include "..\..\..\Include\USkin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_ABOUTSKINFILE, OnAboutskinfile)
	ON_COMMAND(ID_COLORTHEME, OnColortheme)
	ON_COMMAND(ID_TEST1, OnTest1)
	ON_UPDATE_COMMAND_UI(ID_TEST1,OnUpdateTest1)
	ON_COMMAND(ID_TEST2, OnTest2)
	ON_UPDATE_COMMAND_UI(ID_TEST2,OnUpdateTest2)
	ON_COMMAND(ID_TEST3, OnTest3)
	ON_UPDATE_COMMAND_UI(ID_TEST3,OnUpdateTest3)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
	m_nTest=1;
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
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	// TODO: 如果不需要工具栏可停靠，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	time_t t;
	t=time(&t);
	srand(t);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式

	return TRUE;
}


// CMainFrame 诊断

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


// CMainFrame 消息处理程序


void CMainFrame::OnColortheme()
{
	// TODO: 在此添加命令处理程序代码
	
	int n=rand();
	float h=n%360;
	USkinApplyColorTheme(h,0.5f);
}

void CMainFrame::OnAboutskinfile()
{
	// TODO: 在此添加命令处理程序代码
	::USkinAboutSkin();
}
void CMainFrame::OnTest1()
{
	m_nTest=1;
}
void CMainFrame::OnTest2()
{
	m_nTest=2;
}
void CMainFrame::OnTest3()
{
	m_nTest=3;
}
void CMainFrame::OnUpdateTest1(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_nTest==1);
}
void CMainFrame::OnUpdateTest2(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_nTest==2);
}
void CMainFrame::OnUpdateTest3(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetRadio(m_nTest==3);
}
