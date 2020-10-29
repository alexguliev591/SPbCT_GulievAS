#pragma once
#include "table.h"

ref class strochka :table
{
public:
	strochka(int**, int, int, int, int*);
	strochka();
	int fillstroka(int*);
	~strochka();
private:
	int* s;
	int sto;
};


