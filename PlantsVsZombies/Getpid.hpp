
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>
#include <string_view>
#include <Psapi.h>
#include <ctime>
DWORD getpid(LPCSTR lei, LPCSTR windows_name)
{
    //ȡ��Ϸ������
    HWND handle;
    DWORD PID;
    handle = FindWindowA(lei, windows_name);
    //��ȡ��Ϸ���
    GetWindowThreadProcessId(handle, &PID);
    return PID;
}
HMODULE getModuleBase(const TCHAR* name, DWORD PID) {
    MODULEENTRY32 moduleEntry;
    HANDLE handle = NULL;
    handle = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, PID);
    ZeroMemory(&moduleEntry, sizeof(MODULEENTRY32));
    moduleEntry.dwSize = sizeof(MODULEENTRY32);
    if (!Module32First(handle, &moduleEntry)) {
        CloseHandle(handle);
        return NULL;
    }
    do {
        if (_tcscmp(moduleEntry.szModule, name) == 0) { return moduleEntry.hModule; }
    } while (Module32Next(handle, &moduleEntry));
    return 0;
};
void   Delay(int   time)//time*1000Ϊ���� 
{
    clock_t   now = clock();

    while (clock() - now < time);
};

