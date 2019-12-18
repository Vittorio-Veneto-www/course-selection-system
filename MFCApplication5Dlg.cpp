
// MFCApplication5Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "STUDENT_VERIFY.h"
#include "STUDENT_COURSELIST.h"
#include "TEACHER_VERIFY.h"
#include "TEACHER_COURSELIST.h"
#include "afxdialogex.h"
#include <afxconv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication5Dlg 对话框



CMFCApplication5Dlg::CMFCApplication5Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication5Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	CLASS_IDENTIFIER = 1;
	ORDER = -1;
	WNDCNT = 0;
}

void CMFCApplication5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(DLG_STUDENT_VERIFY, &CMFCApplication5Dlg::OnClickedStudentVerify)
	ON_BN_CLICKED(DLG_TEACHER_VERIFY, &CMFCApplication5Dlg::OnClickedTeacherVerify)
	ON_BN_CLICKED(IDC_INSTRUCTION, &CMFCApplication5Dlg::OnClickedInstruction)
END_MESSAGE_MAP()


// CMFCApplication5Dlg 消息处理程序

BOOL CMFCApplication5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication5Dlg::OnClickedStudentVerify()
{
	// TODO: 在此添加控件通知处理程序代码
	STUDENT_VERIFY* m_STUDENT_VERIFY = new STUDENT_VERIFY();
	m_STUDENT_VERIFY->Create(IDD_STUDENT_VERIFY, this);
	m_STUDENT_VERIFY->SetWindowText(L"登陆");
	m_STUDENT_VERIFY->ParentWnd=(CMFCApplication5Dlg*)this;
	m_STUDENT_VERIFY->ShowWindow(SW_SHOW);
}


void CMFCApplication5Dlg::OnClickedTeacherVerify()
{
	// TODO: 在此添加控件通知处理程序代码
	TEACHER_VERIFY* m_TEACHER_VERIFY = new TEACHER_VERIFY();
	m_TEACHER_VERIFY->Create(IDD_TEACHER_VERIFY, this);
	m_TEACHER_VERIFY->SetWindowText(L"登陆");
	m_TEACHER_VERIFY->ParentWnd=(CMFCApplication5Dlg*)this;
	m_TEACHER_VERIFY->ShowWindow(SW_SHOW);
}


//CMFCApplication5Dlg CMFCApplication5Dlg::GetHwnd1(void)
//{
//	return CMFCApplication5Dlg();
//}


void CMFCApplication5Dlg::VERIFIED_STUDENT(void)
{
	if (LOADDATA())
		LOADDATA();
	WNDCNT++;
	ORDER=-1;
	CString temp;
	/*temp=ID;
	MessageBox(temp,NULL,MB_OK);*/
	for (int i=0;i<ID_COUNT;i++)
		if (strcmp(ID,IDLIST[i])==0)
		{
			ORDER=i;
			break;
		}
	if (ORDER==-1)
	{
		strcpy(IDLIST[ID_COUNT],ID);
		STUDENT_CLASS[ID_COUNT]=CLASS_IDENTIFIER;
		ORDER=ID_COUNT;
		ID_COUNT++;
	}
	STUDENT_COURSELIST* m_STUDENT_COURSELIST = new STUDENT_COURSELIST();
	m_STUDENT_COURSELIST->Create(IDD_STUDENT_COURSELIST, this);
	m_STUDENT_COURSELIST->SetWindowText(L"选课界面");
	m_STUDENT_COURSELIST->ParentWnd=(CMFCApplication5Dlg*)this;
	temp=ID;
	m_STUDENT_COURSELIST->TEXT_ID.SetWindowText(temp);
	if (STUDENT_CLASS[ORDER]==1) temp="一班";
	if (STUDENT_CLASS[ORDER]==2) temp="二班";
	if (STUDENT_CLASS[ORDER]==3) temp="三班";
	if (STUDENT_CLASS[ORDER]==4) temp="四班";
	m_STUDENT_COURSELIST->ORDER=ORDER;
	m_STUDENT_COURSELIST->TEXT_CLASSID.SetWindowText(temp);
	m_STUDENT_COURSELIST->DrawPage();
	m_STUDENT_COURSELIST->ShowWindow(SW_SHOW);
}


