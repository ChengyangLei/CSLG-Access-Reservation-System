unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, OleServer,  COMOBJ;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Text1: TMemo;
    Button2: TButton;
    EditSN: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    EditIP1: TEdit;
    EditIP2: TEdit;
    EditIP3: TEdit;
    EditIP4: TEdit;
    Label6: TLabel;
    EditMask1: TEdit;
    EditMask2: TEdit;
    EditMask3: TEdit;
    EditMask4: TEdit;
    Label7: TLabel;
    EditGateway1: TEdit;
    EditGateway2: TEdit;
    EditGateway3: TEdit;
    EditGateway4: TEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
var
strCmd:      WideString;    //Ҫ���͵�ָ��֡
strFuncData: WideString;    //Ҫ���͵Ĺ��ܼ�����
strFrame:    WideString;    //���ص�����
ret:         Integer;       //�����ķ���ֵ
controllerSN: Integer;	    //���������к�

//ˢ����¼����
cardId:      Integer;	    //����
status:      Integer;       //״̬
swipeDate:   WideString;    //����ʱ��

strRunDetail: WideString;   //������Ϣ

recIndex:    Integer; 	    //��¼������
errorNo:     Integer;	    //���Ϻ�

//����Ȩ������
doorIndex:   Integer;       //�ź�
cardno:      array[0..2] of integer ;  //3������
privilege:   WideString;    //Ȩ��
privilegeIndex: Integer;    //Ȩ��������
cardIndex:   Integer;       //��������

timeseg:     WideString;    //ʱ��

//����ʵʱ���
watchIndex: Integer;        //���������
recCnt:     Integer;        //ˢ����¼����

wudp:       Variant;        //WComm_Operate����
ipAddr:     WideString;
strMac:     WideString;
strHexNewIP:    WideString;  //New IP (ʮ������)
strHexMask:     WideString;  //����(ʮ������)
strHexGateway:  WideString;  //����(ʮ������)

startLoc:   Integer;

