
// PlantsVsZobiesModifierDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "PlantsVsZobiesModifier.h"
#include "PlantsVsZobiesModifierDlg.h"
#include "afxdialogex.h"
#define IDTIMER1  1

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPlantsVsZobiesModifierDlg 对话框



CPlantsVsZobiesModifierDlg::CPlantsVsZobiesModifierDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PLANTSVSZOBIESMODIFIER_DIALOG, pParent)
	, m_idcInfiniteCD(FALSE)
	, m_BigFlower(FALSE)
	, m_btAI(FALSE)
	, m_HappyAI(FALSE)
	, m_idcFireAi(FALSE)
	, m_idcBigFlower(FALSE)
	, m_StrongPao(FALSE)
	, m_StrongTomato(FALSE)
	, m_StrongPlantAtt(FALSE)
	, m_AutoCol(FALSE)
	, m_IDCYumipao(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CPlantsVsZobiesModifierDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, LIST_PLANT, m_lstPlant);
	DDX_Control(pDX, LIST_GRASSPLANT, m_lstGrassPlant);
	DDX_Check(pDX, IDC_INFINITCD, m_idcInfiniteCD);
	DDX_Check(pDX, IDC_BIGFLOWER, m_BigFlower);
	DDX_Control(pDX, CMB_SELPLANT, m_cmbzbPlant);
	DDX_Check(pDX, IDC_BTPLANT, m_btAI);
	DDX_Check(pDX, IDC_HAPPYPLANT, m_HappyAI);
	DDX_Check(pDX, IDC_FIREAI, m_idcFireAi);
	DDX_Check(pDX, IDC_ICEAI2, m_idcBigFlower);
	DDX_Check(pDX, IDC_STRONGPAO, m_StrongPao);
	DDX_Check(pDX, IDC_STRONGTOMOTO, m_StrongTomato);
	DDX_Check(pDX, IDC_STRONGATT, m_StrongPlantAtt);
	DDX_Check(pDX, IDC_IDCAUTOCOL, m_AutoCol);
	DDX_Control(pDX, BTN_OPENMONITOR, m_btnOpenM);
	DDX_Control(pDX, BTN_CLOSEMONITOR, m_btnCloseO);
	DDX_Check(pDX, IDC_YUMIPAO, m_IDCYumipao);
}

BEGIN_MESSAGE_MAP(CPlantsVsZobiesModifierDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BTN_MODSUN, &CPlantsVsZobiesModifierDlg::OnBnClickedModsun)
	ON_BN_CLICKED(BTN_START, &CPlantsVsZobiesModifierDlg::OnBnClickedStart)
	ON_BN_CLICKED(BTN_REFRESH, &CPlantsVsZobiesModifierDlg::OnBnClickedReFresh)
	ON_BN_CLICKED(BTN_MODCOIN, &CPlantsVsZobiesModifierDlg::OnBnClickedModcoin)
	ON_BN_CLICKED(BTN_QUIT, &CPlantsVsZobiesModifierDlg::OnBnClickedQuit)
	ON_BN_CLICKED(BTN_MODSUN9, &CPlantsVsZobiesModifierDlg::OnBnClickedModsun9)
	ON_BN_CLICKED(BTN_MODCOIN9, &CPlantsVsZobiesModifierDlg::OnBnClickedModcoin9)
	ON_BN_CLICKED(BTN_OPENMONITOR, &CPlantsVsZobiesModifierDlg::OnBnClickedOpenmonitor)
	ON_BN_CLICKED(BTN_CLOSEMONITOR, &CPlantsVsZobiesModifierDlg::OnBnClickedClosemonitor)
	ON_BN_CLICKED(BTN_CLOSEMONITOR2, &CPlantsVsZobiesModifierDlg::OnBnClickedVip)
	ON_BN_CLICKED(IDC_INFINITCD, &CPlantsVsZobiesModifierDlg::OnBnClickedInfinitcd)
	ON_BN_CLICKED(IDC_BIGFLOWER, &CPlantsVsZobiesModifierDlg::OnBnClickedBigflower)
	ON_BN_CLICKED(IDC_IDCAUTOCOL, &CPlantsVsZobiesModifierDlg::OnBnClickedIdcautocol)
	ON_BN_CLICKED(IDC_ZOMBIESWEAK, &CPlantsVsZobiesModifierDlg::OnBnClickedZombiesweak)
	ON_BN_CLICKED(IDC_INFINTZOMBIES, &CPlantsVsZobiesModifierDlg::OnBnClickedInfintzombies)
	ON_NOTIFY(LVN_ITEMCHANGED, LIST_PLANT, &CPlantsVsZobiesModifierDlg::OnLvnItemchangedPlant)
	ON_BN_CLICKED(BTN_MODSELCD, &CPlantsVsZobiesModifierDlg::OnBnClickedModselcd)
	ON_BN_CLICKED(BTN_SELCARD, &CPlantsVsZobiesModifierDlg::OnBnClickedSelcard)
	ON_BN_CLICKED(BTN_PLANTSEL, &CPlantsVsZobiesModifierDlg::OnBnClickedPlantsel)
	ON_BN_CLICKED(BTN_MODSELPOS, &CPlantsVsZobiesModifierDlg::OnBnClickedModselpos)
	ON_BN_CLICKED(BTN_MODSELHP, &CPlantsVsZobiesModifierDlg::OnBnClickedModselhp)
	ON_BN_CLICKED(BTN_PLANT, &CPlantsVsZobiesModifierDlg::OnBnClickedPlant)
	ON_BN_CLICKED(IDC_BTPLANT, &CPlantsVsZobiesModifierDlg::OnBnClickedBeanPlant)
	ON_BN_CLICKED(IDC_HAPPYPLANT, &CPlantsVsZobiesModifierDlg::OnBnClickedRandomPlant)
	ON_BN_CLICKED(BTN_CLEARALL, &CPlantsVsZobiesModifierDlg::OnBnClickedClearall)
	ON_BN_CLICKED(IDC_FIREAI, &CPlantsVsZobiesModifierDlg::OnBnClickedFirePlant)
	ON_BN_CLICKED(IDC_ICEAI2, &CPlantsVsZobiesModifierDlg::OnBnClickedFlowerPlant)
	//ON_BN_CLICKED(BTN_SELPLANTBACK, &CPlantsVsZobiesModifierDlg::OnBnClickedSelplantback)
	//ON_BN_CLICKED(BTN_SELPLANTNEXT, &CPlantsVsZobiesModifierDlg::OnBnClickedSelplantnext)
	ON_BN_CLICKED(IDC_STRONGPAO, &CPlantsVsZobiesModifierDlg::OnBnClickedStrongpao)
	ON_BN_CLICKED(IDC_STRONGTOMOTO, &CPlantsVsZobiesModifierDlg::OnBnClickedStrongtomoto)
	ON_BN_CLICKED(IDC_STRONGATT, &CPlantsVsZobiesModifierDlg::OnBnClickedStrongatt)
	ON_BN_CLICKED(BTN_WIN, &CPlantsVsZobiesModifierDlg::OnBnClickedWin)
	ON_BN_CLICKED(BTN_KILLALL, &CPlantsVsZobiesModifierDlg::OnBnClickedKillall)
	ON_BN_CLICKED(BTN_ZOMALLOUT, &CPlantsVsZobiesModifierDlg::OnBnClickedZomallout)
	ON_BN_CLICKED(IDC_PERSPECTIVE, &CPlantsVsZobiesModifierDlg::OnBnClickedPerspective)
	ON_BN_CLICKED(IDC_ZOMBIESNOMOVE, &CPlantsVsZobiesModifierDlg::OnBnClickedZombiesnomove)
	ON_BN_CLICKED(IDC_YUMIPAO, &CPlantsVsZobiesModifierDlg::OnBnClickedYumipao)
