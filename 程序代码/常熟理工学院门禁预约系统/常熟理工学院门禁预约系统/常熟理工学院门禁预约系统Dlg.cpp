
// ������ѧԺ�Ž�ԤԼϵͳDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������ѧԺ�Ž�ԤԼϵͳ.h"
#include "������ѧԺ�Ž�ԤԼϵͳDlg.h"
#include "afxdialogex.h"

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


// C������ѧԺ�Ž�ԤԼϵͳDlg �Ի���




C������ѧԺ�Ž�ԤԼϵͳDlg::C������ѧԺ�Ž�ԤԼϵͳDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C������ѧԺ�Ž�ԤԼϵͳDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C������ѧԺ�Ž�ԤԼϵͳDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST1, ctrlList_msg);                          //��ʼ���б�
	DDX_Control(pDX, IDC_COMBO1, comboBox_room);
}

BEGIN_MESSAGE_MAP(C������ѧԺ�Ž�ԤԼϵͳDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &C������ѧԺ�Ž�ԤԼϵͳDlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &C������ѧԺ�Ž�ԤԼϵͳDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &C������ѧԺ�Ž�ԤԼϵͳDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C������ѧԺ�Ž�ԤԼϵͳDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// C������ѧԺ�Ž�ԤԼϵͳDlg ��Ϣ�������

BOOL C������ѧԺ�Ž�ԤԼϵͳDlg::OnInitDialog()
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
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T("CSLG Access reservation system"));//�����������ݿ��Ĭ����ֵ

	comboBox_room.AddString(_T("(local)"));                                    //Ĭ�ϻ��
	comboBox_room.SetCurSel(0);                                                //����0��Ĭ��ѡ��
	CRect rect;
	ctrlList_msg.GetHeaderCtrl()->EnableWindow(false);                         //�̶����ⲻ���ƶ�
	ctrlList_msg.GetClientRect(&rect);                                         //��ȡ��������б���ͼ�ؼ���λ�úʹ�С
	ctrlList_msg.SetExtendedStyle(ctrlList_msg.GetExtendedStyle()
		| LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);                            //Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����

	ctrlList_msg.InsertColumn(0, _T("���"), LVCFMT_CENTER, 40, 0);
	ctrlList_msg.InsertColumn(1, _T("ԤԼ��"), LVCFMT_CENTER, 60, 1);
	ctrlList_msg.InsertColumn(2, _T("ԤԼʱ��"), LVCFMT_CENTER, (rect.Width() - 150) / 2, 2);
	ctrlList_msg.InsertColumn(3, _T("ʱ��"), LVCFMT_CENTER, 50, 3);
	ctrlList_msg.InsertColumn(4, _T("��ע"), LVCFMT_CENTER, (rect.Width() - 150) / 2, 4);

	get_db_data = NULL;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C������ѧԺ�Ž�ԤԼϵͳDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C������ѧԺ�Ž�ԤԼϵͳDlg::OnPaint()
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
HCURSOR C������ѧԺ�Ž�ԤԼϵͳDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C������ѧԺ�Ž�ԤԼϵͳDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C������ѧԺ�Ž�ԤԼϵͳDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C������ѧԺ�Ž�ԤԼϵͳDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_EDIT1)->GetWindowText(DatabaseName);                        //��ȡ���ݿ������
	comboBox_room.ResetContent();                                              //����������
	MyDB *mydb = new MyDB(DatabaseName);
	mydb->ConnectDatabase();                                                   //�������ݿ�
	if (mydb->IsConnect()){
		DBRoom *db_msg = new DBRoom(mydb->getDatabase());
		CString str("select * from ActivityRooms;");                           //��ѯ���еĻ��
		db_msg->query(str);

		for (int i = 0; i < db_msg->getRow(); ++i){                            //�������ݼ�
			int r_id = _ttoi(db_msg->getResult(i, 0));
			CString r_name = db_msg->getResult(i, 1);
			CString information = db_msg->getResult(i, 2);
			ActivityRoom t_room(r_id, r_name, information);                    //����ȡ������ת��Ϊ���󱣴�
			this->rooms.push_back(t_room);
			comboBox_room.AddString(r_name);                                   //��ӵ���������
		}
		comboBox_room.SetCurSel(0);                                            //���õ�һ������Ĭ��ѡ��

		this->get_db_data = new GetReservationsFromDB(_T("select * from Reservations where room_id = 1;"), 3000);

		db_msg->Close();
		mydb->CloseDatabase();
		SetTimer(1, 1000, NULL);
	}
}


void C������ѧԺ�Ž�ԤԼϵͳDlg::OnCbnSelchangeCombo1()                        //��Ӧ������������ʾĳ���ԤԼ���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (get_db_data != NULL){
		get_db_data->CloseTimer();
	}

	CString room_name;
	comboBox_room.GetLBText(comboBox_room.GetCurSel(), room_name);             //��ȡ��ǰѡ�еĻ����
	int room_id = 1;
	for (int i = 0; i < this->rooms.size(); ++i){                              //�ҵ�ӵ�д����ֵĻ�ҵ�ID
		if (this->rooms[i].getRoomName() == room_name){
			room_id = this->rooms[i].getRoomID();
			break;
		}
	}
	CString sql;
	sql.Format(_T("select * from Reservations where room_id = %d;"), room_id); //��д��ѯsql
	this->get_db_data = new GetReservationsFromDB(sql, 3000);                  //��ʼ��ѯ����
}


void C������ѧԺ�Ž�ԤԼϵͳDlg::OnTimer(UINT nIDEvent)                        //��ʱͨ�����������ݼ����е����ݸ����б�
{
	ctrlList_msg.DeleteAllItems();                                             //ɾ������item
	for (int i = 0; i < database_messges.size(); ++i){                         //�����б�����
		ctrlList_msg.InsertItem(i, _T(""));
		ReservationMessages msg = database_messges[i];

		ctrlList_msg.SetItemText(i, 0, msg.getReservationID());
		ctrlList_msg.SetItemText(i, 1, msg.getUsername());
		ctrlList_msg.SetItemText(i, 2, msg.getTime());
		ctrlList_msg.SetItemText(i, 3, msg.getDuration());
		ctrlList_msg.SetItemText(i, 4, msg.getInformation());
	}
}