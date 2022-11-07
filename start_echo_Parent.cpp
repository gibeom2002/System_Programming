/*
    CommandPrmpt_One.cpp
    ���α׷� ����: ��� ������Ʈ�� ���.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <tchar.h>
#include <windows.h> 

#define STR_LEN    256
#define CMD_TOKEN_NUM  10

TCHAR ERROR_CMD[] 
 = _T("'%s'��(��) ������ �� �ִ� ���α׷��� �ƴմϴ�. \n");

int CmdProcessing(void);
void StringCat(TCHAR **);
TCHAR * StrLower(TCHAR *);

int main(int agrc, TCHAR * argv[])
{
	// �ѱ� �Է��� ������ �ϱ� ����.
	_tsetlocale(LC_ALL, _T("Korean")); 
	
	DWORD isExit;
	while(1)
	{
		isExit = CmdProcessing();
		if(isExit == TRUE)
		{
			_fputts(_T("��ɾ� ó���� �����մϴ�. \n"), stdout );
			break;
		}
	}

	return 0; 
}


TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[]   = _T(" ,\t\n");
TCHAR command[STR_LEN]; 
int CmdProcessing(void)
{
	_fputts( _T("Best command prompt>> "), stdout );
	_getts(cmdString);

	// tcstok (���ڿ�, ��) ������ ���ڿ��� �и���Ű�� �� ��  
	TCHAR * token = _tcstok(cmdString, seps); 
	int tokenNum = 0;
	while(token != NULL)
	{
		_tcscpy (
			cmdTokenList[tokenNum++], StrLower(token)
		);
		token = _tcstok(NULL, seps);
	}
	
	if( !_tcscmp(cmdTokenList[0],_T("exit")) )
	{
		return TRUE;
	}
	else if ( !_tcscmp(cmdTokenList[0],_T("start")) )
	{
		int idx = 1, strIdx = 0;
		TCHAR * dest = command;
		TCHAR * start;
		TCHAR blank = _T(' ');
		_tcscpy(command, "start_echo_child.exe ");
		while(*dest)
		{
			dest++;
		}
		while(idx < tokenNum)
		{
			start = cmdTokenList[idx++];
			while(*start)
			{
				*dest = *start;
				dest++, start++;
			}
			*dest = blank;
			dest++;
		}
		*(--dest) = _T('\0');
		
		STARTUPINFO si = {0,};
		PROCESS_INFORMATION pi;
		si.cb=sizeof(si);
		
		BOOL state=CreateProcess(NULL, command,
						NULL,NULL, TRUE, 
						CREATE_NEW_CONSOLE, 
						NULL, NULL, &si, &pi);
		
		if(state == FALSE)
		{
			_tprintf(ERROR_CMD, cmdTokenList[0]);
		}
	}
	else
	{
		STARTUPINFO si = {0,};
		PROCESS_INFORMATION pi;
		si.cb=sizeof(si);
		BOOL state=CreateProcess(NULL, cmdTokenList[0],
						NULL,NULL, TRUE, 
						CREATE_NEW_CONSOLE, 
						NULL, NULL, &si, &pi);
		if(state == FALSE)
		{
			_tprintf(ERROR_CMD, cmdTokenList[0]);
		}
	}

	return 0;
}


TCHAR * StrLower(TCHAR *pStr)
{
	TCHAR *ret = pStr;

	while(*pStr)
	{
		if(_istupper(*pStr))
			*pStr = _totlower(*pStr);
		pStr++;
	}

	return ret;
}



