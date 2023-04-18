// MainToolBar.h: interface for the CMainToolBar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINTOOLBAR_H__76CF28F4_005F_11D7_8F58_00E04C0BECE6__INCLUDED_)
#define AFX_MAINTOOLBAR_H__76CF28F4_005F_11D7_8F58_00E04C0BECE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlatComboBox.h"

class CMainToolBar : public CToolBar   
{
public:
	CMainToolBar();
	virtual ~CMainToolBar();

public:
	CFlatComboBox m_wndZoom;
};
 
#endif // !defined(AFX_MAINTOOLBAR_H__76CF28F4_005F_11D7_8F58_00E04C0BECE6__INCLUDED_)
