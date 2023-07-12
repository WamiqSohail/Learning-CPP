#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <random>
#include<array>
#include <cstring>
#include <iomanip>


template<typename T>
void pretty_print(T &iterator_able,std::string && st);

class mov_med_filt
{
    public:
    float median_filter(float to_find_arr[], int arr_size)
    {
        float median =0;
        //finding if odd or even enteries
        int even_odd = arr_size%2;
        std::sort(to_find_arr, to_find_arr+arr_size);
        // median finding
        if(even_odd == 0)  // is even
        {
            median = (to_find_arr[(arr_size-1)/2])+(to_find_arr[((arr_size-1)/2)+1]);
            median = median/2;
        }
        else //odd
        {
            median = to_find_arr[(arr_size)/2];
        }

        return median;
    }


    std::vector<float> apply_filt(std::array<float,100> &in_arr,int wind_sz)
    {
        //checking size of input array and window size 
        
        int check = in_arr.size()%wind_sz;
        //converting input array into a vector float
        std::vector<float> copy_arr;
        std:: vector<float> filtered;
        //creating copy of input array as vector
        for(int i=0; i<100;i++)
        {
            copy_arr.push_back(in_arr[i]);
        }
        //append zeros to meet the window size
        //finding zeros to appedn to successfully let window to cover the array size till end
        int to_append = ((copy_arr.size()-check)+wind_sz)-copy_arr.size();
       if(check != 0)
        {
            for (int i =0 ; i< to_append ; i++)
            {
                copy_arr.push_back(0);
            }
        }

        
        int check_loop = copy_arr.size();
        while(check_loop > 0)
        {
            float find_med[wind_sz] = {0};
            for(int i =0; i<wind_sz ; i++)
            {
                
                find_med[i] = copy_arr.back();
                copy_arr.pop_back();
            }
        
            filtered.push_back(median_filter((find_med),wind_sz));
            check_loop =check_loop-wind_sz;
        }


       
        return  filtered;
    }    

    

    

};

int main()
{
    std::random_device rd;
    std::mt19937 twister(rd());
    std::uniform_real_distribution<float> dis(-0.5,0.5);
    std::array<float,100> samples;
    for(auto& _a : samples)
        _a = dis(twister);
    pretty_print(samples,"Input Samples");

    mov_med_filt obj1;
   // float input1[12];
    int window_size = 3;
    std::vector<float> filteredVec = obj1.apply_filt(samples,window_size);
    int i=0;
    std::cout<<"\n Filtered View : "<<filteredVec.size()<<std::endl;
    std::for_each(filteredVec.rbegin(),filteredVec.rend(),[&i](float & element){
        if((i%10)==0)
            std::cout<<std::endl;
        if(element<0)
            std::cout<<std::setprecision(2)<<element<<" ";
        else
            std::cout<<" "<<std::setprecision(2)<<element<<" ";
        i++;});
    // pretty_print(filteredVec,"Filtered Samples");

   return 0;
}


template<typename T>
void pretty_print(T &iterator_able,std::string && st)
{
    std::cout<<std::endl<<"-------"<<st<<"-------"<<std::endl;
    int i =0;
    for(auto & element:iterator_able)
    {
        if((i%10)==0)
            std::cout<<std::endl;
        if(element<0)
            std::cout<<std::setprecision(2)<<element<<" ";
        else
            std::cout<<" "<<std::setprecision(2)<<element<<" ";
        i++;
    }
}