// TEACHER_COURSELIST.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "TEACHER_COURSELIST.h"
#include "DETAIL.h"
#include "ADD_COURSE.h"
#include "afxdialogex.h"


// TEACHER_COURSELIST 对话框

IMPLEMENT_DYNAMIC(TEACHER_COURSELIST, CDialogEx)

TEACHER_COURSELIST::TEACHER_COURSELIST(CWnd* pParent /*=NULL*/)
	: CDialogEx(TEACHER_COURSELIST::IDD, pParent)
{
	Page = 0;
}

TEACHER_COURSELIST::~TEACHER_COURSELIST()
{
}

void TEACHER_COURSELIST::DoDataExchange(CDataExchange* pDX)
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
	DDX_Control(pDX, IDC_ADDCOURSE, ADDCOURSE);
}

const UINT WM_REFRESH = ::RegisterWindowMessage(_T("WM_REFRESH"));

BEGIN_MESSAGE_MAP(TEACHER_COURSELIST, CDialogEx)
	ON_BN_CLICKED(IDC_PAGEUP, &TEACHER_COURSELIST::OnClickedPageup)
	ON_BN_CLICKED(IDC_PAGEDOWN, &TEACHER_COURSELIST::OnClickedPagedown)
	ON_BN_CLICKED(IDC_BUTTON1, &TEACHER_COURSELIST::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TEACHER_COURSELIST::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &TEACHER_COURSELIST::OnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &TEACHER_COURSELIST::OnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &TEACHER_COURSELIST::OnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &TEACHER_COURSELIST::OnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &TEACHER_COURSELIST::OnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &TEACHER_COURSELIST::OnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &TEACHER_COURSELIST::OnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &TEACHER_COURSELIST::OnClickedButton10)
	ON_BN_CLICKED(IDC_ADDCOURSE, &TEACHER_COURSELIST::OnClickedAddcourse)
	ON_BN_CLICKED(IDC_REFRESH, &TEACHER_COURSELIST::OnClickedRefresh)
	ON_BN_CLICKED(IDC_TURNTO, &TEACHER_COURSELIST::OnClickedTurnto)
	ON_REGISTERED_MESSAGE(WM_REFRESH, &TEACHER_COURSELIST::OnRefresh)
END_MESSAGE_MAP()


// TEACHER_COURSELIST 消息处理程序


void TEACHER_COURSELIST::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	ParentWnd->SAVEDATA();
	ParentWnd->WNDCNT--;
	CDialogEx::OnCancel();
}


inline void TEACHER_COURSELIST::DRAW(int cnt)
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
		GetDlgItem(IDC_BUTTON6+cnt)->SetWindowText(_T("删除课程"));
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
		BUTTON6.SetWindowText(_T("删除课程"));
		GetDlgItem(IDC_BUTTON6+cnt)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON1+cnt)->EnableWindow(false);
	}
}


void TEACHER_COURSELIST::DrawPage(void)
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


void TEACHER_COURSELIST::OnClickedPageup()
{
	Page--;
	DrawPage();
	// TODO: 在此添加控件通知处理程序代码
}


void TEACHER_COURSELIST::OnClickedPagedown()
{
	Page++;
	DrawPage();
	// TODO: 在此添加控件通知处理程序代码
}


inline void TEACHER_COURSELIST::BTNCLK1(int cnt)
{
	DETAIL* m_DETAIL = new DETAIL();
	m_DETAIL->Create(IDD_DETAIL, this);
	m_DETAIL->SetWindowText(L"详情");
	m_DETAIL->ParentWnd=ParentWnd;
	m_DETAIL->DrawPage(Page*5+cnt);
	m_DETAIL->ShowWindow(SW_SHOW);
}


void TEACHER_COURSELIST::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK1(0);
}


void TEACHER_COURSELIST::OnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK1(1);
}


void TEACHER_COURSELIST::OnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK1(2);
}


void TEACHER_COURSELIST::OnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK1(3);
}


void TEACHER_COURSELIST::OnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK1(4);
}


inline void TEACHER_COURSELIST::BTNCLK2(int cnt)
{
	if (MessageBox(L"选择是否执行",NULL,MB_YESNO)==IDYES)
	{
		for (int i=5*Page+cnt;i<ParentWnd->COURSE_COUNT;i++)
		{
			strcpy(ParentWnd->COURSELIST[i],ParentWnd->COURSELIST[i+1]);
			for (int j=0;j<ParentWnd->ID_COUNT;j++)
			ParentWnd->COURSE_SELECTED[i][j]=ParentWnd->COURSE_SELECTED[i+1][j];
			for (int j=0;j<5;j++)
			ParentWnd->COURSE_SELECTCOUNT[i][j]=ParentWnd->COURSE_SELECTCOUNT[i+1][j];
		}
		ParentWnd->COURSE_COUNT--;
		DrawPage();
	}
}


void TEACHER_COURSELIST::OnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK2(0);
}


void TEACHER_COURSELIST::OnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK2(1);
}


void TEACHER_COURSELIST::OnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK2(2);
}


void TEACHER_COURSELIST::OnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK2(3);
}


void TEACHER_COURSELIST::OnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	BTNCLK2(4);
}


void TEACHER_COURSELIST::OnClickedAddcourse()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD_COURSE* m_ADD_COURSE = new ADD_COURSE();
	m_ADD_COURSE->Create(IDD_ADD_COURSE, this);
	m_ADD_COURSE->ParentWnd=ParentWnd;
	//m_ADD_COURSE->ParentWnd1=this;
	m_ADD_COURSE->ShowWindow(SW_SHOW);
}


void TEACHER_COURSELIST::OnClickedRefresh()
{
	// TODO: 在此添加控件通知处理程序代码
	DrawPage();
}


void TEACHER_COURSELIST::OnClickedTurnto()
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


afx_msg LRESULT TEACHER_COURSELIST::OnRefresh(WPARAM wParam, LPARAM lParam)
{
	DrawPage();
	return 0;
}
