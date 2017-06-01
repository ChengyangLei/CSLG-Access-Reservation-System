// controllerMFC_V6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "controllerMFC_V6.h"
#include "controllerMFC_V6Dlg.h"

#include "atlbase.h"			          //����
#import "..\..\..\bin\WComm_UDP.tlb"      //����
using namespace WComm_UDP;				  //����


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControllerMFC_V6Dlg dialog

CControllerMFC_V6Dlg::CControllerMFC_V6Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CControllerMFC_V6Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CControllerMFC_V6Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControllerMFC_V6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CControllerMFC_V6Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CControllerMFC_V6Dlg, CDialog)
	//{{AFX_MSG_MAP(CControllerMFC_V6Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControllerMFC_V6Dlg message handlers

BOOL CControllerMFC_V6Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	((CEdit*) GetDlgItem(IDC_EDITSN))->SetWindowText( _T("39990") );		//ȱʡ��������

	((CEdit*) GetDlgItem(IDC_EDITIP1)) ->SetWindowText( _T("192") );		//New IP
	((CEdit*) GetDlgItem(IDC_EDITIP2)) ->SetWindowText( _T("168"));
	((CEdit*) GetDlgItem(IDC_EDITIP3)) ->SetWindowText( _T("168"));
	((CEdit*) GetDlgItem(IDC_EDITIP4)) ->SetWindowText( _T("90"));
	((CEdit*) GetDlgItem(IDC_EDITMASK1)) ->SetWindowText( _T("255") );		//Mask
	((CEdit*) GetDlgItem(IDC_EDITMASK2)) ->SetWindowText( _T("255") );		//Mask
	((CEdit*) GetDlgItem(IDC_EDITMASK3)) ->SetWindowText( _T("255") );		//Mask
	((CEdit*) GetDlgItem(IDC_EDITMASK4)) ->SetWindowText( _T("0") );		//Mask
	((CEdit*) GetDlgItem(IDC_EDITGATEWAY1)) ->SetWindowText( _T("192") );		//Gateway
	((CEdit*) GetDlgItem(IDC_EDITGATEWAY2)) ->SetWindowText( _T("168") );		//Gateway
	((CEdit*) GetDlgItem(IDC_EDITGATEWAY3)) ->SetWindowText( _T("168") );		//Gateway
	((CEdit*) GetDlgItem(IDC_EDITGATEWAY4)) ->SetWindowText( _T("254") );		//Gateway
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CControllerMFC_V6Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CControllerMFC_V6Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

bool bStopRun;		//����ֹͣ����
void CControllerMFC_V6Dlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	bStopRun = true;
	CDialog::OnCancel();
}

