#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {

	cout << "\t\t.....IPC Client......" << endl;
	cout << endl;

	//Local variables definition
	HANDLE	hFileMap;
	BOOL	bResult;
	PCHAR	lpBuffer = NULL;
	char	Buffer[1024] = "Hello from Client";
	size_t	szBuffer = sizeof(Buffer);

	//open file mapping
	hFileMap = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		L"Local\\MyFileMap");
	if (hFileMap == NULL)
	{
		cout << "OpenFileMapping Failed and Error No: " << GetLastError() << endl;
	}
	else 
	{
		cout << "OpenFileMapping Success" << endl;
	}
	

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
	else {
		cout << "MapViewOfFile Success" << endl;
	}
	
	//reading the data from file map object
	cout << "READING DATA FROM SERVER" << lpBuffer << endl;

	//unmap view of file
	bResult = UnmapViewOfFile(lpBuffer);
	if (bResult == FALSE)
	{
		cout << "UnMapViewOfFile failed and Error No: " << GetLastError() << endl;
	}
	else 
	{
		cout << "UnMapViewOfFile Success" << endl;
	}

	//close handle
	CloseHandle(hFileMap);

	_getch();
	//system("PAUSE");
	return 0;
}