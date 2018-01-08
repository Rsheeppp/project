#pragma once
#include"resource.h"
extern CString port1;
extern CString emailserver;
extern CString ip;
class CDialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog2)
public:
	CDialog2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialog2();
	enum { IDD = IDD_DIALOG1 };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog(){ 
	CDialogEx::OnInitDialog(); 	
	GetDlgItem(IDC_PORT)->SetWindowText(port1); 
	GetDlgItem(IDC_PORT7)->SetWindowText(emailserver); 
	GetDlgItem(IDC_IPADDRESS1)->SetWindowText(ip);
	GetDlgItem(IDC_IPADDRESS1)->SetWindowText((LPCTSTR)"127.0.0.1"); 
	return 0;
	};
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangePort();
	afx_msg void OnEnChangePort7();
	//afx_msg void OnEnChangePort8();
	afx_msg void OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult);
};