END_MESSAGE_MAP()


// CPlantsVsZobiesModifierDlg 消息处理程序

BOOL CPlantsVsZobiesModifierDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	LoadSafeSkin();

	// TODO: 在此添加额外的初始化代码
	m_lstPlant.InsertColumn(0, _T("序号"), LVCFMT_LEFT, 51);
	m_lstPlant.InsertColumn(1, _T("植物类型"), LVCFMT_LEFT, 100);
	m_lstPlant.InsertColumn(2, _T("冷却时间"), LVCFMT_LEFT, 90);
	m_lstPlant.InsertColumn(3, _T("总冷却时间"), LVCFMT_LEFT, 110);
	m_lstPlant.InsertColumn(4, _T("使用次数"), LVCFMT_LEFT, 95);

	//设置风格
	m_lstPlant.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP);


	// TODO: 在此添加额外的初始化代码
	m_lstGrassPlant.InsertColumn(0, _T("序号"), LVCFMT_LEFT, 51);
	m_lstGrassPlant.InsertColumn(1, _T("植物类型"), LVCFMT_LEFT, 124);
	m_lstGrassPlant.InsertColumn(2, _T("生命值"), LVCFMT_LEFT, 70);
	m_lstGrassPlant.InsertColumn(3, _T("总生命值"), LVCFMT_LEFT, 90);
	m_lstGrassPlant.InsertColumn(4, _T("所在行"), LVCFMT_LEFT, 70);
	m_lstGrassPlant.InsertColumn(5, _T("所在列"), LVCFMT_LEFT, 70);

	//设置风格
	m_lstGrassPlant.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP);

	enableDebugPriv();//获取进程最高权限
	SetTimer(2, 100, NULL); // 选中行信息
	AddCmbPlant();

	//m_btnOpenM.ShowWindow(SW_SH); //修改控件状态为活跃状态

	m_btnOpenM.EnableWindow(FALSE);
	m_btnCloseO.EnableWindow(FALSE);
	m_lstGrassPlant.EnableWindow(FALSE);
	m_lstPlant.EnableWindow(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPlantsVsZobiesModifierDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPlantsVsZobiesModifierDlg::OnPaint()
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
HCURSOR CPlantsVsZobiesModifierDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CPlantsVsZobiesModifierDlg::OnBnClickedStart()
{
	hWndGame = ::FindWindow(NULL, "植物大战僵尸中文版");   // 窗口标题

	if (hWndGame == NULL)
	{
		AfxMessageBox("请先打开植物大战僵尸游戏", MB_OK, 0);
		return;
	}

	GetWindowThreadProcessId(hWndGame, &dwProcId);
	hProcGame = ::OpenProcess(
		PROCESS_ALL_ACCESS, //拥有所有的权限
		TRUE, //允许子类继承此句柄
		dwProcId //进程的id
	);

	if (hProcGame == NULL)
	{
		 
		CloseHandle(hProcGame);
		return;
	}

	OnBnClickedReFresh(); 
}


void CPlantsVsZobiesModifierDlg::OnBnClickedReFresh()
{
	CalSunMemAddress();//计算阳光基址
	CalCoinMemAddress();//计算金币基址
	CalCardSlotMem();//计算开槽基址
	CalPlant();//计算植物信息基址
	CalCheckPoint(); //计算关卡信息基址

	//每刷新一次就 初始化一次各种Map
	mapCardCd.erase(mapCardCd.begin(), mapCardCd.end());
	mapPlantHp.erase(mapPlantHp.begin(), mapPlantHp.end());
	mapPlantX.erase(mapPlantX.begin(), mapPlantX.end());
	mapPlantY.erase(mapPlantY.begin(), mapPlantY.end());

	DWORD dwSunNum = 0;

	//读取阳光信息
	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbSunMem,
		(LPVOID)&dwSunNum,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		NULL
	))
	{
		 
		return;
	}

	CString csSunNum;
	csSunNum.Format("%u", dwSunNum); //DWORD->CSTring

	SetDlgItemText(EDT_SUN, csSunNum); //设置阳光

	//读取金币信息
	DWORD dwCoinNum = 0;
	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbCoinMem,
		(LPVOID)&dwCoinNum,
		sizeof(DWORD),
		NULL
		))
		{
		 
		return;
		}

	CString csCoinNum;
	csCoinNum.Format("%u", dwCoinNum*10);

	SetDlgItemText(EDT_COIN, csCoinNum); //设置金币

	//读取当前关卡信息
	DWORD dwCheckPoint = 0;
	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbCheckPoint,
		(LPVOID)&dwCheckPoint,
		sizeof(DWORD),
		NULL
	))
	{
		 
		CloseHandle(hProcGame);
		return;
	}
	CString csCP1;
	CString csCP2;
	csCP1.Format("%d", dwCheckPoint / 10+1);
	csCP2.Format("%d", dwCheckPoint % 10);
	CString csCP = csCP1 + "-"+csCP2;

	SetDlgItemText(EDT_LEVEL, csCP); //设置金币

	//获取卡槽信息
	//清除上次的卡槽
	m_lstPlant.DeleteAllItems();
	//获取卡槽总数6A9EC0+768+144+24

	DWORD dwCardSum = 0;
	DWORD dmbCardSumNum = dmbCardSlotMem + 0x24;


	//获取卡槽总数
	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbCardSumNum,
		(LPVOID)&dwCardSum,
		sizeof(DWORD),        //缓冲区大小
		NULL
	))
	{
		 
		return;
	}

	CString csCardSum;
	csCardSum.Format("%u", dwCardSum);

	SetDlgItemText(EDT_CARDSUM, csCardSum); //
		//卡槽属性地址6A9EC0+768+144+28    下一个+50
	DWORD dmbCardAtt = dmbCardSlotMem + 0x28;

	//偏移地址
	DWORD dmbCardName = dmbCardAtt + 0x34;
	DWORD dmbCardCD = dmbCardAtt + 0x24;
	DWORD dmbCardSumCD = dmbCardAtt + 0x28;
	DWORD dmbCardUse= dmbCardAtt + 0x4C;

	for (int i = 0; i < atoi(csCardSum); i++)
	{
		CString csI;
		csI.Format("%d", i+1);
		m_lstPlant.InsertItem(i, csI);//序号

		DWORD dwCardName = 0;      
		DWORD dwCardCD = 0;
		DWORD dwCardSumCD = 0;
		DWORD dwCardUse = 0;

		//植物类型
		if (!ReadProcessMemory(
			hProcGame,
			(LPVOID)dmbCardName,
			(LPVOID)&dwCardName,
			sizeof(DWORD),        //缓冲区大小
			NULL
		))
		{
			 
			return;
		}

		m_lstPlant.SetItemText(i, ++nCardColdIdx,mapPlant[dwCardName]);
		
		//植物CD
		if (!ReadProcessMemory(
			hProcGame,
			(LPVOID)dmbCardCD,
			(LPVOID)&dwCardCD,
			sizeof(DWORD),        //缓冲区大小
			NULL
		))
		{
			 
			return;
		}
		//保存cd地址到mapCardCd
		mapCardCd.emplace(csI, dmbCardCD);

		CString csCardCD;
		csCardCD.Format("%u", dwCardCD);
		m_lstPlant.SetItemText(i, ++nCardColdIdx, csCardCD);


		//植物总CD
		if (!ReadProcessMemory(
			hProcGame,
			(LPVOID)dmbCardSumCD,
			(LPVOID)&dwCardSumCD,
			sizeof(DWORD),        //缓冲区大小
			NULL
		))
		{
			 
			return;
		}
		CString csCardSumCD;
		csCardSumCD.Format("%u", dwCardSumCD);
		m_lstPlant.SetItemText(i, ++nCardColdIdx, csCardSumCD);


		//植物使用次数
		if (!ReadProcessMemory(
			hProcGame,
			(LPVOID)dmbCardUse,
			(LPVOID)&dwCardUse,
			sizeof(DWORD),        //缓冲区大小
			NULL
		))
		{
			 
			return;
		}
		CString csCardUse;
		csCardUse.Format("%u", dwCardUse);
		m_lstPlant.SetItemText(i, ++nCardColdIdx, csCardUse);

		nCardColdIdx = 0;
		dmbCardName += 0x50;
		dmbCardCD += 0x50;
		dmbCardSumCD += 0x50;
		dmbCardUse += 0x50;
	}

	//-----------------------获取草地上植物属性------------------------

	//获取当前植物总数
	DWORD dwPlantSum = 0;
	DWORD dmbPlantSum = dmbPlant + 0xBC;

	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbPlantSum,
		(LPVOID)&dwPlantSum,
		sizeof(DWORD),        //缓冲区大小
		NULL
	))
	{
		 
		return;
	}

	CString csPlantSum;
	csPlantSum.Format("%u", dwPlantSum);

	SetDlgItemText(EDT_PREPLANTNUM, csPlantSum); 

	//获取最多放置的植物数
	DWORD dwPlantMaxSum = 0;
	DWORD dmbPlantMaxSum = dmbPlant + 0xB0;

	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbPlantMaxSum,
		(LPVOID)&dwPlantMaxSum,
		sizeof(DWORD),        //缓冲区大小
		NULL
	))
	{
		 
		return;
	}

	CString csPlantMaxSum;
	csPlantMaxSum.Format("%u", dwPlantMaxSum);

	SetDlgItemText(EDT_SUMPLANT, csPlantMaxSum);

	//打印类别草地上的植物信息

	m_lstGrassPlant.DeleteAllItems(); //初始化列表
	DWORD dmbPlantAtt =dmbPlant + 0xAC;

	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbPlantAtt,
		(LPVOID)&dmbPlantAtt,
		sizeof(DWORD),        //缓冲区大小
		NULL
	))
	{
		 
		return;
	}

	DWORD dmbPlantName = dmbPlantAtt + 0x24;
	DWORD dmbPlantHp = dmbPlantAtt + 0x40;
	DWORD dmbPlantSumHp = dmbPlantAtt + 0x44;
	DWORD dmbPlantX = dmbPlantAtt + 0x1C;
	DWORD dmbPlantY = dmbPlantAtt + 0x28;

	for (int i = 0; i < atoi(csPlantSum); i++)
	{
		CString csI;
		csI.Format("%d", i+1);
		m_lstGrassPlant.InsertItem(i, csI);//序号

		DWORD dwPlantName = 0;
		DWORD dwPlantHp = 0;
		DWORD dwPlantSumHp = 0;
		DWORD dwPlantX = 0;
		DWORD dwPlantY = 0;


		//植物类型
		if (!ReadProcessMemory(
			hProcGame,
			(LPVOID)dmbPlantName,
			(LPVOID)&dwPlantName,
			sizeof(DWORD),        //缓冲区大小
			NULL
		))
		{
			 
			return;
		}

		//保存植物Name地址到map
		mapPlantName.emplace(csI, dmbPlantName);
		m_lstGrassPlant.SetItemText(i, ++nCardColdIdx, mapPlant[dwPlantName]);

		//植物HP
		if (!ReadProcessMemory(
			hProcGame,
			(LPVOID)dmbPlantHp,
			(LPVOID)&dwPlantHp,
			sizeof(DWORD),        //缓冲区大小
			NULL
		))
		{
			 
			return;
		}

		//保存植物Hp地址到map
		mapPlantHp.emplace(csI, dmbPlantHp);

		CString csPlantHp;
		csPlantHp.Format("%u", dwPlantHp);
		m_lstGrassPlant.SetItemText(i, ++nCardColdIdx, csPlantHp);


		//植物总HP
		if (!ReadProcessMemory(
			hProcGame,
			(LPVOID)dmbPlantSumHp,
			(LPVOID)&dwPlantSumHp,
			sizeof(DWORD),        //缓冲区大小
			NULL
		))
		{
			 
			return;
		}
		CString csPlantSumHp;
		csPlantSumHp.Format("%u", dwPlantSumHp);
		m_lstGrassPlant.SetItemText(i, ++nCardColdIdx, csPlantSumHp);


		//植物行数
		if (!ReadProcessMemory(
			hProcGame,
			(LPVOID)dmbPlantX,
			(LPVOID)&dwPlantX,
			sizeof(DWORD),        //缓冲区大小
			NULL
		))
		{
			 
			return;
		}
		//保存植物行数地址到map
		mapPlantX.emplace(csI, dmbPlantX);

		CString csPlantX;
		csPlantX.Format("%u", dwPlantX);
		m_lstGrassPlant.SetItemText(i, ++nCardColdIdx, csPlantX);

		//植物列数
		if (!ReadProcessMemory(
			hProcGame,
			(LPVOID)dmbPlantY,
			(LPVOID)&dwPlantY,
			sizeof(DWORD),        //缓冲区大小
			NULL
		))
		{
			 
			return;
		}
		//保存植物列数地址到map
		mapPlantY.emplace(csI, dmbPlantY);

		CString csPlantY;
		csPlantY.Format("%u", dwPlantY);
		m_lstGrassPlant.SetItemText(i, ++nCardColdIdx, csPlantY);

		nCardColdIdx = 0;
		//下一个植物偏移
		dmbPlantName += 0x14C;
		dmbPlantHp += 0x14C;
		dmbPlantSumHp += 0x14C;
		dmbPlantX += 0x14C;
		dmbPlantY += 0x14C;
	}
}

