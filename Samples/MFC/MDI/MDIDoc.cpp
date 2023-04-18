// MDIDoc.cpp :  CMDIDoc 类的实现
//

#include "stdafx.h"
#include "MDI.h"

#include "MDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDIDoc

IMPLEMENT_DYNCREATE(CMDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CMDIDoc, CDocument)
END_MESSAGE_MAP()


// CMDIDoc 构造/析构

CMDIDoc::CMDIDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMDIDoc::~CMDIDoc()
{
}

BOOL CMDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMDIDoc 序列化

void CMDIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CMDIDoc 诊断

#ifdef _DEBUG
void CMDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMDIDoc 命令