void CMFCApplication5Dlg::VERIFIED_TEACHER(void)
{
	if (LOADDATA())
		LOADDATA();
	WNDCNT++;
	/*temp=ID;
	MessageBox(temp,NULL,MB_OK);*/
	TEACHER_COURSELIST* m_TEACHER_COURSELIST = new TEACHER_COURSELIST();
	m_TEACHER_COURSELIST->Create(IDD_TEACHER_COURSELIST, this);
	m_TEACHER_COURSELIST->SetWindowText(L"管理界面");
	m_TEACHER_COURSELIST->ParentWnd=(CMFCApplication5Dlg*)this;
	m_TEACHER_COURSELIST->DrawPage();
	m_TEACHER_COURSELIST->ShowWindow(SW_SHOW);
}


int CMFCApplication5Dlg::LOADDATA(void)
{
	if (WNDCNT)
		return 0;
	CString buffer,temp;
	SHGetSpecialFolderPath(NULL, buffer.GetBuffer(MAX_PATH), CSIDL_MYDOCUMENTS, FALSE);
	temp.Format(_T("%s%s"), buffer ,L"\\elective.db");
	int len =WideCharToMultiByte(CP_ACP,0,temp,-1,NULL,0,NULL,NULL);
	char *buf =new char[len +1];
	WideCharToMultiByte(CP_ACP,0,temp,-1,buf,len,NULL,NULL);
	if (freopen(buf,"r",stdin))
	{
		scanf("%d%d",&COURSE_COUNT,&ID_COUNT);
		memset(COURSELIST,0,sizeof(COURSELIST));
		for (int i=0;i<COURSE_COUNT;i++)
			scanf("%s",COURSELIST[i]);
		for (int i=0;i<ID_COUNT;i++)
			scanf("%s%d",IDLIST[i],&STUDENT_CLASS[i]);
		memset(COURSE_SELECTCOUNT,0,sizeof(COURSE_SELECTCOUNT));
		memset(COURSE_SELECTED,0,sizeof(COURSE_SELECTED));
		for (int i=0;i<ID_COUNT;i++)
			for (int j=0;j<COURSE_COUNT;j++)
				scanf("%d",&COURSE_SELECTED[i][j]),COURSE_SELECTCOUNT[j][STUDENT_CLASS[i]]+=COURSE_SELECTED[i][j],COURSE_SELECTCOUNT[j][0]+=COURSE_SELECTED[i][j];
		/*freopen("%userprofile%\documents\elective1.db","w",stdout);
		printf("%d\n%s",COURSE_COUNT,COURSELIST[0]);
		fclose(stdout);
		temp=COURSELIST[0];
		MessageBox(temp,NULL,MB_OK);*/
		fclose(stdin);
		return 0;
	}
	else
	{
		freopen(buf,"w",stdout);
		printf("4 0\n军事理论\n数学分析\n计算概论\n高等代数\n");
		fclose(stdout);
		return 1;
	}
}


void CMFCApplication5Dlg::SAVEDATA(void)
{
	CString buffer,temp;
	SHGetSpecialFolderPath(NULL, buffer.GetBuffer(MAX_PATH), CSIDL_MYDOCUMENTS, FALSE);
	temp.Format(_T("%s%s"), buffer ,L"\\elective.db");
	int len =WideCharToMultiByte(CP_ACP,0,temp,-1,NULL,0,NULL,NULL);
	char *buf =new char[len +1];
	WideCharToMultiByte(CP_ACP,0,temp,-1,buf,len,NULL,NULL);
	freopen(buf,"w",stdout);
	printf("%d %d\n",COURSE_COUNT,ID_COUNT);
	for (int i=0;i<COURSE_COUNT;i++)
		printf("%s\n",COURSELIST[i]);
	for (int i=0;i<ID_COUNT;i++)
		printf("%s %d\n",IDLIST[i],STUDENT_CLASS[i]);
	for (int i=0;i<ID_COUNT;i++)
	{
		for (int j=0;j<COURSE_COUNT;j++)
			printf("%d ",COURSE_SELECTED[i][j]);
		printf("\n");
	}
	fclose(stdout);
}


void CMFCApplication5Dlg::OnClickedInstruction()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"首先选择学生或者教务，若选择学生则需要选择班级并输入ID，密码为1234，不可修改。若登陆过则会保存选课信息。若选择教务，则需要输入密码，为1234。支持多开窗口，需要手动刷新以查看其他窗口所做更改。",NULL,MB_OK);
}
