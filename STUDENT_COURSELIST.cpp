// STUDENT_COURSELIST.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "STUDENT_COURSELIST.h"
#include "DETAIL.h"
#include "afxdialogex.h"


// STUDENT_COURSELIST 对话框

IMPLEMENT_DYNAMIC(STUDENT_COURSELIST, CDialogEx)

STUDENT_COURSELIST::STUDENT_COURSELIST(CWnd* pParent /*=NULL*/)
	: CDialogEx(STUDENT_COURSELIST::IDD, pParent)
{
	Page = 0;
}

STUDENT_COURSELIST::~STUDENT_COURSELIST()
{
}

void STUDENT_COURSELIST::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, BUTTON1);
	DDX_Control(pDX, IDC_BUTTON2, BUTTON2);
	DDX_Control(pDX, IDC_BUTTON3, BUTTON3);
	DDX_Control(pDX, IDC_BUTTON4, BUTTON4);
	DDX_Control(pDX, IDC_BUTTON5, BUTTON5);
	DDX_Control(pDX, IDC_BUTTON6, BUTTON6);
	DDX_Control(pDX, IDC_BUTTON7, BUTTON7);
	DDX_Control(pDX, IDC_BUTTON8, BUTTON8);
	DDX_Control(pDX, IDC_BUTTON9, BUTTON9);
	DDX_Control(pDX, IDC_BUTTON10, BUTTON10);
	DDX_Control(pDX, IDC_PAGEDOWN, PAGEDOWN);
	DDX_Control(pDX, IDC_PAGEUP, PAGEUP);
	DDX_Control(pDX, IDC_TEXT1, TEXT1);
	DDX_Control(pDX, IDC_TEXT2, TEXT2);
	DDX_Control(pDX, IDC_TEXT3, TEXT3);
	DDX_Control(pDX, IDC_TEXT4, TEXT4);
	DDX_Control(pDX, IDC_TEXT5, TEXT5);
	DDX_Control(pDX, IDC_TEXT6, TEXT6);
	DDX_Control(pDX, IDC_TEXT7, TEXT7);
	DDX_Control(pDX, IDC_TEXT8, TEXT8);
	DDX_Control(pDX, IDC_TEXT9, TEXT9);
	DDX_Control(pDX, IDC_TEXT10, TEXT10);
	DDX_Control(pDX, IDC_ID, TEXT_ID);
	DDX_Control(pDX, IDC_CLASSID, TEXT_CLASSID);
}

const UINT WM_REFRESH = ::RegisterWindowMessage(_T("WM_REFRESH"));

BEGIN_MESSAGE_MAP(STUDENT_COURSELIST, CDialogEx)
	ON_BN_CLICKED(IDC_PAGEUP, &STUDENT_COURSELIST::OnClickedPageup)
	ON_BN_CLICKED(IDC_PAGEDOWN, &STUDENT_COURSELIST::OnClickedPagedown)
	ON_BN_CLICKED(IDC_BUTTON1, &STUDENT_COURSELIST::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &STUDENT_COURSELIST::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &STUDENT_COURSELIST::OnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &STUDENT_COURSELIST::OnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &STUDENT_COURSELIST::OnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &STUDENT_COURSELIST::OnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &STUDENT_COURSELIST::OnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &STUDENT_COURSELIST::OnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &STUDENT_COURSELIST::OnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &STUDENT_COURSELIST::OnClickedButton10)
	ON_BN_CLICKED(IDC_REFRESH, &STUDENT_COURSELIST::OnClickedRefresh)
	ON_BN_CLICKED(IDC_TURNTO, &STUDENT_COURSELIST::OnClickedTurnto)
	ON_REGISTERED_MESSAGE(WM_REFRESH, &STUDENT_COURSELIST::OnRefresh)
END_MESSAGE_MAP()


// STUDENT_COURSELIST 消息处理程序


void STUDENT_COURSELIST::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	ParentWnd->SAVEDATA();
	ParentWnd->WNDCNT--;
	CDialogEx::OnCancel();
}


inline void STUDENT_COURSELIST::DRAW(int cnt)
{
	CString temp;
	char tempsum[100];
	if (ParentWnd->COURSE_COUNT>5*Page+cnt)
	{	
		temp=ParentWnd->COURSELIST[5*Page+cnt];
		GetDlgItem(IDC_TEXT1+cnt)->SetWindowText(temp);
		sprintf(tempsum,"%d",ParentWnd->COURSE_SELECTCOUNT[5*Page+cnt][0]);
		temp=tempsum;
		GetDlgItem(IDC_TEXT6+cnt)->SetWindowText(temp);
		if (ParentWnd->COURSE_SELECTED[ORDER][5*Page+cnt])
			GetDlgItem(IDC_BUTTON6+cnt)->SetWindowText(_T("退课"));
		else
			GetDlgItem(IDC_BUTTON6+cnt)->SetWindowText(_T("选课"));
		GetDlgItem(IDC_TEXT1+cnt)->EnableWindow(true);
		GetDlgItem(IDC_TEXT6+cnt)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON6+cnt)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON1+cnt)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_TEXT1+cnt)->EnableWindow(false);
		GetDlgItem(IDC_TEXT6+cnt)->EnableWindow(false);
		GetDlgItem(IDC_TEXT1+cnt)->SetWindowText(L"");
		GetDlgItem(IDC_TEXT6+cnt)->SetWindowText(L"");
		BUTTON6.SetWindowText(_T("选课"));
		GetDlgItem(IDC_BUTTON6+cnt)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON1+cnt)->EnableWindow(false);
	}
}


