#include <iostream>
#include <vector>

// Ascending order sort 
void SortV1(std::vector<int> &a)
{
    //Logic
    int temp;
    for (int i=0;i<a.size();i++)
    {
        for (int j=i+1;j<a.size();j++)
        {
            if (a[i] > a[j])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
}

int main()
{
    std::vector<int> list({-14,13,18,19,200,-201,144,150});
    SortV1(list);
    for(auto & elem:list)
        std::cout<<elem<<" ";
    std::cout<<std::endl;
    return 0;
}