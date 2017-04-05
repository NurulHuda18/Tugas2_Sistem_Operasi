#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;
int main(VOID)
{
    cout<<"Nama  : Nurul Huda"<<endl;
    cout<<"NIM   : 14201251"<<endl<<endl;
STARTUPINFO si;
PROCESS_INFORMATION pi;

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        if (!CreateProcess(NULL,
        "C:\\WINDOWS\\system32\\mspaint.exe",
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi))
        {
            fprintf(stderr, "Create Process Failed");
            return -1;
        }
        WaitForSingleObject(pi.hProcess, INFINITE);
        printf("Child Complete");

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
}
