// DETAIL.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "DETAIL.h"
#include "afxdialogex.h"


// DETAIL 对话框

IMPLEMENT_DYNAMIC(DETAIL, CDialogEx)

DETAIL::DETAIL(CWnd* pParent /*=NULL*/)
	: CDialogEx(DETAIL::IDD, pParent)
{

}

DETAIL::~DETAIL()
{
}

void DETAIL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CLASS1, CLASS1);
	DDX_Control(pDX, IDC_CLASS2, CLASS2);
	DDX_Control(pDX, IDC_CLASS3, CLASS3);
	DDX_Control(pDX, IDC_CLASS4, CLASS4);
	DDX_Control(pDX, IDC_CLASSID, CLASSID);
}


BEGIN_MESSAGE_MAP(DETAIL, CDialogEx)
END_MESSAGE_MAP()


// DETAIL 消息处理程序


void DETAIL::DrawPage(int CLASSNUM)
{
	CString temp;
	char tempsum[100];
	temp=ParentWnd->COURSELIST[CLASSNUM];
	CLASSID.SetWindowText(temp);
	sprintf(tempsum,"%d",ParentWnd->COURSE_SELECTCOUNT[CLASSNUM][1]);
	temp=tempsum;
	CLASS1.SetWindowText(temp);
	sprintf(tempsum,"%d",ParentWnd->COURSE_SELECTCOUNT[CLASSNUM][2]);
	temp=tempsum;
	CLASS2.SetWindowText(temp);
	sprintf(tempsum,"%d",ParentWnd->COURSE_SELECTCOUNT[CLASSNUM][3]);
	temp=tempsum;
	CLASS3.SetWindowText(temp);
	sprintf(tempsum,"%d",ParentWnd->COURSE_SELECTCOUNT[CLASSNUM][4]);
	temp=tempsum;
	CLASS4.SetWindowText(temp);
}
