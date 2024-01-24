#include<iostream>
#include<vector>

int main()
{
std::vector<std::pair<char, int>>Liste = {};
Liste.push_back(std::make_pair('A', 1));
Liste.push_back(std::make_pair('A', 2));
std::cout << Liste.at(0) << "----" << Liste.at(1);
}
