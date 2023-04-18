// Page1.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "Page1.h"
#include ".\page1.h"


// CPage1 对话框

IMPLEMENT_DYNAMIC(CPage1, CDialog)
CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialog(CPage1::IDD, pParent)
{
}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage1, CDialog)
END_MESSAGE_MAP()


// CPage1 消息处理程序

BOOL CPage1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rc(0, 0, 0, 0);

	GetParent()->GetClientRect(&rc);
	//((CTabCtrl*)GetParent())->AdjustRect(false, &rc); 

	MoveWindow(&rc);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
