#pragma once


// ADD_COURSE �Ի���

class ADD_COURSE : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_COURSE)

public:
	ADD_COURSE(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ADD_COURSE();

// �Ի�������
	enum { IDD = IDD_ADD_COURSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CMFCApplication5Dlg *ParentWnd;
	//TEACHER_COURSELIST *ParentWnd1;
};
