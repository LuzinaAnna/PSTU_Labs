#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(nullptr));
	int x;
	int a1, i;
	x = rand() % 100 + 1;
	cout << "Вводите числа от 1 до 100" << endl;
	cout << "У вас есть 7 попыток" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << i + 1 << "-я попытка :";
		cin >> a1;
		if (a1 != x)
		{
			if(a1 > x)
			{
				cout << "Нужное число меньше, чем " << a1 << endl;
			}
			else
			{
				cout << "Нужное число больше, чем " << a1 << endl;
			}
		}
		else
		{
			cout << "Поздравляем, вы отгадали число!" << endl;
			exit(0);
		}
	}
	cout << "Не угадали :(" << endl;
	cout << "Число = " << x << endl;
	return 0;

}
