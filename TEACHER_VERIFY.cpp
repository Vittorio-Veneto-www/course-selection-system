// TEACHER_VERIFY.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "TEACHER_VERIFY.h"
#include "afxdialogex.h"


// TEACHER_VERIFY �Ի���

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


// TEACHER_VERIFY ��Ϣ�������


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
//	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	// �쳣: OCX ����ҳӦ���� FALSE
//}


//BOOL TEACHER_VERIFY::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//
//	return CDialogEx::Create(lpszTemplateName, pParentWnd);
//}


//HRESULT TEACHER_VERIFY::accDoDefaultAction(VARIANT varChild)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//
//	return CDialogEx::accDoDefaultAction(varChild);
//}


void TEACHER_VERIFY::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	CString password;
	GetDlgItem(IDC_EDIT1)->GetWindowText(password);
	int verified=StrCmpW(password,L"1234");
	if (verified!=0) 
	{
		MessageBox(_T("�������"),NULL,MB_OK);
		return;
	}
	ParentWnd->VERIFIED_TEACHER();
	//ParentWnd->CLASS_IDENTIFIER=CLASS_IDENTIFIER;
	CDialogEx::OnOK();
}
