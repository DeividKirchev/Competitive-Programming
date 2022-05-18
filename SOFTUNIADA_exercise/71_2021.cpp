#include <iostream>
using namespace std;
int m,n,v;
int r[50];
void read()
{
    cin>>n;
    for (int i=0;i<n;i++)cin>>r[i];
    cin>>v>>m;
}
int dfs(int val,int pos)
{
    if(val>m or val<0)return -1;
    if(pos==n-1)return val;
    return max(dfs(val-r[pos+1],pos+1),dfs(val+r[pos+1],pos+1));
}
int main ()
{
    read();
    cout<<dfs(v,-1)<<endl;
    return 0;
}
