#include <iostream>
using namespace std;
short n,m,a1,b1,k1;
void read()
{
    cin>>n>>m>>a1>>b1>>k1;
}
int calc(int p,int k,int a)
{
    //cout<<p<<" "<<k<<" "<<a<<endl;
    if(p-(k*a)>0)return 0;
    if (p==0)return 1;
    int x=0;
    for (int i=p;i>=p-a && i>=0;i--)x=x+calc(i,k-1,a);
    return x;
}
int main ()
{
    read();
    int t=calc(n,k1,a1)*calc(m,k1,b1);
    cout<<t<<endl;
    return 0;
}
