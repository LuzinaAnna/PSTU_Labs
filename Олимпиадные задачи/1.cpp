#include <iostream>
#include <algorithm>

int main()
{
	int x, a, b, c, t, x1, x2, x3, x4, x5, x6, max1, max2, max3, max4, max5;
	setlocale(LC_ALL, "Rus");
	std::cout << "������� ����������� �����" << std::endl;
	std::cin >> x;
	a = x / 100;
	b = x / 10 % 10;
	c = x % 10;
	while ((x < 100 || x > 999) and (a == b || a == c || b == c))
	{
		std::cout << "��������� ����� �� �����������, ��������� ����" << std::endl;
		std::cin >> x;
	}
	std::cout << "��� ��������� ������������������ �����: " << std::endl;
	x1 = a * 100 + b * 10 + c;
	std::cout << a << b << c << std::endl;
	t = c;
	c = b;
	b = t;
	x2 = a * 100 + b * 10 + c;
	std::cout << a << b << c << std::endl;
	t = a;
	a = b;
	b = t;
	x3 = a * 100 + b * 10 + c;
	std::cout << a << b << c << std::endl;
	t = a;
	a = c;
	c = t;
	x4 = a * 100 + b * 10 + c;
	std::cout << a << b << c << std::endl;
	t = c;
	c = b;
	b = t;
	x5 = a * 100 + b * 10 + c;
	std::cout << a << b << c << std::endl;
	t = a;
	a = b;
	b = t;
	x6 = a * 100 + b * 10 + c;
	std::cout << a << b << c << std::endl;
	max1 = std::max(x1, x2);
	max2 = std::max(x3, x4);
	max3 = std::max(x5, x6);
	max4 = std::max(max1, max2);
	max5 = std::max(max3, max4);
	std::cout << "���������� �� ���� �����: " << std::endl;
	std::cout << max5 << std::endl;
	return 0;
}
