
// PlantsVsZobiesModifierDlg.h: 头文件
//

#pragma once
#include<map>
#include"CVIP.h"
using namespace std;

// CPlantsVsZobiesModifierDlg 对话框
class CPlantsVsZobiesModifierDlg : public CDialogEx
{
// 构造
public:
	CPlantsVsZobiesModifierDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLANTSVSZOBIESMODIFIER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


private:
	HWND hWndGame = NULL;
	DWORD dwProcId = 0;
	HANDLE hProcGame = NULL;
	DWORD dmbBase = 0x6A9EC0;
	DWORD dmbSunMem =0;
	DWORD dmbCoinMem = 0;
	DWORD dmbCardSlotMem = 0;
	DWORD dmbPlant = 0;
	DWORD dmbCheckPoint = 0;

private:
	int nPlantCardISel = 0;
	int nPlantSel = 0;
	int nCardColdIdx = 0;
	int nPlantColdIdx = 0;
	int isVIP = 0;
	int CurrentScence = 0; //当前场景 1/2/3/4
public:
	//存放种植植物信息的结构体
	typedef struct  _PutPlantPareame
	{
		UINT u_x;
		UINT u_y;
		UINT u_plantid;
	}PutPlantPareame, *PPutPlantPareame;

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
	void CalSunMemAddress(); //计算阳光偏移
	void CalCoinMemAddress();//金币偏移
	void CalCardSlotMem();//卡槽偏移
	void CalPlant(); //草地植物偏移
	void CalCheckPoint(); //计算关卡偏移
	bool enableDebugPriv(); //提权
	void AddCmbPlant(); //添加植物信息到cmb控件
	void ClearPlantAll(); //清除所有植物
	void	RePlantAll(); //还原清除
	void 	LoadSafeSkin();// 加载皮肤

	//带参注入
	BOOL InjectRemotoFunc(DWORD dwPid, LPVOID mFunc, LPVOID pRemoteParam,DWORD dwParameSize,DWORD dwWaitTime=INFINITE);
	static DWORD __stdcall  PutPlants(LPVOID lpThreadParameter); //注入调用种植植物call的静态函数


public:
	//cs序号-卡槽植物CD地址对照表
	map<CString, DWORD>mapCardCd;

	//cs序号-草地植物种类地址地址对照表   
	map<CString, DWORD>mapPlantName;

	//cs序号-草地植物血量地址对照表
	map<CString, DWORD>mapPlantHp;

	//cs序号-草地植物X地址对照表
	map<CString, DWORD>mapPlantX;

	//cs序号-草地植物Y地址对照表
	map<CString, DWORD>mapPlantY;

	// 序号-植物 对应表
	map<DWORD, CString>mapPlant = {
		{0,"豌豆射手"},
		{1,"太阳花"},
		{2,"樱桃炸弹"},
		{3,"小型坚果"},
		{4,"土豆地雷"},
		{5,"寒冰射手"},
		{6,"食人魔花"},
		{7,"双发射手"},
		{8,"烟雾蘑菇"},
		{9,"阳光蘑菇"},
		{10,"烟喷喷菇"},
		{11,"噬碑者"},
		{12,"胆小蘑菇"},
		{13,"催眠蘑菇"},
		{14,"冰冻蘑菇"},
		{15,"末日蘑菇"},
		{16,"睡莲"},
		{17,"倭瓜"},
		{18,"三联豌豆"},
		{19,"缠绕海带"},
		{20,"火焰辣椒"},
		{21,"地刺"},
		{22,"火炬"},
		{23,"巨型坚果"},
		{24,"海蘑菇"},
		{25,"灯笼草"},
		{26,"仙人掌"},
		{27,"三叶草"},
		{28,"双头豌豆"},
		{29,"五角星"},
		{30,"南瓜墙"},
		{31,"磁铁蘑菇"},
		{32,"卷心菜投手"},
		{33,"花盆"},
		{34,"玉米投手"},
		{35,"咖啡豆"},
		{36,"大蒜"},
		{37,"莴苣"},
		{38,"金盏花"},
		{39,"西瓜投手"},
		{40,"豌豆加农炮"},
		{41,"双子太阳花"},
		{42,"忧郁蘑菇"},
		{43,"香蒲"},
		{44,"冰西瓜"},
		{45,"吸金磁"},
		{46,"尖刺石"},
		{47,"玉米加农炮"},
		{48,"模仿者"},
		{49,"反向豌豆"},
	};	 
	CComboBox m_cmbzbPlant;
	CListCtrl m_lstPlant;
	CListCtrl m_lstGrassPlant;
	BOOL m_idcInfiniteCD;
	BOOL m_BigFlower;
	BOOL m_btAI;
	BOOL m_HappyAI;
	BOOL m_idcFireAi;
	BOOL m_idcBigFlower;
	BOOL m_StrongPao;
	BOOL m_StrongTomato;
	BOOL m_StrongPlantAtt;
	BOOL m_AutoCol;
	CButton m_btnOpenM;
	CButton m_btnCloseO;

