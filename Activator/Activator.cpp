#include <iostream>
#include <Windows.h>
int main() {
    system("cscript //B //Nologo slmgr.vbs -rearm");
    Sleep(10);
    system("exit");
}
