VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   7965
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   9345
   LinkTopic       =   "Form1"
   ScaleHeight     =   7965
   ScaleWidth      =   9345
   StartUpPosition =   3  '����ȱʡ
   Begin VB.TextBox TextSerialPort 
      Height          =   375
      Left            =   480
      TabIndex        =   5
      Text            =   "COM1"
      Top             =   1200
      Width           =   1095
   End
   Begin VB.TextBox TextSN 
      Height          =   390
      Left            =   480
      TabIndex        =   4
      Text            =   "26604"
      Top             =   240
      Width           =   1095
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Exit"
      Height          =   375
      Left            =   480
      TabIndex        =   2
      Top             =   2520
      Width           =   1095
   End
   Begin VB.TextBox Text1 
      Height          =   7815
      Left            =   1800
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   1
      Top             =   120
      Width           =   7455
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Test"
      Height          =   375
      Left            =   480
      TabIndex        =   0
      Top             =   1920
      Width           =   1095
   End
   Begin VB.Label Label2 
      Caption         =   "Serial Port:"
      Height          =   375
      Left            =   120
      TabIndex        =   6
      Top             =   840
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "SN:"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   360
      Width           =   495
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
        '����ͨ�Ų��� (�������controllerSN����)
        Dim wserial As WComm_Serial.CWComm_Serial    '����COM����
        Dim wudp As WComm_UDP.WComm_Operate '����UDP����
        Dim strFrame As String      '���ص�����
        Dim strCmd As String        'Ҫ���͵�ָ��֡
        Dim ret    As Long          '�����ķ���ֵ
        Dim controllerSN As Long    '���������к�
        Dim comPort As String       'ͨ�Ŵ��ں�
        
        'ˢ����¼����
        Dim cardId As Long          '����
        Dim status As Long          '״̬
        Dim swipeDate As String     '����ʱ��
        
        Dim strRunDetail As String  '������Ϣ
        
        Set wserial = New WComm_Serial.CWComm_Serial  '��������ͨ��COM����
        Set wudp = New WComm_UDP.WComm_Operate        '�½�
        
        controllerSN = Me.TextSN.Text        '����ʹ�õĿ�����
        comPort = Me.TextSerialPort.Text             'ʹ�õ�ͨ�Ŷ˿�
        
        Me.Text1.Text = "������ͨ��" & "-" & controllerSN & "-" & comPort
       
        '��ȡ����״̬��Ϣ
        strCmd = wudp.CreateBstrCommand(controllerSN, "8110" & wudp.NumToStrHex(0, 3)) '����ָ��֡ wudp.NumToStrHex(0,3) ��ʾ��0����¼, Ҳ�����¼�¼
        strFrame = wserial.serial_comm(strCmd, comPort)                            '����ָ��, ����ȡ������Ϣ

        If ((wserial.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            Set wserial = Nothing
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
            strRunDetail = strRunDetail & vbCrLf

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

       
        'У׼������ʱ��
        strCmd = wudp.CreateBstrCommandOfAdjustClockByPCTime(controllerSN)    '����ָ��֡
        strFrame = wserial.serial_comm(strCmd, comPort)                       '����ָ��, ����ȡ������Ϣ
        If ((wserial.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            
            Set wserial = Nothing
            Set wudp = Nothing
            Exit Sub
        Else
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "У׼������ʱ��ɹ�"
        End If
        
        
        'Զ�̿�1����
        strCmd = wudp.CreateBstrCommand(controllerSN, "9D10" & "01")          '����ָ��֡
        strFrame = wserial.serial_comm(strCmd, comPort)                       '����ָ��, ����ȡ������Ϣ
        If ((wserial.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            
            Set wserial = Nothing
            Set wudp = Nothing
            Exit Sub
        Else
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "Զ�̿��ųɹ�"
        End If
        
        
        '��ȡ��¼
        Dim recIndex As Long    '��¼������
        recIndex = 1
        Do While (True)
            strCmd = wudp.CreateBstrCommand(controllerSN, "8D10" & wudp.NumToStrHex(recIndex, 4))       '����ָ��֡Ϊ��ȡ��¼ָ��
            strFrame = wserial.serial_comm(strCmd, comPort)                                             '����ָ��, ����ȡ������Ϣ
            If ((wserial.ErrCode <> 0) Or (strFrame = "")) Then
                'û���յ�����,
                'ʧ�ܴ������... (��ErrCode����Է�������)
                '�û��ɿ�������
                Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ȡ��¼����"
                
                Set wserial = Nothing
                Set wudp = Nothing
                Exit Sub
            Else
                swipeDate = wudp.GetSwipeDateFromRunInfo(strFrame, cardId, status)
    
                If swipeDate <> "" Then
                    strRunDetail = "����: " & cardId & vbTab & " ״̬:" & vbTab & status & "(" & wudp.NumToStrHex(status, 1) & ")" & vbTab & "ʱ��:" & vbTab & swipeDate
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & strRunDetail
                    recIndex = recIndex + 1                         '��һ����¼
                Else
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ȡ��¼���. �ܹ���ȡ��¼�� =" & (recIndex - 1)
                    Exit Do
                End If
                Me.Text1.SelStart = Len(Me.Text1.Text)              '��ʾ������
             End If
             DoEvents
        Loop
        
        
        'ɾ������ȡ�ļ�¼
        If (recIndex > 1) Then  'ֻ����ȡ�˼�¼�Ž���ɾ��
            If MsgBox("�Ƿ�ɾ��������������ȡ�ļ�¼: " & (recIndex - 1) & "��", vbYesNo) = vbYes Then
                strCmd = wudp.CreateBstrCommand(controllerSN, "8E10" & wudp.NumToStrHex(recIndex - 1, 4)) '����ָ��֡
                strFrame = wserial.serial_comm(strCmd, comPort)                                           '����ָ��, ����ȡ������Ϣ
                If ((wserial.ErrCode <> 0) Or (strFrame = "")) Then
                    'û���յ�����,
                    'ʧ�ܴ������... (��ErrCode����Է�������)
                    '�û��ɿ�������
                  
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & "ɾ����¼ʧ��"
                    Set wserial = Nothing
                    Set wudp = Nothing
                    Exit Sub
                Else
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & "ɾ����¼�ɹ�"
                End If
            End If
        End If
        
        '����Ȩ�޲���(1.�����Ȩ��)
        strCmd = wudp.CreateBstrCommand(controllerSN, "9310") '����ָ��֡
        strFrame = wserial.serial_comm(strCmd, comPort)       '����ָ��, ����ȡ������Ϣ
        If ((wserial.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            '�û��ɿ�������
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "���Ȩ��ʧ��"
            Set wserial = Nothing
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
                    Set wserial = Nothing
                    Set wudp = Nothing
                    Exit Sub
                End If
                strCmd = wudp.CreateBstrCommand(controllerSN, "9B10" & wudp.NumToStrHex(privilegeIndex, 2) & privilege) '����ָ��֡
                strFrame = wserial.serial_comm(strCmd, comPort)                                                         '����ָ��, ����ȡ������Ϣ
            
                If ((wserial.ErrCode <> 0) Or (strFrame = "")) Then
                    'û���յ�����,
                    'ʧ�ܴ������... (��ErrCode����Է�������)
                    '�û��ɿ�������
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & "���Ȩ��ʧ��"
                    Set wserial = Nothing
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
        timeseg = timeseg & wudp.NumToStrHex(0, 4)       ' ����4�ֽ�(0���)
        If (Len(timeseg) <> (24 * 2)) Then
            '���ɵ�ʱ�β�����Ҫ��, ���һ����һָ����д���ÿ�������Ƿ���ȷ
            Set wserial = Nothing
            Set wudp = Nothing
            Exit Sub
        End If
        strCmd = wudp.CreateBstrCommand(controllerSN, "9710" & wudp.NumToStrHex(2, 2) & timeseg) '����ָ��֡
        strFrame = wserial.serial_comm(strCmd, comPort)                                          '����ָ��, ����ȡ������Ϣ
        If ((wserial.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            '�û��ɿ�������
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "���ʱ��ʧ��"
            Set wserial = Nothing
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
            strFrame = wserial.serial_comm(strCmd, comPort)                            '����ָ��, ����ȡ������Ϣ
            If ((wserial.ErrCode <> 0) Or (strFrame = "")) Then
                'û���յ�����,
                'ʧ�ܴ������... (��ErrCode����Է�������)
                Set wserial = Nothing
                Set wudp = Nothing
                Exit Sub
            Else
                swipeDate = wudp.GetSwipeDateFromRunInfo(strFrame, cardId, status)
                If swipeDate <> "" Then      '�м�¼ʱ
                    strRunDetail = "����: " & cardId & vbTab & " ״̬:" & vbTab & status & "(" & wudp.NumToStrHex(status, 1) & ")" & vbTab & "ʱ��:" & vbTab & swipeDate
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & strRunDetail
                    Me.Text1.SelStart = Len(Me.Text1.Text)              '��ʾ�¼��������
                    If watchIndex = 0 Then                                               '����յ���һ����¼
                         watchIndex = wudp.GetCardRecordCountFromRunInfo(strFrame) + 1   'ָ��(�ܼ�¼��+1), Ҳ�����´�ˢ���Ĵ洢����λ
                    Else
                         watchIndex = watchIndex + 1  'ָ����һ����¼λ
                    End If
                    recCnt = recCnt + 1               '��¼����
                End If
            End If
            DoEvents
       Loop
       Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ֹͣʵʱ���"
       Me.Text1.SelStart = Len(Me.Text1.Text)             '��ʾ������
    
       Set wserial = Nothing
       Set wudp = Nothing
End Sub

Private Sub Command2_Click()
    Unload Me
    End
End Sub
