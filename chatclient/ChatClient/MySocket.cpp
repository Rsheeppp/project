#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "MySocket.h"
#include "Dialog2.h"

// CMySocket
extern int connected;
CMySocket::CMySocket()
{
}

CMySocket::~CMySocket()
{
}


// CMySocket ��Ա����

void CMySocket::OnConnect(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	CChatClientDlg* dlg=(CChatClientDlg*)AfxGetApp()->GetMainWnd(); 
	/*CString str; 
	dlg->m_tm=CTime::GetCurrentTime(); 
	str=dlg->m_tm.Format("%X "); 
	str+="����������ӳɹ���"; 
	dlg->m_list.AddString(str); */
    connected=1;
	CAsyncSocket::OnConnect(nErrorCode);
}

void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	CChatClientDlg* dlg=(CChatClientDlg*)AfxGetApp()->GetMainWnd(); 
Receive(dlg->buff,200,0);
//CString temp1=" server ��"; 
//CString temp2=dlg->buff; 
//CString str; 
//dlg->m_tm=CTime::GetCurrentTime(); 
//str=dlg->m_tm.Format("%X"); 
//temp1=str+temp1; 
//temp1+=temp2; 
CString temp1;
temp1+=(CString)dlg->buff;
dlg->m_list.ResetContent();
dlg->m_list.AddString(temp1); 
dlg->m_list.UpdateData(FALSE);

	CAsyncSocket::OnReceive(nErrorCode);
}