void STUDENT_COURSELIST::DrawPage(void)
{
	if (Page<=0)
		PAGEUP.EnableWindow(false);
	else
		PAGEUP.EnableWindow(true);
	if ((ParentWnd->COURSE_COUNT-1)/5<=Page)
		PAGEDOWN.EnableWindow(false);
	else
		PAGEDOWN.EnableWindow(true);
	CString temp;
	char tempsum[100];
		/*sprintf(tempsum,"%d",ParentWnd->COURSE_COUNT);
		temp=tempsum;
		MessageBox(temp,NULL,MB_OK);*/
	sprintf(tempsum,"页，共%d页",(ParentWnd->COURSE_COUNT-1)/5+1);
	temp=tempsum;
	GetDlgItem(IDC_PAGECNT)->SetWindowText(temp);
	sprintf(tempsum,"%d",Page+1);
	temp=tempsum;
	GetDlgItem(IDC_PAGEORDER)->SetWindowText(temp);
	for (int i=0;i<5;i++)
		DRAW(i);
}


void STUDENT_COURSELIST::OnClickedPageup()
{
	Page--;
	DrawPage();
	// TODO: 在此添加控件通知处理程序代码
}


void STUDENT_COURSELIST::OnClickedPagedown()
{
	Page++;
	DrawPage();
	// TODO: 在此添加控件通知处理程序代码
}


inline void STUDENT_COURSELIST::BTNCLK1(int cnt)
{
	DETAIL* m_DETAIL = new DETAIL();
	m_DETAIL->Create(IDD_DETAIL, this);
	m_DETAIL->SetWindowText(L"详情");
	m_DETAIL->ParentWnd=ParentWnd;
	m_DETAIL->DrawPage(Page*5+cnt);
	m_DETAIL->ShowWindow(SW_SHOW);
}


void STUDENT_COURSELIST::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK1(0);
}


void STUDENT_COURSELIST::OnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK1(1);
}


void STUDENT_COURSELIST::OnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK1(2);
}


void STUDENT_COURSELIST::OnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK1(3);
}


void STUDENT_COURSELIST::OnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK1(4);
}


inline void STUDENT_COURSELIST::BTNCLK2(int cnt)
{
	if (!ParentWnd->COURSE_SELECTED[ORDER][5*Page+cnt])
	{
		ParentWnd->COURSE_SELECTCOUNT[5*Page+cnt][0]++;
		ParentWnd->COURSE_SELECTCOUNT[5*Page+cnt][ParentWnd->STUDENT_CLASS[ORDER]]++;
		ParentWnd->COURSE_SELECTED[ORDER][5*Page+cnt]=1;
		DrawPage();
	}
	else
	{
		ParentWnd->COURSE_SELECTCOUNT[5*Page+cnt][0]--;
		ParentWnd->COURSE_SELECTCOUNT[5*Page+cnt][ParentWnd->STUDENT_CLASS[ORDER]]--;
		ParentWnd->COURSE_SELECTED[ORDER][5*Page+cnt]=0;
		DrawPage();
	}
}


void STUDENT_COURSELIST::OnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK2(0);
}


void STUDENT_COURSELIST::OnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK2(1);
}


void STUDENT_COURSELIST::OnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK2(2);
}


void STUDENT_COURSELIST::OnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK2(3);
}


void STUDENT_COURSELIST::OnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK2(4);
}


void STUDENT_COURSELIST::OnClickedRefresh()
{
	// TODO: 在此添加控件通知处理程序代码
	DrawPage();
}


void STUDENT_COURSELIST::OnClickedTurnto()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	char temp1[100];
	GetDlgItem(IDC_PAGEORDER)->GetWindowText(temp);
	WideCharToMultiByte(CP_ACP,0,temp,temp.GetLength()+1,temp1,100,NULL,NULL);
	int tempsum;
	sscanf(temp1,"%d",&tempsum);
	if (tempsum>0&&tempsum<=(ParentWnd->COURSE_COUNT-1)/5+1)
	{
		Page=tempsum-1;
		DrawPage();
	}
	else
		MessageBox(L"非法页数",NULL,MB_OK);
}


afx_msg LRESULT STUDENT_COURSELIST::OnRefresh(WPARAM wParam, LPARAM lParam)
{
	DrawPage();
	return 0;
}
