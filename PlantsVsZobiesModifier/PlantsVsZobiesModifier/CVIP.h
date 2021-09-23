#pragma once
#include <string>


// CVIP 对话框

class CVIP : public CDialogEx
{
	DECLARE_DYNAMIC(CVIP)

public:
	CVIP(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CVIP();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DLG_VIP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int isOk;
	afx_msg void OnBnClickedOk();
	void SendReturn(int isOk);
	int GetReturn();

};
