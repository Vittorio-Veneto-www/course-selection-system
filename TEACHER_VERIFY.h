#pragma once
#include "afxwin.h"


// TEACHER_VERIFY 对话框

class TEACHER_VERIFY : public CDialogEx
{
	DECLARE_DYNAMIC(TEACHER_VERIFY)

public:
	TEACHER_VERIFY(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TEACHER_VERIFY();

// 对话框数据
	enum { IDD = IDD_TEACHER_VERIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	static TEACHER_VERIFY *m_TEACHER_VERIFY;
//	virtual BOOL OnInitDialog();
//	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	virtual void OnOK();
	CMFCApplication5Dlg *ParentWnd;
};
