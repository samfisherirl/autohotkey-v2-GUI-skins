// MainFrm.h : CMainFrame 类的接口
//


#pragma once
class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAboutskinfile();
	afx_msg void OnColortheme();
	afx_msg void OnTest1();
	afx_msg void OnTest2();
	afx_msg void OnTest3();
	afx_msg void OnUpdateTest1(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTest2(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTest3(CCmdUI *pCmdUI);
protected:
	int m_nTest;
};


