#include "MyDB.h"                                                              //֧�ֵײ����ݿ����
#include <vector>
#include <windows.h>                                                           //����֧�ֶ�ʱ������
#include "ReservationMessages.h"
using namespace std;

class GetReservationsFromDB                                                    //���ڶ�ʱ�����ݿ��л�ȡ��Ϣ
{
private:
	int timer_id;                                                              //��ʱ��ID
	int uElapse;                                                               //��ʱ����
	CString sql;                                                               //��ȡ��Ϣ��sql���
public:
	GetReservationsFromDB(CString, int);                                       //��ʼ����������ʱ��
	void CloseTimer();                                                         //�رն�ʱ��
};

extern vector<ReservationMessages> database_messges;                           //ϵͳȫ�ֱ���-���ڱ�������ݿ��л�ȡ����Ϣ
extern CString DatabaseName;                                                   //Ҫ���ʵ����ݿ������

void WINAPI getReservations(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime);//��ʱ������