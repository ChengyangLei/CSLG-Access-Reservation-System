#pragma once

namespace controllerUDP_NET
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary> 
	/// Form1 ժҪ
	///
	/// ����: ��������ĸ�������ƣ�����Ҫ���� 
	///          ����������������� .resx �ļ��������й���Դ���������ߵ� 
	///          ����Դ�ļ��������ԡ�  ����
	///          �������������˴��������
	///          ���ػ���Դ��ȷ������
	/// </summary>
	public __gc class Form1 : public System::Windows::Forms::Form
	{	
	public:
		Form1(void)
		{
			InitializeComponent();
		}
  
	protected:
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}
	private: System::Windows::Forms::TextBox *  textBox1;
	private: System::Windows::Forms::Button *  button1;
	private: System::Windows::Forms::Button *  button2;
	private: bool bStopRun;
	public private: System::Windows::Forms::TextBox *  TextBoxGateway1;
	public private: System::Windows::Forms::Label *  Label6;
	public private: System::Windows::Forms::TextBox *  TextBoxGateway2;
	public private: System::Windows::Forms::TextBox *  TextBoxGateway3;
	public private: System::Windows::Forms::TextBox *  TextBoxGateway4;
	public private: System::Windows::Forms::Label *  Label7;
	public private: System::Windows::Forms::TextBox *  TextBoxMask1;
	public private: System::Windows::Forms::Label *  Label4;
	public private: System::Windows::Forms::TextBox *  TextBoxMask2;
	public private: System::Windows::Forms::TextBox *  TextBoxMask3;
	public private: System::Windows::Forms::TextBox *  TextBoxMask4;
	public private: System::Windows::Forms::Label *  Label5;
	public private: System::Windows::Forms::TextBox *  TextBoxIP1;
	public private: System::Windows::Forms::Label *  Label1;
	public private: System::Windows::Forms::TextBox *  TextBoxSN;
	public private: System::Windows::Forms::Label *  Label2;
	public private: System::Windows::Forms::TextBox *  TextBoxIP2;
	public private: System::Windows::Forms::TextBox *  TextBoxIP3;
	public private: System::Windows::Forms::TextBox *  TextBoxIP4;
	public private: System::Windows::Forms::Label *  Label3;

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container * components;

		/// <summary>
		/// �����֧������ķ��� - ��Ҫʹ�ô���༭���޸�
		/// �˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = new System::Windows::Forms::TextBox();
			this->button1 = new System::Windows::Forms::Button();
			this->button2 = new System::Windows::Forms::Button();
			this->TextBoxGateway1 = new System::Windows::Forms::TextBox();
			this->Label6 = new System::Windows::Forms::Label();
			this->TextBoxGateway2 = new System::Windows::Forms::TextBox();
			this->TextBoxGateway3 = new System::Windows::Forms::TextBox();
			this->TextBoxGateway4 = new System::Windows::Forms::TextBox();
			this->Label7 = new System::Windows::Forms::Label();
			this->TextBoxMask1 = new System::Windows::Forms::TextBox();
			this->Label4 = new System::Windows::Forms::Label();
			this->TextBoxMask2 = new System::Windows::Forms::TextBox();
			this->TextBoxMask3 = new System::Windows::Forms::TextBox();
			this->TextBoxMask4 = new System::Windows::Forms::TextBox();
			this->Label5 = new System::Windows::Forms::Label();
			this->TextBoxIP1 = new System::Windows::Forms::TextBox();
			this->Label1 = new System::Windows::Forms::Label();
			this->TextBoxSN = new System::Windows::Forms::TextBox();
			this->Label2 = new System::Windows::Forms::Label();
			this->TextBoxIP2 = new System::Windows::Forms::TextBox();
			this->TextBoxIP3 = new System::Windows::Forms::TextBox();
			this->TextBoxIP4 = new System::Windows::Forms::TextBox();
			this->Label3 = new System::Windows::Forms::Label();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(152, 32);
			this->textBox1->Multiline = true;
			this->textBox1->Name = S"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(536, 472);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = S"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(24, 288);
			this->button1->Name = S"button1";
			this->button1->TabIndex = 1;
			this->button1->Text = S"Test";
			this->button1->Click += new System::EventHandler(this, button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(24, 328);
			this->button2->Name = S"button2";
			this->button2->TabIndex = 2;
			this->button2->Text = S"Exit";
			this->button2->Click += new System::EventHandler(this, button2_Click);
			// 
			// TextBoxGateway1
			// 
			this->TextBoxGateway1->Location = System::Drawing::Point(8, 200);
			this->TextBoxGateway1->Name = S"TextBoxGateway1";
			this->TextBoxGateway1->Size = System::Drawing::Size(24, 21);
			this->TextBoxGateway1->TabIndex = 40;
			this->TextBoxGateway1->Text = S"192";
			// 
			// Label6
			// 
			this->Label6->Location = System::Drawing::Point(8, 176);
			this->Label6->Name = S"Label6";
			this->Label6->Size = System::Drawing::Size(88, 16);
			this->Label6->TabIndex = 36;
			this->Label6->Text = S"Gateway:";
			// 
			// TextBoxGateway2
			// 
			this->TextBoxGateway2->Location = System::Drawing::Point(40, 200);
			this->TextBoxGateway2->Name = S"TextBoxGateway2";
			this->TextBoxGateway2->Size = System::Drawing::Size(24, 21);
			this->TextBoxGateway2->TabIndex = 41;
			this->TextBoxGateway2->Text = S"168";
			// 
			// TextBoxGateway3
			// 
			this->TextBoxGateway3->Location = System::Drawing::Point(80, 200);
			this->TextBoxGateway3->Name = S"TextBoxGateway3";
			this->TextBoxGateway3->Size = System::Drawing::Size(24, 21);
			this->TextBoxGateway3->TabIndex = 39;
			this->TextBoxGateway3->Text = S"168";
			// 
			// TextBoxGateway4
			// 
			this->TextBoxGateway4->Location = System::Drawing::Point(112, 200);
			this->TextBoxGateway4->Name = S"TextBoxGateway4";
			this->TextBoxGateway4->Size = System::Drawing::Size(24, 21);
			this->TextBoxGateway4->TabIndex = 38;
			this->TextBoxGateway4->Text = S"254";
			// 
			// Label7
			// 
			this->Label7->Location = System::Drawing::Point(32, 208);
			this->Label7->Name = S"Label7";
			this->Label7->Size = System::Drawing::Size(104, 24);
			this->Label7->TabIndex = 37;
			this->Label7->Text = S".     .     .";
			// 
			// TextBoxMask1
			// 
			this->TextBoxMask1->Location = System::Drawing::Point(8, 152);
			this->TextBoxMask1->Name = S"TextBoxMask1";
			this->TextBoxMask1->Size = System::Drawing::Size(24, 21);
			this->TextBoxMask1->TabIndex = 34;
			this->TextBoxMask1->Text = S"255";
			// 
			// Label4
			// 
			this->Label4->Location = System::Drawing::Point(8, 136);
			this->Label4->Name = S"Label4";
			this->Label4->Size = System::Drawing::Size(88, 16);
			this->Label4->TabIndex = 30;
			this->Label4->Text = S"Mask:";
			// 
			// TextBoxMask2
			// 
			this->TextBoxMask2->Location = System::Drawing::Point(40, 152);
			this->TextBoxMask2->Name = S"TextBoxMask2";
			this->TextBoxMask2->Size = System::Drawing::Size(24, 21);
			this->TextBoxMask2->TabIndex = 35;
			this->TextBoxMask2->Text = S"255";
			// 
			// TextBoxMask3
			// 
			this->TextBoxMask3->Location = System::Drawing::Point(80, 152);
			this->TextBoxMask3->Name = S"TextBoxMask3";
			this->TextBoxMask3->Size = System::Drawing::Size(24, 21);
			this->TextBoxMask3->TabIndex = 33;
			this->TextBoxMask3->Text = S"255";
			// 
			// TextBoxMask4
			// 
			this->TextBoxMask4->Location = System::Drawing::Point(112, 152);
			this->TextBoxMask4->Name = S"TextBoxMask4";
			this->TextBoxMask4->Size = System::Drawing::Size(24, 21);
			this->TextBoxMask4->TabIndex = 32;
			this->TextBoxMask4->Text = S"0";
			// 
			// Label5
			// 
			this->Label5->Location = System::Drawing::Point(32, 160);
			this->Label5->Name = S"Label5";
			this->Label5->Size = System::Drawing::Size(104, 24);
			this->Label5->TabIndex = 31;
			this->Label5->Text = S".     .     .";
			// 
			// TextBoxIP1
			// 
			this->TextBoxIP1->Location = System::Drawing::Point(8, 96);
			this->TextBoxIP1->Name = S"TextBoxIP1";
			this->TextBoxIP1->Size = System::Drawing::Size(24, 21);
			this->TextBoxIP1->TabIndex = 27;
			this->TextBoxIP1->Text = S"192";
			// 
			// Label1
			// 
			this->Label1->Location = System::Drawing::Point(8, 43);
			this->Label1->Name = S"Label1";
			this->Label1->Size = System::Drawing::Size(29, 23);
			this->Label1->TabIndex = 25;
			this->Label1->Text = S"SN:";
			// 
			// TextBoxSN
			// 
			this->TextBoxSN->Location = System::Drawing::Point(40, 40);
			this->TextBoxSN->Name = S"TextBoxSN";
			this->TextBoxSN->Size = System::Drawing::Size(64, 21);
			this->TextBoxSN->TabIndex = 22;
			this->TextBoxSN->Text = S"39990";
			// 
			// Label2
			// 
			this->Label2->Location = System::Drawing::Point(8, 80);
			this->Label2->Name = S"Label2";
			this->Label2->Size = System::Drawing::Size(88, 16);
			this->Label2->TabIndex = 23;
			this->Label2->Text = S"New IP:";
			// 
			// TextBoxIP2
			// 
			this->TextBoxIP2->Location = System::Drawing::Point(40, 96);
			this->TextBoxIP2->Name = S"TextBoxIP2";
			this->TextBoxIP2->Size = System::Drawing::Size(24, 21);
			this->TextBoxIP2->TabIndex = 26;
			this->TextBoxIP2->Text = S"168";
			// 
			// TextBoxIP3
			// 
			this->TextBoxIP3->Location = System::Drawing::Point(80, 96);
			this->TextBoxIP3->Name = S"TextBoxIP3";
			this->TextBoxIP3->Size = System::Drawing::Size(24, 21);
			this->TextBoxIP3->TabIndex = 28;
			this->TextBoxIP3->Text = S"168";
			// 
			// TextBoxIP4
			// 
			this->TextBoxIP4->Location = System::Drawing::Point(112, 96);
			this->TextBoxIP4->Name = S"TextBoxIP4";
			this->TextBoxIP4->Size = System::Drawing::Size(24, 21);
			this->TextBoxIP4->TabIndex = 29;
			this->TextBoxIP4->Text = S"90";
			// 
			// Label3
			// 
			this->Label3->Location = System::Drawing::Point(32, 104);
			this->Label3->Name = S"Label3";
			this->Label3->Size = System::Drawing::Size(104, 24);
			this->Label3->TabIndex = 24;
			this->Label3->Text = S".     .     .";
			// 
			// Form1
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(6, 14);
			this->ClientSize = System::Drawing::Size(704, 518);
			this->Controls->Add(this->TextBoxGateway1);
			this->Controls->Add(this->Label6);
			this->Controls->Add(this->TextBoxGateway2);
			this->Controls->Add(this->TextBoxGateway3);
			this->Controls->Add(this->TextBoxGateway4);
			this->Controls->Add(this->Label7);
			this->Controls->Add(this->TextBoxMask1);
			this->Controls->Add(this->Label4);
			this->Controls->Add(this->TextBoxMask2);
			this->Controls->Add(this->TextBoxMask3);
			this->Controls->Add(this->TextBoxMask4);
			this->Controls->Add(this->Label5);
			this->Controls->Add(this->TextBoxIP1);
			this->Controls->Add(this->Label1);
			this->Controls->Add(this->TextBoxSN);
			this->Controls->Add(this->Label2);
			this->Controls->Add(this->TextBoxIP2);
			this->Controls->Add(this->TextBoxIP3);
			this->Controls->Add(this->TextBoxIP4);
			this->Controls->Add(this->Label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = S"Form1";
			this->Text = S"Form1";
			this->Load += new System::EventHandler(this, Form1_Load);
			this->ResumeLayout(false);

		}	
	private: System::Void button2_Click(System::Object *  sender, System::EventArgs *  e)
			 {
				 bStopRun = true;
				 this->Close() ;
			 }

	private: System::Void button1_Click(System::Object *  sender, System::EventArgs *  e)
			 {
				// TODO: �ڴ���ӿؼ�֪ͨ����������
				this->button1->Enabled = false;

				WComm_UDP::IWCOMM_OPERATE		*wudp ;				//.NETͨ�Ŷ���

				String*    strTemp;
				String*    strInfo;

				wudp = new WComm_UDP::WComm_Operate();
				

				while (true)
				{
				
					bStopRun = false;


 					__int64 lngRet;
					String* strT;			//�м����
					String* strFrame;	    //ͨ�ŷ��ص�����
					String* strCmd;         //���͵�ָ��֡
					long controllerSN;      //���������к�
					String* strIPAddr;		//IP��ַ
					String* strMac;			//MAC��ַ
					String* strHexNewIP;    //New IP (ʮ������)
                    String* strHexMask;     //����(ʮ������)
                    String* strHexGateway;  //����(ʮ������)

			      
					//ˢ����¼����
					__int64  cardId;		//����    
					__int64  status;        //״̬    
					String* strSwipeDate;   //����ʱ��

					String* strRunDetail;   //������Ϣ
			
			    
					controllerSN = System::Convert::ToInt64(this->TextBoxSN->Text) ;  //����ʹ�õ�.NET������
					strIPAddr = "";	          //һ��ʼΪ��, ��ʾ�㲥����ʽ

					strInfo = String::Concat("������ͨ�ţ�" , controllerSN.ToString() , "-.NET");
					this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
					Application::DoEvents();
			    
					//��ȡ����״̬��Ϣ
					strCmd = wudp -> CreateBstrCommand(controllerSN, "811000000000");	//����ָ��֡ 
					strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	//����ָ��, ����ȡ������Ϣ
					if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
					{
						strInfo = String::Concat( "\r\n", "������" );
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
						break;
					}
					//���ݴ���
					strInfo = String::Concat("\r\n", "��ȡ������Ϣ�ɹ�");
					this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);

					//��������Ϣ����ϸ����
					strRunDetail = ""  ;
					strInfo =String::Concat("\r\n", "�豸���к�S/N: " ,"\t", wudp->GetSNFromRunInfo(strFrame).ToString());
					strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
					
					strInfo =String::Concat("\r\n", "�豸ʱ��:      " ,"\t", wudp->GetClockTimeFromRunInfo(strFrame) );
					strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);

					strInfo =String::Concat("\r\n", "ˢ����¼��:    " ,"\t", wudp->GetCardRecordCountFromRunInfo(strFrame).ToString() );
					strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
				
					strInfo =String::Concat("\r\n", "Ȩ����:        " ,"\t", wudp->GetPrivilegeNumFromRunInfo(strFrame).ToString() );
					strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
					strInfo =String::Concat("\r\n", "�����һ��ˢ����¼: " ,"\t" );
					strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);

					strSwipeDate = wudp->GetSwipeDateFromRunInfo(strFrame,  &cardId, &status) ;
					if (strSwipeDate->Length != 0 )
					{
						//��¼����ϸ����
						strInfo =String::Concat("\r\n", "����: " ,"\t", cardId.ToString() );
						strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
						
						strT =  wudp->NumToStrHex(status,1);
						strInfo = String::Concat("\t", "״̬: " ,"\t", (status.ToString())); 
						strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
						strInfo = String::Concat("(", strT , ")" );
						strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);

						strInfo =String::Concat("\t", "ʱ��: " ,"\t", strSwipeDate );
						strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
					}

					//�ŴŰ�ť״̬
					//Bitλ  7   6   5   4   3   2   1   0
					//˵��   �Ŵ�4   �Ŵ�3   �Ŵ�2   �Ŵ�1   ��ť4   ��ť3   ��ť2   ��ť1
					strInfo =String::Concat("\r\n\r\n", "�Ŵ�״̬  1���Ŵ� 2���Ŵ� 3���Ŵ� 4���Ŵ�" ,"\r\n",  "                   "   );
					strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
					if (wudp->GetDoorStatusFromRunInfo(strFrame,1) == 1)
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  "   ��   ");
					}
					else
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  "   ��   ");
					}
					if (wudp->GetDoorStatusFromRunInfo(strFrame,2) == 1)
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  "   ��   ");
					}
					else
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  "   ��   ");
					}

					if (wudp->GetDoorStatusFromRunInfo(strFrame,3) == 1)
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  "   ��   ");
					}
					else
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  "   ��   ");
					}

					if (wudp->GetDoorStatusFromRunInfo(strFrame,4) == 1)
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  "   ��   ");
					}
					else
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  "   ��   ");
					}

					
		
					////��ť״̬
					////Bitλ  7   6   5   4   3   2   1   0
					////˵��   �Ŵ�4   �Ŵ�3   �Ŵ�2   �Ŵ�1   ��ť4   ��ť3   ��ť2   ��ť1
					strRunDetail =strRunDetail->Insert(strRunDetail->Length, "\r\n");
					strRunDetail =strRunDetail->Insert(strRunDetail->Length, "��ť״̬  1�Ű�ť 2�Ű�ť 3�Ű�ť 4�Ű�ť\r\n                   ");
					if (wudp->GetButtonStatusFromRunInfo(strFrame,1) == 1)
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  " �ɿ�   ");
					}
					else
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  " ����   ");
					}
					if (wudp->GetButtonStatusFromRunInfo(strFrame,2) == 1)
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  " �ɿ�   ");
					}
					else
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  " ����   ");
					}
					if (wudp->GetButtonStatusFromRunInfo(strFrame,3) == 1)
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  " �ɿ�   ");
					}
					else
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  " ����   ");
					}
					if (wudp->GetButtonStatusFromRunInfo(strFrame,3) == 1)
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  " �ɿ�   ");
					}
					else
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  " ����   ");
					}

				
					strRunDetail =strRunDetail->Insert(strRunDetail->Length, "\r\n����״̬:\t");
					lngRet =wudp->GetErrorNoFromRunInfo(strFrame);
					if ( lngRet== 0)
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length,  " �޹���  ");
					}
					else
					{
						strRunDetail =strRunDetail->Insert(strRunDetail->Length, " �й���   ");
						if ((lngRet & 1) > 0)
						{
							strRunDetail = strRunDetail->Insert(strRunDetail->Length, "\r\n        \tϵͳ����1");
						}
						if ((lngRet & 2) > 0)
						{
							strRunDetail = strRunDetail->Insert(strRunDetail->Length, "\r\n        \tϵͳ����2");
						}
						if ((lngRet & 4) > 0)
						{
							strRunDetail = strRunDetail->Insert(strRunDetail->Length, "\r\n        \tϵͳ����3[�豸ʱ���й���], ��У��ʱ�Ӵ���");
						}
						if ((lngRet & 8) > 0)
						{
							strRunDetail = strRunDetail->Insert(strRunDetail->Length, "\r\n        \tϵͳ����4");
						}
					}
					this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strRunDetail);

					Application::DoEvents();
        
					//��ѯ��������IP����
					//��ȡ����������Ϣָ��
					strCmd = wudp->CreateBstrCommand(controllerSN, "0111");	//����ָ��֡ ��ȡ����������Ϣָ��
					strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	//����ָ��, ����ȡ������Ϣ
					if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
					{
						strInfo ="\r\n��ѯ������IP ʧ��";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
						break;
					}
					else
					{
					    long startLoc;			//�ַ�������ʼλ��
						String* deviceInfo;
						
						deviceInfo = "";
						//MAC
						startLoc = 11-1;
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, "\r\nMAC:\t\t");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, strFrame->Substring( startLoc, 2));
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, "-");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, strFrame->Substring( startLoc+2, 2));
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, "-");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, strFrame->Substring( startLoc+4, 2));
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, "-");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, strFrame->Substring( startLoc+6, 2));
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, "-");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, strFrame->Substring( startLoc+8, 2));
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, "-");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, strFrame->Substring( startLoc+10, 2));
						strMac = strFrame->Substring( startLoc, 12);
					

						//IP
						startLoc = 23-1;
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, "\r\nIP:\t\t");
						strInfo = String::Concat("0x",strFrame->Substring( startLoc, 2));
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc, 2)).ToString());
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, ".");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc+2, 2)).ToString());
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, ".");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc+4, 2)).ToString());
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, ".");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc+6, 2)).ToString());

						//Subnet Mask
						startLoc = 31-1;
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, "\r\n��������:\t");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc, 2)).ToString());
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, ".");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc+2, 2)).ToString());
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, ".");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc+4, 2)).ToString());
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, ".");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc+6, 2)).ToString());

						//Default Gateway
						startLoc = 39-1;
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, "\r\n����:\t\t");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc, 2)).ToString());
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, ".");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc+2, 2)).ToString());
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, ".");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc+4, 2)).ToString());
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, ".");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc+6, 2)).ToString());

						//TCP Port
						startLoc = 47-1;
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, "\r\nPORT:\t\t");
						deviceInfo = deviceInfo->Insert(deviceInfo->Length, wudp->StrHexToNum(strFrame->Substring( startLoc, 4)).ToString());
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,deviceInfo);
					}

					strInfo = "\r\n��ʼIP��ַ����: "          ;
					this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
					//�µ�IP����: (MAC����) IP��ַ: 192.168.168.90; ����: 255.255.255.0; ����: 192.168.168.254; �˿�: 60000
					strInfo = String::Concat(  "F211", strMac );						        //���ܺ�
					strHexNewIP = String::Concat(wudp->NumToStrHex(System::Convert::ToInt64( this->TextBoxIP1->Text), 1) ,
						wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxIP2->Text), 1),
						wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxIP3->Text), 1),
						wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxIP4->Text), 1));
					strHexMask = String::Concat( wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxMask1->Text), 1) ,
						wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxMask2->Text), 1) ,
						wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxMask3->Text), 1) ,
						wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxMask4->Text), 1));
					strHexGateway =  String::Concat(wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxGateway1->Text), 1) ,
						wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxGateway2->Text), 1) ,
						wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxGateway3->Text), 1) ,
						wudp->NumToStrHex(System::Convert::ToInt64(this->TextBoxGateway4->Text), 1));
					strTemp = String::Concat(  strHexNewIP, strHexMask, strHexGateway, "60EA" );
					strInfo = strInfo->Insert(strInfo->Length,strTemp);					
					strCmd = wudp->CreateBstrCommand(controllerSN,strInfo );					//����ָ��֡ ��ȡ����������Ϣָ��
					strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	                    //����ָ��, ����ȡ������Ϣ
					if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
					{
						strInfo ="\r\nIP��ַ���ó���";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
						break;
					}
					else
					{
						strInfo ="\r\nIP��ַ�������...Ҫ�ȴ�3����, ���Ժ�";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
						Application::DoEvents();
						System::Threading::Thread::Sleep(3000);		//'����3����ʱ
						lngRet = MessageBox::Show(this,"IP��ַ�������","",MessageBoxButtons::OK);
					}

 					//�����µ�IP��ַ����ͨ��
					strTemp =".";
					strIPAddr = String::Concat(this->TextBoxIP1->Text ,strTemp,
						this->TextBoxIP2->Text,strTemp,
						this->TextBoxIP3->Text,strTemp,
						this->TextBoxIP4->Text);
					strInfo = String::Concat( "\r\n�����µ�IP��ַ����ͨ��" , strIPAddr);
					this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);


					//У׼������ʱ��
					strCmd = wudp->CreateBstrCommandOfAdjustClockByPCTime(controllerSN);  //����ָ��֡
					strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	                    //����ָ��, ����ȡ������Ϣ
					if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
					{
						strInfo ="\r\nУ׼������ʱ�����";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
						break;
					}
					else
					{
						strInfo ="\r\nУ׼������ʱ��ɹ�";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
					}
		

					//Զ�̿�1����
					strCmd = wudp->CreateBstrCommand(controllerSN,"9D1001");  //����ָ��֡
					strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	                    //����ָ��, ����ȡ������Ϣ
					if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
					{
						strInfo ="\r\nԶ�̿���ʧ��";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
						break;
					}
					else
					{
						strInfo ="\r\nԶ�̿��ųɹ�";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
					}
					Application::DoEvents();

					//��ȡ��¼
					long recIndex;
					recIndex = 1;
					while(true)
					{
						if (bStopRun)
						{
							break;
						}

						strT =String::Concat("8D10", wudp->NumToStrHex(recIndex,4));
						strCmd  = wudp->CreateBstrCommand(controllerSN, strT) ;  //����ָ��֡
						strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	                    //����ָ��, ����ȡ������Ϣ
						if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
 						{
							//û���յ�����,
							//ʧ�ܴ������... (��ErrCode����Է�������)
							//�û��ɿ�������
							strInfo ="\r\n��ȡ��¼����";
							this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
							break;
						}
						else
						{
							strSwipeDate = wudp->GetSwipeDateFromRunInfo(strFrame,  &cardId, &status) ;
							if (strSwipeDate->Length != 0 )
							{
								//��¼����ϸ����
								strRunDetail="";
								strInfo =String::Concat("\r\n", "����: ", cardId.ToString()  );
								strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
								strT =  wudp->NumToStrHex(status,1);
								strInfo = String::Concat( "\t", "״̬: " , (status.ToString())); 
								strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
								strInfo = String::Concat("(", strT , ")" );
								strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
								strInfo =String::Concat( "\t", "ʱ��: " , strSwipeDate );
								strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
								recIndex = recIndex + 1;                    //��һ����¼
								this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strRunDetail);
								this->textBox1->SelectionStart = this->textBox1->TextLength;
								this->textBox1->ScrollToCaret();			//��ʾ���һ��

							}
							else
							{
								strInfo =String::Concat("\r\n��ȡ��¼���. �ܹ���ȡ��¼�� = " ,  (recIndex-1).ToString()  );
								this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
								this->textBox1->SelectionStart = this->textBox1->TextLength;
								this->textBox1->ScrollToCaret();			//��ʾ���һ��
								break;
							}
							Application::DoEvents();
						}
					}
					if ((0 != wudp ->ErrCode)||(strFrame->Length == 0))	
					{
						break;		//���� �˳�
					}

			        
					//ɾ������ȡ�ļ�¼
					if (recIndex > 1)   //ֻ����ȡ�˼�¼�Ž���ɾ��
					{
						strTemp =String::Concat("�Ƿ�ɾ��������������ȡ�ļ�¼: ", (recIndex-1).ToString());
						if ( MessageBox::Show(this,strTemp,"ɾ��",MessageBoxButtons::YesNo) == DialogResult::Yes )
						{
							strT = String::Concat("8E10" , wudp->NumToStrHex(recIndex-1, 4));
  							strCmd  = wudp->CreateBstrCommand(controllerSN, strT) ;                     //����ָ��֡
							strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	                    //����ָ��, ����ȡ������Ϣ
							if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
 							{
								//û���յ�����,
								//ʧ�ܴ������... (��ErrCode����Է�������)
								//�û��ɿ�������
								strInfo ="\r\nɾ����¼ʧ��";
								this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
								break;
							}
							else
							{
								strInfo ="\r\nɾ����¼�ɹ�";
								this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
							} 						
						}
					}



					//����Ȩ�޲���(1.�����Ȩ��)
  					strCmd  = wudp->CreateBstrCommand(controllerSN, "9310") ;                   //����ָ��֡ 
					strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	                    //����ָ��, ����ȡ������Ϣ
					if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
 					{
						//û���յ�����,
						//ʧ�ܴ������... (��ErrCode����Է�������)
						//�û��ɿ�������
						strInfo ="\r\n���Ȩ��ʧ��";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
						break;
					}
					else
					{
						strInfo ="\r\n���Ȩ�޳ɹ�";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
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
					String* privilege;
					cardno[0] = 342681 ;
					cardno[1] = 7217564;
					cardno[2] = 25409969;
					privilegeIndex = 1  ;
					for( doorIndex = 0;doorIndex<=1; doorIndex++)
					{
						for(cardIndex = 0; cardIndex <= 2; cardIndex++)
						{
			                privilege = ""; 
							privilege = privilege->Insert(privilege->Length,wudp->CardToStrHex(cardno[cardIndex]));           //����
							privilege = privilege->Insert(privilege->Length,wudp->NumToStrHex(doorIndex + 1, 1));			  //�ź�
							privilege = privilege->Insert(privilege->Length,wudp->MSDateYmdToWCDateYmd("2007-8-14"));         //��Ч��ʼ����
							privilege = privilege->Insert(privilege->Length,wudp->MSDateYmdToWCDateYmd("2020-12-31"));        //��Ч��ֹ����
							privilege = privilege->Insert(privilege->Length,wudp->NumToStrHex(1, 1));						  //ʱ��������
							privilege = privilege->Insert(privilege->Length,wudp->NumToStrHex(123456, 3));					  //�û�����
							privilege = privilege->Insert(privilege->Length,wudp->NumToStrHex(0, 4));						  //����4�ֽ�(��0���)
						
							if (privilege->Length != (16 * 2))
							{
								//���ɵ�Ȩ�޲�����Ҫ��, ���һ����һָ����д���ÿ�������Ƿ���ȷ
								strInfo = "\r\n���ɵ�Ȩ�޲�����Ҫ��: ���Ȩ��ʧ��";
								this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
								break;
							}


							strTemp =String::Concat( "9B10" ,wudp->NumToStrHex(privilegeIndex, 2), privilege);				 //Ȩ��������
							strCmd  = wudp->CreateBstrCommand(controllerSN, strTemp) ;                  //����ָ��֡ 
							strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	                    //����ָ��, ����ȡ������Ϣ
							if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
 							{
								//û���յ�����,
								//ʧ�ܴ������... (��ErrCode����Է�������)
								//�û��ɿ�������
								strInfo ="\r\n���Ȩ��ʧ��";
								this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
								break;
							}
							else
							{
								privilegeIndex = privilegeIndex + 1;
							} 						
							Application::DoEvents();
						}
					}
					strInfo =String::Concat("\r\n���Ȩ���� = ",(privilegeIndex-1).ToString());
					this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
							
			        
					//���Ϳ���ʱ��
					//����Ҫ�趨��ʱ�� [ע��0,1ʱ��Ϊϵͳ�̶���,��������Ч��, �����趨��ʱ��һ���2��ʼ]
					//�˰����趨ʱ��2: ��2007-8-1��2007-12-31��
					// ����1��5������7:30-12:30, 13:30-17:30, 19:00-21:00ͨ��, ����ʱ�䲻����
					String* timeseg;
					long timeIndex;
					timeseg = "";
					timeseg = timeseg->Insert(timeseg->Length,wudp->NumToStrHex(0x1F, 1));            //���ڿ���
					timeseg = timeseg->Insert(timeseg->Length,wudp->NumToStrHex(0x00, 1));            // ��һ����ʱ��(0--��ʾ��)
					timeseg = timeseg->Insert(timeseg->Length,wudp->NumToStrHex(0x00, 2));            // ����2�ֽ�(0���)
					timeseg = timeseg->Insert(timeseg->Length,wudp->MSDateHmsToWCDateHms("07:30:00")); //  ��ʼʱ����1
					timeseg = timeseg->Insert(timeseg->Length,wudp->MSDateHmsToWCDateHms("12:30:00")); //  ��ֹʱ����1
					timeseg = timeseg->Insert(timeseg->Length,wudp->MSDateHmsToWCDateHms("13:30:00")); //  ��ʼʱ����2
					timeseg = timeseg->Insert(timeseg->Length,wudp->MSDateHmsToWCDateHms("17:30:00")); //  ��ֹʱ����2
					timeseg = timeseg->Insert(timeseg->Length,wudp->MSDateHmsToWCDateHms("19:00:00")); //  ��ʼʱ����3
 					timeseg = timeseg->Insert(timeseg->Length,wudp->MSDateHmsToWCDateHms("21:00:00")); //  ��ֹʱ����3
					timeseg = timeseg->Insert(timeseg->Length,wudp->MSDateYmdToWCDateYmd("2007-08-01")); //  ��ʼ����
 					timeseg = timeseg->Insert(timeseg->Length,wudp->MSDateYmdToWCDateYmd("2007-12-31")); //  ��ֹ����
					timeseg = timeseg->Insert(timeseg->Length,wudp->NumToStrHex(0x00, 4));            // ����4�ֽ�(0���)
					if (timeseg->Length  != (24 * 2))
					{
						//���ɵ�ʱ�β�����Ҫ��, ���һ����һָ����д���ÿ�������Ƿ���ȷ
						strInfo ="\r\n���ɵ�ʱ�β�����Ҫ��: �޸�ʱ��ʧ��";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
						break;
					}

					timeIndex = 2;
					strTemp =String::Concat( "9710" ,wudp->NumToStrHex(timeIndex, 2), timeseg);				//ʱ��������2
					strCmd  = wudp->CreateBstrCommand(controllerSN, strTemp) ;                  //����ָ��֡ 
					strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	                    //����ָ��, ����ȡ������Ϣ
					if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
 					{
						//û���յ�����,
						//ʧ�ܴ������... (��ErrCode����Է�������)
						//�û��ɿ�������
						strInfo ="\r\n���ʱ��ʧ��";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
						break;
					}
					else
					{
						strInfo ="\r\n���ʱ�γɹ�";
						this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
					} 						
					Application::DoEvents();

	 
					//ʵʱ���
					// ��ȡ����״̬��ʵ�ּ�صĹؼ�ָ� �ڽ��м��ʱ, �ȶ�ȡ���¼�¼����λ�ļ�¼. ��ȡ�����µļ�¼�� ͬʱ���Ի�ȡ��ˢ����¼����
					// ��ʱ�Ϳ����ö�ȡ��ˢ����¼����1��䵽Ҫ��ȡ�����¼�¼����λ�ϣ�ȥ��ȡ����״̬�� �Ա��ȡ��һ����¼��
					// �����ȡ�����µ�ˢ����¼�� �Ϳ��Խ�����λ��1�� ���򱣳�����λ���䡣 �����Ϳ���ʵ�����ݵ�ʵʱ��ء�
					// ����ͨ�Ų��ϵĴ�����ʱ�ɶԴ���ͨ�Ų�ȡ��ʱ400-500������Ϊ����������һ�Σ��ٽ��ղ������ݣ� ����Ϊ�豸��PC����Ĳ���ͨ�š�
					__int64 watchIndex;
					long recCnt;

					watchIndex = 0   ;                   //ȱʡ��0, ��ʾ����ȡ���һ����¼
					recCnt = 0       ;                   //��ؼ�¼����
					strInfo ="\r\n��ʼʵʱ���......(��ˢ��3��)" ;
					this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
					this->textBox1->SelectionStart = this->textBox1->TextLength;
					this->textBox1->ScrollToCaret();			//��ʾ���һ��

					Application::DoEvents();
					
					while (recCnt < 3)         //������ ����3����ֹͣ
					{
		   					if (bStopRun)
							{
								break;
							}

							strTemp =String::Concat( "8110" ,wudp->NumToStrHex(watchIndex, 2));			//��ʾ��watchIndex����¼, �����0��ȡ����һ����¼
							strCmd  = wudp->CreateBstrCommand(controllerSN, strTemp) ;                  //����ָ��֡ 
							strFrame = wudp -> udp_comm(strCmd, strIPAddr, 60000);	                    //����ָ��, ����ȡ������Ϣ
							if (( 0 != wudp ->ErrCode)||(strFrame->Length  ==0))	
 							{
								//û���յ�����,
								//ʧ�ܴ������... (��ErrCode����Է�������)
								//�û��ɿ�������
								strInfo ="\r\nʵʱ���ʧ��";
								this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
								break;
							}
							else
							{
								strSwipeDate = wudp->GetSwipeDateFromRunInfo(strFrame,  &cardId, &status) ;
								if (strSwipeDate->Length != 0 )
								{
									//��¼����ϸ����
									strRunDetail="";
									strInfo =String::Concat("\r\n", "����: ", cardId.ToString()  );
									strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
									strT =  wudp->NumToStrHex(status,1);
									strInfo = String::Concat( "\t", "״̬: " , (status.ToString())); 
									strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
									strInfo = String::Concat("(", strT , ")" );
									strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
									strInfo =String::Concat( "\t", "ʱ��: " , strSwipeDate );
									strRunDetail =strRunDetail->Insert(strRunDetail->Length, strInfo);
									recIndex = recIndex + 1;             //��һ����¼
									this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strRunDetail);
								
									if (watchIndex == 0)                //����յ���һ����¼
									{
										watchIndex = wudp->GetCardRecordCountFromRunInfo(strFrame);
										watchIndex =  watchIndex + 1;   //ָ��(�ܼ�¼��+1), Ҳ�����´�ˢ���Ĵ洢����λ
									}
									else
									{
										watchIndex = watchIndex + 1 ; //ָ����һ����¼λ
									}
									recCnt = recCnt + 1;                //��¼����	
									this->textBox1->SelectionStart = this->textBox1->TextLength;
									this->textBox1->ScrollToCaret();			//��ʾ���һ��

								}
							}
							Application::DoEvents();
					}
					strInfo ="\r\n��ֹͣʵʱ���" ;
					this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
					Application::DoEvents();

					break;
				}
				this->textBox1->SelectionStart = this->textBox1->TextLength;
				this->textBox1->ScrollToCaret();			//��ʾ���һ��
				this->button1->Enabled = true;

				wudp = NULL;

			 }

	private: System::Void Form1_Load(System::Object *  sender, System::EventArgs *  e)
			 {
			 }

};
}


