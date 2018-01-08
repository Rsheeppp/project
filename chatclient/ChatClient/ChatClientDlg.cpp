// ChatClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "Dialog2.h"
#include "resource.h"
#include"sendmail.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
 CString port1="";
 CString emailserver="";
 CString ip="";
 CString name="";
 CString code="";
 CString myemail="";
 CString sendmail="";
 CString theme="";
 int connected=0;
extern int  canstart;
int ifstartjudge=1;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CChatClientDlg �Ի���




CChatClientDlg::CChatClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HISTORY, m_list);
	DDX_Control(pDX, IDC_INPUT, m_input);
}

BEGIN_MESSAGE_MAP(CChatClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, &CChatClientDlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_DISCONNECT, &CChatClientDlg::OnBnClickedDisconnect)
	ON_BN_CLICKED(IDC_SEND, &CChatClientDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_SEND2, &CChatClientDlg::OnBnClickedSend2)
	//ON_EN_CHANGE(IDC_PORT, &CChatClientDlg::OnEnChangePort)
	//ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS, &CChatClientDlg::OnIpnFieldchangedIpaddress)
	ON_BN_CLICKED(IDC_DISCONNECT2, &CChatClientDlg::OnBnClickedDisconnect2)
	ON_EN_CHANGE(IDC_PORT2, &CChatClientDlg::OnEnChangePort2)
	ON_EN_CHANGE(IDC_PORT3, &CChatClientDlg::OnEnChangePort3)
	ON_EN_CHANGE(IDC_PORT4, &CChatClientDlg::OnEnChangePort4)
	ON_EN_CHANGE(IDC_PORT5, &CChatClientDlg::OnEnChangePort5)
	ON_EN_CHANGE(IDC_PORT6, &CChatClientDlg::OnEnChangePort6)
	ON_LBN_SELCHANGE(IDC_HISTORY, &CChatClientDlg::OnLbnSelchangeHistory)
END_MESSAGE_MAP()


// CChatClientDlg ��Ϣ�������

BOOL CChatClientDlg::OnInitDialog()
{

	
	CDialog::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
GetDlgItem(IDC_DISCONNECT)->EnableWindow(FALSE);
GetDlgItem(IDC_SEND)->EnableWindow(FALSE); 
GetDlgItem(IDC_SEND2)->EnableWindow(FALSE); 
GetDlgItem(IDC_INPUT)->EnableWindow(FALSE); 
//GetDlgItem(IDC_IPADDRESS)->SetWindowText((LPCTSTR)"127.0.0.1"); 
//GetDlgItem(IDC_PORT)->SetWindowText((LPCTSTR)"5000");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CChatClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChatClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		   CPaintDC   dc(this);   
          CRect   rect;   
          GetClientRect(&rect);   
          CDC   dcMem;   
          dcMem.CreateCompatibleDC(&dc);   

		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��

HCURSOR CChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CChatClientDlg::OnBnClickedConnect()
{
	if(canstart){
	ifstartjudge=1;
	GetDlgItem(IDC_CONNECT)->EnableWindow(FALSE); 
	GetDlgItem(IDC_DISCONNECT)->EnableWindow(TRUE); 
	//GetDlgItem(IDC_SEND)->EnableWindow(TRUE); 
	GetDlgItem(IDC_SEND2)->EnableWindow(TRUE); 
	/*CString temp1,temp2; 
	GetDlgItem(IDC_IPADDRESS)->GetWindowText(temp1); */
	CString m_IPAddress=ip.GetBuffer(ip.GetLength() ); 
	//GetDlgItem(IDC_PORT)->GetWindowText(temp2); 
	//port1="5000";
	int m_Port=atoi(port1); 
	m_client=new CMySocket; 
	if ((*m_client).Create()==0) 
	{ 
		CString errcode; 
		errcode.Format("%d",GetLastError()); 
		m_list.AddString(errcode); 
		UpdateData(FALSE); 
	} 
	m_client->Connect(m_IPAddress,m_Port);
	//GetDlgItem(IDC_IPADDRESS)->EnableWindow(FALSE); 
	//GetDlgItem(IDC_PORT)->EnableWindow(FALSE); 
	
	GetDlgItem(IDC_PORT2)->GetWindowText(name); 
	GetDlgItem(IDC_PORT3)->GetWindowText(code); 
	GetDlgItem(IDC_PORT4)->GetWindowText(myemail); 
	GetDlgItem(IDC_PORT5)->GetWindowText(sendmail); 
	}
}

void CChatClientDlg::OnBnClickedDisconnect()
{  
	if(connected){
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	(*m_client).Close(); 
	delete m_client; 
	//GetDlgItem(IDC_IPADDRESS)->EnableWindow(TRUE); 
	//GetDlgItem(IDC_PORT)->EnableWindow(TRUE); 
	GetDlgItem(IDC_INPUT)->EnableWindow(FALSE); 
	GetDlgItem(IDC_CONNECT)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEND)->EnableWindow(FALSE); 
	GetDlgItem(IDC_SEND2)->EnableWindow(FALSE); 
	GetDlgItem(IDC_DISCONNECT)->EnableWindow(FALSE); 
	/*CString str; 
	m_tm=CTime::GetCurrentTime(); 
	str=m_tm.Format("%X "); 
	str+="�ӷ������Ͽ�!"; 
	m_list.AddString(str); */
	UpdateData(FALSE);
	connected=0;
	}

}

