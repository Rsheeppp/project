// Dialog2.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog2.h"
#include "afxdialogex.h"
#include"resource.h"

// CDialog2 对话框
extern CString port1;
extern CString emailserver;
extern CString ip;
int canstart=0;
IMPLEMENT_DYNAMIC(CDialog2, CDialogEx)
CDialog2::CDialog2(CWnd* pParent)
	: CDialogEx(CDialog2::IDD, pParent)
{

}
CDialog2::~CDialog2()
{
}
void CDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CDialog2, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog2::OnBnClickedOk)
	ON_EN_CHANGE(IDC_PORT, &CDialog2::OnEnChangePort)
	ON_EN_CHANGE(IDC_PORT7, &CDialog2::OnEnChangePort7)
	//ON_EN_CHANGE(IDC_PORT8, &CDialog2::OnEnChangePort8)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS1, &CDialog2::OnIpnFieldchangedIpaddress1)
END_MESSAGE_MAP()
void CDialog2::OnBnClickedOk()
{
	GetDlgItem(IDC_PORT)->GetWindowText(port1);
	GetDlgItem(IDC_PORT7)->GetWindowText(emailserver); 
	GetDlgItem(IDC_IPADDRESS1)->GetWindowText(ip); 
	canstart=1;
	CDialogEx::OnOK();
}
void CDialog2::OnEnChangePort()
{

}
void CDialog2::OnEnChangePort7()
{

}



void CDialog2::OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