void CPlantsVsZobiesModifierDlg::CalSunMemAddress()
{
	//计算阳光基址 [[6A9EC0]+768]+5560
	DWORD dmbTemp = 0;

	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbBase,  //写入的地址
		(LPVOID)&dmbTemp,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		&dwProcId
	))
	{
		 
		return;
	}

	dmbTemp += 0x768;
	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbTemp,  //写入的地址
		(LPVOID)&dmbTemp,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		&dwProcId
	))
	{
		 
		return;
	}
	dmbSunMem = dmbTemp + 0x5560;

 }

void CPlantsVsZobiesModifierDlg::CalCoinMemAddress()
{
	//[[[006A9EC0]+ 82c] + 28]

	DWORD dmbTemp = 0;

	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbBase,  //写入的地址
		(LPVOID)&dmbTemp,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		&dwProcId
	))
	{
		return;
	}

	dmbTemp += 0x82c;
	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbTemp,  //写入的地址
		(LPVOID)&dmbTemp,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		&dwProcId
	))
	{
		return;
	}

	dmbCoinMem = dmbTemp + 0x28;
}

void CPlantsVsZobiesModifierDlg::CalCardSlotMem()
{
	// 卡槽偏移	6A9EC0 + 768 + 144 

	DWORD dmbTemp = 0;
	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbBase,  //写入的地址
		(LPVOID)&dmbTemp,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		&dwProcId
	))
	{
		return;
	}

	dmbTemp += 0x768;
	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbTemp,  //写入的地址
		(LPVOID)&dmbTemp,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		&dwProcId
	))
	{
		return;
	}

	dmbTemp += 0x144;