begin
        //.NET������ͨ�Ų��� (�������controllerSN����)
        controllerSN :=StrToInt64(EditSN.Text);        //����ʹ�õ�.NET ������
        ipAddr := '';                 //Ϊ��, ��ʾ�㲥����ʽ

        Text1.Text := '������ͨ��' + '-' + IntToStr(controllerSN) + '-.NET';

        //��������
        wudp := CreateOleObject('WComm_UDP.WComm_Operate');

        //��ȡ����״̬��Ϣ
        strFuncData := '8110' + wudp.NumToStrHex(0, 3);               // wudp.NumToStrHex(0,3) ��ʾ��0����¼, Ҳ�����¼�¼
        strCmd := wudp.CreateBstrCommand(controllerSN, strFuncData);  //����ָ��֡
        strFrame := wudp.udp_comm(strCmd, ipAddr, 60000);             //����ָ��, ����ȡ������Ϣ
        if ((wudp.ErrCode <> 0) or (strFrame = '')) then
            begin
            //û���յ�����,
            //ʧ�ܴ������... (��ErrCode����Է�������)
            Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '��ȡ������Ϣʧ��';
            Exit;
            end
        Else
            begin
            Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '��ȡ������Ϣ�ɹ�';
            //��������Ϣ����ϸ����
            //�������ĵ�ǰʱ��
            strRunDetail := ''  ;
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) + '�豸���к�S/N: ' +  Chr(9) + IntToStr( wudp.GetSNFromRunInfo(strFrame));
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) + '�豸ʱ��:      ' +  Chr(9) + wudp.GetClockTimeFromRunInfo(strFrame);
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) + 'ˢ����¼��:    ' +  Chr(9) + IntToStr(wudp.GetCardRecordCountFromRunInfo(strFrame));
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) + 'Ȩ����:        ' +  Chr(9) + IntToStr(wudp.GetPrivilegeNumFromRunInfo(strFrame));
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) +  Chr(13) + Chr(10) + '�����һ��ˢ����¼: ' +  Chr(9)                     ;
            swipeDate := wudp.GetSwipeDateFromRunInfo(strFrame, cardId, status) ;
            If swipeDate <> '' Then
            begin
                  strRunDetail := strRunDetail +  Chr(13) + Chr(10) + '����: ' + IntToStr(cardId) +  Chr(9) + ' ״̬:' +  Chr(9) + IntToStr(status) + '(' + wudp.NumToStrHex(status, 1) + ')' +  Chr(9) + 'ʱ��:' +  Chr(9) + swipeDate ;
            end ;
            strRunDetail := strRunDetail +  Chr(13) + Chr(10)                                               ;

            //�ŴŰ�ť״̬
            //Bitλ  7   6   5   4   3   2   1   0
            //˵��   �Ŵ�4   �Ŵ�3   �Ŵ�2   �Ŵ�1   ��ť4   ��ť3   ��ť2   ��ť1
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) + '�Ŵ�״̬  1���Ŵ� 2���Ŵ� 3���Ŵ� 4���Ŵ�' ;
            strRunDetail := strRunDetail +  Chr(13) + Chr(10)                                               ;
            strRunDetail := strRunDetail + '          '                                                     ;
            If wudp.GetDoorStatusFromRunInfo(strFrame, 1) = 1 Then
                strRunDetail := strRunDetail + '   ��   '
            Else
                strRunDetail := strRunDetail + '   ��   '           ;
            If wudp.GetDoorStatusFromRunInfo(strFrame, 2) = 1 Then
                strRunDetail := strRunDetail + '   ��   '
            Else
                strRunDetail := strRunDetail + '   ��   '           ;
            If wudp.GetDoorStatusFromRunInfo(strFrame, 3) = 1 Then
                strRunDetail := strRunDetail + '   ��   '
            Else
                strRunDetail := strRunDetail + '   ��   '           ;
            If wudp.GetDoorStatusFromRunInfo(strFrame, 4) = 1 Then
                strRunDetail := strRunDetail + '   ��   '
            Else
                strRunDetail := strRunDetail + '   ��   '           ;

            strRunDetail := strRunDetail +  Chr(13) + Chr(10);
            //��ť״̬
            //Bitλ  7   6   5   4   3   2   1   0
            //˵��   �Ŵ�4   �Ŵ�3   �Ŵ�2   �Ŵ�1   ��ť4   ��ť3   ��ť2   ��ť1
            strRunDetail := strRunDetail + '��ť״̬  1�Ű�ť 2�Ű�ť 3�Ű�ť 4�Ű�ť';
            strRunDetail := strRunDetail +  Chr(13) + Chr(10)                         ;
            strRunDetail := strRunDetail + '          '                               ;
            If wudp.GetButtonStatusFromRunInfo(strFrame, 1) = 1 Then
                strRunDetail := strRunDetail + ' �ɿ�   '
            Else
                strRunDetail := strRunDetail + ' ����   '            ;
            If wudp.GetButtonStatusFromRunInfo(strFrame, 2) = 1 Then
                strRunDetail := strRunDetail + ' �ɿ�   '
            Else
                strRunDetail := strRunDetail + ' ����   '            ;
            If wudp.GetButtonStatusFromRunInfo(strFrame, 3) = 1 Then
                strRunDetail := strRunDetail + ' �ɿ�   '
            Else
                strRunDetail := strRunDetail + ' ����   '            ;
            If wudp.GetButtonStatusFromRunInfo(strFrame, 4) = 1 Then
                strRunDetail := strRunDetail + ' �ɿ�   '
            Else
                strRunDetail := strRunDetail + ' ����   '            ;

            strRunDetail := strRunDetail +  Chr(13) + Chr(10) + '����״̬:' +  Chr(9);
            errorNo := wudp.GetErrorNoFromRunInfo(strFrame);
            If errorNo = 0 Then
                strRunDetail := strRunDetail + ' �޹���  '
            Else
                begin
                strRunDetail := strRunDetail + ' �й���  '   ;
                If (errorNo And 1) > 0  Then
                    strRunDetail := strRunDetail +  Chr(13) + Chr(10) + '        ' +  Chr(9) + 'ϵͳ����1'  ;
                If (errorNo And 2) > 0  Then
                    strRunDetail := strRunDetail +  Chr(13) + Chr(10) + '        ' +  Chr(9) + 'ϵͳ����2';
                If (errorNo And 4) > 0 Then
                    strRunDetail := strRunDetail +  Chr(13) + Chr(10) + '        ' +  Chr(9) + 'ϵͳ����3[�豸ʱ���й���], ��У��ʱ�Ӵ���';
                If (errorNo And 8) > 0 Then
                    strRunDetail := strRunDetail +  Chr(13) + Chr(10) + '        ' +  Chr(9) + 'ϵͳ����4';
                end  ;
            Text1.Text := Text1.Text + strRunDetail;
            end  ;

        //��ѯ��������IP����
        //��ȡ����������Ϣָ��
        strCmd := wudp.CreateBstrCommand(controllerSN, '0111');   //����ָ��֡ ��ȡ����������Ϣָ��
        strFrame := wudp.udp_comm(strCmd,  ipAddr, 60000)  ;      //����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = '')) Then
            begin
            //û���յ�����,
            //ʧ�ܴ������... (��ErrCode����Է�������)
            Exit;
            end
        Else
            begin
            strRunDetail := '';

            //'MAC
            startLoc := 11; 
            
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) +   'MAC:' + chr(9) + chr(9) + (copy (strFrame, startLoc, 2));
            strRunDetail := strRunDetail + '-' + (copy(strFrame, startLoc + 2, 2));
            strRunDetail := strRunDetail + '-' + (copy(strFrame, startLoc + 4, 2));
            strRunDetail := strRunDetail + '-' + (copy(strFrame, startLoc + 6, 2));
            strRunDetail := strRunDetail + '-' + (copy(strFrame, startLoc + 8, 2));
            strRunDetail := strRunDetail + '-' + (copy(strFrame, startLoc + 10, 2));

            strMac := copy(strFrame, startLoc, 12);

            //IP
            startLoc := 23;  
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) +  'IP:' + chr(9) + chr(9) + IntToStr(StrToInt('$' + (copy(strFrame, startLoc, 2))));
            strRunDetail := strRunDetail + '.' + IntToStr(StrToInt('$' + (copy(strFrame, startLoc + 2, 2))));
            strRunDetail := strRunDetail + '.' + IntToStr(StrToInt('$' + (copy(strFrame, startLoc + 4, 2))));
            strRunDetail := strRunDetail + '.' + IntToStr(StrToInt('$' + (copy(strFrame, startLoc + 6, 2))));

            //Subnet Mask
            startLoc := 31;
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) +  '��������:' + chr(9) + IntToStr(StrToInt('$' + (copy(strFrame, startLoc, 2)))) ;
            strRunDetail := strRunDetail + '.' + IntToStr(StrToInt('$' + (copy(strFrame, startLoc + 2, 2))));
            strRunDetail := strRunDetail + '.' + IntToStr(StrToInt('$' + (copy(strFrame, startLoc + 4, 2))));
            strRunDetail := strRunDetail + '.' + IntToStr(StrToInt('$' + (copy(strFrame, startLoc + 6, 2))));


            //Default Gateway
            startLoc := 39;
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) +   '����:' + chr(9) + chr(9) + IntToStr(StrToInt('$' + (copy(strFrame, startLoc, 2))));
            strRunDetail := strRunDetail + '.' + IntToStr(StrToInt('$' + (copy(strFrame, startLoc + 2, 2))));
            strRunDetail := strRunDetail + '.' + IntToStr(StrToInt('$' + (copy(strFrame, startLoc + 4, 2))));
            strRunDetail := strRunDetail + '.' + IntToStr(StrToInt('$' + (copy(strFrame, startLoc + 6, 2))));

            //TCP Port
            startLoc := 47;
            strRunDetail := strRunDetail +  Chr(13) + Chr(10) +  'PORT:' + chr(9) + chr(9) + IntToStr(StrToInt('$' + (copy(strFrame, startLoc + 2, 2)) + (copy(strFrame, startLoc, 2))));
            Text1.Text := Text1.Text + Chr(13) + Chr(10) +  strRunDetail +  Chr(13) + Chr(10);
            End ;


        Text1.Text := Text1.Text + Chr(13) + Chr(10) + '��ʼIP��ַ����: '+ Chr(13) + Chr(10); // + 'IP 192.168.168.90/Mask 255.255.255.0/Gateway 192.168.168.254: Port 60000';

        application.ProcessMessages ;

        //�µ�IP����: (MAC����) IP��ַ: 192.168.168.90; ����: 255.255.255.0; ����: 192.168.168.254; �˿�: 60000
        strHexNewIP := wudp.NumToStrHex(EditIP1.Text, 1) + wudp.NumToStrHex(EditIP2.Text, 1) + wudp.NumToStrHex(EditIP3.Text, 1) + wudp.NumToStrHex(EditIP4.Text, 1);
        strHexMask := wudp.NumToStrHex(EditMask1.Text, 1)  +  wudp.NumToStrHex(EditMask2.Text, 1)  +  wudp.NumToStrHex(EditMask3.Text, 1)  +  wudp.NumToStrHex(EditMask4.Text, 1) ;
        strHexGateway := wudp.NumToStrHex(EditGateway1.Text, 1)  +  wudp.NumToStrHex(EditGateway2.Text, 1)  +  wudp.NumToStrHex(EditGateway3.Text, 1)  +  wudp.NumToStrHex(EditGateway4.Text, 1) ;

        strCmd := wudp.CreateBstrCommand(controllerSN, 'F211' + strMac + strhexnewip + strhexmask + strhexgateway +  '60EA'); // ����ָ��֡ ��ȡ����������Ϣָ��
        strFrame := wudp.udp_comm(strCmd, ipAddr, 60000);                    //����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = '')) Then
            begin
            //û���յ�����,
            //ʧ�ܴ������... (��ErrCode����Է�������)
            Exit;
            end
        Else
            begin
            Text1.Text := Text1.Text +  Chr(13) + Chr(10) +  'IP��ַ�������...Ҫ�ȴ�3����, ���Ժ�' ;
            application.ProcessMessages ;
            Sleep (3000);                                                                                                   //����3����ʱ
            ret := Application.MessageBox (PChar('IP��ַ�������'),'', MB_OK)
            End;

        //�����µ�IP��ַ����ͨ��
        ipAddr := EditIP1.Text + '.' + EditIP2.Text + '.' + EditIP3.Text + '.' + EditIP4.Text;
        Text1.Text := Text1.Text +  Chr(13) + Chr(10) +  '�����µ�IP��ַ����ͨ��' + ipAddr;

        //У׼������ʱ��
        strCmd := wudp.CreateBstrCommandOfAdjustClockByPCTime(controllerSN) ;  //����ָ��֡
        strFrame := wudp.udp_comm(strCmd, ipAddr, 60000)                    ;  //����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = '')) Then
            //û���յ�����,
            //ʧ�ܴ������... (��ErrCode����Է�������)
            Exit
        Else
            Text1.Text := Text1.Text +  Chr(13) + Chr(10) + 'У׼������ʱ��ɹ�';
        
        
        //Զ�̿�1����
        strCmd := wudp.CreateBstrCommand(controllerSN, '9D10' + '01');        //����ָ��֡
        strFrame := wudp.udp_comm(strCmd, ipAddr, 60000)                    ; //����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = '')) Then
            //û���յ�����,
            //ʧ�ܴ������... (��ErrCode����Է�������)
            Exit
        Else
            Text1.Text := Text1.Text +  Chr(13) + Chr(10) + 'Զ�̿��ųɹ�';
       
        
        //��ȡ��¼
        recIndex := 1 ;
        While true do
        begin
            strFuncData := '8D10' + wudp.NumToStrHex(recIndex, 4);            // wudp.NumToStrHex(recIndex,4) ��ʾ��recIndex����¼
            strCmd := wudp.CreateBstrCommand(controllerSN,strFuncData );      //����ָ��֡ 8D10Ϊ��ȡ��¼ָ��
            strFrame := wudp.udp_comm(strCmd, ipAddr, 60000)           ;      //����ָ��, ����ȡ������Ϣ
            If ((wudp.ErrCode <> 0) Or (strFrame = '')) Then
                begin
                //û���յ�����,
                //ʧ�ܴ������... (��ErrCode����Է�������)
                //�û��ɿ�������
                Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '��ȡ��¼����';
                Exit;
                end
            Else
                begin
                swipeDate := wudp.GetSwipeDateFromRunInfo(strFrame, cardId, status) ;
                If swipeDate <> '' Then
                   begin
	                   strRunDetail := '����: ' + IntToStr(cardId) +  Chr(9) + ' ״̬:' +  Chr(9) + IntToStr(status) + '(' + wudp.NumToStrHex(status, 1) + ')' +  Chr(9) + 'ʱ��:' +  Chr(9) + swipeDate ;
	                   Text1.Text := Text1.Text +  Chr(13) + Chr(10) + strRunDetail;
	                   recIndex := recIndex + 1;             //��һ����¼
                   end
                Else
                   begin
                    Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '��ȡ��¼���. �ܹ���ȡ��¼�� =' + IntToStr(recIndex - 1);
                    break;
                    end;
             end ;
             application.ProcessMessages            
        end;
        
        
        //ɾ������ȡ�ļ�¼
        If (recIndex > 1) Then  //ֻ����ȡ�˼�¼�Ž���ɾ��
        begin
            If (Application.MessageBox (PChar('�Ƿ�ɾ��������������ȡ�ļ�¼: '+ (IntToStr(recIndex - 1 )) + '��'),'ɾ��',MB_YESNO) = IDYES ) Then
                begin
                strFuncData := '8E10' + wudp.NumToStrHex(recIndex - 1, 4);
                strCmd := wudp.CreateBstrCommand(controllerSN, strFuncData);  //����ָ��֡
                strFrame := wudp.udp_comm(strCmd, ipAddr, 60000)           ;  //����ָ��, ����ȡ������Ϣ
                If ((wudp.ErrCode <> 0) Or (strFrame = '')) Then
                    begin
                    //û���յ�����,
                    //ʧ�ܴ������... (��ErrCode����Է�������)
                    //�û��ɿ�������

                    Text1.Text := Text1.Text +  Chr(13) + Chr(10) + 'ɾ����¼ʧ��';
                    Exit;
                    end
                Else
                    Text1.Text := Text1.Text +  Chr(13) + Chr(10) + 'ɾ����¼�ɹ�';
            End;
        End;

        //����Ȩ�޲���(1.�����Ȩ��)
        strCmd := wudp.CreateBstrCommand(controllerSN, '9310');               //����ָ��֡
        strFrame := wudp.udp_comm(strCmd, ipAddr, 60000)             ;        //����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = '')) Then
            begin
            //û���յ�����,
            //ʧ�ܴ������... (��ErrCode����Է�������)
            //�û��ɿ�������
            Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '���Ȩ��ʧ��';
            Exit;
            end
        Else
            Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '���Ȩ�޳ɹ�';


        //����Ȩ�޲���(2.�����Ȩ��)
        //Ȩ�޸�ʽ: ���ţ�2��+���ţ�1��+�źţ�1��+����ʼ�����գ�2��+����ֹ�����գ�2��+ ����ʱ�������ţ�1��+���루3��+���ã�4����0��䣩
        //����Ȩ�ް�: �ȷ�1����(����С���ȷ�), �ٷ�2����(����С���ȷ�)
        //�˰�����Ȩ����Ϊ: ����Ч�ڴ�(2007-8-14 ��2020-12-31), ����Ĭ��ʱ��1(����ʱ����Ч), ȱʡ����(1234), ����ֵ��00���
        //���������� 07217564 [9C4448]��342681[B9A603]��25409969[F126FE]Ϊ�����ֱ����ͨ����������2���š�
        //ʵ��ʹ�ð����޸�
        
        //!!!!!!!ע��:  �˴�������ֱ�Ӱ���С�������и�ֵ��. ʵ��ʹ����Ҫ���㷨ʵ������
        cardno[0] := 342681 ;
        cardno[1] := 7217564;
        cardno[2] := 25409969;
        privilegeIndex := 1  ;
        For doorIndex := 0 To 1 do
            For cardIndex := 0 To 2 do
                begin
                privilege := '';
                privilege := wudp.CardToStrHex(cardno[cardIndex]) ;                  //����
                privilege := privilege + wudp.NumToStrHex(doorIndex + 1, 1) ;        //�ź�
                privilege := privilege + wudp.MSDateYmdToWCDateYmd('2007-8-14') ;    //��Ч��ʼ����
                privilege := privilege + wudp.MSDateYmdToWCDateYmd('2020-12-31');    //��Ч��ֹ����
                privilege := privilege + wudp.NumToStrHex(1, 1)                 ;    //ʱ��������
                privilege := privilege + wudp.NumToStrHex(123456, 3)            ;    //�û�����
                privilege := privilege + wudp.NumToStrHex(0, 4)                 ;    //����4�ֽ�(��0���)
                If (Length(privilege) <> (16 * 2)) Then
                    //���ɵ�Ȩ�޲�����Ҫ��, ���һ����һָ����д���ÿ�������Ƿ���ȷ
                    Exit;
                strFuncData := '9B10' + wudp.NumToStrHex(privilegeIndex, 2) + privilege;
                strCmd := wudp.CreateBstrCommand(controllerSN, strFuncData );   //����ָ��֡
                strFrame := wudp.udp_comm(strCmd, ipAddr, 60000)            ;   //����ָ��, ����ȡ������Ϣ

                If ((wudp.ErrCode <> 0) Or (strFrame = '')) Then
                    begin
                    //û���յ�����,
                    //ʧ�ܴ������... (��ErrCode����Է�������)
                    //�û��ɿ�������
                    Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '���Ȩ��ʧ��';
                    Exit;
                    end
                Else
                    privilegeIndex := privilegeIndex + 1;
            end;
        Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '���Ȩ���� := ' + IntToStr(privilegeIndex - 1);
        
        
        //���Ϳ���ʱ��
        //����Ҫ�趨��ʱ�� [ע��0,1ʱ��Ϊϵͳ�̶���,��������Ч��, �����趨��ʱ��һ���2��ʼ]
        //�˰����趨ʱ��2: ��2007-8-1��2007-12-31��
        // ����1��5������7:30-12:30, 13:30-17:30, 19:00-21:00ͨ��, ����ʱ�䲻����
        timeseg := '';
        timeseg := timeseg + wudp.NumToStrHex($1F, 1);     //���ڿ���
        timeseg := timeseg + wudp.NumToStrHex(0, 1)   ;    // ��һ����ʱ��(0--��ʾ��)
        timeseg := timeseg + wudp.NumToStrHex(0, 2)   ;    // ����2�ֽ�(0���)
        timeseg := timeseg + wudp.MSDateHmsToWCDateHms('07:30:00')  ;    // ��ʼʱ����1
        timeseg := timeseg + wudp.MSDateHmsToWCDateHms('12:30:00')  ;    // ��ֹʱ����1
        timeseg := timeseg + wudp.MSDateHmsToWCDateHms('13:30:00')  ;    // ��ʼʱ����2
        timeseg := timeseg + wudp.MSDateHmsToWCDateHms('17:30:00')  ;    // ��ֹʱ����2
        timeseg := timeseg + wudp.MSDateHmsToWCDateHms('19:00:00')  ;    // ��ʼʱ����3
        timeseg := timeseg + wudp.MSDateHmsToWCDateHms('21:00:00')  ;    // ��ֹʱ����3
        timeseg := timeseg + wudp.MSDateYmdToWCDateYmd('2007-8-1')  ;    // ��ʼ����
        timeseg := timeseg + wudp.MSDateYmdToWCDateYmd('2007-12-31');    // ��ֹ����
        timeseg := timeseg + wudp.NumToStrHex(0, 4)  ;                   // ����4�ֽ�(0���)
        If (Length(timeseg) <> (24 * 2)) Then
            //���ɵ�ʱ�β�����Ҫ��, ���һ����һָ����д���ÿ�������Ƿ���ȷ
            Exit;

        strFuncData :=  '9710' + wudp.NumToStrHex(2, 2) + timeseg;
        strCmd := wudp.CreateBstrCommand(controllerSN,strFuncData);      //����ָ��֡
        strFrame := wudp.udp_comm(strCmd, ipAddr, 60000)          ;      //����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = '')) Then
            begin
            //û���յ�����,
            //ʧ�ܴ������... (��ErrCode����Է�������)
            //�û��ɿ�������
            Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '���ʱ��ʧ��';
            Exit;
            end
        Else
            Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '���ʱ�γɹ�';


       // ʵʱ���
       // ��ȡ����״̬��ʵ�ּ�صĹؼ�ָ� �ڽ��м��ʱ, �ȶ�ȡ���¼�¼����λ�ļ�¼. ��ȡ�����µļ�¼�� ͬʱ���Ի�ȡ��ˢ����¼����
       // ��ʱ�Ϳ����ö�ȡ��ˢ����¼����1��䵽Ҫ��ȡ�����¼�¼����λ�ϣ�ȥ��ȡ����״̬�� �Ա��ȡ��һ����¼��
       // �����ȡ�����µ�ˢ����¼�� �Ϳ��Խ�����λ��1�� ���򱣳�����λ���䡣 �����Ϳ���ʵ�����ݵ�ʵʱ��ء�
       // ����ͨ�Ų��ϵĴ�����ʱ�ɶԴ���ͨ�Ų�ȡ��ʱ400-500������Ϊ����������һ�Σ��ٽ��ղ������ݣ� ����Ϊ�豸��PC����Ĳ���ͨ�š�
       watchIndex := 0   ;                   //ȱʡ��0, ��ʾ����ȡ���һ����¼
       recCnt := 0       ;                   //��ؼ�¼����
       Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '��ʼʵʱ���......(��ˢ��3��)';
       Text1.SelStart := Length(Text1.Text)  ;           //��ʾ�¼��������
       application.ProcessMessages                                       ;
       While (recCnt < 3) do        //������ ����3����ֹͣ
         begin
            strFuncData :=   '8110' + wudp.NumToStrHex(watchIndex, 3) ;   //wudp.NumToStrHex(watchIndex,3) ��ʾ��watchIndex����¼, �����0��ȡ����һ����¼
            strCmd := wudp.CreateBstrCommand(controllerSN,strFuncData);   //����ָ��֡
            strFrame := wudp.udp_comm(strCmd, ipAddr, 60000)          ;   //����ָ��, ����ȡ������Ϣ
            If ((wudp.ErrCode <> 0) Or (strFrame = '')) Then
                //û���յ�����,
                //ʧ�ܴ������... (��ErrCode����Է�������)
                Exit
            Else
                begin
		                swipeDate := wudp.GetSwipeDateFromRunInfo(strFrame, cardId, status) ;
		                If swipeDate <> '' Then   //�м�¼ʱ
	                    begin
	                    strRunDetail := '����: ' + IntToStr(cardId) +  Chr(9) + ' ״̬:' +  Chr(9) + IntToStr(status) + '(' + wudp.NumToStrHex(status, 1) + ')' +  Chr(9) + 'ʱ��:' +  Chr(9) + swipeDate ;
	                    Text1.Text := Text1.Text +  Chr(13) + Chr(10) + strRunDetail;
	                    Text1.SelStart := Length(Text1.Text)   ;           //��ʾ�¼��������
	                    If watchIndex = 0 Then                                                //����յ���һ����¼
	                         watchIndex := wudp.GetCardRecordCountFromRunInfo(strFrame) + 1   //ָ��(�ܼ�¼��+1), Ҳ�����´�ˢ���Ĵ洢����λ
	                    Else
	                         watchIndex := watchIndex + 1 ;                                   //ָ����һ����¼λ
	                    recCnt := recCnt + 1;                                                 //��¼����
	                    End;
                End;
            application.ProcessMessages ;
         end;
       Text1.Text := Text1.Text +  Chr(13) + Chr(10) + '��ֹͣʵʱ���';
       Text1.SelStart := Length(Text1.Text)  ;           //��ʾ�¼��������
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
halt(1);
end;

end.



