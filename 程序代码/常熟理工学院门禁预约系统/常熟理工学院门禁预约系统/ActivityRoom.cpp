#include "stdafx.h"
#include "ActivityRoom.h"

ActivityRoom::ActivityRoom(int room_id, CString room_name, CString information)
{
	this->room_id = room_id;
	this->room_name = room_name;
	this->information = information;
}

int ActivityRoom::getRoomID()                                                  //��ȡ���ID
{
	return this->room_id;
}

CString ActivityRoom::getRoomName()                                            //��ȡ�����
{
	return this->room_name;
}

CString ActivityRoom::getInformation()                                         //��ȡ��ұ�ע��Ϣ
{
	return this->information;
}