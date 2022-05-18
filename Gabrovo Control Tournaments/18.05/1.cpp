#include <iostream>
using namespace std;
int a[1000000];
int n;
void read()
{
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void solve ()
{
    int br=0;
    int i=0,j=n-1;
    while(i<j)
    {
        if(a[i]==a[j])
           {
                i++;
                j--;
                continue;
           }
        if(a[i]<a[j])
        {
            br++;
            i++;
            a[i]=a[i]+a[i-1];
            continue;
        }
        if(a[i]>a[j])
        {
            br++;
            j--;
            a[j]=a[j]+a[j+1];
            continue;
        }
    }
    cout<<br<<endl;
}
int main()
{
    read();
    solve();
    return 0;
}
