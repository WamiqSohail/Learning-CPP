#include <iostream>
using namespace std;

class Vol
{
    private:
        int area;
    public:
        int b;
    protected:
        int l;
        int h;
        void set_Area(int l, int b)
        {
             area = l * b;
        }
        int get_Area()
        {
            return area;
        }
};

class A1 :public Vol
{
    public:
        void set_length(int x)
        {
            l = x;
        }
        int get_length()
        {
            return l;
        }
        void set_height(int c)
        {
            h = c;
        }
        int get_height()
        {
            return h;
        }
        void Volumn(int l,int b, int h)
        {
            cout << "Volumn is = " << l * b * h << endl;
        }
        void Area(int l,int b)
        {
            int A;
            set_Area(l,b);
            A = get_Area();
            cout << " Area is = " << A << endl;
        }
};

int main()
{
    A1 rect;
    int len,hei,a,c;
    cout << "Enter length = ";
    cin >> len;
    cout << "\nEnter height = ";
    cin >> hei;
    cout << endl;
    rect.b = 25;
    rect.set_length(len);
    a = rect.get_length();
    rect.set_height(hei);
    c = rect.get_height();
    rect.Area(a,rect.b);
    rect.Volumn(a,rect.b,c);
    return 0;
}