if (!ReadProcessMemory(
	hProcGame,
	(LPVOID)dmbTemp,  //写入的地址
	(LPVOID)&dmbCardSlotMem,           //读取到的数据的缓冲区
	sizeof(DWORD),        //缓冲区大小
	&dwProcId
))
{
	return;
}

}

void CPlantsVsZobiesModifierDlg::CalPlant()
{
	DWORD dmbTemp = 0;

	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbBase,  //写入的地址
		(LPVOID)&dmbTemp,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		&dwProcId
	))
	{
		return;
	}

	dmbTemp += 0x768;
	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbTemp,  //写入的地址
		(LPVOID)&dmbPlant,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		&dwProcId
	))
	{
		return;
	}

}

void CPlantsVsZobiesModifierDlg::CalCheckPoint()
{
	DWORD dmbTemp = 0;

	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbBase,  //写入的地址
		(LPVOID)&dmbTemp,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		&dwProcId
	))
	{
		return;
	}

	dmbTemp += 0x768;
	if (!ReadProcessMemory(
		hProcGame,
		(LPVOID)dmbTemp,  //写入的地址
		(LPVOID)&dmbTemp,           //读取到的数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		&dwProcId
	))
	{
		return;
	}
	dmbCheckPoint = dmbTemp+0x5550;
}


void CPlantsVsZobiesModifierDlg::OnBnClickedModsun()
{
	CString csSunNum = 0;
	GetDlgItemText(EDT_SUN, csSunNum);

	DWORD btCode = _tcstoul(csSunNum, NULL, 10);

	BOOL bRet = WriteProcessMemory(
		hProcGame,
		(LPVOID)dmbSunMem,  //写入的地址
		&btCode,           //写入数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		return;
	}

}


void CPlantsVsZobiesModifierDlg::OnBnClickedModcoin()
{
	CString csCoinNum = 0;
	GetDlgItemText(EDT_COIN, csCoinNum);

	DWORD btCode = _tcstoul(csCoinNum, NULL, 10);
	btCode /= 10;

	BOOL bRet = WriteProcessMemory(
		hProcGame,
		(LPVOID)dmbCoinMem,  //写入的地址
		&btCode,           //写入数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		return;
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedQuit()
{
	KillTimer(1);
	KillTimer(2);

	if (!hProcGame)
	{
	CloseHandle(hProcGame);
	}

	ExitProcess(0);
}


void CPlantsVsZobiesModifierDlg::OnBnClickedModsun9()
{
	DWORD btCode = 9999;

	BOOL bRet = WriteProcessMemory(
		hProcGame,
		(LPVOID)dmbSunMem,  //写入的地址
		&btCode,           //写入数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		return;
	}
	SetDlgItemText(EDT_SUN, "9999");
}

void CPlantsVsZobiesModifierDlg::OnBnClickedModcoin9()
{
	DWORD btCode = 9999;

	BOOL bRet = WriteProcessMemory(
		hProcGame,
		(LPVOID)dmbCoinMem,  //写入的地址
		&btCode,           //写入数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		return;
	}
	SetDlgItemText(EDT_COIN, "99990");
}


void CPlantsVsZobiesModifierDlg::OnBnClickedOpenmonitor()
{
	SetTimer(1,100,NULL);//定时器一，
}


void CPlantsVsZobiesModifierDlg::OnBnClickedClosemonitor()
{
	KillTimer(1);
}


void CPlantsVsZobiesModifierDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent) {
	case 1:
	{
		OnBnClickedReFresh();
		break;
	}
	case 2:
	{
		OnBnClickedSelcard();
		OnBnClickedPlantsel();
		break;
	}
	case 3:
	{
		for (int i = 0; i < 6; i++)
		{
			PutPlantPareame parame;
			parame.u_plantid = 20;
			parame.u_x = i;
			parame.u_y = 5;
			InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}
	}
	break;
	}
	CDialogEx::OnTimer(nIDEvent);
}



void CPlantsVsZobiesModifierDlg::OnBnClickedVip()
{
	CVIP VipDlg;
	VipDlg.DoModal();
	isVIP=VipDlg.GetReturn();

	Invalidate(FALSE);

	if (isVIP == 1)
	{
		m_btnOpenM.EnableWindow(TRUE);
		m_btnCloseO.EnableWindow(TRUE);
		m_lstGrassPlant.EnableWindow(TRUE);
		m_lstPlant.EnableWindow(TRUE);
	}

}


