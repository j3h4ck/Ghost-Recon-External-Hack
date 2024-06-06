#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <vector>

#pragma comment(lib, "user32.lib")
namespace GameHacking {
    const wchar_t* process = L"GRW.exe";
    TCHAR gameModule[] = _T("GRW.exe");
    DWORD64 gamebaseaddress;
    DWORD64 moneyAddress;
    DWORD64 moneybaseaddress = 0x04031438;
    std::vector<DWORD64> moneyOffsets = { 0x8 ,0x4A0 };
    DWORD64 xPositionbaseaddress = 0x03A7D9C0;
    DWORD64 xPositionAddress;
    std::vector<DWORD64> xPositionOffsets = { 0x5A0 ,0x1D0 };
    DWORD64 yPositionbaseaddress = 0x03A7D9C0;
    DWORD64 yPositionAddress;
    std::vector<DWORD64> yPositionOffsets = { 0x5A0 ,0x1D4 };
}

DWORD64 GetPointerAddress64(HANDLE hProc, DWORD64 gameBaseAddr, DWORD64 address, std::vector<DWORD64> offsets)
{
    DWORD64 pointerAddress = gameBaseAddr + address; // Initial address

    for (size_t i = 0; i < offsets.size(); ++i) {
        if (!ReadProcessMemory(hProc, (LPCVOID)pointerAddress, &pointerAddress, sizeof(pointerAddress), NULL)) {
            printf("[-] Unable to read memory at offset %zu\n", i);
            return 0;
        }
        pointerAddress += offsets[i];
    }

    return pointerAddress;
}
DWORD GetPointerAddress32(HWND hwnd, DWORD gameBaseAddr, DWORD address, std::vector<DWORD64> offsets)
{
    DWORD pID = NULL; // Game process ID
    GetWindowThreadProcessId(hwnd, &pID);
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);

    DWORD offset_null = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddr + address), &offset_null, sizeof(offset_null), 0);
    DWORD pointeraddress = offset_null; // the address we need
    for (int i = 0; i < offsets.size() - 1; i++) // we dont want to change the last offset value so we do -1
    {
        ReadProcessMemory(phandle, (LPVOID*)(pointeraddress + offsets.at(i)), &pointeraddress, sizeof(pointeraddress), 0);
    }
    return pointeraddress += offsets.at(offsets.size() - 1); // adding the last offset
}
DWORD64 GetModuleBaseAddress64(TCHAR* lpszModuleName, DWORD pID) {
    DWORD64 dwModuleBaseAddress = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID); // make snapshot of all modules within process
    MODULEENTRY32 ModuleEntry32 = { 0 };
    ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

    if (Module32First(hSnapshot, &ModuleEntry32)) //store first Module in ModuleEntry32
    {
        do {
            if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0) // if Found Module matches Module we look for -> done!
            {
                dwModuleBaseAddress = (DWORD64)ModuleEntry32.modBaseAddr;
                break;
            }
        } while (Module32Next(hSnapshot, &ModuleEntry32)); // go through Module entries in Snapshot and store in ModuleEntry32


    }
    CloseHandle(hSnapshot);
    return dwModuleBaseAddress;
}
int FindProcessIdByName(const wchar_t* procname) {

    HANDLE hSnapshot;
    PROCESSENTRY32 pe;
    int pid = 0;
    BOOL hResult;

    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hSnapshot) return 0;

    pe.dwSize = sizeof(PROCESSENTRY32);

    hResult = Process32First(hSnapshot, &pe);


    while (hResult) {

        if (uaw_lstrcmpiW(procname, pe.szExeFile) == 0) {
            pid = pe.th32ProcessID;

            break;
        }
        hResult = Process32Next(hSnapshot, &pe);
    }


    CloseHandle(hSnapshot);
    return pid;
}


