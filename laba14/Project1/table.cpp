#include "table.h"
#include <ctime>
#include <iostream>

table::table(int** tab, int n, int m)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tab[i][j] = rand() % 10;
}

table::table()
{
	n = 0;
	m = 0;
	int** tab = new int* [n];
	for (int i = 0; i < n; i++)
		tab[i] = new int[m];
}

int table::filltable(int** tab)
{
	return**tab;
}

table::~table()
{

}