#include "stdafx.h"
#include "resource.h"
#include "AboutDlg.h"

CAboutDlg::CAboutDlg(void)
{
}

CAboutDlg::~CAboutDlg(void)
{
}

HICON CAboutDlg::GetIconHandle()
{
   return AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
