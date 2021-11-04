#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	float f, c;
	cout << "Введите температуру в Фаренгейтах" << endl;
	cin >> f;
	c = 5 * (f - 32) / 9;
	cout << "Температура в Цельсиях: " << c;
	return 0;
}
