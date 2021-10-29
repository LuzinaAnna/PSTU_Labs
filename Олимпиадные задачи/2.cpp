#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(std::time(nullptr));
	int x;
	int a1, i;
	x = rand() % 100 + 1;
	std::cout << "Вводите числа от 1 до 100" << std::endl;
	std::cout << "У вас есть 7 попыток" << std::endl;
	for (int i = 0; i < 7; i++)
	{
		std::cout << i + 1 << "-я попытка :";
		std::cin >> a1;
		if (a1 != x)
		{
			if(a1 > x)
			{
				std::cout << "Нужное число меньше, чем " << a1 << std::endl;
			}
			else
			{
				std::cout << "Нужное число больше, чем " << a1 << std::endl;
			}
		}
		else
		{
			std::cout << "Поздравляем, вы отгадали число!" << std::endl;
			std::exit(0);
		}
	}
	std::cout << "Не угадали :(" << std::endl;
	std::cout << "Число = " << x << std::endl;
	return 0;

}
