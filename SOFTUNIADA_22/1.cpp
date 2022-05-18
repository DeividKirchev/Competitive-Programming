#include <iostream>
using namespace std;
int nod (int a,int b)
{
    if (a>b)swap(a,b);
    while(a!=0)
    {
        b=b%a;
        swap(a,b);
    }
    return b;
}
int main ()
{
    int a,b;
    cin>>a>>b;
    int x=nod(a,b);
    cout<<x+(a/x)*b<<endl;;
    return 0;
}
