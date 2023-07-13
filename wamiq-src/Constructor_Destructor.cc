#include <iostream>
using namespace std;

class volumn
{
    public:
        int length;
        int breath;
        int height;
        volumn (int a ,int b ,int c)
        {
            length = a;
            breath = b;
            height = c;
        }
        ~volumn()
        {
            
        };
};

int main()
{
    volumn V1(10 , 15 , 20);
    volumn V2(2 , 4 , 6);
    cout << V1.length << " " << V1.breath << " " << V1.height << endl;
    cout << V2.length << " " << V2.breath << " " << V2.height << endl;
    cout << "Volumn of V1 = " << V1.length * V1.breath * V1.height << endl;
    cout << "Volumn of V2 = " << V2.length * V2.breath * V2.height;
    return 0;
}