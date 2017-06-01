class ReservationMessages                                                      //���ڱ�ʾĳ��ԤԼ��Ϣ
{
private:
	int reservation_id;                                                        //ԤԼ��Ϣ��Ӧ���ݿ��е���ϢID
	int user_id;                                                               //ԤԼ�û�ID
	int room_id;                                                               //ԤԼ����ID
	CString username;
	bool isValid;                                                              //ԤԼ�Ƿ����
	bool isLock;                                                               //ԤԼ�Ƿ�Ϊ����ԤԼ
	int year;
	int month;
	int day;
	int start;                                                                 //ԤԼ��ʼʱ��-��λ��
	int finish;                                                                //ԤԼ����ʱ��-��λ��
	CString qr_location;                                                       //��ά���·��
	CString information;                                                       //��ע��Ϣ

public:
	ReservationMessages(int, int, int, bool, bool, int, int, int, int, int, CString, CString);
	ReservationMessages(int, int, int, CString, bool, bool, int, int, int, int, int, CString, CString);
	void setUsername(CString username);

	int getReservation_id();
	int getUser_id();
	bool IsValid();
	bool IsLock();
	int getYear();
	int getMonth();
	int getDay();
	int getStart();
	int getFinish();
	CString getQr_location();
	CString getInformation();                                                  //��ȡ��ע��Ϣ

	CString getReservationID();                                                //��ȡԤԼ��ϢID
	CString getUsername();                                                     //��ȡԤԼ�û���
	CString getTime();                                                         //��ȡԤԼʱ��
	CString getDuration();                                                     //��ȡԤԼ����ʱ��
};