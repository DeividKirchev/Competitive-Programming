#include <iostream>
#include <string>
using namespace std;
    string name;
void ToUpper()
{
    for (int i=0;i<name.length();i++)
        name[i]=toupper(name[i]);
}
void ch (char x,int n)
{
    for (int i=0;i<n;i++)cout<<x;
}
void top(int n)
{
    for (int i=0;i<n;i++)
    {
        ch(' ',n);
        cout<<"~ ~ ~"<<endl;
    }
}
void cup (int n)
{
    ch('=',3*n+5);
    cout<<endl;
    for(int i=0;i<(n-2)/2;i++)
    {
        cout<<'|';
        ch('~',2*n+name.length());
        cout<<'|';
        ch(' ',n-1);
        cout<<'|';
        cout<<endl;
    }

        cout<<'|';
        ch('~',n);
        ToUpper();
        cout<<name;
        ch('~',n);
        cout<<'|';
        ch(' ',n-1);
        cout<<'|';
        cout<<endl;
        int n1=n;
        if(n1%2==0)n1--;
    for(int i=0;i<(n1-2)/2;i++)
    {
        cout<<'|';
        ch('~',2*n+name.length());
        cout<<'|';
        ch(' ',n-1);
        cout<<'|';
        cout<<endl;
    }
    ch('=',3*n+5);
    cout<<endl;
}
void bot(int n)
{
    for (int i=0;i<n;i++)
    {
        ch(' ',i);
        cout<<"\\";
        ch('@',2*n+name.length()-2*i);
        cout<<"/"<<endl;
    }
    ch('-',3*n+5);
}
int main ()
{
    int n;
    cin>>n;
    char trash;
    cin.get(trash);
    getline(cin, name);
    top(n);
    cup(n);
    bot(n);
    return 0;
}