	afx_msg void OnTimer(UINT_PTR nIDEvent); //定时器
	afx_msg void OnLvnItemchangedPlant(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedModsun();//修改阳光
	afx_msg void OnBnClickedStart(); //开始
	afx_msg void OnBnClickedReFresh();//刷新
	afx_msg void OnBnClickedModcoin(); //修改金币
	afx_msg void OnBnClickedQuit();  //退出
	afx_msg void OnBnClickedModsun9();  //修改阳光9999
	afx_msg void OnBnClickedModcoin9(); //修改金币9999
	afx_msg void OnBnClickedOpenmonitor(); //开启监控列表(0.1s刷新1次)
	afx_msg void OnBnClickedClosemonitor(); //关闭监控
	afx_msg void OnBnClickedVip(); //VIP
	afx_msg void OnBnClickedInfinitcd(); //无限冷却
	afx_msg void OnBnClickedBigflower(); //超级食人花
	afx_msg void OnBnClickedIdcautocol();//自动收集阳光
	afx_msg void OnBnClickedZombiesweak(); //**
	afx_msg void OnBnClickedInfintzombies();//**
	afx_msg void OnBnClickedSelcard(); //选中卡槽
	afx_msg void OnBnClickedPlantsel();//选中植物
	afx_msg void OnBnClickedModselcd(); //修改CD
	afx_msg void OnBnClickedModselpos(); //修改坐标
	afx_msg void OnBnClickedModselhp(); //修改HP
	afx_msg void OnBnClickedPlant();  //选则植物坐标种植
	afx_msg void OnBnClickedClearall(); //清除所有屏幕植物
	afx_msg void OnBnClickedBeanPlant(); //自动种植豌豆
	afx_msg void OnBnClickedRandomPlant(); //随机种植
	afx_msg void OnBnClickedFirePlant();//自动全屏爆炸
	afx_msg void OnBnClickedFlowerPlant();//自动终止超级食人花
	//afx_msg void OnBnClickedSelplantback();//植物退化
	//afx_msg void OnBnClickedSelplantnext();//植物进化
	afx_msg void OnBnClickedStrongpao();  //强化加农炮
	afx_msg void OnBnClickedStrongtomoto(); //强化土豆雷
	afx_msg void OnBnClickedStrongatt(); //强化植物攻击
	afx_msg void OnBnClickedWin();  //一键跳关
	afx_msg void OnBnClickedKillall();//一键秒杀
	afx_msg void OnBnClickedZomallout();//一波出僵尸
	afx_msg void OnBnClickedPerspective();
	afx_msg void OnBnClickedZombiesnomove();
	afx_msg void OnBnClickedYumipao();
	BOOL m_IDCYumipao;
};
