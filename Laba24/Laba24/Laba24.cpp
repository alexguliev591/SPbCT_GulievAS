#include <iostream>
#include <windows.h>


using namespace std;

HANDLE Events[4], EndEvent;
HANDLE Mutex;

DWORD WINAPI Employee(LPVOID lpParam) {
	char in;
	if (WaitForSingleObject(Mutex, INFINITE) != 0) {
		cout << "Не удалось занять мьютекс\n";
		return 1;
	}
	if (WaitForSingleObject(EndEvent, 10) == WAIT_TIMEOUT) {
		cout << "Введите сообщение (0 или 1, или 2, или 3): ";
		cin >> in;
		if (cin.fail() || (in < '0' || in>'3'))
			cout << "Введены неправильные данные\n";
		else if (SetEvent(Events[(unsigned int)(in - '0')]) == 0)
			cout << "Не удалось установить событие\n";
		ReleaseMutex(Mutex);
		return 0;
	}
	else {
		ReleaseMutex(Mutex);
		return 1;
	}
}

void main() {
	setlocale(LC_ALL, ".1251");
	cout << "Введите количество потоков для запуска: ";
	unsigned int n;
	cin >> n;
	if (cin.fail()) {
		cout << "Введены неправильные данные\n";
		ExitProcess(1);
	}
	cout << "Будет создано потоков: " << n << endl;
	//Запуск потоков
	for (unsigned int i = 0; i < 4; i++)
		if ((Events[i] = CreateEventA(0, 0, 0, 0)) == 0) {
			cout << "Не удалось создать событие \"" << i << "\"\n";
			ExitProcess(1);
		}
	if ((EndEvent = CreateEventA(0, 1, 0, 0)) == 0) {
		cout << "Не удалось создать событие\n";
		ExitProcess(1);
	}
	Mutex = CreateMutexA(0, 1, 0);
	HANDLE* Threads = new HANDLE[n];
	for (unsigned int i = 0; i < n; i++)
		if ((Threads[i] = CreateThread(0, 0, Employee, 0, 0, 0)) == 0) {
			cout << "Не удалось создать поток №" << i + 1 << endl;
			ExitProcess(1);
		}
	cout << "Создано потоков: " << n << endl;
	ReleaseMutex(Mutex);
	//Ожидание 3 сообщений
	for (unsigned int i = 0; i < 3; i++) {
		WaitForMultipleObjects(4, Events, 0, INFINITE);
		cout << "Принято сообщение №" << i + 1 << endl;
	}
	//Блокирование последующих сообщений
	SetEvent(EndEvent);
	WaitForSingleObject(Mutex, INFINITE);
	ResetEvent(EndEvent);
	cout << "Программа успешно завершается\n";
	delete[] Threads;
	//Завершение работы
	ExitProcess(0);
}