void CPlantsVsZobiesModifierDlg::OnBnClickedInfinitcd()
{
	UpdateData(TRUE);

	UCHAR buf[2] = { 0 };
	 //禁用CD
	if (m_idcInfiniteCD && isVIP)
	{
		//nop90  nop90
		buf[0] = 0x90;
		buf[1] = 0x90;
		AfxMessageBox("尊敬的VIP用户 开启无限冷却成功！");
	 }
	else if(m_idcInfiniteCD && isVIP==0)
	{
		m_idcInfiniteCD = FALSE;
		AfxMessageBox("开启无限冷却失败,充值VIP！");
		return;
	}
	else
	{
		// 启用
		//7E 14
		buf[0] = 0x7E;
		buf[1] = 0x14; 
		AfxMessageBox("关闭无限冷却");
	}

	BOOL bRet = ::WriteProcessMemory(
		hProcGame,
		(LPVOID)0x487296,  //写入的地址
		buf,           
		sizeof(buf),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{ 
		return;
	}

}


void CPlantsVsZobiesModifierDlg::OnBnClickedIdcautocol()
{
	UpdateData(TRUE);

	UCHAR buf[2] = { 0 };
	//禁用CD
	if (m_AutoCol && isVIP)
	{
		//nop90  nop90
		buf[0] = 0x90;
		buf[1] = 0x90;
		AfxMessageBox("尊敬的VIP用户 开启自动收集阳光！");
	}
	else if (m_AutoCol && isVIP == 0)
	{
		m_AutoCol = FALSE;
		AfxMessageBox("开启自动收集失败,充值VIP！");
		return;
	}
	else
	{
		// 关闭	
		buf[0] = 0x75;
		buf[1] = 0x3E;
		AfxMessageBox("关闭自动收集阳光");
	}

	BOOL bRet = ::WriteProcessMemory(
		hProcGame,
		(LPVOID)0x430AD0,  //写入的地址
		buf,
		sizeof(buf),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{		 
		return;
	}
}

void CPlantsVsZobiesModifierDlg::OnBnClickedPerspective()
{
	if (isVIP == 1)
	{
		AfxMessageBox("请更新后使用");
	}
	else
	{
		AfxMessageBox("请先获得VIP才能使用以下功能!");
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedZombiesnomove()
{
	if (isVIP == 1)
	{
		AfxMessageBox("请更新后使用");
	}
	else
	{
		AfxMessageBox("请先获得VIP才能使用以下功能!");
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedZombiesweak()
{
	if (isVIP == 1)
	{
		AfxMessageBox("请更新后使用");
	}
	else
	{
		AfxMessageBox("请先获得VIP才能使用以下功能!");
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedInfintzombies()
{
	if (isVIP == 1)
	{
		AfxMessageBox("请更新后使用");
	}
	else
	{
		AfxMessageBox("请先获得VIP才能使用以下功能!");
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedWin()
{
	if (isVIP == 1)
	{
		AfxMessageBox("请更新后使用");
	}
	else
	{
		AfxMessageBox("请先获得VIP才能使用以下功能!");
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedKillall()
{
	if (isVIP == 1)
	{
		AfxMessageBox("请更新后使用");
	}
	else
	{
		AfxMessageBox("请先获得VIP才能使用以下功能!");
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedZomallout()
{
	if (isVIP == 1)
	{
		UCHAR buf1[7] = { 0 };
		// 开启无限僵尸
		buf1[0] = 0xE9;
		buf1[1] = 0xFA;
		buf1[2] = 0xDA;
		buf1[3] = 0x2C;
		buf1[4] = 0x00;
		buf1[5] = 0x66;
		buf1[6] = 0x90;

		BOOL bRet = ::WriteProcessMemory(
			hProcGame,
			(LPVOID)0x413E45,  //写入的地址
			buf1,
			sizeof(buf1),        //缓冲区大小
			NULL);
		
		UCHAR buf2[22] = { 0 };
		buf2[0] = 0xC7,buf2[1] = 0x87,buf2[2] = 0x9C,buf2[3] = 0x55;
		buf2[4] = 0x00,buf2[5] = 0x00,buf2[6] = 0x01,buf2[7] = 0x00;
		buf2[8] = 0x00,buf2[9] = 0x00,buf2[10] = 0x83,buf2[11] = 0x87, 
		buf2[12] = 0x9C, buf2[13] = 0x55, buf2[14] = 0x00,buf2[15] = 0x00,
		buf2[16] = 0xFF, buf2[17] = 0xE9, buf2[18] = 0xF2,buf2[19] = 0x24,
		buf2[20] = 0xD3, buf2[21] = 0xFF;

		bRet = ::WriteProcessMemory(
			hProcGame,
			(LPVOID)0x6E1944,  //写入的地址
			buf2,
			sizeof(buf2),        //缓冲区大小
			NULL);

		if (bRet)
		{
			AfxMessageBox("尊敬的VIP用户 开启一波出僵尸！");
		}
		else
		{
			return;
		}
		//延时
		Sleep(3000);

		// 关闭	

		UCHAR buf3[7] = { 0 };
		buf3[0] = 0x83;
		buf3[1] = 0x87;
		buf3[2] = 0x9c;
		buf3[3] = 0x55;
		buf3[4] = 0x00;
		buf3[5] = 0x00;
		buf3[6] = 0xff;

		bRet = ::WriteProcessMemory(
			hProcGame,
			(LPVOID)0x413E45,  //写入的地址
			buf3,
			sizeof(buf3),        //缓冲区大小
			NULL);

		UCHAR buf4[22] = { 0 };

		bRet = ::WriteProcessMemory(
			hProcGame,
			(LPVOID)0x6E1944,  //写入的地址
			buf4,
			sizeof(buf4),        //缓冲区大小
			NULL);
	}
	else
	{
		AfxMessageBox("请先获得VIP才能使用以下功能!");
		return;
	}
}


void CPlantsVsZobiesModifierDlg::ClearPlantAll()
{
	//清除
	UCHAR buf[2] = { 0 };
	//nop90  nop90
	buf[0] = 0x90;
	buf[1] = 0x90;

	BOOL bRet = ::WriteProcessMemory(
		hProcGame,
		(LPVOID)0x41BB2E,  //写入的地址
		buf,
		sizeof(buf),        //缓冲区大小
		NULL
	);

	if (!bRet)
	{		 
		return;
	}
}

void CPlantsVsZobiesModifierDlg::RePlantAll()
{
	//还原清除
	UCHAR buf2[2] = { 0 };
	//75 5f
	buf2[0] = 0x74;
	buf2[1] = 0xB0;

	BOOL bRet = ::WriteProcessMemory(
		hProcGame,
		(LPVOID)0x41BB2E,  //写入的地址
		buf2,
		sizeof(buf2),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		return;
	}

}



void CPlantsVsZobiesModifierDlg::OnBnClickedClearall()
{
	ClearPlantAll();
	Sleep(100);
	RePlantAll();

}

void CPlantsVsZobiesModifierDlg::OnLvnItemchangedPlant(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CPlantsVsZobiesModifierDlg::OnBnClickedModselcd()
{
	CString csPlantId;
	GetDlgItemText(EDT_CARDSELID,csPlantId );

	CString csPlantCd;
	GetDlgItemText(EDT_MODSELCD, csPlantCd);

	DWORD btCode = _tcstoul(csPlantCd, NULL, 10);
	BOOL bRet = WriteProcessMemory(
		hProcGame,
		(LPVOID)mapCardCd[csPlantId],  //写入的地址
		&btCode,           //写入数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		return;
	}

	SetDlgItemText(EDT_MODSELCD, "");

}


void CPlantsVsZobiesModifierDlg::OnBnClickedSelcard()
{
	//选中卡片显示卡槽编号
	nPlantCardISel = m_lstPlant.GetSelectionMark();
	CString cscardId;
	cscardId.Format("%d", nPlantCardISel+1);
	if (nPlantCardISel != -1)
	{
		SetDlgItemText(EDT_CARDSELID, cscardId);
	}

}


void CPlantsVsZobiesModifierDlg::OnBnClickedPlantsel()
{
	//选中植物选中植物编号
	nPlantColdIdx = m_lstGrassPlant.GetSelectionMark();
	CString csPlantId;
	csPlantId.Format("%d", nPlantColdIdx+1);
	if (nPlantColdIdx != -1)
	{
		SetDlgItemText(EDT_PLANTSELID, csPlantId);

		//获取选中HP、信息到EDT
		CString csHp =m_lstGrassPlant.GetItemText(nPlantColdIdx, 2);
		SetDlgItemText(EDT_OLDHP, csHp);

		CString csX = m_lstGrassPlant.GetItemText(nPlantColdIdx, 4);
		CString csY = m_lstGrassPlant.GetItemText(nPlantColdIdx, 5);
		SetDlgItemText(EDT_OLDX, csX);
		SetDlgItemText(EDT_OLDY, csY);
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedModselpos()
{
	CString csPlantId;
	GetDlgItemText(EDT_PLANTSELID, csPlantId);

	CString csPlantX;
	GetDlgItemText(EDT_MODSELX, csPlantX);

	CString csPlantY;
	GetDlgItemText(EDT_MODSELHP, csPlantY);

	DWORD btCodeX = _tcstoul(csPlantY, NULL, 10);
	DWORD btCodeY = _tcstoul(csPlantX, NULL, 10);

	if (btCodeX > 5 || btCodeY > 8)
	{
		AfxMessageBox("您输入的位置必须在(0,0)-(5,8)");
		return;
	}

	BOOL bRet = WriteProcessMemory(
		hProcGame,
		(LPVOID)mapPlantX[csPlantId],  //写入的地址
		&btCodeX,           //写入数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		return;
	}


	//Y
	BOOL bRet2 = WriteProcessMemory(
		hProcGame,
		(LPVOID)mapPlantY[csPlantId],  //写入的地址
		&btCodeY,           //写入数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		NULL
	);
	if (!bRet2)
	{
		 
		return;
	}

	SetDlgItemText(EDT_MODSELX,"");
	SetDlgItemText(EDT_MODSELY, "");
}


void CPlantsVsZobiesModifierDlg::OnBnClickedModselhp()
{
	CString csPlantId;
	GetDlgItemText(EDT_PLANTSELID, csPlantId);

	CString csPlantHp;
	GetDlgItemText(EDT_MODSELHP, csPlantHp);

	//bug
	DWORD btCode = _tcstoul(csPlantHp, NULL, 10);
	BOOL bRet = WriteProcessMemory(
		hProcGame,
		(LPVOID)mapPlantHp[csPlantId],  //写入的地址
		&btCode,           //写入数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		CloseHandle(hProcGame);
		return;
	}

	SetDlgItemText(EDT_MODSELHP, "");
}

	/*
	//控制堆栈平衡
__declspec(naked) void CallPlant()
{
		__asm
		{
			pushad
			push -1
			push 2 
			mov eax,4
			push 4  
			mov ebx, ds: [0x6A9EC0]
			mov ebx, ds: [ebx+0x768]
			push ebx
			mov edx, 0x40D120
			call edx
			popad
			ret
		}
}


		//在目标进程分配空间
		PVOID ThreadMemInject = VirtualAllocEx(hProcGame, NULL, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		//在分配的空间写入代码
		DWORD dwWrite = 0;

		BOOL bRet=WriteProcessMemory(hProcGame, ThreadMemInject, CallPlant, 4096, &dwWrite);
		//创建远程线程
		CreateRemoteThread(hProcGame, NULL, NULL, (LPTHREAD_START_ROUTINE)ThreadMemInject, NULL, NULL, NULL);
	
*/


//未公开API提权
bool CPlantsVsZobiesModifierDlg::enableDebugPriv()
{

	HANDLE hToken;
	LUID sedebugnameValue;
	TOKEN_PRIVILEGES tkp;

	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)){
			return false;
		}
	if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &sedebugnameValue))
	{
		CloseHandle(hToken);
		return false;
	}
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = sedebugnameValue;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(tkp), NULL, NULL))
	{
		CloseHandle(hToken);
		return false;
	}

	return TRUE;
}


void CPlantsVsZobiesModifierDlg::OnBnClickedPlant()
{
	
	CString strPlantName;
	m_cmbzbPlant.GetWindowText(strPlantName);

		DWORD dwPlantId = 0;

		// value->key
		for (std::map<DWORD, CString>::iterator it =mapPlant.begin(); it != mapPlant.end(); it++)
		{
			if (it->second == strPlantName)
			{
				dwPlantId = it->first;
				break;
			}
		}
		//获得下x，y 坐标
		CString csPlantX;
		CString csPlantY;
		GetDlgItemText(EDT_PLANTX, csPlantX);
		GetDlgItemText(EDT_PLANTY, csPlantY);

		//远程参数调用
		PutPlantPareame parame;
		parame.u_plantid = (int)dwPlantId;
		parame.u_x = atoi(csPlantX);
		parame.u_y = atoi(csPlantY);

		InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));

	return;
}

void CPlantsVsZobiesModifierDlg::AddCmbPlant()
{
	for (DWORD i = 0; i <48; i++)
	{
		m_cmbzbPlant.AddString(mapPlant[i]);
	}
}


BOOL CPlantsVsZobiesModifierDlg::InjectRemotoFunc(DWORD dwPid, LPVOID mFunc,
	LPVOID pRemoteParam, DWORD dwParameSize, DWORD dwWaitTime)
{
	
	LPVOID ThreadAdd = NULL;
	DWORD lpNumberofBytes = 0;
	BOOL bRet = FALSE;
	BOOL bSucc = FALSE ; //是否注入成功
	LPVOID ParamAdd = NULL; 
	HANDLE hThread = NULL;
	DWORD dwWait = 0; //等待参数

	do
	{
		//在目标进程分配空间
		ThreadAdd= VirtualAllocEx(hProcGame, NULL, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (ThreadAdd == NULL)
		{
			break;
		}

		//在分配的空间写入函数
		bRet = WriteProcessMemory(hProcGame, ThreadAdd, mFunc, 4096, &lpNumberofBytes);
		if (bRet== NULL)
		{
			break;
		}
	
		if (dwParameSize != 0)
		{
			//装载函数所需分配空间
			ParamAdd = VirtualAllocEx(hProcGame, NULL, dwParameSize, MEM_COMMIT, PAGE_READWRITE);
			if (ThreadAdd == NULL)
			{
				break;
			}
			//写入参数
			bRet = WriteProcessMemory(hProcGame, ParamAdd, pRemoteParam, dwParameSize, &lpNumberofBytes);
			if (bRet == NULL)
			{
				break;
			}
		}
		//创建远程线程
		hThread=CreateRemoteThread(hProcGame, NULL, NULL, (LPTHREAD_START_ROUTINE)ThreadAdd,ParamAdd, NULL, &lpNumberofBytes);
		if (hThread == NULL)
		{
			break;
		}
		bSucc = TRUE;

	} while (0);

	//等待线程执行结束
	if (bSucc)
	{
		dwWait = WaitForSingleObject(hThread, dwWaitTime);
		if (dwWait == WAIT_TIMEOUT)   //超时放弃释放资源
		{
			goto end;
		}
	}
		//释放目标进程中分配的资源
		if (bSucc && ThreadAdd && hProcGame)
		{
			VirtualFreeEx(hProcGame, ThreadAdd, 0, MEM_RELEASE);
		}
		if (bSucc && (dwParameSize!=0) && pRemoteParam && hProcGame)
		{
			VirtualFreeEx(hProcGame, pRemoteParam, 0, MEM_RELEASE);
		}

	end:
		if (hThread != NULL)
		{
			CloseHandle(hThread);
		}

		return bSucc;
}

//这里要用release版 !!dbug版一直崩溃
DWORD __stdcall CPlantsVsZobiesModifierDlg::PutPlants(LPVOID lpThreadParameter)
{
	PPutPlantPareame pParame = (PPutPlantPareame)lpThreadParameter;
	UINT u_x = pParame->u_x;
	UINT u_y = pParame->u_y;
	UINT u_plantid = pParame->u_plantid;

	__asm
	{
		pushad
		push		-1
		push		u_plantid
		mov		eax, u_x
		push		u_y
		mov ebx, ds:[0x6A9EC0]
		mov ebx, ds:[ebx + 0x768]
		push ebx
		mov edx, 0x40D120
		call edx
		popad
	}

	return 0;
}


void CPlantsVsZobiesModifierDlg::OnBnClickedBeanPlant()
{
	AfxMessageBox("豌豆模式，都是豌豆豌豆豌豆");

	OnBnClickedClearall();
	UpdateData(TRUE);

	if (m_btAI)
	{
		for (int i = 0; i < 5; i++)
		{
			PutPlantPareame parame;
			parame.u_plantid = 0;
			parame.u_x = i;
			parame.u_y = 0;
			InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}

		for (int i = 0; i < 5; i++)
		{
				PutPlantPareame parame;
				parame.u_plantid = 7;
				parame.u_x = i;
				parame.u_y = 1;
				InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}
		for (int i = 0; i < 5; i++)
		{
			PutPlantPareame parame;
			parame.u_plantid = 18;
			parame.u_x = i;
			parame.u_y = 2;
			InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}
		for (int i = 0; i < 5; i++)
		{
			PutPlantPareame parame;
			parame.u_plantid = 40;
			parame.u_x = i;
			parame.u_y = 3;
			InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}
		for (int i = 0; i < 5; i++)
		{
			PutPlantPareame parame;

			parame.u_plantid = 28;
			parame.u_x = i;
			parame.u_y = 4;
			InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}
		for (int i = 0; i < 5; i++)
		{
			PutPlantPareame parame;
			parame.u_plantid = 29;
			parame.u_x = i;
			parame.u_y = 5;
			InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}
		for (int i = 0; i < 5; i++)
		{
			PutPlantPareame parame;
			parame.u_plantid = 22;
			parame.u_x = i;
			parame.u_y = 6;
			InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}
		for (int i = 0; i < 5; i++)
		{
			PutPlantPareame parame;
			parame.u_plantid = 23;
			parame.u_x = i;
			parame.u_y = 7;
			InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}
		for (int i = 0; i < 5; i++)
		{
			PutPlantPareame parame;
			parame.u_plantid = 21;
			parame.u_x = i;
			parame.u_y = 8;
			InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}
	}
	else
	{
		//清除掉植物
		m_BigFlower = 0;
		OnBnClickedClearall();
	}

}



void CPlantsVsZobiesModifierDlg::OnBnClickedRandomPlant()
{
	AfxMessageBox("快乐模式，随机放置各种植物");

	OnBnClickedClearall();
	UpdateData(TRUE);
	if (m_HappyAI)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				PutPlantPareame parame;
				srand(GetTickCount());
				int n = rand() / 2+1;
				n= n%49;
				while (1)
				{
					if ( n==0 || n == 2 || n == 3 || n ==4 ||n==5||  n==6||n==7||n==16|| n==17|| n==20
						|| n == 21 || n == 22 || n == 23 || n == 26 || n == 27 || n == 28 || n == 29 ||n==40
						)
					{
						break;
					}
					Sleep(50);
					n = rand() % 49;
				}
				parame.u_plantid = n;
				parame.u_x = i;
				parame.u_y = j;
				Sleep(10);
				InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
			}
		}

	}
	else
	{
		//清除掉植物
		m_BigFlower = 0;
		OnBnClickedClearall();
	}
}

void CPlantsVsZobiesModifierDlg::OnBnClickedFirePlant()
{
	OnBnClickedClearall();
	UpdateData(TRUE);

	if (m_idcFireAi)
	{
		AfxMessageBox("开启AI超级火焰辣椒模式！");
		SetTimer(3, 2000, NULL);//定时器一，
	}
	else
	{
		KillTimer(3);
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedFlowerPlant()
{
	OnBnClickedClearall();
	UpdateData(TRUE);

	if (m_idcBigFlower)
	{
		AfxMessageBox("开启AI超级食人花模式！");

		//食人花冷却无CD
		UCHAR buf[2] = { 0 };
			buf[0] = 0x90;
			buf[1] = 0x90;

		 ::WriteProcessMemory(
			hProcGame,
			(LPVOID)0x461565,  //写入的地址
			buf,
			sizeof(buf),        //缓冲区大小
			NULL
		);

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				PutPlantPareame parame;
				parame.u_plantid = 6;
				parame.u_x = i;
				parame.u_y = j;
				InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
			}
		}
		for (int i = 0; i < 5; i++)
		{
			PutPlantPareame parame;
			parame.u_plantid = 23;
			parame.u_x = i;
			parame.u_y = 8;
			InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
		}
		m_BigFlower = 1;
	}
	else
	{
		//清除掉植物
		m_BigFlower = 0;
		OnBnClickedClearall();
	}

	UpdateData(FALSE);
}


void CPlantsVsZobiesModifierDlg::OnBnClickedYumipao()
{
	OnBnClickedClearall();
	UpdateData(TRUE);

	if (m_IDCYumipao)
	{
		AfxMessageBox("开启赫鲁晓夫之力！");



		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j+=2)
			{
				PutPlantPareame parame;
				parame.u_plantid = 47;
				parame.u_x = i;
				parame.u_y = j;
				InjectRemotoFunc(dwProcId, PutPlants, &parame, sizeof(parame));
			}
		}

	}
	else
	{
		//清除掉植物
		m_BigFlower = 0;
		OnBnClickedClearall();
	}

	UpdateData(FALSE);

}

/*
void CPlantsVsZobiesModifierDlg::OnBnClickedSelplantback()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CPlantsVsZobiesModifierDlg::OnBnClickedSelplantnext()
{
	CString csPlantId;
	GetDlgItemText(EDT_PLANTSELID, csPlantId);

	//获取植物名称
	CString csPlantName = m_lstGrassPlant.GetItemText(atoi(csPlantId)-1,1);
	//转换位植物编号到dwPlantId
	DWORD dwPlantId = 0;

	// value->key
	for (std::map<DWORD, CString>::iterator it = mapPlant.begin(); it != mapPlant.end(); it++)
	{
		if (it->second == csPlantName)
		{
			dwPlantId = it->first;
			break;
		}
	}
	//植物编号+1
	dwPlantId++;

	BOOL bRet = WriteProcessMemory(
		hProcGame,
		(LPVOID)mapPlantName[csPlantId],  //写入的地址
		&dwPlantId,           //写入数据的缓冲区
		sizeof(DWORD),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		CloseHandle(hProcGame);
		return;
	}
}
*/

void CPlantsVsZobiesModifierDlg::OnBnClickedBigflower()
{
	UpdateData(TRUE);

	UCHAR buf[2] = { 0 };
	//禁用CD
	if (m_BigFlower)
	{
		//nop90  nop90
		buf[0] = 0x90;
		buf[1] = 0x90;
		AfxMessageBox("超级食人花开启成功！");
	}
	else
	{
		// 启用
		//75 5f
		buf[0] = 0x75;
		buf[1] = 0x5f;
		AfxMessageBox("超级食人花开启失败");
	}

	BOOL bRet = ::WriteProcessMemory(
		hProcGame,
		(LPVOID)0x461565,  //写入的地址
		buf,
		sizeof(buf),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		return;
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedStrongpao()
{
	UpdateData(TRUE);

	UCHAR buf[6] = { 0 };
	//禁用CD
	if (m_StrongPao)
	{
		//nop90  nop90
		buf[0] = 0x90;
		buf[1] = 0x90;
		buf[2] = 0x90;
		buf[3] = 0x90;
		buf[4] = 0x90;
		buf[5] = 0x90;
		AfxMessageBox("超级加农炮开启成功！");
	}
	else
	{
		buf[0] = 0x0F;
		buf[1] = 0x85;
		buf[2] = 0x9C;
		buf[3] = 0x01;
		buf[4] = 0x00;
		buf[5] = 0x00;
		AfxMessageBox("超级加农炮关闭");
	}

	BOOL bRet = ::WriteProcessMemory(
		hProcGame,
		(LPVOID)0x46103A,  //写入的地址
		buf,
		sizeof(buf),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		return;
	}
}


void CPlantsVsZobiesModifierDlg::OnBnClickedStrongtomoto()
{
	UpdateData(TRUE);

	UCHAR buf[6] = { 0 };
	//禁用CD
	if (m_StrongTomato)
	{
		//nop90  nop90
		buf[0] = 0x90;
		buf[1] = 0x90;
		buf[2] = 0x90;
		buf[3] = 0x90;
		buf[4] = 0x90;
		buf[5] = 0x90;
		AfxMessageBox("超级土豆地雷已开启！");
	}
	else
	{
		// 启用
		//75 5f
		buf[0] = 0x0F;
		buf[1] = 0x85;
		buf[2] = 0xFA;
		buf[3] = 0x01;
		buf[4] = 0x00;
		buf[5] = 0x00;

		AfxMessageBox("超级土豆地雷已关闭");
	}

	BOOL bRet = ::WriteProcessMemory(
		hProcGame,
		(LPVOID)0x45FE53,  //写入的地址
		buf,
		sizeof(buf),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		return;
	}
}



void CPlantsVsZobiesModifierDlg::OnBnClickedStrongatt()
{
	UpdateData(TRUE);

	UCHAR buf[6] = { 0 };
	//禁用CD
	if (m_StrongPlantAtt)
	{
		//nop90  nop90
		buf[0] = 0x90;
		buf[1] = 0x90;
		buf[2] = 0x90;
		buf[3] = 0x90;
		buf[4] = 0x90;
		buf[5] = 0x90;
		AfxMessageBox("植物已强化！");
	}
	else
	{
		// 启用
		//75 5f
		buf[0] = 0x0f;
		buf[1] = 0x85;
		buf[2] = 0x98;
		buf[3] = 0xFE;
		buf[4] = 0xFF;
		buf[5] = 0xFF;
		AfxMessageBox("关闭植物强化");
	}

	BOOL bRet = ::WriteProcessMemory(
		hProcGame,
		(LPVOID)0x464A96,  //写入的地址
		buf,
		sizeof(buf),        //缓冲区大小
		NULL
	);
	if (!bRet)
	{
		 
		return;
	}
}


void CPlantsVsZobiesModifierDlg::LoadSafeSkin()
{

	HMODULE hModule = LoadLibrary("MySafeSkin.dll");
	if (hModule)
	{
		typedef  int  (WINAPI* pMySafeSkin)(void);
		pMySafeSkin MySafeSkin;
		MySafeSkin = (pMySafeSkin)GetProcAddress(hModule, "MySafeSkin");
		MySafeSkin();
	}
}



