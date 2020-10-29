#include "strochka.h"

strochka::strochka(int** tab, int n, int m, int sto, int* s) : table(tab, n, m)
{
	//int *s = new int[m];
	for (int j = 0; j < m; j++)
		s[j] = tab[sto - 1][j];
}

int strochka::fillstroka(int* s)
{
	return*s;
}

strochka::strochka() : table()
{

}

strochka::~strochka()
{
	delete[] s;
}

