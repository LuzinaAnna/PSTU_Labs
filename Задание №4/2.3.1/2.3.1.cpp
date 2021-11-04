#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	float a, b;
	setlocale(LC_ALL, "Rus");
	cout << "Введите два числа";
	cin >> a >> b;
	cout <<"Произведение двух чисел: " <<a * b;
	return 0;
}

