#pragma once
#include "afxwin.h"


// STUDENT_COURSELIST 对话框

class STUDENT_COURSELIST : public CDialogEx
{
	DECLARE_DYNAMIC(STUDENT_COURSELIST)

public:
	STUDENT_COURSELIST(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~STUDENT_COURSELIST();

// 对话框数据
	enum { IDD = IDD_STUDENT_COURSELIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMFCApplication5Dlg *ParentWnd;
	virtual void OnCancel();
	int Page,ORDER;
	inline void DRAW(int);
	void DrawPage(void);
	CButton BUTTON1;
	CButton BUTTON2;
	CButton BUTTON3;
	CButton BUTTON4;
	CButton BUTTON5;
	CButton BUTTON6;
	CButton BUTTON7;
	CButton BUTTON8;
	CButton BUTTON9;
	CButton BUTTON10;
	CButton PAGEDOWN;
	CButton PAGEUP;
	CStatic TEXT1;
	CStatic TEXT2;
	CStatic TEXT3;
	CStatic TEXT4;
	CStatic TEXT5;
	CStatic TEXT6;
	CStatic TEXT7;
	CStatic TEXT8;
	CStatic TEXT9;
	CStatic TEXT10;
	afx_msg void OnClickedPageup();
	afx_msg void OnClickedPagedown();
	inline void BTNCLK1(int);
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton2();
	afx_msg void OnClickedButton3();
	afx_msg void OnClickedButton4();
	afx_msg void OnClickedButton5();
	inline void BTNCLK2(int);
	afx_msg void OnClickedButton6();
	afx_msg void OnClickedButton7();
	afx_msg void OnClickedButton8();
	afx_msg void OnClickedButton9();
	afx_msg void OnClickedButton10();
	CStatic TEXT_ID;
	CStatic TEXT_CLASSID;
	afx_msg void OnClickedRefresh();
	afx_msg void OnClickedTurnto();
protected:
	afx_msg LRESULT OnRefresh(WPARAM wParam, LPARAM lParam);
};
