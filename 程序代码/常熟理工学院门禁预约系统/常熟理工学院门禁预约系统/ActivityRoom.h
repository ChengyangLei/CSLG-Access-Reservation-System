class ActivityRoom                                                             //�����
{
private:
	int room_id;                                                               //���ID
	CString room_name;                                                         //�����
	CString information;                                                       //��ұ�ע��Ϣ
public:
	ActivityRoom(int, CString, CString);                                       //���췽��
	int getRoomID();                                                           //��ȡ���ID
	CString getRoomName();                                                     //��ȡ�����
	CString getInformation();                                                  //��ȡ��ұ�ע��Ϣ
};