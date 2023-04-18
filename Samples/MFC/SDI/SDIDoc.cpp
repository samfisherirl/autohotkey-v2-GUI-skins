// SDIDoc.cpp :  CSDIDoc 类的实现
//

#include "stdafx.h"
#include "SDI.h"

#include "SDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIDoc

IMPLEMENT_DYNCREATE(CSDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDIDoc, CDocument)
END_MESSAGE_MAP()


// CSDIDoc 构造/析构

CSDIDoc::CSDIDoc()
{
	// TODO: 在此添加一次性构造代码

}

CSDIDoc::~CSDIDoc()
{
}

BOOL CSDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CSDIDoc 序列化

void CSDIDoc::Serialize(CArchive& ar)
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


// CSDIDoc 诊断

#ifdef _DEBUG
void CSDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSDIDoc 命令
