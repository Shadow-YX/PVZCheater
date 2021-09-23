// CVIP.cpp: 实现文件
//

#include "pch.h"
#include "PlantsVsZobiesModifier.h"
#include "CVIP.h"
#include "afxdialogex.h"

using namespace std;

// CVIP 对话框

IMPLEMENT_DYNAMIC(CVIP, CDialogEx)

CVIP::CVIP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DLG_VIP, pParent)
{

}

CVIP::~CVIP()
{
}

void CVIP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVIP, CDialogEx)
	ON_BN_CLICKED(IDOK, &CVIP::OnBnClickedOk)
END_MESSAGE_MAP()


// CVIP 消息处理程序


string Encode1(const  char* Data, int DataByte)
{
    //编码表
    const char EncodeTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    //返回值
    string strEncode;
    unsigned char Tmp[4] = { 0 };
    int LineLength = 0;
    for (int i = 0; i < (int)(DataByte / 3); i++)
    {
        Tmp[1] = *Data++;
        Tmp[2] = *Data++;
        Tmp[3] = *Data++;
        strEncode += EncodeTable[Tmp[1] >> 2];
        strEncode += EncodeTable[((Tmp[1] << 4) | (Tmp[2] >> 4)) & 0x3F];
        strEncode += EncodeTable[((Tmp[2] << 2) | (Tmp[3] >> 6)) & 0x3F];
        strEncode += EncodeTable[Tmp[3] & 0x3F];
        if (LineLength += 4, LineLength == 76) { strEncode += "\r\n"; LineLength = 0; }
    }
    //对剩余数据进行编码
    int Mod = DataByte % 3;
    if (Mod == 1)
    {
        Tmp[1] = *Data++;
        strEncode += EncodeTable[(Tmp[1] & 0xFC) >> 2];
        strEncode += EncodeTable[((Tmp[1] & 0x03) << 4)];
        strEncode += "==";
    }
    else if (Mod == 2)
    {
        Tmp[1] = *Data++;
        Tmp[2] = *Data++;
        strEncode += EncodeTable[(Tmp[1] & 0xFC) >> 2];
        strEncode += EncodeTable[((Tmp[1] & 0x03) << 4) | ((Tmp[2] & 0xF0) >> 4)];
        strEncode += EncodeTable[((Tmp[2] & 0x0F) << 2)];
        strEncode += "=";
    }

    return strEncode;
}


void CVIP::OnBnClickedOk()
{
    char szTmp2[64] = { 0 };
	CString csPwd;
	GetDlgItemText(EDT_VIP, csPwd);
    string cs;
    const char pwd[32] = "OZYzO[14WUiUQWs{UoRuR1t|XBAB";
    //首先base64
    cs=Encode1(csPwd, csPwd.GetLength()); 
    memcpy_s(szTmp2,cs.length(),cs.c_str(),cs.length());
    int n = strlen(szTmp2);

    //再进行各种异位加密
    for (int i = 0; i < n; i++)
    {
        szTmp2[i]+= 1;
        szTmp2[i] <<1;
    }
    for (int i =n-1; i >0 ; i--)
    {
        szTmp2[i] += 4;
        i /= 2;
    }
    for (int i = 0; i < n-2; i += 3)
    {
        szTmp2[i] >> 2;
        szTmp2[i + 2] += 3;
    }
	
	if (!strcmp(szTmp2,pwd))
	{
		AfxMessageBox("VIP开通成功，您已解锁全部功能");
		SendReturn(1);
	}
	else
	{
		AfxMessageBox("序列号输入错误");
		SendReturn(0);
	}

	CDialogEx::OnOK();
}

void CVIP::SendReturn(int is)
{
	if (isOk == 1)
	{
		isOk = is;
	}
	else
	{
		isOk = is;
	}
}

int CVIP::GetReturn()
{
	return isOk;
}

