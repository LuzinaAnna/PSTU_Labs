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
	cout << "������� ����� �� 1 �� 100" << endl;
	cout << "� ��� ���� 7 �������" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << i + 1 << "-� ������� :";
		cin >> a1;
		if (a1 != x)
		{
			if(a1 > x)
			{
				cout << "������ ����� ������, ��� " << a1 << endl;
			}
			else
			{
				cout << "������ ����� ������, ��� " << a1 << endl;
			}
		}
		else
		{
			cout << "�����������, �� �������� �����!" << endl;
			exit(0);
		}
	}
	cout << "�� ������� :(" << endl;
	cout << "����� = " << x << endl;
	return 0;

}
