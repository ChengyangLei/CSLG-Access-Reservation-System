VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   7965
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   9930
   LinkTopic       =   "Form1"
   ScaleHeight     =   7965
   ScaleWidth      =   9930
   StartUpPosition =   3  '����ȱʡ
   Begin VB.TextBox TextGateway1 
      Height          =   270
      Left            =   120
      TabIndex        =   21
      Text            =   "192"
      Top             =   3000
      Width           =   375
   End
   Begin VB.TextBox TextGateway2 
      Height          =   270
      Left            =   675
      TabIndex        =   20
      Text            =   "168"
      Top             =   3000
      Width           =   375
   End
   Begin VB.TextBox TextGateway3 
      Height          =   270
      Left            =   1245
      TabIndex        =   19
      Text            =   "168"
      Top             =   3000
      Width           =   375
   End
   Begin VB.TextBox TextGateway4 
      Height          =   270
      Left            =   1800
      TabIndex        =   18
      Text            =   "254"
      Top             =   3000
      Width           =   375
   End
   Begin VB.TextBox TextMask1 
      Height          =   270
      Left            =   120
      TabIndex        =   16
      Text            =   "255"
      Top             =   2160
      Width           =   375
   End
   Begin VB.TextBox TextMask2 
      Height          =   270
      Left            =   675
      TabIndex        =   15
      Text            =   "255"
      Top             =   2160
      Width           =   375
   End
   Begin VB.TextBox TextMask3 
      Height          =   270
      Left            =   1245
      TabIndex        =   14
      Text            =   "255"
      Top             =   2160
      Width           =   375
   End
   Begin VB.TextBox TextMask4 
      Height          =   270
      Left            =   1800
      TabIndex        =   13
      Text            =   "0"
      Top             =   2160
      Width           =   375
   End
   Begin VB.TextBox TextIP4 
      Height          =   270
      Left            =   1800
      TabIndex        =   12
      Text            =   "90"
      Top             =   1440
      Width           =   375
   End
   Begin VB.TextBox TextIP3 
      Height          =   270
      Left            =   1240
      TabIndex        =   11
      Text            =   "168"
      Top             =   1440
      Width           =   375
   End
   Begin VB.TextBox TextIP2 
      Height          =   270
      Left            =   680
      TabIndex        =   10
      Text            =   "168"
      Top             =   1440
      Width           =   375
   End
   Begin VB.TextBox TextIP1 
      Height          =   270
      Left            =   120
      TabIndex        =   8
      Text            =   "192"
      Top             =   1440
      Width           =   375
   End
   Begin VB.TextBox TextSN 
      Height          =   375
      Left            =   600
      TabIndex        =   3
      Text            =   "39990"
      Top             =   240
      Width           =   1095
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Exit"
      Height          =   375
      Left            =   360
      TabIndex        =   2
      Top             =   4200
      Width           =   1095
   End
   Begin VB.TextBox Text1 
      Height          =   7815
      Left            =   2280
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   1
      Top             =   120
      Width           =   7455
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Test"
      Height          =   375
      Left            =   360
      TabIndex        =   0
      Top             =   3720
      Width           =   1095
   End
   Begin VB.Label Label7 
      Caption         =   ".     .     .    ."
      Height          =   375
      Left            =   570
      TabIndex        =   22
      Top             =   3105
      Width           =   2040
   End
   Begin VB.Label Label6 
      Caption         =   ".     .     .    ."
      Height          =   375
      Left            =   570
      TabIndex        =   17
      Top             =   2265
      Width           =   2040
   End
   Begin VB.Label Label5 
      Caption         =   ".     .     .    ."
      Height          =   375
      Left            =   570
      TabIndex        =   9
      Top             =   1545
      Width           =   2040
   End
   Begin VB.Label Label4 
      Caption         =   "Gateway:"
      Height          =   255
      Left            =   120
      TabIndex        =   7
      Top             =   2640
      Width           =   1095
   End
   Begin VB.Label Label3 
      Caption         =   "Mask:"
      Height          =   255
      Left            =   120
      TabIndex        =   6
      Top             =   1920
      Width           =   1095
   End
   Begin VB.Label Label2 
      Caption         =   "New IP:"
      Height          =   255
      Left            =   120
      TabIndex        =   5
      Top             =   1200
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "SN:"
      Height          =   375
      Left            =   240
      TabIndex        =   4
      Top             =   360
      Width           =   495
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long) '��ʱ

