#include "stdafx.h"
#include "MyDB.h"

MyDB::MyDB(CString dataSource)
{
	this->username = "sa";
	this->password = "123456";
	this->database = dataSource;
}

MyDB::~MyDB()
{
	this->CloseDatabase();
}

bool MyDB::ConnectDatabase()                                                   //�������ݿ����
{
	CString str("ODBC;UID=");                                                  //�������ݿ�ǰ׺
	str += this->username;
	str += ";pwd=";
	str += this->password;

	if ((this->m_db.Open(this->database, false, false, str, true)) != 0){      //�����ݿ������
		return true;
	}
	else{
		return false;
	}
}

bool MyDB::IsConnect()                                                         //�ж��Ƿ����������ݿ�
{
	return this->m_db.IsOpen();
}

CDatabase* MyDB::getDatabase()
{
	return &(this->m_db);
}

void MyDB::CloseDatabase()                                                     //�ر����ݿ������
{
	this->m_db.Close();
}

void DBRoom::query(CString sql)                                                //���ݿ��ѯ����
{
	this->Open(CRecordset::forwardOnly, sql);                                  //ִ�в�ѯ���

	int row = 0;
	while (!(this->IsEOF())){                                                  //��ȡ���ݼ�¼����
		++row;
		this->MoveNext();
	}
	this->Close();                                                             //�ر����ݿⲢ���´�
	this->Open(CRecordset::forwardOnly, sql);

	this->row = row;
	this->col = this->GetODBCFieldCount();                                     //��ȡ�����ֶ���
	result = new CString *[this->row];                                         //Ϊ���ݼ���������ڴ�ռ�
	for (int i = 0; i < this->row; ++i){
		result[i] = new CString[this->col];
	}

	for (int i = 0; i < this->row; ++i){
		for (int j = 0; j < this->col; ++j){
			this->GetFieldValue(j, result[i][j]);                              //���ֶ����ݱ���������ݼ�
		}
		this->MoveNext();
	}
}

void DBRoom::update(CString sql)                                               //���ݿ��޸Ĳ���
{

}

int DBRoom::getRow()                                                           //��ȡ��ѯ�������
{
	if (result != NULL){
		return this->row;
	}
	else{
		return 0;
	}
}

int DBRoom::getCol()                                                           //��ȡ��ѯ�������
{
	if (result != NULL){
		return this->col;
	}
	else{
		return 0;
	}
}

CString** DBRoom::getResult()                                                  //��ȡ��ѯ������ݼ�
{
	if (result != NULL){
		return this->result;
	}
	else{
		return NULL;
	}
}

CString DBRoom::getResult(int row, int col)                                    //��ȡĳ��λ���ϵĲ�ѯ���
{
	if (result != NULL){
		return this->result[row][col];
	}
	else{
		return NULL;
	}
}

void DBReservationMessage::query(CString sql)
{
	this->Open(CRecordset::forwardOnly, sql);                                  //ִ�в�ѯ���

	int row = 0;
	while (!(this->IsEOF())){                                                  //��ȡ���ݼ�¼����
		++row;
		this->MoveNext();
	}
	this->Close();                                                             //�ر����ݿⲢ���´�
	this->Open(CRecordset::forwardOnly, sql);

	this->row = row;
	this->col = this->GetODBCFieldCount();                                     //��ȡ�����ֶ���
	result = new CString *[this->row];                                         //Ϊ���ݼ���������ڴ�ռ�
	for (int i = 0; i < this->row; ++i){
		result[i] = new CString[this->col];
	}

	for (int i = 0; i < this->row; ++i){
		for (int j = 0; j < this->col; ++j){
			this->GetFieldValue(j, result[i][j]);                              //���ֶ����ݱ���������ݼ�
		}
		this->MoveNext();
	}
}

void DBReservationMessage::update(CString sql)                                 //���ݿ��޸Ĳ���
{

}

int DBReservationMessage::getRow()                                             //��ȡ��ѯ�������
{
	if (result != NULL){
		return this->row;
	}
	else{
		return 0;
	}
}

int DBReservationMessage::getCol()                                             //��ȡ��ѯ�������
{
	if (result != NULL){
		return this->col;
	}
	else{
		return 0;
	}
}

CString** DBReservationMessage::getResult()                                    //��ȡ��ѯ������ݼ�
{
	if (result != NULL){
		return this->result;
	}
	else{
		return NULL;
	}
}

CString DBReservationMessage::getResult(int row, int col)                      //��ȡĳ��λ���ϵĲ�ѯ���
{
	if (result != NULL){
		return this->result[row][col];
	}
	else{
		return NULL;
	}
}
