#define WIN32_LEAN_AND_MEAN

#include "resource.h"
#include <windows.h>
#include "Header.h"

//======================================================================//
BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);
//======================================================================//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCMDline, int nCmdShow)
{
	//======================================================================//
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	//======================================================================//
	HWND dialog;
	//======================================================================//
	dialog = CreateDialog(hInstance, MAKEINTRESOURCE(Windows), NULL, DialogProc);
	if (!dialog)
	{
		//MessageBox(NULL, "Cannot Create Windows", "CreateDialog", MB_ICONERROR);
		return 1;
	}
	ShowWindow(dialog, nCmdShow);
	//======================================================================//
	UpdateWindow(dialog);
	//======================================================================//
	MSG msg;
	//======================================================================//
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//======================================================================//
	return (int)msg.wParam;
}
//======================================================================//
BOOL CALLBACK DialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		//======================================================================//
	    //MessageBox(NULL, "คลิกขวา Run Administrator ทุกครั้ง", "ข้อความจากระบบ", MB_OK | MB_ICONASTERISK);
		//======================================================================//
		ShowWindow(hwnd, SW_HIDE);
		//======================================================================//
		download(); //เรียกฟังชั่น ดาวโหลด dll จาก Server
		//======================================================================//
		inject(); //เรียกฟังชั่น inject
		//======================================================================//
		ExitProcess(1); // Inject dll เสร็จ สั่งให้ปิดโปรแกรม
		//======================================================================//
		break;
		//======================================================================//
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return TRUE;
		break;
		//======================================================================//
	case WM_DESTROY:
		PostQuitMessage(0);
		return TRUE;
		//======================================================================//
	}
	    //======================================================================//
	return FALSE;
}
//======================================================================//