#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <random>

// Pushback , Erase, Pop()
void FilterOnlyEvens(std::vector<int> &a)
{

}

int main()
{
    std::random_device rd;
    std::mt19937 twister(rd());
    std::uniform_int_distribution<int> dist(1,100);
    std::array<int,15> _array;
    for(auto& a: _array)
    {
        a = dist(twister);
        std::cout<<a<<" ";
    }
    std::vector<int> list;
    FilterOnlyEvens(list);
    std::cout<<"\n Vector Output :";
    // auto listView
    for(auto & elem:list)
        std::cout<<elem<<" ";
    std::cout<<std::endl;
    return 0;
}