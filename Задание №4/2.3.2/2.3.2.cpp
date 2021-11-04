#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	char a, b, c, d, e;
	cout << "Введите пять символов ";
	cin >> a >> b >> c >> d >> e;
	cout <<"Обратная последовательность " << e << d << c << b << a;
	return 0;
}