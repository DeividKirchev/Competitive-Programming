#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int m;

int zav[10];
int fact (int x)
{
    if(x==0 or x==1)return 1;
    return x*fact(x-1);
}
void read()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)zav[i]=-1;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x;
        char trash;
        cin.get(trash);
        cin.get(trash);
        cin.get(trash);
        cin>>y;
        zav[y]=x;
    }
}

bool Check(int x)
{
    for (int i=1;i<=n;i++)if(zav[i]==x)return true;
    return false;
}
bool * copi(bool a[10])
{
          return a;
}
int rec(int x,bool used[10],int ende)
{
    if(ende==n)return 1;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        if(used[i]==0)
        {
        bool used1[10];
        *used1=copi(used);
        used1[i]=true;
        if(zav[i]!=-1)
        {
            used1[zav[i]]=false;
        }
        sum=sum+rec(i,used1,ende+1);
        }
    }
    return sum;
}
void solve()
{
    bool a[10];
    for(int i=0;i<n;i++)a[i]=0;
    for(int i=0;i<n;i++)
       if(Check(i))
          a[i]=1;
    a[0]=true;
    cout<<rec(0,a,1)<<endl;

}
int main()
{
    read();
    solve();
    return 0;
}
