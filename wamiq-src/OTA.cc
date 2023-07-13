#include iostream
#include vector
#include sstream
#include string
#include cmath
using namespace std;

class ota
{
    private
    int number,sum;
    string s;
    vectorint a;
    string S, T;
    stringstream X;
    public
    string get_string()
    {
        getline(cin, S);
        return S;
    }
    int add(vectorint a) 
    {
        sum=0;
        for (int y = 0; y  a.size(); y++)
        {
            sum += a[y];
        }
        return sum;
    }
    vectorint separate(string s)
    {
        stringstream X(s);
        string pop(pop);
        string dup(dup);
        while (getline(X, T, ' '))
        {
            if (isdigit(T[0]))
            {
                number = stoi(T);
                a.push_back(number);
            }
            else
            {
                sum=add(a);
                if (T.compare(pop)==0)
                {
                    if (sum == 0)
                    {
                        sum = -1;
                        cout  sum  endl;
                        break;
                    }
                    sum -= a.back();
                    a.pop_back();
                    if (a.empty())
                    {
                        sum = -1;
                        cout  sum  endl;
                        break;
                    }
                }
                else if (T.compare(dup)==0)
                {
                    if (sum == 0)
                    {
                        sum = -1;
                        cout  sum  endl;
                        break;
                    }
                    sum += a.back();
                    a.push_back(a.back());
                }
            }
        }
        cout  nSum is   sum  endl;
        return a;
    }
};

int main()
{
    vectorint T;
    string th;
    ota swiss;
    th = swiss.get_string();
    T = swiss.separate(th);
    for (int y = 0; y  T.size(); y++)
    {
        cout  T[y]  ' ';
        sum += a[y];
    }

}
    int number, sum;
    sum = 0;
    string pop(pop);
    string dup(dup);

    vectorint a;
    string S, T;
    getline(cin, S);
    stringstream X(S);
    while (getline(X, T, ' '))
    {
        if (isdigit(T[0]))
        {
            number = stoi(T);
            a.push_back(number);
            sum += number;
            cout  sum  endl;
            len = T.length();
            sum = 0;
            for (int i = 0; i  len; i++)
            {
                number = (T[i] - '0');
                number = number  pow(10, len - i - 1);
                sum += number;
            }
         }
        else
        {
            if (T.compare(pop)==0)
            {
                if (sum == 0)
                {
                    sum = -1;
                    cout  sum  endl;
                    break;
                }
                sum -= a[a.size() - 1];
                sum -= a.back();
                a.pop_back();
                if (a.empty())
                {
                    sum = -1;
                    cout  sum  endl;
                    break;
                }
            }
            else if (T.compare(dup)==0)
            {
                if (sum == 0)
                {
                    sum = -1;
                    cout  sum  endl;
                    break;
                }
                sum += a[a.size() - 1];
                sum += a.back();
                a.push_back(a.back());
            }
        }
    }
    for (int y = 0; y  a.size(); y++)
    {
        cout  a[y]  ' ';
        sum += a[y];
    }
    cout  nSum is   sum  endl;
    return 0;
}