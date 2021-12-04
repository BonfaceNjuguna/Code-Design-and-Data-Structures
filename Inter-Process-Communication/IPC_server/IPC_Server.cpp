#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>


using namespace std;

int main() {

	cout << "\t\t.....IPC server......" << endl;
	cout << endl;

	//Local variables definition
	HANDLE	hFileMap;
	BOOL	bResult;
	PCHAR	lpBuffer = NULL;
	char	Buffer[1024] = " Hello from Server";
	size_t	szBuffer = sizeof(Buffer);

	//create file mapping
	hFileMap = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		256,
		L"Local\\MyFileMap");
	if (hFileMap==FALSE)
	{
		cout << "CreateFileMapping Failed and Error No: " << GetLastError() << endl;
	}
	cout << "CreateFileMapping Success" << endl;

	//map view of file
	lpBuffer = (PCHAR)MapViewOfFile(
		hFileMap,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		256);
	if (lpBuffer == NULL)
	{
		cout << "MapViewOfFile failed and Error No: " << GetLastError() << endl;
	}
	cout << "MapViewOfFile Success" << endl;

	//copy memory
	CopyMemory(lpBuffer, Buffer, szBuffer);

	//unmap view of file
	bResult = UnmapViewOfFile(lpBuffer);
	if (bResult == FALSE)
	{
		cout << "UnMapViewOfFile failed and Error No: " << GetLastError() << endl;
	}
	cout << "UnMapViewOfFile Success" << endl;

	system("PAUSE");
	return 0;
}