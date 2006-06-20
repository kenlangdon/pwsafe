// ImportXMLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "passwordsafe.h"
#include "ImportXMLDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImportXMLDlg dialog


CImportXMLDlg::CImportXMLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImportXMLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImportXMLDlg)
	m_groupName = _T("Imported");
	m_group = 0;
	//}}AFX_DATA_INIT
}


void CImportXMLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImportXMLDlg)
	DDX_Text(pDX, IDC_GROUP_NAME, m_groupName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CImportXMLDlg, CDialog)
	//{{AFX_MSG_MAP(CImportXMLDlg)
	ON_BN_CLICKED(IDC_NO_GROUP, OnNoGroup)
	ON_BN_CLICKED(IDC_YES_GROUP, OnYesGroup)
	ON_BN_CLICKED(ID_HELP, OnHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CImportXMLDlg message handlers


void CImportXMLDlg::OnNoGroup() 
{
	GetDlgItem(IDC_GROUP_NAME)->EnableWindow(FALSE);
	m_group=0;
}

void CImportXMLDlg::OnYesGroup() 
{
	GetDlgItem(IDC_GROUP_NAME)->EnableWindow(TRUE);
	m_group=1;
}

void CImportXMLDlg::OnHelp() 
{
   ::HtmlHelp(NULL,
              "pwsafe.chm::/html/importxml.html",
              HH_DISPLAY_TOPIC, 0);
}

void CImportXMLDlg::OnOK() 
{
	if (m_group == 0) {
		m_groupName = _T("");
		UpdateData(FALSE);
	} else {
		GetDlgItemText(IDC_GROUP_NAME,m_groupName);
		UpdateData(FALSE);
	}

	CDialog::OnOK();
}
