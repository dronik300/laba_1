#include <iostream>

int main()
{
	std::cout << "Vvedite razmernost matric \n";
	int a[100][100], b[100][100], i, j, str, stb;
	std::cout << "stroki=  ";
	std::cin >> str;
	std::cout << "stolbci= ";
	std::cin >> stb;
	//std::cout << "Vvedite dannie matricy a ";
	for (i = 0; i < str; i++) // vvod matrici a
		for (j = 0; j < stb; j++)
		{
			std::cout << "a[" << i << "]" << "[" << j << "] ";
			std::cin >> a[i][j];
		}
	//std::cout << "Vvedite dannie matricy b ";
	for (i = 0; i < str; i++) // vvod matrici b
		for (j = 0; j < stb; j++)
		{
			std::cout << "b[" << i << "]" << "[" << j << "] ";
			std::cin >> b[i][j];
		}
	std::cout << "\n";
	for (i = 0; i < str; i++) // vivod matrici a
	{
		for (j = 0; j < stb; j++)
		{
			std::cout << "a[" << i << "]" << "[" << j << "] " << a[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (i = 0; i < str; i++) // vivod matrici b
	{
		for (j = 0; j < stb; j++)
		{
			std::cout << "b[" << i << "]" << "[" << j << "] " << b[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (i = 0; i < str; i++)
	{
		for (j = 0; j < stb; j++)
		{
			a[i][j] = a[i][j] + b[i][j];
			std::cout << "a[" << i << "]" << "[" << j << "] " << a[i][j] << " ";
		}
		std::cout << "\n";
	}
}
