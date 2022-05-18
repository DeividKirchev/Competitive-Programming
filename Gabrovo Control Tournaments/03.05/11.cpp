#include <iostream>
#include <algorithm>
#define INT_MAX 1000000000
using namespace std;
int n,m;
int a[1000][1000];
int dyn[1000][1000];
int rec(int posR,int posC,int sum)
{
    //cout<<sum<<endl;
    sum=sum+a[posR][posC];
    if(dyn[posR][posC]!=0)return sum+dyn[posR][posC];

    if(posC==m-1)return sum;

    int min1,min2,min3;
    if(posR!=0)min1=rec(posR-1,posC+1,sum);
    else min1=INT_MAX;
    min2=rec(posR,posC+1,sum);
    if(posR!=n-1)min3=rec(posR+1,posC+1,sum);
    else min3=INT_MAX;
    int x=min(min1,min(min2,min3));
    dyn[posR][posC]=x-sum;
    return x;
}
void read()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)cin>>a[i][j];
}
int main ()
{
    read();
    int sum1 = INT_MAX;
    for(int i=0;i<n;i++)sum1=min(sum1,rec(i,0,0));
    cout<<sum1<<endl;
    return 0;
}
