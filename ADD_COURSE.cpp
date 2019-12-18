// ADD_COURSE.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "ADD_COURSE.h"
#include "TEACHER_COURSELIST.h"
#include "afxdialogex.h"


// ADD_COURSE �Ի���

IMPLEMENT_DYNAMIC(ADD_COURSE, CDialogEx)

ADD_COURSE::ADD_COURSE(CWnd* pParent /*=NULL*/)
	: CDialogEx(ADD_COURSE::IDD, pParent)
{

}

ADD_COURSE::~ADD_COURSE()
{
}

void ADD_COURSE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ADD_COURSE, CDialogEx)
	ON_BN_CLICKED(IDOK, &ADD_COURSE::OnBnClickedOk)
END_MESSAGE_MAP()


// ADD_COURSE ��Ϣ�������


void ADD_COURSE::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString ID;
	GetDlgItem(IDC_EDIT1)->GetWindowText(ID);
	if (ID.GetLength()>20)
	{
		MessageBox(L"���ƹ���",NULL,MB_OK);
		return;
	}
	WideCharToMultiByte(CP_ACP,0,ID,ID.GetLength()+1,ParentWnd->COURSELIST[ParentWnd->COURSE_COUNT],100,NULL,NULL);
	for (int i=0;i<ParentWnd->COURSE_COUNT;i++)
		if (strcmp(ParentWnd->COURSELIST[ParentWnd->COURSE_COUNT],ParentWnd->COURSELIST[i])==0)
			{
				MessageBox(L"�����ظ�",NULL,MB_OK);
				ParentWnd->COURSELIST[ParentWnd->COURSE_COUNT][0]='\0';
				return;
			}
	ParentWnd->COURSE_COUNT++;
	TEACHER_COURSELIST *ParentWnd1;
	ParentWnd1=(TEACHER_COURSELIST *)GetParent();
	ParentWnd1->DrawPage();
	CDialogEx::OnOK();
}
