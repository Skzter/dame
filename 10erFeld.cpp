//test für ausgabe

#include<iostream>
#include<iomanip>

int main()
{
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 1; j <= 10; j++)
		{
			if((i*j)%2 == 0)
			{
				std::cout << std::setw(4) << i*j;
			}
			else
			{
				std::cout << std::setw(4) << "#";
			}
		}
	std::cout << "\n";
	}
}
