#include "stdafx.h"
#include "GetReservationsFromDB.h"

vector<ReservationMessages> database_messges;                                  //ϵͳȫ�ֱ���-���ڱ�������ݿ��л�ȡ����Ϣ
CString DatabaseName;                                                          //Ҫ���ʵ����ݿ������
CString DatabaseSQl;                                                           //�����ݿ��ж�ȡ���ݵ�SQL���

GetReservationsFromDB::GetReservationsFromDB(CString sql, int uElapse = 2000)
{
	this->uElapse = uElapse;
	this->sql = sql;
	DatabaseSQl = this->sql;
	SetTimer(NULL, this->timer_id, this->uElapse, getReservations);
}

void GetReservationsFromDB::CloseTimer()                                       //�رն�ʱ��
{
	KillTimer(NULL, this->timer_id);
}

void WINAPI getReservations(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime) //��ʱ������-�����ݿ��ж�ȡԤԼ��Ϣ
{
	database_messges.clear();                                                  //���ԭ�ȶ�ȡ��ԤԼ��Ϣ
	MyDB *mydb = new MyDB(DatabaseName);                                       //���ݿ����
	mydb->ConnectDatabase();                                                   //�������ݿ�
	if (mydb->IsConnect()){
		DBReservationMessage *db_msg = new DBReservationMessage(mydb->getDatabase());    //��ȡ���ݶ���
		db_msg->query(DatabaseSQl);                                            //����sql��ѯԤԼ��Ϣ

		for (int i = 0; i < db_msg->getRow(); ++i){                            //���ռ�¼����ת��Ϊ���װ�õ���Ϣ
			int r_id = _ttoi(db_msg->getResult(i, 0));
			int u_id = _ttoi(db_msg->getResult(i, 1));
			int o_id = _ttoi(db_msg->getResult(i, 2));
			bool is_valid = _ttoi(db_msg->getResult(i, 3)) == 1;
			bool is_lock = _ttoi(db_msg->getResult(i, 4)) == 1;
			int yea = _ttoi(db_msg->getResult(i, 5));
			int mon = _ttoi(db_msg->getResult(i, 6));
			int day = _ttoi(db_msg->getResult(i, 7));
			int sta = _ttoi(db_msg->getResult(i, 8));
			int fin = _ttoi(db_msg->getResult(i, 9));
			CString qr = db_msg->getResult(i, 10);
			CString in = db_msg->getResult(i, 11);
			ReservationMessages msg(r_id, u_id, o_id, is_valid, is_lock, yea, mon, day, sta, fin, qr, in);
			database_messges.push_back(msg);                                   //���浽ȫ����Ϣ�У����������ʹ��
		}
		db_msg->Close();                                                       //�ر���������
		mydb->CloseDatabase();                                                 //�ر����ݿ�
	}

	//Todo ��ȡԤԼ�ߵ�����
	for(unsigned long i = 0; i < database_messges.size(); ++i){
		mydb = new MyDB(DatabaseName);                                         //���ݿ����
		mydb->ConnectDatabase();                                               //�������ݿ�
		if(mydb->IsConnect()){
			DBReservationMessage *db_msg = new DBReservationMessage(mydb->getDatabase());
			int u_id = database_messges[i].getUser_id();
			CString tempSQL;
			tempSQL.Format(_T("select userName from Users where user_id = %d;"), u_id);
			db_msg->query(tempSQL);
			CString username = db_msg->getResult(0, 0);
			database_messges[i].setUsername(username);
			db_msg->Close();                                                   //�ر���������
		}
		mydb->CloseDatabase();                                                 //�ر����ݿ�
	}
}