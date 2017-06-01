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

	public private: System::Windows::Forms::Label *  Label1;

	public private: System::Windows::Forms::Label *  Label2;
	public private: System::Windows::Forms::TextBox *  TextBoxSerailPort;
	public private: System::Windows::Forms::TextBox *  textBoxSN;

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
			this->TextBoxSerailPort = new System::Windows::Forms::TextBox();
			this->Label1 = new System::Windows::Forms::Label();
			this->textBoxSN = new System::Windows::Forms::TextBox();
			this->Label2 = new System::Windows::Forms::Label();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(112, 32);
			this->textBox1->Multiline = true;
			this->textBox1->Name = S"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(536, 472);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = S"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(24, 128);
			this->button1->Name = S"button1";
			this->button1->TabIndex = 1;
			this->button1->Text = S"Test";
			this->button1->Click += new System::EventHandler(this, button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(24, 168);
			this->button2->Name = S"button2";
			this->button2->TabIndex = 2;
			this->button2->Text = S"Exit";
			this->button2->Click += new System::EventHandler(this, button2_Click);
			// 
			// TextBoxSerailPort
			// 
			this->TextBoxSerailPort->Location = System::Drawing::Point(40, 96);
			this->TextBoxSerailPort->Name = S"TextBoxSerailPort";
			this->TextBoxSerailPort->Size = System::Drawing::Size(64, 21);
			this->TextBoxSerailPort->TabIndex = 9;
			this->TextBoxSerailPort->Text = S"COM1";
			// 
			// Label1
			// 
			this->Label1->Location = System::Drawing::Point(8, 42);
			this->Label1->Name = S"Label1";
			this->Label1->Size = System::Drawing::Size(29, 23);
			this->Label1->TabIndex = 8;
			this->Label1->Text = S"SN:";
			// 
			// textBoxSN
			// 
			this->textBoxSN->Location = System::Drawing::Point(40, 40);
			this->textBoxSN->Name = S"textBoxSN";
			this->textBoxSN->Size = System::Drawing::Size(64, 21);
			this->textBoxSN->TabIndex = 6;
			this->textBoxSN->Text = S"26604";
			// 
			// Label2
			// 
			this->Label2->Location = System::Drawing::Point(8, 72);
			this->Label2->Name = S"Label2";
			this->Label2->Size = System::Drawing::Size(88, 16);
			this->Label2->TabIndex = 7;
			this->Label2->Text = S"Serial Port:";
			// 
			// Form1
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(6, 14);
			this->ClientSize = System::Drawing::Size(664, 518);
			this->Controls->Add(this->TextBoxSerailPort);
			this->Controls->Add(this->Label1);
			this->Controls->Add(this->textBoxSN);
			this->Controls->Add(this->Label2);
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

				Interop::WComm_Serial::IWComm_Serial		*wserial;				//����ͨ��COM����
				WComm_UDP::IWCOMM_OPERATE		*wudp ;				//UDPͨ�Ŷ���

				String*    strTemp;
				String*    strInfo;

				wserial = new Interop::WComm_Serial::CWComm_SerialClass();

				wudp = new WComm_UDP::WComm_Operate();
				

				while (true)
				{
				
					bStopRun = false;


 					__int64 lngRet;
					String* strT;			//�м����
					String* strFrame;	    //ͨ�ŷ��ص�����
					String* strCmd;         //���͵�ָ��֡
					long controllerSN;      //���������к�
					String* strComPort;     //ͨ�Ŵ��ں�

					
					//ˢ����¼����
					__int64  cardId;		//����    
					__int64  status;        //״̬    
					String* strSwipeDate;   //����ʱ��

					String* strRunDetail;   //������Ϣ
			
			    
					controllerSN = System::Convert::ToInt64 (this->textBoxSN->Text) ;  //����ʹ�õĿ�����
					strComPort = this->TextBoxSerailPort->Text;               //ʹ�õ�ͨ�Ŷ˿�

					strInfo = String::Concat("������ͨ�ţ�" , controllerSN.ToString() , "-", strComPort);
					this->textBox1->Text = this->textBox1->Text->Insert(this->textBox1->Text->Length ,strInfo);
					Application::DoEvents();
			    
					//��ȡ����״̬��Ϣ
					strCmd = wudp -> CreateBstrCommand(controllerSN, "811000000000");	//����ָ��֡ 
					strFrame = wserial ->serial_comm(strCmd, strComPort);	//����ָ��, ����ȡ������Ϣ
					if (( 0 != wserial ->ErrCode)||(strFrame->Length  ==0))	
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
        

					//У׼������ʱ��
					strCmd = wudp->CreateBstrCommandOfAdjustClockByPCTime(controllerSN);  //����ָ��֡
					strFrame = wserial ->serial_comm(strCmd, strComPort);	//����ָ��, ����ȡ������Ϣ
					if (( 0 != wserial ->ErrCode)||(strFrame->Length  ==0))	
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
					strFrame = wserial ->serial_comm(strCmd, strComPort);	//����ָ��, ����ȡ������Ϣ
					if (( 0 != wserial ->ErrCode)||(strFrame->Length  ==0))	
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
						strFrame = wserial ->serial_comm(strCmd, strComPort);	//����ָ��, ����ȡ������Ϣ
						if (( 0 != wserial ->ErrCode)||(strFrame->Length  ==0))	
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
					if (( 0 != wserial ->ErrCode)||(strFrame->Length  ==0))	
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
							strFrame = wserial ->serial_comm(strCmd, strComPort);	//����ָ��, ����ȡ������Ϣ
							if (( 0 != wserial ->ErrCode)||(strFrame->Length  ==0))	
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
					strFrame = wserial ->serial_comm(strCmd, strComPort);	//����ָ��, ����ȡ������Ϣ
					if (( 0 != wserial ->ErrCode)||(strFrame->Length  ==0))	
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
							strFrame = wserial ->serial_comm(strCmd, strComPort);	//����ָ��, ����ȡ������Ϣ
							if (( 0 != wserial ->ErrCode)||(strFrame->Length  ==0))	
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
					strFrame = wserial ->serial_comm(strCmd, strComPort);	//����ָ��, ����ȡ������Ϣ
					if (( 0 != wserial ->ErrCode)||(strFrame->Length  ==0))	
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
							strFrame = wserial ->serial_comm(strCmd, strComPort);	//����ָ��, ����ȡ������Ϣ
							if (( 0 != wserial ->ErrCode)||(strFrame->Length  ==0))	
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

				wserial = NULL;
				wudp = NULL;

			 }

	private: System::Void Form1_Load(System::Object *  sender, System::EventArgs *  e)
			 {
			 }

};
}


