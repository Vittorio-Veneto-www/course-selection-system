#pragma once
#include "afxwin.h"


// DETAIL 对话框

class DETAIL : public CDialogEx
{
	DECLARE_DYNAMIC(DETAIL)

public:
	DETAIL(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DETAIL();

// 对话框数据
	enum { IDD = IDD_DETAIL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMFCApplication5Dlg *ParentWnd;
	void DrawPage(int CLASSNUM);
	CStatic CLASS1;
	CStatic CLASS2;
	CStatic CLASS3;
	CStatic CLASS4;
	CStatic CLASSID;
};
