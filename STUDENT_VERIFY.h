#pragma once
#include "afxwin.h"


// STUDENT_VERIFY 对话框

class STUDENT_VERIFY : public CDialogEx
{
	DECLARE_DYNAMIC(STUDENT_VERIFY)

public:
	STUDENT_VERIFY(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~STUDENT_VERIFY();

// 对话框数据
	enum { IDD = IDD_STUDENT_VERIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSplit1();
	CSplitButton m_CHOOSE_CLASS;
	void CLASS1(void);
	void CLASS2(void);
	void CLASS3(void);
	void CLASS4(void);
	int CLASS_IDENTIFIER;
	static STUDENT_VERIFY *m_STUDENT_VERIFY;
//	virtual BOOL OnInitDialog();
//	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	virtual void OnOK();
	CMFCApplication5Dlg *ParentWnd;
};