void CControllerMFC_V6Dlg::OnOK() 
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���EDIT
	CEdit* pBoxOne;
	pBoxOne = (CEdit*) GetDlgItem(IDC_EDIT1);
	pBoxOne->SetWindowText( _T("") );
	
	MSG   message;   
	CString    strTemp;
	CString    strNewIPAddr;
	CString    strInfo;

	HRESULT hr;
	// Now we will intilize COM
	hr = CoInitialize(0);
	if (!SUCCEEDED(hr))
	{
		::MessageBox (NULL,(LPCTSTR)("����Comʧ��"),"",0);
		return;	//����
	}


	while (true)
	{
		bStopRun = false;

 		__int64 lngRet;
		BSTR bstrT;				//�м����
		BSTR bstrFrame;	        //ͨ�ŷ��ص�����
		BSTR bstrCmd;           //���͵�ָ��֡
		long controllerSN;      //���������к�
      
		//ˢ����¼����
		__int64  cardId;		//����    
		__int64  status;        //״̬    
		BSTR bstrSwipeDate;     //����ʱ��

		CString strRunDetail;   //������Ϣ
		BSTR strIPAddr;			//IP��ַ
		CString strMac;			//MAC��ַ
		CString strHexNewIP;    //New IP (ʮ������)
        CString strHexMask;     //����(ʮ������)
        CString strHexGateway;  //����(ʮ������)
		long startLoc;			//�ַ�������ʼλ��

    	IWCOMM_OPERATEPtr wudp(__uuidof(WComm_Operate));	//����UDP ͨ�Ŷ���
    
		((CWnd*)GetDlgItem(IDC_EDITSN))->GetWindowText(strTemp);
		controllerSN = _ttol((LPCTSTR)strTemp);		//����ʹ�õĿ�����

		strIPAddr = BSTR(L"");		      //һ��ʼΪ��, ��ʾ�㲥����ʽ
		strTemp.Format("%d",controllerSN);
		strInfo = "������ͨ�ţ�" + strTemp + "-.NET" ;

		pBoxOne->SetWindowText( strInfo);
    
 		//��ȡ����״̬��Ϣ(1081)
		bstrT = BSTR(L"811000000000");
		bstrCmd = wudp -> CreateBstrCommand(controllerSN, bstrT);	//����ָ��֡ 
		bstrFrame = wudp -> udp_comm(bstrCmd, strIPAddr, 60000);	//����ָ��, ����ȡ������Ϣ
		if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)=="" )	)	
		{
			strInfo = strInfo + char(13) + char(10) + "������: ��ȡ������Ϣʧ��" ;
			pBoxOne->SetWindowText(strInfo );
			break;
		}
		//���ݴ���
		strInfo = strInfo +  char(13) + char(10) + "��ȡ������Ϣ�ɹ�";

		//��������Ϣ����ϸ����
		strRunDetail = ""  ;
		strTemp.Format("%ld",wudp->GetSNFromRunInfo(bstrFrame) );
		strRunDetail = strRunDetail +  char(13) + char(10) + "�豸���к�S/N: " +  char(9) + strTemp;

		bstrT = wudp->GetClockTimeFromRunInfo(bstrFrame);
		strRunDetail = strRunDetail +  char(13) + char(10) + "�豸ʱ��:      " +  char(9) + CString(bstrT);

		strTemp.Format("%ld",wudp->GetCardRecordCountFromRunInfo(bstrFrame) );
		strRunDetail = strRunDetail +  char(13) + char(10) + "ˢ����¼��:    " +  char(9) + strTemp;

		strTemp.Format("%ld",wudp->GetPrivilegeNumFromRunInfo(bstrFrame) );
		strRunDetail = strRunDetail +  char(13) + char(10) + "Ȩ����:        " +  char(9) + strTemp;

		strRunDetail = strRunDetail +  char(13) + char(10) +  char(13) + char(10) + "�����һ��ˢ����¼: " +  char(9)   ;
		bstrSwipeDate = wudp->GetSwipeDateFromRunInfo(bstrFrame,  &cardId, &status) ;
		if (CString((bstrSwipeDate)) != "" )
		{
			strTemp.Format( "%ld",cardId);
			strRunDetail = strRunDetail +  char(13) + char(10) + "����: " + strTemp ;
			strTemp.Format( "%ld",status);
			strRunDetail = strRunDetail +  char(9) + " ״̬:" +  char(9) + strTemp ;
			bstrT = wudp->NumToStrHex(status,1);
			strRunDetail = strRunDetail +  "(" + CString(bstrT) + ")" ;
			strRunDetail = strRunDetail +  char(9) + "ʱ��:" +  char(9) + CString(bstrSwipeDate) ;
		}
		strRunDetail = strRunDetail +  "        ";

		//�ŴŰ�ť״̬
		//Bitλ  7   6   5   4   3   2   1   0
		//˵��   �Ŵ�4   �Ŵ�3   �Ŵ�2   �Ŵ�1   ��ť4   ��ť3   ��ť2   ��ť1
		strRunDetail = strRunDetail +  char(13) + char(10) + "�Ŵ�״̬  1���Ŵ� 2���Ŵ� 3���Ŵ� 4���Ŵ�" ;
		strRunDetail = strRunDetail +  char(13) + char(10)                                               ;
		strRunDetail = strRunDetail +  "        ";
		
		lngRet = wudp->GetDoorStatusFromRunInfo(bstrFrame, 1);
		if (lngRet == 1)
		{
			strRunDetail = strRunDetail + "   ��   ";
		}
		else
		{
			strRunDetail = strRunDetail + "   ��   ";
		}

		lngRet = wudp->GetDoorStatusFromRunInfo(bstrFrame, 2);
		if (lngRet == 1)
		{
			strRunDetail = strRunDetail + "   ��   ";
		}
		else
		{
			strRunDetail = strRunDetail + "   ��   ";
		}

		lngRet = wudp->GetDoorStatusFromRunInfo(bstrFrame, 3);
		if (lngRet == 1)
		{
			strRunDetail = strRunDetail + "   ��   ";
		}
		else
		{
			strRunDetail = strRunDetail + "   ��   ";
		}

		lngRet = wudp->GetDoorStatusFromRunInfo(bstrFrame, 4);
		if (lngRet == 1)
		{
			strRunDetail = strRunDetail + "   ��   ";
		}
		else
		{
			strRunDetail = strRunDetail + "   ��   ";
		}


		strRunDetail = strRunDetail +  char(13) + char(10);
		//��ť״̬
		//Bitλ  7   6   5   4   3   2   1   0
		//˵��   �Ŵ�4   �Ŵ�3   �Ŵ�2   �Ŵ�1   ��ť4   ��ť3   ��ť2   ��ť1
		strRunDetail = strRunDetail + "��ť״̬  1�Ű�ť 2�Ű�ť 3�Ű�ť 4�Ű�ť";
		strRunDetail = strRunDetail +  char(13) + char(10)                       ;
		strRunDetail = strRunDetail +  "        ";
		lngRet = wudp->GetButtonStatusFromRunInfo(bstrFrame, 1);
		if (lngRet == 1)
		{
			strRunDetail = strRunDetail + " �ɿ�   ";
		}
		else
		{
			strRunDetail = strRunDetail + " ����   ";
		}
		lngRet = wudp->GetButtonStatusFromRunInfo(bstrFrame, 2);
		if (lngRet == 1)
		{
			strRunDetail = strRunDetail + " �ɿ�   ";
		}
		else
		{
			strRunDetail = strRunDetail + " ����   ";
		}
		lngRet = wudp->GetButtonStatusFromRunInfo(bstrFrame, 3);
		if (lngRet == 1)
		{
			strRunDetail = strRunDetail + " �ɿ�   ";
		}
		else
		{
			strRunDetail = strRunDetail + " ����   ";
		}
		lngRet = wudp->GetButtonStatusFromRunInfo(bstrFrame, 4);
		if (lngRet == 1)
		{
			strRunDetail = strRunDetail + " �ɿ�   ";
		}
		else
		{
			strRunDetail = strRunDetail + " ����   ";
		}
	
	
		strRunDetail = strRunDetail +  char(13) + char(10) + "����״̬:" +  char(9);
		lngRet = wudp->GetErrorNoFromRunInfo(bstrFrame);
		if (lngRet== 0)
		{
			strRunDetail = strRunDetail + " �޹���  "	;
		}
		else
		{
			strRunDetail = strRunDetail + " �й���  "   ;
			if ((lngRet & 1) > 0)
			{
				strRunDetail = strRunDetail +  char(13) + char(10) + "        " +  char(9) + "ϵͳ����1"  ;
			}
			if ((lngRet & 2) > 0)
			{
				strRunDetail = strRunDetail +  char(13) + char(10) + "        " +  char(9) + "ϵͳ����2";
			}
			if ((lngRet & 4) > 0)
			{
				strRunDetail = strRunDetail +  char(13) + char(10) + "        " +  char(9) + "ϵͳ����3[�豸ʱ���й���], ��У��ʱ�Ӵ���";
			}
			if ((lngRet & 8) > 0)
			{
				strRunDetail = strRunDetail +  char(13) + char(10) + "        " +  char(9) + "ϵͳ����4";
			}
		}
		strInfo = strInfo + strRunDetail;
		pBoxOne->SetWindowText(strInfo );

		if(::PeekMessage   (&message,NULL,0,0,PM_REMOVE)){		//��Ӧ�����¼� ��Exit��ť����
				::TranslateMessage   (&message);   
				::DispatchMessage   (&message);   
			}   


        //��ѯ��������IP����
        //��ȡ����������Ϣָ��
        bstrCmd = wudp->CreateBstrCommand(controllerSN, "0111");       //����ָ��֡ ��ȡ����������Ϣָ��
        bstrFrame = wudp->udp_comm(bstrCmd,  strIPAddr, 60000) ;       //����ָ��, ����ȡ������Ϣ
        if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)=="" ))	
		{
			strInfo = strInfo + char(13) + char(10) + "������" ;
			pBoxOne->SetWindowText(strInfo );
			break;
		}

        strRunDetail = "";

        //MAC
        startLoc = 11-1;                                                         ;
        strRunDetail = strRunDetail +  char(13) + char(10) +   "MAC:" + char(9) + char(9) + CString(bstrFrame).Mid(startLoc, 2);
        strRunDetail = strRunDetail + "-" +  CString(bstrFrame).Mid(startLoc + 2, 2);
        strRunDetail = strRunDetail + "-" +  CString(bstrFrame).Mid(startLoc + 4, 2);
        strRunDetail = strRunDetail + "-" +  CString(bstrFrame).Mid(startLoc + 6, 2);
        strRunDetail = strRunDetail + "-" +  CString(bstrFrame).Mid(startLoc + 8, 2);
        strRunDetail = strRunDetail + "-" +  CString(bstrFrame).Mid(startLoc + 10, 2);
        strMac =  CString(bstrFrame).Mid(startLoc , 12);

        //IP
        startLoc = 23-1; 
		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc, 2)));
		strTemp.Format( "%ld",lngRet);
        strRunDetail = strRunDetail +  char(13) + char(10) +  "IP:" + char(9) + char(9) + strTemp ;
  		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc+2, 2)));
		strTemp.Format( "%ld",lngRet);
		strRunDetail = strRunDetail + "." + strTemp                              ;
   		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc+4, 2)));
		strTemp.Format( "%ld",lngRet);
		strRunDetail = strRunDetail + "." + strTemp                              ;
  		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc+6, 2)));
		strTemp.Format( "%ld",lngRet);
		strRunDetail = strRunDetail + "." + strTemp                              ;

        //Subnet Mask
        startLoc = 31-1;
		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc, 2)));
		strTemp.Format( "%ld",lngRet);
        strRunDetail = strRunDetail +  char(13) + char(10) +  "��������:" + char(9) + strTemp ;
  		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc+2, 2)));
		strTemp.Format( "%ld",lngRet);
		strRunDetail = strRunDetail + "." + strTemp                              ;
   		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc+4, 2)));
		strTemp.Format( "%ld",lngRet);
		strRunDetail = strRunDetail + "." + strTemp                              ;
  		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc+6, 2)));
		strTemp.Format( "%ld",lngRet);
		strRunDetail = strRunDetail + "." + strTemp                              ;


        //Default Gateway
        startLoc = 39-1;
 		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc, 2)));
		strTemp.Format( "%ld",lngRet);
        strRunDetail = strRunDetail +  char(13) + char(10) +  "����:    " + char(9) + strTemp ;
  		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc+2, 2)));
		strTemp.Format( "%ld",lngRet);
		strRunDetail = strRunDetail + "." + strTemp                              ;
   		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc+4, 2)));
		strTemp.Format( "%ld",lngRet);
		strRunDetail = strRunDetail + "." + strTemp                              ;
  		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc+6, 2)));
		strTemp.Format( "%ld",lngRet);
		strRunDetail = strRunDetail + "." + strTemp                              ;

        //TCP Port
        startLoc = 47-1;
 		lngRet = wudp->StrHexToNum(A2BSTR(CString(bstrFrame).Mid(startLoc, 4)));
		strTemp.Format( "%ld",lngRet);
        strRunDetail = strRunDetail +  char(13) + char(10) +  "PORT:" + char(9) + char(9) + strTemp;
        strInfo = strInfo + char(13) + char(10) +  strRunDetail +  char(13) + char(10);
		pBoxOne->SetWindowText(strInfo );


        strInfo = strInfo + char(13) + char(10) + "��ʼIP��ַ����: "+ char(13);
		pBoxOne->SetWindowText(strInfo );

		if(::PeekMessage   (&message,NULL,0,0,PM_REMOVE)){		//��Ӧ�����¼� ��Exit��ť����
			::TranslateMessage   (&message);   
			::DispatchMessage   (&message);   
		}   

        //�µ�IP����: (MAC����) IP��ַ: 192.168.168.90; ����: 255.255.255.0; ����: 192.168.168.254; �˿�: 60000
		((CWnd*)GetDlgItem(IDC_EDITIP1))->GetWindowText(strTemp);
		strHexNewIP = CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));
		((CWnd*)GetDlgItem(IDC_EDITIP2))->GetWindowText(strTemp);
		strHexNewIP = strHexNewIP + CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));
		((CWnd*)GetDlgItem(IDC_EDITIP3))->GetWindowText(strTemp);
		strHexNewIP = strHexNewIP + CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));
		((CWnd*)GetDlgItem(IDC_EDITIP4))->GetWindowText(strTemp);
		strHexNewIP = strHexNewIP + CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));

		((CWnd*)GetDlgItem(IDC_EDITMASK1))->GetWindowText(strTemp);
		strHexMask = CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));
		((CWnd*)GetDlgItem(IDC_EDITMASK2))->GetWindowText(strTemp);
		strHexMask = strHexMask + CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));
		((CWnd*)GetDlgItem(IDC_EDITMASK3))->GetWindowText(strTemp);
		strHexMask = strHexMask + CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));
		((CWnd*)GetDlgItem(IDC_EDITMASK4))->GetWindowText(strTemp);
		strHexMask =  strHexMask + CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));

		((CWnd*)GetDlgItem(IDC_EDITGATEWAY1))->GetWindowText(strTemp);
		strHexGateway = CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));
		((CWnd*)GetDlgItem(IDC_EDITGATEWAY2))->GetWindowText(strTemp);
		strHexGateway = strHexGateway + CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));
		((CWnd*)GetDlgItem(IDC_EDITGATEWAY3))->GetWindowText(strTemp);
		strHexGateway = strHexGateway + CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));
		((CWnd*)GetDlgItem(IDC_EDITGATEWAY4))->GetWindowText(strTemp);
		strHexGateway = strHexGateway + CString((BSTR)wudp->NumToStrHex(_ttol((LPCTSTR)strTemp), 1));

		strTemp = "F211" + strMac + strHexNewIP + strHexMask + strHexGateway + "60EA";
		bstrCmd = wudp ->CreateBstrCommand(controllerSN, A2BSTR(strTemp)) ;   //����ָ��֡ ��ȡ����������Ϣָ��
        bstrFrame = wudp->udp_comm(bstrCmd, strIPAddr, 60000);                    //����ָ��, ����ȡ������Ϣ
        if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)=="" )	)	
		{
			strInfo = strInfo + char(13) + char(10) + "������" ;
			pBoxOne->SetWindowText(strInfo );
			break;
		}

         
        strInfo = strInfo +  char(13) + char(10) +  "IP��ַ�������...Ҫ�ȴ�3����, ���Ժ�" ;
		pBoxOne->SetWindowText(strInfo );
		if(::PeekMessage   (&message,NULL,0,0,PM_REMOVE)){		//��Ӧ�����¼� ��Exit��ť����
			::TranslateMessage   (&message);   
			::DispatchMessage   (&message);   
		}   
        Sleep (3000);               //����3����ʱ
		::MessageBox(NULL,(LPCTSTR)"IP��ַ�������","",MB_OK );
		pBoxOne->SetWindowText(strInfo );

        //�����µ�IP��ַ����ͨ��
		((CWnd*)GetDlgItem(IDC_EDITIP1))->GetWindowText(strTemp);
		strNewIPAddr = strTemp ;
		((CWnd*)GetDlgItem(IDC_EDITIP2))->GetWindowText(strTemp);
		strNewIPAddr = strNewIPAddr + "." + strTemp;
		((CWnd*)GetDlgItem(IDC_EDITIP3))->GetWindowText(strTemp);
		strNewIPAddr = strNewIPAddr + "." + strTemp;
		((CWnd*)GetDlgItem(IDC_EDITIP4))->GetWindowText(strTemp);
		strNewIPAddr = strNewIPAddr + "." + strTemp;
		strIPAddr = strNewIPAddr.AllocSysString();

        strInfo = strInfo +  char(13) + char(10) +  "�����µ�IP��ַ����ͨ��" + CString(strIPAddr);
		pBoxOne->SetWindowText(strInfo );


		//У׼������ʱ��
		bstrCmd = wudp -> CreateBstrCommandOfAdjustClockByPCTime(controllerSN);  //����ָ��֡
		bstrFrame = wudp -> udp_comm(bstrCmd, strIPAddr, 60000);	//����ָ��, ����ȡ������Ϣ
		if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)=="" )	)	
		{
			strInfo = strInfo + char(13) + char(10) + "У׼������ʱ�����" ;
			pBoxOne->SetWindowText(strInfo );
			break;
		}
		else
		{
			strInfo = strInfo + char(13) + char(10) + "У׼������ʱ��ɹ�" ;
			pBoxOne->SetWindowText(strInfo );
		}

		//Զ�̿�1����
 		bstrCmd = wudp ->CreateBstrCommand(controllerSN, A2BSTR("9D1001")) ;  //����ָ��֡
		bstrFrame = wudp -> udp_comm(bstrCmd, strIPAddr, 60000);	          //����ָ��, ����ȡ������Ϣ
		if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)=="" )	)	
		{
			//û���յ�����,
			//ʧ�ܴ������... (��ErrCode����Է�������)
			strInfo = strInfo + char(13) + char(10) + "Զ�̿���ʧ��" ;
			pBoxOne->SetWindowText(strInfo );
			break;
		}
		else
		{
			strInfo = strInfo + char(13) + char(10) + "Զ�̿��ųɹ�" ;
			pBoxOne->SetWindowText(strInfo );
		}
		 
		UpdateWindow();	//ˢ�´���

		//��ȡ��¼
        long recIndex;
		recIndex = 1;
        while(true)
		{
			if (bStopRun)
			{
				break;
			}

			bstrT = wudp->NumToStrHex(recIndex, 4);
			strTemp = "8D10" + CString(bstrT);
			bstrCmd = wudp ->CreateBstrCommand(controllerSN, A2BSTR(strTemp)) ;  //����ָ��֡
			bstrFrame = wudp -> udp_comm(bstrCmd, strIPAddr, 60000);	         //����ָ��, ����ȡ������Ϣ
			if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)=="" )	)	
			{
				//û���յ�����,
                //ʧ�ܴ������... (��ErrCode����Է�������)
                //�û��ɿ�������
				strInfo = strInfo + char(13) + char(10) + "��ȡ��¼����" ;
				pBoxOne->SetWindowText(strInfo );
				break;
			}
			else
			{
				bstrSwipeDate = wudp->GetSwipeDateFromRunInfo(bstrFrame, &cardId, &status) ;
				if (CString((bstrSwipeDate)) != "" )
				{
					strRunDetail = "";
					strTemp.Format( "%ld",cardId);
					strRunDetail = strRunDetail  + "����: " + strTemp ;
					strTemp.Format( "%ld",status);
					strRunDetail = strRunDetail +  char(9) + " ״̬:" +  char(9) + strTemp ;
					bstrT = wudp->NumToStrHex(status,1);
					strRunDetail = strRunDetail +  "(" + CString(bstrT) + ")" ;
					strRunDetail = strRunDetail +  char(9) + "ʱ��:" +  char(9) + CString(bstrSwipeDate) ;
					strInfo = strInfo + char(13) + char(10) + strRunDetail ;
                    recIndex = recIndex + 1;                        //��һ����¼
					pBoxOne->SetWindowText(strInfo );
					pBoxOne->LineScroll(pBoxOne->GetLineCount());	//��ʾ���һ��
				}
				else
				{
					strTemp.Format("%ld", (recIndex-1));
					strInfo = strInfo + char(13) + char(10) + "��ȡ��¼���. �ܹ���ȡ��¼�� =" + strTemp;
					pBoxOne->SetWindowText(strInfo );
					pBoxOne->LineScroll(pBoxOne->GetLineCount());	//��ʾ���һ��
					break;
				}
			}
			if(::PeekMessage   (&message,NULL,0,0,PM_REMOVE)){		//��Ӧ�����¼� ��Exit��ť����
						::TranslateMessage   (&message);   
						::DispatchMessage   (&message);   
			}   

		}
		if ((ERROR_SUCCESS != wudp->ErrCode )||(CString(bstrFrame)==""))	
		{
			break;		//���� �˳�
		}

        
        //ɾ������ȡ�ļ�¼
        if (recIndex > 1)   //ֻ����ȡ�˼�¼�Ž���ɾ��
		{
			strTemp.Format("%ld", (recIndex-1));
			strTemp = "�Ƿ�ɾ��������������ȡ�ļ�¼: " + strTemp;
			if (::MessageBox(NULL,(LPCTSTR)strTemp,"ɾ��",MB_YESNO ) == IDYES)
			{
				bstrT = wudp->NumToStrHex(recIndex-1, 4);
				strTemp = "8E10" + CString(bstrT);
   				bstrCmd = wudp ->CreateBstrCommand(controllerSN, A2BSTR(strTemp)) ;  //����ָ��֡
				bstrFrame = wudp -> udp_comm(bstrCmd, strIPAddr, 60000);	         //����ָ��, ����ȡ������Ϣ
				if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)==""))	
				{
					//û���յ�����,
					//ʧ�ܴ������... (��ErrCode����Է�������)
					//�û��ɿ�������
					strInfo = strInfo + char(13) + char(10) + "ɾ����¼ʧ��" ;
					pBoxOne->SetWindowText(strInfo );
					break;
				}
				else
				{
					strInfo = strInfo + char(13) + char(10) + "ɾ����¼�ɹ�";
					pBoxOne->SetWindowText(strInfo );
				}
			}
		}

		//����Ȩ�޲���(1.�����Ȩ��)
   		bstrCmd = wudp ->CreateBstrCommand(controllerSN, A2BSTR("9310")) ;  //����ָ��֡ 
		bstrFrame =  wudp -> udp_comm(bstrCmd, strIPAddr, 60000);	        //����ָ��, ����ȡ������Ϣ
		if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)=="" )	)	
		{
			//û���յ�����,
			//ʧ�ܴ������... (��ErrCode����Է�������)
			//�û��ɿ�������
			strInfo = strInfo + char(13) + char(10) + "���Ȩ��ʧ��" ;
			pBoxOne->SetWindowText(strInfo );
			break;
		}
		else
		{
			strInfo = strInfo + char(13) + char(10) + "���Ȩ�޳ɹ�" ;
			pBoxOne->SetWindowText(strInfo );
		}

        //����Ȩ�޲���(2.�����Ȩ��)
        //Ȩ�޸�ʽ: ���ţ�2��+���ţ�1��+�źţ�1��+����ʼ�����գ�2��+����ֹ�����գ�2��+ ����ʱ�������ţ�1��+���루3��+���ã�4����0��䣩
        //����Ȩ�ް�: �ȷ�1����(����С���ȷ�), �ٷ�2����(����С���ȷ�)
        //�˰�����Ȩ����Ϊ: ����Ч�ڴ�(2007-8-14 ��2020-12-31), ����Ĭ��ʱ��1(����ʱ����Ч), ȱʡ����(1234), ����ֵ��00���
        //���������� 07217564 [9C4448]��342681[B9A603]��25409969[F126FE]Ϊ�����ֱ����ͨ����������2���š�
        //ʵ��ʹ�ð����޸�
        
        //!!!!!!!ע��:  �˴�������ֱ�Ӱ���С�������и�ֵ��. ʵ��ʹ����Ҫ���㷨ʵ������
		long cardno[3];
		long privilegeIndex;
		long doorIndex;
		long cardIndex;
		CString privilege;
        cardno[0] = 342681 ;
        cardno[1] = 7217564;
        cardno[2] = 25409969;
        privilegeIndex = 1  ;
        for( doorIndex = 0;doorIndex<=1; doorIndex++)
		{
            for(cardIndex = 0; cardIndex <= 2; cardIndex++)
			{
                
                privilege = ""; 
				bstrT = wudp->CardToStrHex(cardno[cardIndex]);
                privilege = privilege + CString(bstrT);                  //����
 				bstrT = wudp->NumToStrHex(doorIndex + 1, 1);
				privilege = privilege + CString(bstrT) ;                 //�ź�
				bstrT = wudp->MSDateYmdToWCDateYmd(A2BSTR("2007-8-14")) ;//��Ч��ʼ����
                privilege = privilege + CString(bstrT);                  
                bstrT = wudp->MSDateYmdToWCDateYmd(A2BSTR("2020-12-31"));//��Ч��ֹ����
				privilege = privilege + CString(bstrT) ;
                bstrT = wudp->NumToStrHex(1, 1)                 ;    //ʱ��������
				privilege = privilege + CString(bstrT) ;
                bstrT = wudp->NumToStrHex(123456, 3)            ;    //�û�����
				privilege = privilege + CString(bstrT) ;
                bstrT = wudp->NumToStrHex(0, 4)                 ;    //����4�ֽ�(��0���)
				privilege = privilege + CString(bstrT) ;
                if (lstrlen(privilege) != (16 * 2))
				{
                    //���ɵ�Ȩ�޲�����Ҫ��, ���һ����һָ����д���ÿ�������Ƿ���ȷ
				   strInfo = strInfo + char(13) + char(10) + "���ɵ�Ȩ�޲�����Ҫ��: ���Ȩ��ʧ��" ;
				   pBoxOne->SetWindowText(strInfo );
				   break;;
				}

                bstrT = wudp->NumToStrHex(privilegeIndex, 2)                 ;    //Ȩ��������
				strTemp = "9B10" + CString(bstrT) + privilege;
				bstrCmd = wudp->CreateBstrCommand(controllerSN, A2BSTR(strTemp)) ;  //����ָ��֡ 
				bstrFrame =( wudp -> udp_comm(bstrCmd, strIPAddr, 60000));	        //����ָ��, ����ȡ������Ϣ
				if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)=="" )	)	
				{
					//û���յ�����,
					//ʧ�ܴ������... (��ErrCode����Է�������)
					//�û��ɿ�������
					strInfo = strInfo + char(13) + char(10) + "���Ȩ��ʧ��" ;
					pBoxOne->SetWindowText(strInfo );
					break;
				}
				else
				{
                    privilegeIndex = privilegeIndex + 1;
				}
				if(::PeekMessage   (&message,NULL,0,0,PM_REMOVE)){		//��Ӧ�����¼� ��Exit��ť����
							::TranslateMessage   (&message);   
							::DispatchMessage   (&message);   
				}   
			}
		}
		strTemp.Format("%ld", privilegeIndex-1 );
		strInfo = strInfo + char(13) + char(10) + "���Ȩ���� = " + strTemp ;
		pBoxOne->SetWindowText(strInfo );
				
        
        //���Ϳ���ʱ��
        //����Ҫ�趨��ʱ�� [ע��0,1ʱ��Ϊϵͳ�̶���,��������Ч��, �����趨��ʱ��һ���2��ʼ]
        //�˰����趨ʱ��2: ��2007-8-1��2007-12-31��
        // ����1��5������7:30-12:30, 13:30-17:30, 19:00-21:00ͨ��, ����ʱ�䲻����
		CString timeseg;
        timeseg = "";
    	bstrT = wudp->NumToStrHex(0x1F, 1);
		timeseg = timeseg + CString(bstrT) ;   //���ڿ���
     	bstrT = wudp->NumToStrHex(0x00, 1);
		timeseg = timeseg + CString(bstrT) ;   // ��һ����ʱ��(0--��ʾ��)
    	bstrT = wudp->NumToStrHex(0x00, 2);
		timeseg = timeseg + CString(bstrT) ;   // ����2�ֽ�(0���)
    	bstrT = wudp->MSDateHmsToWCDateHms(A2BSTR("7:30:00"));
		timeseg = timeseg + CString(bstrT) ;   //  ��ʼʱ����1
   		bstrT = wudp->MSDateHmsToWCDateHms(A2BSTR("12:30:00"));
		timeseg = timeseg + CString(bstrT) ;   //  ��ֹʱ����1
    	bstrT = wudp->MSDateHmsToWCDateHms(A2BSTR("13:30:00"));
		timeseg = timeseg + CString(bstrT) ;   //  ��ʼʱ����2
   		bstrT = wudp->MSDateHmsToWCDateHms(A2BSTR("17:30:00"));
		timeseg = timeseg + CString(bstrT) ;   //  ��ֹʱ����2
    	bstrT = wudp->MSDateHmsToWCDateHms(A2BSTR("19:00:00"));
		timeseg = timeseg + CString(bstrT) ;   //  ��ʼʱ����3
   		bstrT = wudp->MSDateHmsToWCDateHms(A2BSTR("21:00:00"));
		timeseg = timeseg + CString(bstrT) ;   //  ��ֹʱ����3
    	bstrT = wudp->MSDateYmdToWCDateYmd(A2BSTR("2007-8-1"));
		timeseg = timeseg + CString(bstrT) ;   //  ��ʼ����
   		bstrT = wudp->MSDateYmdToWCDateYmd(A2BSTR("2007-12-31"));
		timeseg = timeseg + CString(bstrT) ;   //  ��ֹ����
    	bstrT = wudp->NumToStrHex(0x00, 4);
		timeseg = timeseg + CString(bstrT) ;   // ����4�ֽ�(0���)

        if (lstrlen(timeseg) != (24 * 2))
		{
            //���ɵ�ʱ�β�����Ҫ��, ���һ����һָ����д���ÿ�������Ƿ���ȷ
			strInfo = strInfo + char(13) + char(10) + "���ɵ�ʱ�β�����Ҫ��: �޸�ʱ��ʧ��" ;
			pBoxOne->SetWindowText(strInfo );
			break;;
		}

		bstrT = wudp->NumToStrHex(2, 2)  ;                                  //ʱ��������2
		strTemp = "9710" + CString(bstrT) + timeseg;
		bstrCmd = wudp->CreateBstrCommand(controllerSN, A2BSTR(strTemp)) ;  //����ָ��֡ 
		bstrFrame = ( wudp -> udp_comm(bstrCmd, strIPAddr, 60000));	        //����ָ��, ����ȡ������Ϣ
		if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)=="" ))	
		{
			//û���յ�����,
			//ʧ�ܴ������... (��ErrCode����Է�������)
			//�û��ɿ�������
			strInfo = strInfo + char(13) + char(10) + "���ʱ��ʧ��" ;
			pBoxOne->SetWindowText(strInfo );
			break;
		}
		else
		{
			strInfo = strInfo + char(13) + char(10) + "���ʱ�γɹ�" ;
			pBoxOne->SetWindowText(strInfo );
		}


        //ʵʱ���
       // ��ȡ����״̬��ʵ�ּ�صĹؼ�ָ� �ڽ��м��ʱ, �ȶ�ȡ���¼�¼����λ�ļ�¼. ��ȡ�����µļ�¼�� ͬʱ���Ի�ȡ��ˢ����¼����
       // ��ʱ�Ϳ����ö�ȡ��ˢ����¼����1��䵽Ҫ��ȡ�����¼�¼����λ�ϣ�ȥ��ȡ����״̬�� �Ա��ȡ��һ����¼��
       // �����ȡ�����µ�ˢ����¼�� �Ϳ��Խ�����λ��1�� ���򱣳�����λ���䡣 �����Ϳ���ʵ�����ݵ�ʵʱ��ء�
       // ����ͨ�Ų��ϵĴ�����ʱ�ɶԴ���ͨ�Ų�ȡ��ʱ400-500������Ϊ����������һ�Σ��ٽ��ղ������ݣ� ����Ϊ�豸��PC����Ĳ���ͨ�š�
	   __int64 watchIndex;
	   long recCnt;

       watchIndex = 0   ;                   //ȱʡ��0, ��ʾ����ȡ���һ����¼
       recCnt = 0       ;                   //��ؼ�¼����
       strInfo = strInfo + char(13) + char(10) + "��ʼʵʱ���......(��ˢ��3��)" ;
	   pBoxOne->SetWindowText(strInfo );
	   UpdateWindow();	//ˢ�´���
	   pBoxOne->LineScroll(pBoxOne->GetLineCount());	//��ʾ���һ��

       while (recCnt < 3)         //������ ����3����ֹͣ
	   {
		   	if (bStopRun)
			{
				break;
			}

		    bstrT = wudp->NumToStrHex(watchIndex, 3) ;                          //��ʾ��watchIndex����¼, �����0��ȡ����һ����¼
			strTemp = "8110" + CString(bstrT);
			bstrCmd = wudp->CreateBstrCommand(controllerSN, A2BSTR(strTemp)) ;  //����ָ��֡ 
			bstrFrame =( wudp -> udp_comm(bstrCmd, strIPAddr, 60000));	        //����ָ��, ����ȡ������Ϣ
			if (( ERROR_SUCCESS != wudp ->ErrCode)||(CString(bstrFrame)=="" )	)	
			{
				//û���յ�����,
				//ʧ�ܴ������... (��ErrCode����Է�������)
				//�û��ɿ�������
				strInfo = strInfo + char(13) + char(10) + "ʵʱ���ʧ��" ;
				pBoxOne->SetWindowText(strInfo );
				break;
			}
			else
			{
				bstrSwipeDate = wudp->GetSwipeDateFromRunInfo(bstrFrame, &cardId, &status) ;
				if (CString(bstrSwipeDate) != "" )
				{
					strRunDetail="";
					strTemp.Format( "%ld",cardId);
					strRunDetail = strRunDetail  + "����: " + strTemp ;
					strTemp.Format( "%ld",status);
					strRunDetail = strRunDetail +  char(9) + " ״̬:" +  char(9) + strTemp ;
					bstrT = wudp->NumToStrHex(status,1);
					strRunDetail = strRunDetail +  "(" + CString(bstrT) + ")" ;
					strRunDetail = strRunDetail +  char(9) + "ʱ��:" +  char(9) + CString((bstrSwipeDate)) ;
					strInfo = strInfo + char(13) + char(10) + strRunDetail ;
					pBoxOne->SetWindowText(strInfo );
                    recIndex = recIndex + 1;             //��һ����¼
					UpdateWindow();	                     //ˢ�´���
				   if (watchIndex == 0)                  //����յ���һ����¼
				   {
					   watchIndex = wudp->GetCardRecordCountFromRunInfo(bstrFrame);
					   watchIndex =  watchIndex + 1;     //ָ��(�ܼ�¼��+1), Ҳ�����´�ˢ���Ĵ洢����λ
				   }
				   else
				   {
						watchIndex = watchIndex + 1 ;    //ָ����һ����¼λ
				   }
					recCnt = recCnt + 1;                 //��¼����				}
				   pBoxOne->LineScroll(pBoxOne->GetLineCount());	//��ʾ���һ��
				}
			}

			if(::PeekMessage   (&message,NULL,0,0,PM_REMOVE)){		//��Ӧ�����¼� ��Exit��ť����
				::TranslateMessage   (&message);   
				::DispatchMessage   (&message);   
			}   

	   }
		strInfo = strInfo + char(13) + char(10) + "��ֹͣʵʱ���" ;
		pBoxOne->SetWindowText(strInfo );
	    pBoxOne->LineScroll(pBoxOne->GetLineCount());	//��ʾ���һ��

		//�ͷ���Դ
		wudp -> Release();
		break;
	}
	// Uninitialize COM
	CoUninitialize();
}
