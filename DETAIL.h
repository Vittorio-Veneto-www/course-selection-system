#pragma once
#include "afxwin.h"


// DETAIL �Ի���

class DETAIL : public CDialogEx
{
	DECLARE_DYNAMIC(DETAIL)

public:
	DETAIL(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DETAIL();

// �Ի�������
	enum { IDD = IDD_DETAIL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
