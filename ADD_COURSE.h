#pragma once


// ADD_COURSE 对话框

class ADD_COURSE : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_COURSE)

public:
	ADD_COURSE(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ADD_COURSE();

// 对话框数据
	enum { IDD = IDD_ADD_COURSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CMFCApplication5Dlg *ParentWnd;
	//TEACHER_COURSELIST *ParentWnd1;
};
