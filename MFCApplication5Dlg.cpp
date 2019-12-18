
// MFCApplication5Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication5Dlg �Ի���



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


// CMFCApplication5Dlg ��Ϣ�������

BOOL CMFCApplication5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication5Dlg::OnClickedStudentVerify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	STUDENT_VERIFY* m_STUDENT_VERIFY = new STUDENT_VERIFY();
	m_STUDENT_VERIFY->Create(IDD_STUDENT_VERIFY, this);
	m_STUDENT_VERIFY->SetWindowText(L"��½");
	m_STUDENT_VERIFY->ParentWnd=(CMFCApplication5Dlg*)this;
	m_STUDENT_VERIFY->ShowWindow(SW_SHOW);
}


void CMFCApplication5Dlg::OnClickedTeacherVerify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TEACHER_VERIFY* m_TEACHER_VERIFY = new TEACHER_VERIFY();
	m_TEACHER_VERIFY->Create(IDD_TEACHER_VERIFY, this);
	m_TEACHER_VERIFY->SetWindowText(L"��½");
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
	m_STUDENT_COURSELIST->SetWindowText(L"ѡ�ν���");
	m_STUDENT_COURSELIST->ParentWnd=(CMFCApplication5Dlg*)this;
	temp=ID;
	m_STUDENT_COURSELIST->TEXT_ID.SetWindowText(temp);
	if (STUDENT_CLASS[ORDER]==1) temp="һ��";
	if (STUDENT_CLASS[ORDER]==2) temp="����";
	if (STUDENT_CLASS[ORDER]==3) temp="����";
	if (STUDENT_CLASS[ORDER]==4) temp="�İ�";
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
	m_TEACHER_COURSELIST->SetWindowText(L"�������");
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
		printf("4 0\n��������\n��ѧ����\n�������\n�ߵȴ���\n");
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(L"����ѡ��ѧ�����߽�����ѡ��ѧ������Ҫѡ��༶������ID������Ϊ1234�������޸ġ�����½����ᱣ��ѡ����Ϣ����ѡ���������Ҫ�������룬Ϊ1234��֧�ֶ࿪���ڣ���Ҫ�ֶ�ˢ���Բ鿴���������������ġ�",NULL,MB_OK);
}
