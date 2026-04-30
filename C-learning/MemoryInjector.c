#include <stdio.h>
#include <Windows.h>
#include <string.h>

int main()
{
    DWORD pid = NULL; // definir dps
    const char* dllpath = "dllmain.dll"; // mude para um caminho absoluto depois

    HANDLE Hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    LPVOID VirtualMemory = VirtualAllocEx(
        Hprocess,
        NULL,
        strlen(dllpath) + 1,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE
    );

    if (!WriteProcessMemory(Hprocess,
        VirtualMemory,
        dllpath,
        strlen(dllpath) + 1,    
        NULL // iria mostrar quantos bytes foram escritos, mas eu coloquei null
    )) {
        printf("Erro ao escrever na memoria do processo");
    }

    LPVOID LoadLibrary = GetProcAddress(
        GetModuleHandleA("kernel32.dll"),
        "LoadLibraryA" // ache o endereço real da função "LoadLibraryA" dentro de "kernel32.dll"
    );

    HANDLE HThread = CreateRemoteThreadEx(
        Hprocess,
        NULL,
        0,
        (LPTHREAD_START_ROUTINE)LoadLibrary,
        VirtualMemory,
        0,
        NULL,
        NULL
    );

    WaitForSingleObject(HThread, INFINITE);

    CloseHandle(Hprocess);
    CloseHandle(HThread);
}
