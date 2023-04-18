// MyTabCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "MyTabCtrl.h"
#include ".\mytabctrl.h"


// CMyTabCtrl

IMPLEMENT_DYNAMIC(CMyTabCtrl, CTabCtrl)
CMyTabCtrl::CMyTabCtrl()
{
}

CMyTabCtrl::~CMyTabCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyTabCtrl, CTabCtrl)
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()



// CMyTabCtrl 消息处理程序


void CMyTabCtrl::OnNcDestroy()
{
	CTabCtrl::OnNcDestroy();
	TRACE("HANDLE ME");
	// TODO: 在此处添加消息处理程序代码
}
