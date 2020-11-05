

#include <iostream>
#include "MathFuncsDll.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double a,d;
	double P = 3.14,s,p;
	cout << "Введите радиус =	";
	cin >> a;
	p = 2 * MathFuncs::MyMathFuncs::Multiply(P, a);
	s = P * MathFuncs::MyMathFuncs::Pow(a, 2);
	cout << "Площадь = " << s << endl;
	cout << "Периметр = " << p << endl;
}
