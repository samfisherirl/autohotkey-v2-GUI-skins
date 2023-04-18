// DialogDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "DialogDlg.h"
#include ".\dialogdlg.h"
#include "..\..\..\Include\uskin.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDialogDlg 对话框



CDialogDlg::CDialogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_lstView);
	DDX_Control(pDX, IDC_TAB1, m_tabCtrl);
	DDX_Control(pDX, IDC_BUTTON6, m_btn);
}

BEGIN_MESSAGE_MAP(CDialogDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnBnClickedButton6)
	ON_WM_NCDESTROY()
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_SIZE()
	ON_COMMAND(ID_COLORTHEME, OnColortheme)
	ON_COMMAND(ID_ABOUTSKINFILE, OnAboutskinfile)
END_MESSAGE_MAP()


// CDialogDlg 消息处理程序

BOOL CDialogDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码
	m_tabCtrl.InsertItem(0,"TabPage1");
	m_tabCtrl.InsertItem(1,"TabPage2");
	m_tabCtrl.InsertItem(2,"TabPage3");
	m_tabCtrl.InsertItem(3,"TabPage4");
	CString str;
	int i=0;
	for(i=0;i<4;i++)
	{
		str.Format("col%d",i);
		m_lstView.InsertColumn(i,str,0,80);
	}
	for(i=0;i<20;i++)
	{
		str.Format("col%d",i);	
		m_lstView.InsertItem(i,str,0);
	}
	time_t t;
	t=time(&t);
	srand(t); 
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDialogDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDialogDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE);
	dlg.DoModal();
}

void CDialogDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog dlg;
	dlg.DoModal();
}

void CDialogDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CFontDialog dlg;
	dlg.DoModal();
}

void CDialogDlg::OnBnClickedButton5()
{

	// TODO: 在此添加控件通知处理程序代码
	CPrintDialog dlg(TRUE);
	dlg.DoModal();
}

void CDialogDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	
	USkinLoadSkin(_T("TorsionBar.u3"));
	
}

void CDialogDlg::OnNcDestroy()
{
	CDialog::OnNcDestroy();
	
	// TODO: 在此处添加消息处理程序代码
}


void CDialogDlg::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	//AfxMessageBox("？\n");
	MessageBox("");
}

void CDialogDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	TRACE("ONSIZE\n");
	// TODO: 在此处添加消息处理程序代码
}

void CDialogDlg::OnColortheme()
{
	// TODO: 在此添加命令处理程序代码
	
	int n=rand();
	float h=n%360;
	USkinApplyColorTheme(h,1.0f);
}

void CDialogDlg::OnAboutskinfile()
{
	// TODO: 在此添加命令处理程序代码
	::USkinAboutSkin();
}