Private Sub Command1_Click()
        '.NETͨ�Ų��� (�������controllerSN����)
        Dim wudp As WComm_UDP.WComm_Operate '����UDP����
        Dim strFrame As String      '���ص�����
        Dim strCmd As String        'Ҫ���͵�ָ��֡
        Dim ret    As Long          '�����ķ���ֵ
        Dim controllerSN As Long    '���������к�
        
        'ˢ����¼����
        Dim cardId As Long          '����
        Dim status As Long          '״̬
        Dim swipeDate As String     '����ʱ��
        
        Dim strRunDetail As String  '������Ϣ
        
        Dim ipAddr As String        'ip��ַ
        Dim strMac As String        'MAC��ַ
        Dim strHexNewIP As String   'New IP (ʮ������)
        Dim strHexMask As String    '����(ʮ������)
        Dim strHexGateway As String '����(ʮ������)
     
        Set wudp = New WComm_UDP.WComm_Operate  '�½�
        
        controllerSN = Me.TextSN.Text         '����ʹ�õ�.NET������
        ipAddr = ""                 'Ϊ��, ��ʾ�㲥����ʽ
        
        Me.Text1.Text = "������ͨ��" & "-" & controllerSN & "-.NET"
       
        '��ȡ����״̬��Ϣ
        strCmd = wudp.CreateBstrCommand(controllerSN, "8110" & wudp.NumToStrHex(0, 3)) '����ָ��֡ wudp.NumToStrHex(0,3) ��ʾ��0����¼, Ҳ�����¼�¼
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                                '����ָ��, ����ȡ������Ϣ

        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ȡ������Ϣʧ��"
            Set wudp = Nothing
            Exit Sub
        Else
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ȡ������Ϣ�ɹ�"

            '��������Ϣ����ϸ����
            '�������ĵ�ǰʱ��
            strRunDetail = ""
            strRunDetail = strRunDetail & vbCrLf & "�豸���к�S/N: " & vbTab & wudp.GetSNFromRunInfo(strFrame)
            strRunDetail = strRunDetail & vbCrLf & "�豸ʱ��:      " & vbTab & wudp.GetClockTimeFromRunInfo(strFrame)
            strRunDetail = strRunDetail & vbCrLf & "ˢ����¼��:    " & vbTab & wudp.GetCardRecordCountFromRunInfo(strFrame)
            strRunDetail = strRunDetail & vbCrLf & "Ȩ����:        " & vbTab & wudp.GetPrivilegeNumFromRunInfo(strFrame)
            strRunDetail = strRunDetail & vbCrLf & vbCrLf & "�����һ��ˢ����¼: " & vbTab
            swipeDate = wudp.GetSwipeDateFromRunInfo(strFrame, cardId, status)

            If swipeDate <> "" Then
                  strRunDetail = strRunDetail & vbCrLf & "����: " & cardId & vbTab & " ״̬:" & vbTab & status & "(" & wudp.NumToStrHex(status, 1) & ")" & vbTab & "ʱ��:" & vbTab & swipeDate
            End If

            '�ŴŰ�ť״̬
            'Bitλ     7     6       5       4        3       2       1       0
            '˵��   �Ŵ�4   �Ŵ�3   �Ŵ�2   �Ŵ�1   ��ť4   ��ť3   ��ť2   ��ť1
            strRunDetail = strRunDetail & vbCrLf & "�Ŵ�״̬  1���Ŵ� 2���Ŵ� 3���Ŵ� 4���Ŵ�"
            strRunDetail = strRunDetail & vbCrLf
            strRunDetail = strRunDetail & "          "
            If wudp.GetDoorStatusFromRunInfo(strFrame, 1) = 1 Then
                strRunDetail = strRunDetail & "   ��   "
            Else
                strRunDetail = strRunDetail & "   ��   "
            End If
            If wudp.GetDoorStatusFromRunInfo(strFrame, 2) = 1 Then
                strRunDetail = strRunDetail & "   ��   "
            Else
                strRunDetail = strRunDetail & "   ��   "
            End If
            If wudp.GetDoorStatusFromRunInfo(strFrame, 3) = 1 Then
                strRunDetail = strRunDetail & "   ��   "
            Else
                strRunDetail = strRunDetail & "   ��   "
            End If
            If wudp.GetDoorStatusFromRunInfo(strFrame, 4) = 1 Then
                strRunDetail = strRunDetail & "   ��   "
            Else
                strRunDetail = strRunDetail & "   ��   "
            End If

            strRunDetail = strRunDetail & vbCrLf
            strRunDetail = strRunDetail & "��ť״̬  1�Ű�ť 2�Ű�ť 3�Ű�ť 4�Ű�ť"
            strRunDetail = strRunDetail & vbCrLf
            strRunDetail = strRunDetail & "          "
            If wudp.GetButtonStatusFromRunInfo(strFrame, 1) = 1 Then
                strRunDetail = strRunDetail & " �ɿ�   "
            Else
                strRunDetail = strRunDetail & " ����   "
            End If
            If wudp.GetButtonStatusFromRunInfo(strFrame, 2) = 1 Then
                strRunDetail = strRunDetail & " �ɿ�   "
            Else
                strRunDetail = strRunDetail & " ����   "
            End If
            If wudp.GetButtonStatusFromRunInfo(strFrame, 3) = 1 Then
                strRunDetail = strRunDetail & " �ɿ�   "
            Else
                strRunDetail = strRunDetail & " ����   "
            End If
            If wudp.GetButtonStatusFromRunInfo(strFrame, 4) = 1 Then
                strRunDetail = strRunDetail & " �ɿ�   "
            Else
                strRunDetail = strRunDetail & " ����   "
            End If

            strRunDetail = strRunDetail & vbCrLf & "����״̬:" & vbTab
            Dim errorNo As Integer
            errorNo = wudp.GetErrorNoFromRunInfo(strFrame)
            If errorNo = 0 Then
                strRunDetail = strRunDetail & " �޹���   "
            Else
                strRunDetail = strRunDetail & " �й���  "
                If (errorNo And 1) Then
                    strRunDetail = strRunDetail & vbCrLf & "        " & vbTab & "ϵͳ����1"
                End If
                If errorNo And 2 Then
                    strRunDetail = strRunDetail & vbCrLf & "        " & vbTab & "ϵͳ����2"
                End If
                If errorNo And 4 Then
                    strRunDetail = strRunDetail & vbCrLf & "        " & vbTab & "ϵͳ����3[�豸ʱ���й���], ��У��ʱ�Ӵ���"
                End If
                If errorNo And 8 Then
                    strRunDetail = strRunDetail & vbCrLf & "        " & vbTab & "ϵͳ����4"
                End If
            End If
            Me.Text1.Text = Me.Text1.Text & strRunDetail
        End If

        DoEvents
        
        '��ѯ��������IP����
        '��ȡ����������Ϣָ��
        strCmd = wudp.CreateBstrCommand(controllerSN, "0111")  '����ָ��֡ ��ȡ����������Ϣָ��
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                     '����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
             'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            
            Set wudp = Nothing
            Exit Sub
        Else
            Dim startLoc As Integer
            Dim deviceInfo As String
            '
            deviceInfo = ""

            'MAC
            startLoc = 11
            deviceInfo = deviceInfo & vbCrLf & "MAC:" & vbTab & vbTab & (Mid$(strFrame, startLoc, 2))
            deviceInfo = deviceInfo & "-" & (Mid$(strFrame, startLoc + 2, 2))
            deviceInfo = deviceInfo & "-" & (Mid$(strFrame, startLoc + 4, 2))
            deviceInfo = deviceInfo & "-" & (Mid$(strFrame, startLoc + 6, 2))
            deviceInfo = deviceInfo & "-" & (Mid$(strFrame, startLoc + 8, 2))
            deviceInfo = deviceInfo & "-" & (Mid$(strFrame, startLoc + 10, 2))
            strMac = (Mid$(strFrame, startLoc, 12))

            'IP
            startLoc = 23
            deviceInfo = deviceInfo & vbCrLf & "IP:" & vbTab & vbTab & CLng("&H" & (Mid$(strFrame, startLoc, 2)))
            deviceInfo = deviceInfo & "." & CLng("&H" & (Mid$(strFrame, startLoc + 2, 2)))
            deviceInfo = deviceInfo & "." & CLng("&H" & (Mid$(strFrame, startLoc + 4, 2)))
            deviceInfo = deviceInfo & "." & CLng("&H" & (Mid$(strFrame, startLoc + 6, 2)))

            'Subnet Mask
            startLoc = 31
            deviceInfo = deviceInfo & vbCrLf & "��������:" & vbTab & CLng("&H" & (Mid$(strFrame, startLoc, 2)))
            deviceInfo = deviceInfo & "." & CLng("&H" & (Mid$(strFrame, startLoc + 2, 2)))
            deviceInfo = deviceInfo & "." & CLng("&H" & (Mid$(strFrame, startLoc + 4, 2)))
            deviceInfo = deviceInfo & "." & CLng("&H" & (Mid$(strFrame, startLoc + 6, 2)))

            'Default Gateway
            startLoc = 39
            deviceInfo = deviceInfo & vbCrLf & "����:" & vbTab & vbTab & CLng("&H" & (Mid$(strFrame, startLoc, 2)))
            deviceInfo = deviceInfo & "." & CLng("&H" & (Mid$(strFrame, startLoc + 2, 2)))
            deviceInfo = deviceInfo & "." & CLng("&H" & (Mid$(strFrame, startLoc + 4, 2)))
            deviceInfo = deviceInfo & "." & CLng("&H" & (Mid$(strFrame, startLoc + 6, 2)))

            'UDP Port
            startLoc = 47
            deviceInfo = deviceInfo & vbCrLf & "PORT:" & vbTab & vbTab & CLng("&H" & (Mid$(strFrame, startLoc + 2, 2)) & (Mid$(strFrame, startLoc, 2)))
            Me.Text1.Text = Me.Text1.Text & (vbCrLf & deviceInfo & vbCrLf)
        End If
      
        Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ʼIP��ַ����: " & vbCrLf & "IP 192.168.168.90/Mask 255.255.255.0/Gateway 192.168.168.254: Port 60000"
        
        DoEvents
        
       '�µ�IP����: (MAC����) IP��ַ: 192.168.168.90; ����: 255.255.255.0; ����: 192.168.168.254; �˿�: 60000
        strHexNewIP = wudp.NumToStrHex(Me.TextIP1.Text, 1) & wudp.NumToStrHex(Me.TextIP2.Text, 1) & wudp.NumToStrHex(Me.TextIP3.Text, 1) & wudp.NumToStrHex(Me.TextIP4.Text, 1)
        strHexMask = wudp.NumToStrHex(Me.TextMask1.Text, 1) & wudp.NumToStrHex(Me.TextMask2.Text, 1) & wudp.NumToStrHex(Me.TextMask3.Text, 1) & wudp.NumToStrHex(Me.TextMask4.Text, 1)
        strHexGateway = wudp.NumToStrHex(Me.TextGateway1.Text, 1) & wudp.NumToStrHex(Me.TextGateway2.Text, 1) & wudp.NumToStrHex(Me.TextGateway3.Text, 1) & wudp.NumToStrHex(Me.TextGateway4.Text, 1)
        
        strCmd = wudp.CreateBstrCommand(controllerSN, "F211" & strMac & strHexNewIP & strHexMask & strHexGateway & "60EA")     '����ָ��֡ ��ȡ����������Ϣָ��
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)       '����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)

            Set wudp = Nothing
            Exit Sub
        Else
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "IP��ַ�������...Ҫ�ȴ�3����, ���Ժ�"
            DoEvents
            Sleep (3000) '����3����ʱ
            ret = MsgBox("IP��ַ�������", vbOKOnly)
        End If

        '�����µ�IP��ַ����ͨ��
       ' ipAddr = "192.168.168.90"
        ipAddr = Me.TextIP1.Text & "." & Me.TextIP2.Text & "." & Me.TextIP3.Text & "." & Me.TextIP4.Text
        Me.Text1.Text = Me.Text1.Text & vbCrLf & "�����µ�IP��ַ����ͨ��" & ipAddr
        Me.Text1.Text = Me.Text1.Text & vbCrLf
        
       
        'У׼������ʱ��
        strCmd = wudp.CreateBstrCommandOfAdjustClockByPCTime(controllerSN) '����ָ��֡
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                    '����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            
            Set wudp = Nothing
            Exit Sub
        Else
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "У׼������ʱ��ɹ�"
        End If
        
        
        'Զ�̿�1����
        strCmd = wudp.CreateBstrCommand(controllerSN, "9D10" & "01") '����ָ��֡
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)              '����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            
            Set wudp = Nothing
            Exit Sub
        Else
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "Զ�̿��ųɹ�"
        End If
        
        
        '��ȡ��¼
        Dim recIndex As Long    '��¼������
        recIndex = 1
        Do While (True)
            strCmd = wudp.CreateBstrCommand(controllerSN, "8D10" & wudp.NumToStrHex(recIndex, 4))       '����ָ��֡ 8D10Ϊ��ȡ��¼ָ��
            strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                           '����ָ��, ����ȡ������Ϣ
            If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
                'û���յ�����,
                'ʧ�ܴ������... (��ErrCode����Է�������)
                '�û��ɿ�������
                Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ȡ��¼����"
                
                Set wudp = Nothing
                Exit Sub
            Else
                swipeDate = wudp.GetSwipeDateFromRunInfo(strFrame, cardId, status)
    
                If swipeDate <> "" Then
                    strRunDetail = "����: " & cardId & vbTab & " ״̬:" & vbTab & status & "(" & wudp.NumToStrHex(status, 1) & ")" & vbTab & "ʱ��:" & vbTab & swipeDate
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & strRunDetail
                    recIndex = recIndex + 1                          '��һ����¼
                Else
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ȡ��¼���. �ܹ���ȡ��¼�� =" & (recIndex - 1)
                    Exit Do
                End If
                Me.Text1.SelStart = Len(Me.Text1.Text)              '��ʾ������
             End If
             DoEvents            'VB.NETʹ��Application.DoEvents()
        Loop
        
        
        'ɾ������ȡ�ļ�¼
        If (recIndex > 1) Then  'ֻ����ȡ�˼�¼�Ž���ɾ��
            If MsgBox("�Ƿ�ɾ��������������ȡ�ļ�¼: " & (recIndex - 1) & "��", vbYesNo) = vbYes Then
                strCmd = wudp.CreateBstrCommand(controllerSN, "8E10" & wudp.NumToStrHex(recIndex - 1, 4)) '����ָ��֡
                strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                                           '����ָ��, ����ȡ������Ϣ
                If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
                    'û���յ�����,
                    'ʧ�ܴ������... (��ErrCode����Է�������)
                    '�û��ɿ�������
                  
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & "ɾ����¼ʧ��"
                    Set wudp = Nothing
                    Exit Sub
                Else
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & "ɾ����¼�ɹ�"
                End If
            End If
        End If
        
        '����Ȩ�޲���(1.�����Ȩ��)
        strCmd = wudp.CreateBstrCommand(controllerSN, "9310") '����ָ��֡
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)       '����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            '�û��ɿ�������
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "���Ȩ��ʧ��"
            Set wudp = Nothing
            Exit Sub
        Else
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "���Ȩ�޳ɹ�"
        End If

        '����Ȩ�޲���(2.�����Ȩ��)
        'Ȩ�޸�ʽ: ���ţ�2��+���ţ�1��+�źţ�1��+����ʼ�����գ�2��+����ֹ�����գ�2��+ ����ʱ�������ţ�1��+���루3��+���ã�4����0��䣩
        '����Ȩ�ް�: �ȷ�1����(����С���ȷ�), �ٷ�2����(����С���ȷ�)
        '�˰�����Ȩ����Ϊ: ����Ч�ڴ�(2007-8-14 ��2020-12-31), ����Ĭ��ʱ��1(����ʱ����Ч), ȱʡ����(1234), ����ֵ��00���
        '���������� 07217564 [9C4448]��342681[B9A603]��25409969[F126FE]Ϊ�����ֱ����ͨ����������2���š�
        'ʵ��ʹ�ð����޸�
        Dim doorIndex As Long
        Dim cardno(2) As Long
        Dim privilege As String
        Dim privilegeIndex As Long 'Ȩ������λ
        
        '!!!!!!!ע��:  �˴�������ֱ�Ӱ���С�������и�ֵ��. ʵ��ʹ����Ҫ���㷨ʵ������
        cardno(0) = 342681
        cardno(1) = 7217564
        cardno(2) = 25409969
        privilegeIndex = 1
        For doorIndex = 0 To 1
            Dim cardIndex As Long
            For cardIndex = 0 To 2
                privilege = ""
                privilege = wudp.CardToStrHex(cardno(cardIndex))                   '����
                privilege = privilege & wudp.NumToStrHex(doorIndex + 1, 1)         '�ź�
                privilege = privilege & wudp.MSDateYmdToWCDateYmd("2007-8-14")     '��Ч��ʼ����
                privilege = privilege & wudp.MSDateYmdToWCDateYmd("2020-12-31")    '��Ч��ֹ����
                privilege = privilege & wudp.NumToStrHex(1, 1)                     'ʱ��������
                privilege = privilege & wudp.NumToStrHex(123456, 3)                '�û�����
                privilege = privilege & wudp.NumToStrHex(0, 4)                     '����4�ֽ�(��0���)
                If (Len(privilege) <> (16 * 2)) Then
                    '���ɵ�Ȩ�޲�����Ҫ��, ���һ����һָ����д���ÿ�������Ƿ���ȷ
                    Set wudp = Nothing
                    Exit Sub
                End If
                strCmd = wudp.CreateBstrCommand(controllerSN, "9B10" & wudp.NumToStrHex(privilegeIndex, 2) & privilege) '����ָ��֡
                strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                                                         '����ָ��, ����ȡ������Ϣ
            
                If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
                    'û���յ�����,
                    'ʧ�ܴ������... (��ErrCode����Է�������)
                    '�û��ɿ�������
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & "���Ȩ��ʧ��"
                    Set wudp = Nothing
                    Exit Sub
                Else
                    privilegeIndex = privilegeIndex + 1
                End If
            Next cardIndex
        Next doorIndex
        Me.Text1.Text = Me.Text1.Text & vbCrLf & "���Ȩ���� = " & (privilegeIndex - 1)
        
        
        '���Ϳ���ʱ��
        '����Ҫ�趨��ʱ�� [ע��0,1ʱ��Ϊϵͳ�̶���,��������Ч��, �����趨��ʱ��һ���2��ʼ]
        '�˰����趨ʱ��2: ��2007-8-1��2007-12-31��
        ' ����1��5������7:30-12:30, 13:30-17:30, 19:00-21:00ͨ��, ����ʱ�䲻����
        Dim timeseg As String
        timeseg = ""
        timeseg = timeseg & wudp.NumToStrHex(&H1F, 1)    '���ڿ���
        timeseg = timeseg & wudp.NumToStrHex(0, 1)       ' ��һ����ʱ��(0--��ʾ��)
        timeseg = timeseg & wudp.NumToStrHex(0, 2)       ' ����2�ֽ�(0���)
        timeseg = timeseg & wudp.MSDateHmsToWCDateHms("07:30:00")       ' ��ʼʱ����1
        timeseg = timeseg & wudp.MSDateHmsToWCDateHms("12:30:00")       ' ��ֹʱ����1
        timeseg = timeseg & wudp.MSDateHmsToWCDateHms("13:30:00")       ' ��ʼʱ����2
        timeseg = timeseg & wudp.MSDateHmsToWCDateHms("17:30:00")       ' ��ֹʱ����2
        timeseg = timeseg & wudp.MSDateHmsToWCDateHms("19:00:00")       ' ��ʼʱ����3
        timeseg = timeseg & wudp.MSDateHmsToWCDateHms("21:00:00")       ' ��ֹʱ����3
        timeseg = timeseg & wudp.MSDateYmdToWCDateYmd("2007-08-01")     ' ��ʼ����
        timeseg = timeseg & wudp.MSDateYmdToWCDateYmd("2007-12-31")     ' ��ֹ����
        timeseg = timeseg & wudp.NumToStrHex(0, 4)                      ' ����4�ֽ�(0���)
        If (Len(timeseg) <> (24 * 2)) Then
            '���ɵ�ʱ�β�����Ҫ��, ���һ����һָ����д���ÿ�������Ƿ���ȷ
            Set wudp = Nothing
            Exit Sub
        End If
        strCmd = wudp.CreateBstrCommand(controllerSN, "9710" & wudp.NumToStrHex(2, 2) & timeseg) '����ָ��֡
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                                          '����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            '�û��ɿ�������
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "���ʱ��ʧ��"
            Set wudp = Nothing
            Exit Sub
        Else
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "���ʱ�γɹ�"
        End If
        
        'ʵʱ���
       ' ��ȡ����״̬��ʵ�ּ�صĹؼ�ָ� �ڽ��м��ʱ, �ȶ�ȡ���¼�¼����λ�ļ�¼. ��ȡ�����µļ�¼�� ͬʱ���Ի�ȡ��ˢ����¼����
       ' ��ʱ�Ϳ����ö�ȡ��ˢ����¼����1��䵽Ҫ��ȡ�����¼�¼����λ�ϣ�ȥ��ȡ����״̬�� �Ա��ȡ��һ����¼��
       ' �����ȡ�����µ�ˢ����¼�� �Ϳ��Խ�����λ��1�� ���򱣳�����λ���䡣 �����Ϳ���ʵ�����ݵ�ʵʱ��ء�
       ' ����ͨ�Ų��ϵĴ�����ʱ�ɶԴ���ͨ�Ų�ȡ��ʱ400-500������Ϊ����������һ�Σ��ٽ��ղ������ݣ� ����Ϊ�豸��PC����Ĳ���ͨ�š�
       Dim watchIndex As Long
       Dim recCnt As Long
       watchIndex = 0                      'ȱʡ��0, ��ʾ����ȡ���һ����¼
       recCnt = 0                          '��ؼ�¼����
       Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ʼʵʱ���....(��ˢ��3��)"
       DoEvents
       Do While (recCnt < 3)        '������ ����3����ֹͣ
            strCmd = wudp.CreateBstrCommand(controllerSN, "8110" & wudp.NumToStrHex(watchIndex, 3)) '����ָ��֡ wudp.NumToStrHex(watchIndex,3) ��ʾ��watchIndex����¼, �����0��ȡ����һ����¼
            strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                                         '����ָ��, ����ȡ������Ϣ
            If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
                'û���յ�����,
                'ʧ�ܴ������... (��ErrCode����Է�������)
                Set wudp = Nothing
                Exit Sub
            Else
                swipeDate = wudp.GetSwipeDateFromRunInfo(strFrame, cardId, status)
                If swipeDate <> "" Then '�м�¼ʱ
                    strRunDetail = "����: " & cardId & vbTab & " ״̬:" & vbTab & status & "(" & wudp.NumToStrHex(status, 1) & ")" & vbTab & "ʱ��:" & vbTab & swipeDate
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & strRunDetail
                    Me.Text1.SelStart = Len(Me.Text1.Text)              '��ʾ������
                    If watchIndex = 0 Then                              '����յ���һ����¼
                         watchIndex = wudp.GetCardRecordCountFromRunInfo(strFrame) + 1   'ָ��(�ܼ�¼��+1), Ҳ�����´�ˢ���Ĵ洢����λ
                    Else
                         watchIndex = watchIndex + 1   'ָ����һ����¼λ
                    End If
                    recCnt = recCnt + 1                '��¼����
                End If
            End If
            DoEvents
       Loop
       Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ֹͣʵʱ���"
       Me.Text1.SelStart = Len(Me.Text1.Text)          '��ʾ������
       
       Set wudp = Nothing
End Sub

Private Sub Command2_Click()
    Unload Me
    End
End Sub

