#include<iostream>
#include<sstream>

int main()
{
	std::string zug = "xxxxxxx";

	char B1, B2;
	int Z1, Z2;
	
	do{
		std::getline(std::cin, zug);
		std::stringstream test(zug);
		
		test >> B1 >> Z1 >> B2 >> Z2;
	}while(!((B1 >= 'A' && B1 <= 'J') && (Z1 >= 1 && Z1 <= 10) && (B2 >= 'A' && B2 <= 'J') && (Z2 >= 1 && B2 <= 10)));


	
	std::cout << B1 << Z1 << " " << B2 << Z2;
}
