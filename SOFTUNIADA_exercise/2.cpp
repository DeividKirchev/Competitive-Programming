#include <iostream>
using namespace std;
void line (int n,char c)
{
    for (int i=0;i<n;i++)
        cout<<c;
}
int main ()
{
    int n;
    cin>>n;
    const char c='.';
    const char c1=' ';
    const char c2='*';
    const char c3='-';
    const char c4='+';
    const char c5='|';
    line(n-1,c);
    cout<<c2;
    line(n-1,c);
    cout<<endl;
    for (int i=0;i<n-2;i++)
    {
        line(n-2-i,c);
        cout<<c2;
        line(1+i*2,c1);
        cout<<c2;
        line(n-2-i,c);
        cout<<endl;
    }

    for (int i=0;i<n;i++)
    {
        cout<<c2<<c1;
    }
    cout<<endl;
    cout<<c4;
    line(n*2-3,c3);
    cout<<c4;
    cout<<endl;
    for (int i=0;i<n-2;i++)
    {
        cout<<c5;
        line(n*2-3,c1);
        cout<<c5;
        cout<<endl;
    }
    cout<<c4;
    line(n*2-3,c3);
    cout<<c4;
    cout<<endl;
    return 0;
}
