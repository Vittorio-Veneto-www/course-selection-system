
// MFCApplication5Dlg.h : 头文件
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


// CMFCApplication5Dlg 对话框
class CMFCApplication5Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication5Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION5_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedStudentVerify();
	afx_msg void OnClickedTeacherVerify();
	int CLASS_IDENTIFIER;
	char ID[100];
	char COURSELIST[200][100],IDLIST[200][100];
	int COURSE_COUNT,ID_COUNT,STUDENT_CLASS[200],COURSE_SELECTED[200][200],COURSE_SELECTCOUNT[200][5];
//	CMFCApplication5Dlg ParentWnd;
//	static CMFCApplication5Dlg GetHwnd1(void);
	void VERIFIED_STUDENT(void);
	void VERIFIED_TEACHER(void);
	int LOADDATA(void);
	void SAVEDATA(void);
	int ORDER;
	afx_msg void OnClickedInstruction();
	int WNDCNT;
};
