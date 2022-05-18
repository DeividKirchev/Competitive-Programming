#include <iostream>
using namespace std;
int a[100];
int n;
void sart()
{
    for (int i=0;i<n-1;i++)
    {
        if(i%2==0)
        {
            if(a[i]<a[i+1])swap(a[i],a[i+1]);
        }
        if(i%2==1)
        {
            if(a[i]>a[i+1])swap(a[i],a[i+1]);
        }

    }
}
void read()
{

    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
}
void output()
{
    for (int i=0;i<n-1;i++)
        cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}
int main ()
{
    read();
    sart();
    output();
    return 0;
}

