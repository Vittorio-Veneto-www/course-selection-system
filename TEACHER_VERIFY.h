#pragma once
#include "afxwin.h"


// TEACHER_VERIFY �Ի���

class TEACHER_VERIFY : public CDialogEx
{
	DECLARE_DYNAMIC(TEACHER_VERIFY)

public:
	TEACHER_VERIFY(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TEACHER_VERIFY();

// �Ի�������
	enum { IDD = IDD_TEACHER_VERIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	static TEACHER_VERIFY *m_TEACHER_VERIFY;
//	virtual BOOL OnInitDialog();
//	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	virtual void OnOK();
	CMFCApplication5Dlg *ParentWnd;
};
