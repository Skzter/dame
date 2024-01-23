//test für ausgabe

#include<iostream>
#include<iomanip>

int main()
{
	for(char i = 'a'; i <= 'k'; i++)
	{
		for(int j = 1; j <= 10; j++)
		{
			std::cout << std::setw(3) << "#";
		}
	std::cout << "\n";
	}
}
