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

int CmdProcessing(void);
void StringCat(TCHAR **);
TCHAR * StrLower(TCHAR *);

int main(int argc, TCHAR * argv[])
{
	// �ѱ� �Է��� ������ �ϱ� ����.
	_tsetlocale(LC_ALL, _T("Korean"));
	if(argc > 1)
	{
		if(!_tcscmp(argv[1],_T("echo")))
		{
		
			for(int i = 2; i < argc; i++)
			{
				_tprintf("%s ", argv[i]);
			}
		}
	}
	else
	{
		_tprintf("�Էµ� ��ɾ ����.\n");
	}
	_gettchar();

	return 0; 
}


