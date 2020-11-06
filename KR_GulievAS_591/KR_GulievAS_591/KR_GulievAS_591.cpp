#include <iostream>
#include <vector>
#include "windows.h"
#include <fstream>
#include <locale.h>

using namespace std;

int main()
{
    HANDLE file0;
    DWORD k;
    int len = 0;
    int size = 0;
    char Buffer[1026] = { 0 };
    string text;
    fstream file("passwd/KR.txt");

    setlocale(LC_ALL, "Russian");

    file0 = CreateFile(L"CONIN$", GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    ReadFile(file0, Buffer, sizeof(Buffer), &k, NULL);

    
    text = Buffer;
    len = text.length() - 2;
    cout << "Введённый текст весит: ";
    if (len < 1024) cout << len << " байт" << endl;
    else cout << 1024 << " байт" << endl;

    file.seekg(0, ios::end);
    size = file.tellg();
    cout << "Файл весит: " << size << " байт" << endl;
    file.close();

    return 1;
}