// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "WProtect.h"

int _tmain(int argc, _TCHAR* argv[])
{
	WProtectBegin();
	printf("Shit\r\n");
	WProtectEnd();
	getchar();
	return 0;
}

