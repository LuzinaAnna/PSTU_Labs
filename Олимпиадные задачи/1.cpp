#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int x, a, b, c, t, x1, x2, x3, x4, x5, x6, max1, max2, max3, max4, max5;
	setlocale(LC_ALL, "Rus");
	cout << "������� ����������� �����" << endl;
	cin >> x;
	a = x / 100;
	b = x / 10 % 10;
	c = x % 10;
	while ((x < 100 || x > 999) and (a == b || a == c || b == c))
	{
		cout << "��������� ����� �� �����������, ��������� ����" << endl;
		cin >> x;
	}
	cout << "��� ��������� ������������������ �����: " << endl;
	x1 = a * 100 + b * 10 + c;
	cout << a << b << c << endl;
	t = c;
	c = b;
	b = t;
	x2 = a * 100 + b * 10 + c;
	cout << a << b << c << endl;
	t = a;
	a = b;
	b = t;
	x3 = a * 100 + b * 10 + c;
	cout << a << b << c << endl;
	t = a;
	a = c;
	c = t;
	x4 = a * 100 + b * 10 + c;
	cout << a << b << c << endl;
	t = c;
	c = b;
	b = t;
	x5 = a * 100 + b * 10 + c;
	cout << a << b << c << endl;
	t = a;
	a = b;
	b = t;
	x6 = a * 100 + b * 10 + c;
	cout << a << b << c << endl;
	max1 = max(x1, x2);
	max2 = max(x3, x4);
	max3 = max(x5, x6);
	max4 = max(max1, max2);
	max5 = max(max3, max4);
	cout << "���������� �� ���� �����: " << endl;
	cout << max5 << endl;
	return 0;
}
