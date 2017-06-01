#include <afxdb.h>                                                             //����֧�����ݿ����

class MyDB                                                                     //�ع��ķ���SQL Server�����ݿ����Ӳ���
{
private:
	char* username;                                                            //�û���
	char* password;                                                            //����
	CString database;                                                          //���ݿ���
	CDatabase m_db;                                                            //�������ݿ�Ļ���
public:
	MyDB(CString);
	~MyDB();
	bool ConnectDatabase();                                                    //�������ݿ����
	bool IsConnect();                                                          //�ж��Ƿ����������ݿ�
	CDatabase* getDatabase();                                                  //��ȡ����
	void CloseDatabase();                                                      //�ر����ݿ������
};

class DBRoom :public CRecordset                                                //�ع��ķ��ʻ�ұ�Ĳ���
{
private:
	CString **result;                                                          //���ݿ�Ĳ�ѯ���
	int row;                                                                   //��ѯ���������
	int col;                                                                   //��ѯ���������
public:
	DBRoom(CDatabase* pDatabase = NULL) :CRecordset(pDatabase) {
	}
	~DBRoom(){
		this->Close();
	}
	void query(CString);                                                       //���ݿ��ѯ����
	void update(CString);                                                      //���ݿ��޸Ĳ���
	int getRow();                                                              //��ȡ��ѯ�������
	int getCol();                                                              //��ȡ��ѯ�������
	CString** getResult();                                                     //��ȡ��ѯ������ݼ�
	CString getResult(int row, int col);                                       //��ȡĳ��λ���ϵĲ�ѯ���
};

class DBReservationMessage :public CRecordset
{
private:
	CString **result;                                                          //���ݿ�Ĳ�ѯ���
	int row;                                                                   //��ѯ���������
	int col;                                                                   //��ѯ���������
public:
	DBReservationMessage(CDatabase* pDatabase = NULL) :CRecordset(pDatabase) {
	}
	~DBReservationMessage(){
		this->Close();
	}
	void query(CString);                                                       //���ݿ��ѯ����
	void update(CString);                                                      //���ݿ��޸Ĳ���
	int getRow();                                                              //��ȡ��ѯ�������
	int getCol();                                                              //��ȡ��ѯ�������
	CString** getResult();                                                     //��ȡ��ѯ������ݼ�
	CString getResult(int row, int col);                                       //��ȡĳ��λ���ϵĲ�ѯ���
};