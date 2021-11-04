#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int x = 10;
	int y, z;
	y = 2 * x;
	z = y--;
	cout << x << endl;
	cout << z << endl;
	cout << y << endl;
	return 0;
}

