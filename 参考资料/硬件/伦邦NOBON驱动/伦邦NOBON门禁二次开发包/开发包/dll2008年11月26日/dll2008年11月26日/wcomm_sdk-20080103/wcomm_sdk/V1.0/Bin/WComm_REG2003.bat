REM ע��WComm_UDP,WComm_Serial
@echo off

REM �Ƚ��WComm_Serialע��
regsvr32  /s /u WComm_Serial

REM ��ע��WComm_Serial��
regsvr32 /s /i WComm_Serial

REM ע��WComm_UDP
regasm11 /tlb: WComm_UDP.tlb WComm_UDP.dll
gacutil2003 /I WComm_UDP.dll

set /p Finish=�������(���س�����)
