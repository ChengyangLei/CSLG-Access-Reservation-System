Public Class Form1
    Inherits System.Windows.Forms.Form

#Region " Windows ������������ɵĴ��� "

    Public Sub New()
        MyBase.New()

        '�õ����� Windows ���������������ġ�
        InitializeComponent()

        '�� InitializeComponent() ����֮������κγ�ʼ��

    End Sub

    '������д dispose ����������б�
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Windows ����������������
    Private components As System.ComponentModel.IContainer

    'ע��: ���¹����� Windows ����������������
    '����ʹ�� Windows ����������޸Ĵ˹��̡�
    '��Ҫʹ�ô���༭���޸�����
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents Text1 As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents TextBoxIP1 As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxIP2 As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxIP3 As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxIP4 As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxMask1 As System.Windows.Forms.TextBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents TextBoxMask2 As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxMask3 As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxMask4 As System.Windows.Forms.TextBox
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents TextBoxGateway1 As System.Windows.Forms.TextBox
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents TextBoxGateway2 As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxGateway3 As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxGateway4 As System.Windows.Forms.TextBox
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents TextBoxSN As System.Windows.Forms.TextBox
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.Button1 = New System.Windows.Forms.Button
        Me.Button2 = New System.Windows.Forms.Button
        Me.Text1 = New System.Windows.Forms.TextBox
        Me.TextBoxIP1 = New System.Windows.Forms.TextBox
        Me.Label1 = New System.Windows.Forms.Label
        Me.TextBoxSN = New System.Windows.Forms.TextBox
        Me.Label2 = New System.Windows.Forms.Label
        Me.TextBoxIP2 = New System.Windows.Forms.TextBox
        Me.TextBoxIP3 = New System.Windows.Forms.TextBox
        Me.TextBoxIP4 = New System.Windows.Forms.TextBox
        Me.Label3 = New System.Windows.Forms.Label
        Me.TextBoxMask1 = New System.Windows.Forms.TextBox
        Me.Label4 = New System.Windows.Forms.Label
        Me.TextBoxMask2 = New System.Windows.Forms.TextBox
        Me.TextBoxMask3 = New System.Windows.Forms.TextBox
        Me.TextBoxMask4 = New System.Windows.Forms.TextBox
        Me.Label5 = New System.Windows.Forms.Label
        Me.TextBoxGateway1 = New System.Windows.Forms.TextBox
        Me.Label6 = New System.Windows.Forms.Label
        Me.TextBoxGateway2 = New System.Windows.Forms.TextBox
        Me.TextBoxGateway3 = New System.Windows.Forms.TextBox
        Me.TextBoxGateway4 = New System.Windows.Forms.TextBox
        Me.Label7 = New System.Windows.Forms.Label
        Me.SuspendLayout()
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(32, 256)
        Me.Button1.Name = "Button1"
        Me.Button1.TabIndex = 1
        Me.Button1.Text = "Test"
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(32, 296)
        Me.Button2.Name = "Button2"
        Me.Button2.TabIndex = 2
        Me.Button2.Text = "Exit"
        '
        'Text1
        '
        Me.Text1.Location = New System.Drawing.Point(152, 16)
        Me.Text1.Multiline = True
        Me.Text1.Name = "Text1"
        Me.Text1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical
        Me.Text1.Size = New System.Drawing.Size(488, 424)
        Me.Text1.TabIndex = 0
        Me.Text1.Text = ""
        '
        'TextBoxIP1
        '
        Me.TextBoxIP1.Location = New System.Drawing.Point(8, 88)
        Me.TextBoxIP1.Name = "TextBoxIP1"
        Me.TextBoxIP1.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxIP1.TabIndex = 9
        Me.TextBoxIP1.Text = "192"
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(8, 40)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(29, 23)
        Me.Label1.TabIndex = 8
        Me.Label1.Text = "SN:"
        '
        'TextBoxSN
        '
        Me.TextBoxSN.Location = New System.Drawing.Point(40, 32)
        Me.TextBoxSN.Name = "TextBoxSN"
        Me.TextBoxSN.Size = New System.Drawing.Size(64, 21)
        Me.TextBoxSN.TabIndex = 6
        Me.TextBoxSN.Text = "39990"
        '
        'Label2
        '
        Me.Label2.Location = New System.Drawing.Point(8, 68)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(88, 16)
        Me.Label2.TabIndex = 7
        Me.Label2.Text = "New IP:"
        '
        'TextBoxIP2
        '
        Me.TextBoxIP2.Location = New System.Drawing.Point(42, 88)
        Me.TextBoxIP2.Name = "TextBoxIP2"
        Me.TextBoxIP2.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxIP2.TabIndex = 9
        Me.TextBoxIP2.Text = "168"
        '
        'TextBoxIP3
        '
        Me.TextBoxIP3.Location = New System.Drawing.Point(78, 88)
        Me.TextBoxIP3.Name = "TextBoxIP3"
        Me.TextBoxIP3.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxIP3.TabIndex = 9
        Me.TextBoxIP3.Text = "168"
        '
        'TextBoxIP4
        '
        Me.TextBoxIP4.Location = New System.Drawing.Point(114, 88)
        Me.TextBoxIP4.Name = "TextBoxIP4"
        Me.TextBoxIP4.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxIP4.TabIndex = 9
        Me.TextBoxIP4.Text = "90"
        '
        'Label3
        '
        Me.Label3.Location = New System.Drawing.Point(32, 96)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(104, 24)
        Me.Label3.TabIndex = 7
        Me.Label3.Text = ".     .     ."
        '
        'TextBoxMask1
        '
        Me.TextBoxMask1.Location = New System.Drawing.Point(8, 144)
        Me.TextBoxMask1.Name = "TextBoxMask1"
        Me.TextBoxMask1.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxMask1.TabIndex = 14
        Me.TextBoxMask1.Text = "255"
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(8, 124)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(88, 16)
        Me.Label4.TabIndex = 10
        Me.Label4.Text = "Mask:"
        '
        'TextBoxMask2
        '
        Me.TextBoxMask2.Location = New System.Drawing.Point(42, 144)
        Me.TextBoxMask2.Name = "TextBoxMask2"
        Me.TextBoxMask2.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxMask2.TabIndex = 15
        Me.TextBoxMask2.Text = "255"
        '
        'TextBoxMask3
        '
        Me.TextBoxMask3.Location = New System.Drawing.Point(78, 144)
        Me.TextBoxMask3.Name = "TextBoxMask3"
        Me.TextBoxMask3.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxMask3.TabIndex = 13
        Me.TextBoxMask3.Text = "255"
        '
        'TextBoxMask4
        '
        Me.TextBoxMask4.Location = New System.Drawing.Point(114, 144)
        Me.TextBoxMask4.Name = "TextBoxMask4"
        Me.TextBoxMask4.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxMask4.TabIndex = 12
        Me.TextBoxMask4.Text = "0"
        '
        'Label5
        '
        Me.Label5.Location = New System.Drawing.Point(32, 152)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(104, 24)
        Me.Label5.TabIndex = 11
        Me.Label5.Text = ".     .     ."
        '
        'TextBoxGateway1
        '
        Me.TextBoxGateway1.Location = New System.Drawing.Point(8, 192)
        Me.TextBoxGateway1.Name = "TextBoxGateway1"
        Me.TextBoxGateway1.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxGateway1.TabIndex = 20
        Me.TextBoxGateway1.Text = "192"
        '
        'Label6
        '
        Me.Label6.Location = New System.Drawing.Point(8, 171)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(88, 16)
        Me.Label6.TabIndex = 16
        Me.Label6.Text = "Gateway:"
        '
        'TextBoxGateway2
        '
        Me.TextBoxGateway2.Location = New System.Drawing.Point(42, 192)
        Me.TextBoxGateway2.Name = "TextBoxGateway2"
        Me.TextBoxGateway2.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxGateway2.TabIndex = 21
        Me.TextBoxGateway2.Text = "168"
        '
        'TextBoxGateway3
        '
        Me.TextBoxGateway3.Location = New System.Drawing.Point(78, 192)
        Me.TextBoxGateway3.Name = "TextBoxGateway3"
        Me.TextBoxGateway3.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxGateway3.TabIndex = 19
        Me.TextBoxGateway3.Text = "168"
        '
        'TextBoxGateway4
        '
        Me.TextBoxGateway4.Location = New System.Drawing.Point(114, 192)
        Me.TextBoxGateway4.Name = "TextBoxGateway4"
        Me.TextBoxGateway4.Size = New System.Drawing.Size(24, 21)
        Me.TextBoxGateway4.TabIndex = 18
        Me.TextBoxGateway4.Text = "254"
        '
        'Label7
        '
        Me.Label7.Location = New System.Drawing.Point(32, 200)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(104, 24)
        Me.Label7.TabIndex = 17
        Me.Label7.Text = ".     .     ."
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(6, 14)
        Me.ClientSize = New System.Drawing.Size(648, 454)
        Me.Controls.Add(Me.TextBoxGateway1)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.TextBoxGateway2)
        Me.Controls.Add(Me.TextBoxGateway3)
        Me.Controls.Add(Me.TextBoxGateway4)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.TextBoxMask1)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.TextBoxMask2)
        Me.Controls.Add(Me.TextBoxMask3)
        Me.Controls.Add(Me.TextBoxMask4)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.TextBoxIP1)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.TextBoxSN)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Text1)
        Me.Controls.Add(Me.TextBoxIP2)
        Me.Controls.Add(Me.TextBoxIP3)
        Me.Controls.Add(Me.TextBoxIP4)
        Me.Controls.Add(Me.Label3)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Me.Close()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        '.NETͨ�Ų��� (�������controllerSN����)
        Dim wudp As WComm_UDP.WComm_Operate '����UDP����
        Dim strFrame As String      '���ص�����
        Dim strCmd As String        'Ҫ���͵�ָ��֡
        Dim ret As Long             '�����ķ���ֵ
        Dim controllerSN As Long    '���������к�

        'ˢ����¼����
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

        wudp = New WComm_UDP.WComm_Operate      '�½�

        controllerSN = System.Convert.ToInt64(Me.TextBoxSN.Text)          '����ʹ�õ�.NET������
        ipAddr = ""                 'Ϊ��, ��ʾ�㲥����ʽ

        Me.Text1.Text = "������ͨ��" & "-" & controllerSN & "-.NET"

        '��ȡ����״̬��Ϣ
        strCmd = wudp.CreateBstrCommand(controllerSN, "8110" & wudp.NumToStrHex(0, 3)) '����ָ��֡ wudp.NumToStrHex(0,3) ��ʾ��0����¼, Ҳ�����¼�¼
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                                '����ָ��, ����ȡ������Ϣ

        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)

            wudp = Nothing
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

        Application.DoEvents()

        '��ѯ��������IP����
        '��ȡ����������Ϣָ��
        strCmd = wudp.CreateBstrCommand(controllerSN, "0111")  '����ָ��֡ ��ȡ����������Ϣָ��
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                     '����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)

            wudp = Nothing
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


        Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ʼIP��ַ����: " 
        Application.DoEvents()

        '�µ�IP����: (MAC����) IP��ַ: 192.168.168.90; ����: 255.255.255.0; ����: 192.168.168.254; �˿�: 60000
        strHexNewIP = wudp.NumToStrHex(Me.TextBoxIP1.Text, 1) & wudp.NumToStrHex(Me.TextBoxIP2.Text, 1) & wudp.NumToStrHex(Me.TextBoxIP3.Text, 1) & wudp.NumToStrHex(Me.TextBoxIP4.Text, 1)
        strHexMask = wudp.NumToStrHex(Me.TextBoxMask1.Text, 1) & wudp.NumToStrHex(Me.TextBoxMask2.Text, 1) & wudp.NumToStrHex(Me.TextBoxMask3.Text, 1) & wudp.NumToStrHex(Me.TextBoxMask4.Text, 1)
        strHexGateway = wudp.NumToStrHex(Me.TextBoxGateway1.Text, 1) & wudp.NumToStrHex(Me.TextBoxGateway2.Text, 1) & wudp.NumToStrHex(Me.TextBoxGateway3.Text, 1) & wudp.NumToStrHex(Me.TextBoxGateway4.Text, 1)

        strCmd = wudp.CreateBstrCommand(controllerSN, "F211" & strMac & strhexnewip & strhexmask & strhexgateway &  "60EA")    '����ָ��֡ ��ȡ����������Ϣָ��

        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)       '����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)

            wudp = Nothing
            Exit Sub
        Else
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "IP��ַ�������...Ҫ�ȴ�3����, ���Ժ�"
            Application.DoEvents()
            System.Threading.Thread.Sleep(3000)  '����3����ʱ
            ret = MsgBox("IP��ַ�������", vbOKOnly)
        End If

        '�����µ�IP��ַ����ͨ��
        ipAddr = Me.TextBoxIP1.Text & "." & Me.TextBoxIP2.Text & "." & Me.TextBoxIP3.Text & "." & Me.TextBoxIP4.Text
        Me.Text1.Text = Me.Text1.Text & vbCrLf & "�����µ�IP��ַ����ͨ��" & ipAddr
        Me.Text1.Text = Me.Text1.Text & vbCrLf


        'У׼������ʱ��
        strCmd = wudp.CreateBstrCommandOfAdjustClockByPCTime(controllerSN) '����ָ��֡
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                    '����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)

            wudp = Nothing
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

            wudp = Nothing
            Exit Sub
        Else
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "Զ�̿��ųɹ�"
        End If


        '��ȡ��¼
        Dim recIndex As Long    '��¼������
        recIndex = 1
        Do While (True)
            strCmd = wudp.CreateBstrCommand(controllerSN, "8D10" & wudp.NumToStrHex(recIndex, 4))       '����ָ��֡
            strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                           '����ָ��, ����ȡ������Ϣ
            If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
                'û���յ�����,
                'ʧ�ܴ������... (��ErrCode����Է�������)
                '�û��ɿ�������
                Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ȡ��¼����"

                wudp = Nothing
                Exit Sub
            Else
                swipeDate = wudp.GetSwipeDateFromRunInfo(strFrame, cardId, status)

                If swipeDate <> "" Then
                    strRunDetail = "����: " & cardId & vbTab & " ״̬:" & vbTab & status & "(" & wudp.NumToStrHex(status, 1) & ")" & vbTab & "ʱ��:" & vbTab & swipeDate
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & strRunDetail
                    recIndex = recIndex + 1                          '��һ����¼
                    Me.Text1.SelectionStart = Len(Me.Text1.Text)          '��ʾ������
                    Me.Text1.ScrollToCaret()
                Else
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ȡ��¼���. �ܹ���ȡ��¼�� =" & (recIndex - 1)
                    Exit Do
                End If
                Me.Text1.SelectionStart = Len(Me.Text1.Text)              '��ʾ������
            End If
            Application.DoEvents()          'VB.NETʹ��Application.application.DoEvents()
        Loop
        Me.Text1.SelectionStart = Len(Me.Text1.Text)          '��ʾ������
        Me.Text1.ScrollToCaret()


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
                    wudp = Nothing
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
            wudp = Nothing
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
                    wudp = Nothing
                    Exit Sub
                End If
                strCmd = wudp.CreateBstrCommand(controllerSN, "9B10" & wudp.NumToStrHex(privilegeIndex, 2) & privilege) '����ָ��֡
                strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                                                         '����ָ��, ����ȡ������Ϣ

                If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
                    'û���յ�����,
                    'ʧ�ܴ������... (��ErrCode����Է�������)
                    '�û��ɿ�������
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & "���Ȩ��ʧ��"
                    wudp = Nothing
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
            wudp = Nothing
            Exit Sub
        End If
        strCmd = wudp.CreateBstrCommand(controllerSN, "9710" & wudp.NumToStrHex(2, 2) & timeseg) '����ָ��֡
        strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                                          '����ָ��, ����ȡ������Ϣ
        If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
            'û���յ�����,
            'ʧ�ܴ������... (��ErrCode����Է�������)
            '�û��ɿ�������
            Me.Text1.Text = Me.Text1.Text & vbCrLf & "���ʱ��ʧ��"
            wudp = Nothing
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
        Me.Text1.SelectionStart = Len(Me.Text1.Text)          '��ʾ������
        Me.Text1.ScrollToCaret()
        Application.DoEvents()
        Do While (recCnt < 3)        '������ ����3����ֹͣ
            strCmd = wudp.CreateBstrCommand(controllerSN, "8110" & wudp.NumToStrHex(watchIndex, 3)) '����ָ��֡ wudp.NumToStrHex(watchIndex,3) ��ʾ��watchIndex����¼, �����0��ȡ����һ����¼
            strFrame = wudp.udp_comm(strCmd, ipAddr, 60000)                                         '����ָ��, ����ȡ������Ϣ
            If ((wudp.ErrCode <> 0) Or (strFrame = "")) Then
                'û���յ�����,
                'ʧ�ܴ������... (��ErrCode����Է�������)
                wudp = Nothing
                Exit Sub
            Else
                swipeDate = wudp.GetSwipeDateFromRunInfo(strFrame, cardId, status)
                If swipeDate <> "" Then '�м�¼ʱ
                    strRunDetail = "����: " & cardId & vbTab & " ״̬:" & vbTab & status & "(" & wudp.NumToStrHex(status, 1) & ")" & vbTab & "ʱ��:" & vbTab & swipeDate
                    Me.Text1.Text = Me.Text1.Text & vbCrLf & strRunDetail
                    Me.Text1.SelectionStart = Len(Me.Text1.Text)              '��ʾ������
                    If watchIndex = 0 Then                              '����յ���һ����¼
                        watchIndex = wudp.GetCardRecordCountFromRunInfo(strFrame) + 1   'ָ��(�ܼ�¼��+1), Ҳ�����´�ˢ���Ĵ洢����λ
                    Else
                        watchIndex = watchIndex + 1   'ָ����һ����¼λ
                    End If
                    recCnt = recCnt + 1                '��¼����
                    Me.Text1.SelectionStart = Len(Me.Text1.Text)          '��ʾ������
                    Me.Text1.ScrollToCaret()
                End If
            End If
            Application.DoEvents()
        Loop
        Me.Text1.Text = Me.Text1.Text & vbCrLf & "��ֹͣʵʱ���"
        Me.Text1.SelectionStart = Len(Me.Text1.Text)          '��ʾ������
        Me.Text1.ScrollToCaret()


        wudp = Nothing

    End Sub
End Class
