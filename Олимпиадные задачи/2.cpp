#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(std::time(nullptr));
	int x;
	int a1, i;
	x = rand() % 100 + 1;
	std::cout << "������� ����� �� 1 �� 100" << std::endl;
	std::cout << "� ��� ���� 7 �������" << std::endl;
	for (int i = 0; i < 7; i++)
	{
		std::cout << i + 1 << "-� ������� :";
		std::cin >> a1;
		if (a1 != x)
		{
			if(a1 > x)
			{
				std::cout << "������ ����� ������, ��� " << a1 << std::endl;
			}
			else
			{
				std::cout << "������ ����� ������, ��� " << a1 << std::endl;
			}
		}
		else
		{
			std::cout << "�����������, �� �������� �����!" << std::endl;
			std::exit(0);
		}
	}
	std::cout << "�� ������� :(" << std::endl;
	std::cout << "����� = " << x << std::endl;
	return 0;

}
