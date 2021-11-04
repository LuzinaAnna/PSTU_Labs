#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	float f,c;
	cout << "Введите температуру в Фаренгейтах" << endl;
	cin >> f;
	c =5 * (f - 32)/9;
	cout <<"Температцра в Цельсиях: "<< c;
	return 0;
}

