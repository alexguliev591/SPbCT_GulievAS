#include <iostream>
#include <string>
using namespace std;

template <class type1>
class X
{
public:
	int dlina;
	type1* XY;

	X(int dlina) //конструктор
	{
		this->dlina = dlina;
		XY = new type1[dlina];
	}

	~X()//деструктор
	{
		delete[] XY;
	}

	X(const X& r) //конструктор копирования
	{
		dlina = r.dlina;
		XY = new type1[dlina];
		for (int i = 0; i < r.dlina; i++)
		{
			XY[i] = r.XY[i];
		}
	}

	void input(int ras, type1 element) // функция ввода элемента
	{
		XY[ras] = element;
	}

	int Get_dlina() // функция возвращающая размер массива
	{
		return dlina;
	}

	type1 operator[](int i)
	{
		return XY[i];
	}

	X& operator=(const X& right) // перегрузка оператора присваивания
	{

		for (int i = 0; i < right.dlina; i++)
		{
			XY[i] = right.XY[i];
		}
		return *this;
	}

	X& operator+ (type1 i)// перегрузка оператора сложения массива с элементом
	{
		XY[dlina - 1] = XY[dlina - 1] + i;
		return *this;
	}

	X& operator+ (X l)//перегрузка оператора сложения массива
	{
		for (int i = 0; i < l.dlina; i++)
		{
			XY[i] = XY[i] + l.XY[i];
		}
		return *this;
	}

	void show() //функция вывода 
	{
		for (int i = 0; i < dlina; i++)
		{
			cout << XY[i] << endl;
		}
		cout << endl;
	}
};

class Complex//пользовательский класс 
{
public:
	Complex(int _x = 0, int _y = 0) : x(_x), y(_y) {}//конструктор по умолчнию

	Complex(const Complex& copy)//конструктор копирования
	{
		x = copy.x;
		y = copy.y;
	}

	void Show() const//функция показа точки
	{
		cout << x << "+" << y << "i" << endl;
	}

	Complex& operator =(const Complex& a)//перезрузка оператора присваивания
	{
		x = a.x;
		y = a.y;
		return *this;
	}

	const Complex operator +(const Complex& a)//перезрузка оператора сложения
	{

		return Complex(x + a.x, y + a.y);
	}
	int x, y;

	friend ostream& operator<< (ostream& out, const Complex& point);
};

ostream& operator<< (ostream& out, const Complex& Complex)// перегрузка оператора вывода для класса Complex
{
	out << Complex.x << "+" << Complex.y << "i";
	return out;
}

int main()
{
	setlocale(LC_ALL, "rus");
	X <double> c(15);
	cout << "Массив X c(15) заполненый числами." << endl;
	for (int i = 0; i < 15; i++)
	{
		c.input(i, i + 1);
	}
	c.show();
	cout << "Массив X c = v " << endl;
	X <double> v = c;
	v.show();
	cout << "Массив X b = c + v " << endl;
	X <double> b(15);
	b = c + v;
	b.show();
	cout << "Массив X b = b + 5 " << endl;
	b = b + 5;
	b.show();

	X <Complex> c1(15);
	cout << "Массив X c1(15)" << endl;
	for (int i = 0; i < 15; i++)
	{
		c1.input(i, Complex(i + 1, i));
	}
	c1.show();
	cout << "Массив X v1 = c1 " << endl;
	X <Complex> v1 = c1;
	v1.show();
	cout << "Массив X b1 = v1 + c1 " << endl;
	X <Complex> b1(15);
	b1 = v1 + c1;
	b1.show();
	cout << "Массив X b1 = b1 + Complex 100 + 100i " << endl;
	b1 = b1 + Complex(100, 100);
	b1.show();
}
