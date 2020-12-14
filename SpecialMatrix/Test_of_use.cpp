#include <iostream>
#include "TMatrix.cpp"
#include "TVector.cpp"
#include "TMatrix.h"
#include "TVector.h"
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << endl << "Тестирование программ поддержки треугольных матриц " <<endl<<endl;

	int size; //задается переменная, которая будет использоваться как размер матриц

	cout << "Введите размер матрицы: "<<endl;
	cin >> size;

	TMatrix<int> a(2), b(2), c(5), d(size), e(size); //инициализируются матрицы, необходимые для дальнейшего использования

	int i, j;


	for (i = 0; i < size; i++) //заполнение матриц d,e
		for (j = i; j < size; j++)
		{
			d[i][j] = i * 10 + j;
			e[i][j] = 1;
		}
	
for (i = 0; i < 2; i++) //заполнение матриц a,b
		for (j = i; j < 2; j++)
		{
			a[i][j] = 2;
			b[i][j] = 5;
		}

	cout << endl;
	cout << "Матрица d" <<endl<< endl << d << endl;
		

	cout << endl;
	cout << "Матрица e" << endl << endl << e << endl;


	cout << endl;
	cout << "Матрица a" << endl << endl << a << endl;


	cout << endl;
	cout << "Матрица b" << endl << endl << b << endl;


	cout << endl;
	cout << "Проверка равенства матриц e и d:" << endl;
	if (d == e)
	{
		cout << endl << "Матрицы d и e равны" << endl;
	}
	else cout << endl << "Матрицы e и d не равны " << endl;

	cout << endl;

	cout << "Присвоение результата сложения матриц d и d матрице c" << endl;
	c = d + d;
	cout << endl << c << endl;

	cout << "Присвоение результата сложения матриц a и b матрице c" << endl;
	c = a + b;
	cout << endl << c << endl;

	
	cout << endl;
	cout<< "Присвоение результата разности матриц a и b матрице c" << endl;
	c = a - b;
	cout << endl << c << endl;

	cout << endl;
	cout << "Присвоение результата умножения матриц a и b матрице c" << endl;
	c = a * b;
	cout << endl << c << endl;

	return 0;
}
