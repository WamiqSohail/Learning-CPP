#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <numbers>
#include <ranges>
#include <vector>

template<typename T>
void pretty_print(T &iterator_able,std::string && st);

/*
    Your code goes here
*/
std::vector <float> result;

void medianfilter(std::array<float,100> arr, int N)
{
    float temp;
    float window[N];
    for (int i = 0; i < 100 ;i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i+N) > 100)
            {
                continue;
            }
            else
            {
                window[j] = arr[i + j];
            }
        }
        for (int k=0;k<N;k++)
        {
            for (int l=k+1;l<N;l++)
            {
                if (window[k] > window[l])
                {
                    temp=window[l];
                    window[l]=window[k];
                    window[k]=temp;
                }
            }
        }
        if ((i+N) <= 100)
        {
            if (N%2==0)
            {
                result.push_back((window[N/2]+window[(N/2)+1])/2);
            }
            else
            {
                result.push_back(window[N/2]);
            }
        }
    }
}


int main()
{
    std::random_device rd;
    std::mt19937 twister(rd());
    std::uniform_real_distribution<float> dis(-0.5,0.5);
    std::array<float,100> samples;
    for(auto& _a : samples)
        _a = dis(twister);
    pretty_print(samples,"Input Samples");
    std::cout<<std::endl;
    std::cout<<std::endl;

    medianfilter(samples,19);

    pretty_print(result,"Moving Median Filter");
    /*
        Pretty print your vector into the function to see output
    */
}

template<typename T>
void pretty_print(T &iterator_able,std::string && st)
{
    std::cout<<"-------"<<st<<"-------"<<std::endl;
    int i =0;
    for(auto & element:iterator_able)
    {
        if((i%5)==0)
            std::cout<<std::endl;
        if(element<0)
            std::cout<<std::setprecision(2)<<element<<" ";
        else
            std::cout<<" "<<std::setprecision(2)<<element<<" ";
        i++;
    }
}
