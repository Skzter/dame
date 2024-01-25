#include<iostream>

int main()
{
	std::cout << "\{";
	char buchstabe = 'A';
	for(int i = 10; i >= 1; i--)
	{
	std::cout << "\{";
		for(int j = 10; j >= 1; j--)
		{
			if(j==1)
			{
				std::cout << "\"" << buchstabe << i << "\""; 
			}
			else
			{
				std::cout  << "\"" << buchstabe << i  << "\"" << ",";
			}
			buchstabe++;
		}
	buchstabe = 'A';
	std::cout << "\}" << "\,";
	std::cout << "\n";
	}
	std::cout << "\}";
}
