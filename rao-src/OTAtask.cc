#include<iostream>
#include<sstream>
#include<string>
#include<vector>

class ota 
{   private:
    std::vector<int> secondpass;
    std::stringstream ss;
    int sum ;

    public:

    void acquire_string()
    {   std::string s;
        //getline(std::cin,s);
        s = "11 12 13";
        
        ss.str(s);
        std::cout <<"size: "<< ss.str().size()<<std::endl;
    }

    





    std:: vector<std::string> seperate(std::string sepr)
    {
        sepr = "8 pop 8 dup 11 12 13 pop 11 dup ";
        std::vector<std::string> firstpass;
        std::string temp;
        for(int i=0; i<=sepr.length();i++)
        {  
            if(sepr[i] != ' ' && sepr[i]!=0)
            {   
                temp+= sepr[i];
                
            }
            if((sepr[i] == ' ') || (sepr[i]==0))
            {
                //firstpass.push_back(",");
                firstpass.push_back(temp);
                temp.clear();
            }
            
        }

        for(int i=0; i<firstpass.size();i++)
        {
            std::cout<< firstpass[i]<<std::endl;
        }

        return firstpass;
        
    }

    std::vector<int> create_vect(std::vector<std::string>pass )
    {   

        
        std::cout<<pass.size()<<pass[3].length()<<std::endl;
        
        for(int i=0; i<pass.size()-1;i++)
        {   
            
            std::cout<<"Element : "<<pass[i]<<std::endl;
           if(pass[i]=="pop")
            {   
                std::cout<< "pop exec";
                secondpass.pop_back();
                std::cout<<"Element : "<<secondpass[i-1]<<std::endl;
                
            }
            else if(pass[i] == "dup")
            {
                secondpass.push_back(secondpass.back());
                std::cout<< "dup exec"<< std::endl;
            }
            else if (pass[i]== "dup" && i==0)
            {
                ;
            }
            else
            {
                std::cout<<"continue "<<pass[i]<<std::endl;
                std::stringstream ss(pass[i]);
                int str_num;
                ss>>str_num;
                secondpass.push_back(str_num);
            }
        }

        for(int i=0; i<secondpass.size();i++)
        {
            std::cout<< secondpass[i];
        }
        return secondpass;
    }

    int getsum()
    {   sum = 0;
        
        for (int i=0 ; i<secondpass.size();i++)
        {
            sum+= secondpass[i];       
           
           // std::cout <<"sum : "<< num <<std::endl;
           // std::cout <<"last num : "<< lastnum <<std::endl;
            
        }
        std::cout <<"\n"<<sum;
        return sum;
    }

     

};

int main()
{
    ota a;
    a.acquire_string();
    std::string sepr = "11 12 13";
   std:: vector<std::string> seperate= a.seperate(sepr);
   
   a.create_vect(seperate);
   a.getsum();

    return 0;
}