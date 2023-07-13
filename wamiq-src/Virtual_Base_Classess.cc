#include <iostream>
using namespace std;
 
class A 
{
    public:
        int a;
        A()
        {
            a = 10;
        }
};
class B : public virtual A
{
    public:
        int b;
        B()
        {
            b = 20;
        }
};
class C : public virtual A 
{
    public:
        int c;
        C()
        {
            c = 30;
        }
};
class D : public B, public C 
{
    public:
        void Area(int b, int c)
        {
            cout<<"The Area is = "<<b*c<<endl;
        }
};
int main()
{
    int x,y,z;
    D elem;
    x= elem.a;
    y = elem.b;
    z = elem.c;
    elem.Area(y,z);
    cout<<"The Volumn is = "<<x*y*z<<endl;
    cout<<elem.a<<endl;
    return 0;
}