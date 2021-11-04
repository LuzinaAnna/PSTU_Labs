
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	float i;
	float p;
	int k;
	i = 1 / 7.481;
	cout << "Введите число галлонов" << endl;
	cin >> k  ;
	p = k * i;
	cout <<"Эквивалентый объем в кубических футах равен "<< p;
	return 0;
}
