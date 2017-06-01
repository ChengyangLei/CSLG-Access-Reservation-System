
// ������ѧԺ�Ž�ԤԼϵͳDlg.h : ͷ�ļ�
//

#pragma once
#include "GetReservationsFromDB.h"
#include "ActivityRoom.h"
#include "afxwin.h"
// C������ѧԺ�Ž�ԤԼϵͳDlg �Ի���
class C������ѧԺ�Ž�ԤԼϵͳDlg : public CDialogEx
{
	// ����
public:
	C������ѧԺ�Ž�ԤԼϵͳDlg(CWnd* pParent = NULL);	// ��׼���캯��

	// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


	// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CListCtrl ctrlList_msg;                                                    //ԤԼ��Ϣ�б��
	CComboBox comboBox_room;                                                   //���������
	GetReservationsFromDB *get_db_data;                                        //��ȡԤԼ��Ϣ��ʱ��
	vector<ActivityRoom> rooms;                                                //����б�
public:
	afx_msg void OnBnClickedButton1();                                         //����
	afx_msg void OnBnClickedButton2();                                         //ɾ��ԤԼ
	afx_msg void OnBnClickedButton3();                                         //�������ݿ�
	afx_msg void OnCbnSelchangeCombo1();                                       //��Ӧ������������ʾĳ���ԤԼ���
	afx_msg void OnTimer(UINT nIDEvent);                                       //ˢ�»���б�
};
