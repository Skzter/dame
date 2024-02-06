#include<iostream>

int main()
{
		char a = 2;
		char b = 3;
		std::cout << "Ausgang: " << a << "\n";
		std::cout << "Ziel: " << b << "\n";

		std::cout << "a + 1: " << a+1 << "\n";
		std::cout << "a++: " << a++ << "\n";

		std::cout << "Ist a++ gleich b? \n"; 
		if(b == a++)
		{
			std::cout << "Ja \n";
		}
		else
		{
			std::cout << "ne \n";
		}

}