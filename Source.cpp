#include <iostream>
#include <iomanip>

int input_check(int a) // proverka na vvod
{
	while (true)
	{
		std::cin >> a;
		if (!std::cin)
		{
			std::cout << "ne verno vveli, povtorite vvod\n";
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		else break;
	}
	return a;
}

int main()
{
	std::cout << "Vvedite razmernost matric \n";
	int a[100][100], b[100][100], i, j, str_1=0, stb_1=0, str_2=0, stb_2=0, str_max, stb_max;
	std::cout << "stroki_1_matrici=  ";
	str_1=input_check(str_1);
	std::cout << "stolbci_1_matrici= ";
	stb_1=input_check(stb_1);
	std::cout << "stroki_2_matrici=  ";
	str_2=input_check(str_2);
	std::cout << "stolbci_2_matrici= ";
	stb_2=input_check(stb_2);
	str_max = str_1;
	stb_max = stb_1;
	if (str_2 > str_1)
		str_max = str_2;
	if (stb_2 > stb_1)
		stb_max = stb_2;
	for (i = 0; i < str_max; i++) // obnylenie matric
		for (j = 0; j < stb_max; j++)
		{
			a[i][j] = 0;
			b[i][j] = 0;
		}
	std::cout << "Vvedite dannie matricy a ";
	for (i = 0; i < str_1; i++) // vvod matrici a
		for (j = 0; j < stb_1; j++)
		{
			//std::cout << "a[" << i << "]" << "[" << j << "] ";
			a[i][j]=input_check(a[i][j]);
		}
	std::cout << "Vvedite dannie matricy b ";
	for (i = 0; i < str_2; i++) // vvod matrici b
		for (j = 0; j < stb_2; j++)
		{
			//std::cout << "b[" << i << "]" << "[" << j << "] ";
			b[i][j]= input_check(b[i][j]);
		}
	std::cout << "\n";
	for (i = 0; i < str_1; i++) // vivod matrici a
	{
		for (j = 0; j < stb_1; j++)
		{
			std::cout << "a[" << i << "]" << "[" << j << "] " << std::setw(5) << a[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (i = 0; i < str_2; i++) // vivod matrici b
	{
		for (j = 0; j < stb_2; j++)
		{
			std::cout << "b[" << i << "]" << "[" << j << "] " << std::setw(5) << b[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (i = 0; i < str_max; i++)
	{
		for (j = 0; j < stb_max; j++)
		{
			a[i][j] = a[i][j] + b[i][j];
			std::cout  <<"a[" << i << "]" << "[" << j << "] " << std::setw(5) << a[i][j] << " ";
		}
		std::cout << "\n";
	}
}
