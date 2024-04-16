#include <windows.h>
#include <wininet.h>
#include <iostream>
#include <fstream>
#include <string>
#pragma comment(lib, "wininet.lib")


#include "TaskScheduler.h"

using namespace std;

void downloadFile(const string& url, const string& dest) {
    HINTERNET hInternet, hConnect;
    DWORD bytesRead;

    hInternet = InternetOpen(L"Internet Connection", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (hInternet == NULL) {
        cout << "InternetOpen failed" << endl;
        return;
    }

    hConnect = InternetOpenUrlA(hInternet, (url + "?raw=true").c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (hConnect == NULL) {
        cout << "InternetOpenUrlA failed" << endl;
        InternetCloseHandle(hInternet);
        return;
    }

    char buffer[4096];
    ofstream destStream(dest, ios::binary);

    while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
        destStream.write(buffer, bytesRead);
    }

    destStream.close();
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);
}

int main() {
    
    //Creaating the file
    LPCWSTR dirPath = L"C:\\OpenSourceActivator";
    if (CreateDirectory(dirPath, NULL)) {
        std::cout << "Directory created successfully.\n";
    }
    else if (ERROR_ALREADY_EXISTS == GetLastError()) {
        std::cout << "Directory already exists.\n";
    }
    else {
        std::cout << "Failed to create directory.\n";
    }
    
   //downloading the file
   downloadFile("https://github.com/finutz/Windows-activation-tool/blob/main/precompiled/Activator.exe", "C:\\OpenSourceActivator\\Activator.exe");

   //creating new task  
    createTask();

    return 0;
}
