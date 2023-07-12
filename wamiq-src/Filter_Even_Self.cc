#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <random>

// Pushback , Erase, Pop()
void FilterOnlyEvens(std::vector<int> &a)
{
    for (int j=0;j<a.size();j++)
    {
        if (a[j]%2!=0)
        {
            a.erase(a.begin()+j);
            j-=1;
        }
    }
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
    for (int i=0;i<(sizeof(_array)/sizeof(_array[0]));i++)
    {

        list.push_back(_array[i]);
    }
    FilterOnlyEvens(list);
    std::cout<<"\n Vector Output :";
    // auto listView
    for(auto & elem:list)
        std::cout<<elem<<" ";
    std::cout<<std::endl;
    return 0;
}