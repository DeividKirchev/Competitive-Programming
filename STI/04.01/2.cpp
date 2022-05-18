#include <iostream>
#define p first
#define r second
using namespace std;
int a[200000];
int n,q;
void getPoints(int l,int r)
{
    int br=0;
    int pos=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(pos%2!=0 && i+1>=l && i+1<=r)
        {
            maxi=max(maxi,a[i]);
        }
        if(a[i] == -1)
        {
            pos++;
            br=br+maxi;
            maxi=0;
        }
    }
    cout<<br<<endl;
}
void read()
{
    cin>>n>>q;
    int z,x,y;
    for(int i=0;i<q;i++)
    {
        cin>>z;
        if(z==1)
        {
            cin>>x;
            a[x]=true;
        }
        if(z==2)
        {
            cin>>x;
            a[x].r=false;
        }
        if(z==3)
        {
            cin>>x>>y;
            a[x].p =a[x].p+y;
        }
        if(z==4)
        {
            cin>>x>>y;
            getPoints(x,y);
        }
    }
}
int main()
{
    read();
    return 0;
}