void CChatClientDlg::OnBnClickedSend()
{
	
	//if(ifstartjudge==0){
	//
	//GetDlgItem(IDC_PORT6)->GetWindowText(theme); 
	//CString formatbuff="#c#s#";
	//formatbuff+="(����:";
	//formatbuff+=theme;
	//formatbuff+=")";
	////(*m_client).Send(formatbuff,200,0); 
	////Sleep(1000);
	//m_input.GetWindowText(buff,200); 
 //   formatbuff+=(CString)buff;
	//(*m_client).Send(formatbuff,200,0); 
	///*CString temp1="�ң�"; 
	//CString temp2=buff; 
	//CString str; 
	//m_tm=CTime::GetCurrentTime(); 
	//str=m_tm.Format("%X "); 
	//temp1=str+temp1; 
	//temp1+=temp2; 
	//m_list.AddString(temp1); */
	//UpdateData(FALSE); 
	//m_input.SetWindowText("");
	//}
	//----------------------------------------------------------------------------------
	// CString port1="";
 //CString emailserver="";
 //CString ip="";
 //CString name="";
 //CString code="";
 //CString myemail="";
 //CString sendmail="";
 //CString theme=""
	//SmtpMail mymail(SmtpSrvName, Port, UserName, Password,From, To, Subject, Msg);
	
	//SmtpMail mymail("smtp.126.com", "25", "bbad1323","-----------","bbad1323@126.com","bbad1323@126.com", "ilove", "ilove");
	//mymail.SendMail();
	GetDlgItem(IDC_PORT6)->GetWindowText(theme); 
	m_input.GetWindowText(buff,200); 
	SmtpMail mymail2(emailserver, port1, name,code,myemail, sendmail ,theme, buff);

	if(NULL==mymail2.SendMail())
		MessageBox("Mailed successfully!");
	UpdateData(FALSE); 
	m_input.SetWindowText("");

}
void CChatClientDlg::OnBnClickedSend2(){
	//if(ifstartjudge)
	//{
	//CString formatbuff="#c#s#"+emailserver+name+code+sendmail;
	//(*m_client).Send(formatbuff,200,0);
	//ifstartjudge=0;
	GetDlgItem(IDC_SEND)->EnableWindow(TRUE); 
	GetDlgItem(IDC_SEND2)->EnableWindow(FALSE); 
	GetDlgItem(IDC_INPUT)->EnableWindow(TRUE); 
	//}
}


//void CChatClientDlg::OnEnChangePort()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
////#1015
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}


//void CChatClientDlg::OnIpnFieldchangedIpaddress(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
//	//@TN
//		*pResult = 0;
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	*pResult = 0;
//}


void CChatClientDlg::OnBnClickedDisconnect2()
{
     CDialog2 *cdialog2;
	 cdialog2 =new CDialog2;
	 cdialog2->Create(IDD_DIALOG1);
	 cdialog2->ShowWindow(SW_SHOW);
}
void CChatClientDlg::OnEnChangePort2()
{

}
void CChatClientDlg::OnEnChangePort3()
{

}
void CChatClientDlg::OnEnChangePort4()
{

}
void CChatClientDlg::OnEnChangePort5()
{
}
void CChatClientDlg::OnEnChangePort6()
{
}


void CChatClientDlg::OnLbnSelchangeHistory()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
