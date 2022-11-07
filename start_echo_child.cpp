/*
    CommandPrmpt_One.cpp
    프로그램 설명: 명령 프롬프트의 골격.
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
	// 한글 입력을 가능케 하기 위해.
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
		_tprintf("입력된 명령어가 없음.\n");
	}
	_gettchar();

	return 0; 
}


