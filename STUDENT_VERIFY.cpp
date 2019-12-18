// STUDENT_VERIFY.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "STUDENT_VERIFY.h"
#include "afxdialogex.h"


// STUDENT_VERIFY 对话框

IMPLEMENT_DYNAMIC(STUDENT_VERIFY, CDialogEx)

STUDENT_VERIFY::STUDENT_VERIFY(CWnd* pParent /*=NULL*/)
	: CDialogEx(STUDENT_VERIFY::IDD, pParent)
{
}

STUDENT_VERIFY::~STUDENT_VERIFY()
{
}

void STUDENT_VERIFY::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_SPLIT1, m_CLASS_CHOOSE);
	DDX_Control(pDX, IDC_SPLIT1, m_CHOOSE_CLASS);
	m_CHOOSE_CLASS.SetWindowText(L"一班");
}


BEGIN_MESSAGE_MAP(STUDENT_VERIFY, CDialogEx)
	ON_BN_CLICKED(IDC_SPLIT1, &STUDENT_VERIFY::OnBnClickedSplit1)
	ON_BN_CLICKED(CHOOSE_CLASS1, &STUDENT_VERIFY::CLASS1)
	ON_BN_CLICKED(CHOOSE_CLASS2, &STUDENT_VERIFY::CLASS2)
	ON_BN_CLICKED(CHOOSE_CLASS3, &STUDENT_VERIFY::CLASS3)
	ON_BN_CLICKED(CHOOSE_CLASS4, &STUDENT_VERIFY::CLASS4)
END_MESSAGE_MAP()


// STUDENT_VERIFY 消息处理程序


void STUDENT_VERIFY::OnBnClickedSplit1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_CHOOSE_CLASS.SetDropDownMenu(IDR_SELECT_CLASS, 0);
}


void STUDENT_VERIFY::CLASS1(void)
{
	ParentWnd->CLASS_IDENTIFIER=1;
	m_CHOOSE_CLASS.SetWindowText(L"一班");
}


void STUDENT_VERIFY::CLASS2(void)
{
	ParentWnd->CLASS_IDENTIFIER=2;
	m_CHOOSE_CLASS.SetWindowText(L"二班");
}


void STUDENT_VERIFY::CLASS3(void)
{
	ParentWnd->CLASS_IDENTIFIER=3;
	m_CHOOSE_CLASS.SetWindowText(L"三班");
}


void STUDENT_VERIFY::CLASS4(void)
{
	ParentWnd->CLASS_IDENTIFIER=4;
	m_CHOOSE_CLASS.SetWindowText(L"四班");
}


//BOOL STUDENT_VERIFY::OnInitDialog()
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


//BOOL STUDENT_VERIFY::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	return CDialogEx::Create(lpszTemplateName, pParentWnd);
//}


//HRESULT STUDENT_VERIFY::accDoDefaultAction(VARIANT varChild)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	return CDialogEx::accDoDefaultAction(varChild);
//}


void STUDENT_VERIFY::OnOK()
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
	CString ID;
	GetDlgItem(IDC_EDIT2)->GetWindowText(ID);
	if (ID.GetLength()>20)
	{
		MessageBox(L"名称过长",NULL,MB_OK);
		return;
	}
	WideCharToMultiByte(CP_ACP,0,ID,ID.GetLength()+1,ParentWnd->ID,100,NULL,NULL);
	ParentWnd->VERIFIED_STUDENT();
	//ParentWnd->CLASS_IDENTIFIER=CLASS_IDENTIFIER;
	CDialogEx::OnOK();
}
