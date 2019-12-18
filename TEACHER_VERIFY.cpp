// TEACHER_VERIFY.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "TEACHER_VERIFY.h"
#include "afxdialogex.h"


// TEACHER_VERIFY 对话框

IMPLEMENT_DYNAMIC(TEACHER_VERIFY, CDialogEx)

TEACHER_VERIFY::TEACHER_VERIFY(CWnd* pParent /*=NULL*/)
	: CDialogEx(TEACHER_VERIFY::IDD, pParent)
{
}

TEACHER_VERIFY::~TEACHER_VERIFY()
{
}

void TEACHER_VERIFY::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TEACHER_VERIFY, CDialogEx)
END_MESSAGE_MAP()


// TEACHER_VERIFY 消息处理程序


//BOOL TEACHER_VERIFY::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
//#5312
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//
//#5312
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	// TODO:  在此添加额外的初始化
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	// 异常: OCX 属性页应返回 FALSE
//}


//BOOL TEACHER_VERIFY::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	return CDialogEx::Create(lpszTemplateName, pParentWnd);
//}


//HRESULT TEACHER_VERIFY::accDoDefaultAction(VARIANT varChild)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	return CDialogEx::accDoDefaultAction(varChild);
//}


void TEACHER_VERIFY::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	CString password;
	GetDlgItem(IDC_EDIT1)->GetWindowText(password);
	int verified=StrCmpW(password,L"1234");
	if (verified!=0) 
	{
		MessageBox(_T("密码错误"),NULL,MB_OK);
		return;
	}
	ParentWnd->VERIFIED_TEACHER();
	//ParentWnd->CLASS_IDENTIFIER=CLASS_IDENTIFIER;
	CDialogEx::OnOK();
}
