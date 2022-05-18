#include <iostream>
using namespace std;
int v[1000020];
int new_v[1000020];
bool check[1000000];
int n;
void read();
long long solve();
int main ()
{
    read();
    if(n!=2)
    cout<<solve()<<endl;
    return 0;
}
int perm(int x)
{
    if (x==1 or x==0)return 1;
    return x*perm(x-1);
}
void read ()
{
    cin>>n;
    if (n==2)
    {
        int a,b;
        cin>>a>>b;
        if(a==b)cout<<0<<endl;
        else cout<<1<<endl;
        return;
    }
    int x;
    cin>>x;
    v[1]=x;
    cin>>x;
    v[2]=x;
    for (int i=3;i<=n;i++)
    {
        cin>>x;
        v[i]=x;
        if(v[i]==v[i-2])new_v[i-1]=v[i];
    }
    if(new_v[2]!=0 && new_v[2]!=v[1])
    {
        cout<<0<<endl;
        return;
    }
    new_v[2]=v[1];
    new_v[n-1]=v[n];
}
long long solve()
{
    int brodd=0;
    int breven=0;

    for (int i=2;i<=n-1;i++)
    {
        //for (int i=1;i<=n;i++)cout<<new_v[i]<<endl;
       // cout<<endl;
        if(new_v[i-1]!=0 && new_v[i-1]!=v[i])
        {
            for (int j=i;j<=n-1;j=j+2)
            {
                if(new_v[j+1]!=0 && new_v[j+1]!=v[j])
                {
                    return 0;
                }
                if(new_v[j+1]!=0 && new_v[j+1]==v[j])break;
                new_v[j+1]=v[j];
            }
        }
        if(new_v[i+1]!=0 && new_v[i+1]!=v[i])
        {
            for (int j=i;j>=2;j=j-2)
            {
                if(new_v[j-1]!=0 && new_v[j-1]!=v[j]) return 0;
                if(new_v[j-1]!=0 && new_v[j-1]==v[j])break;
                new_v[j-1]=v[j];
            }
        }
    }
    int br2=0;
    for (int i=2;i<=n-1;i++)
    {
        if(new_v[i-1]+new_v[i+1]==0)
        {
            if(i%2==0)breven++;
            else brodd++;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if(check[new_v[i]]==true)return 0;
        else if (new_v[i]!=0)check[new_v[i]]=true;
    }
    int k=0;

    int br=0;
    for (int i=1;i<=n;i++)if(check[i]==false)br++;
    //for (int i=1;i<=n;i++)cout<<new_v[i]<<endl;
    //cout<<endl;
    for (int i=3;i<=n-2;i++)if(new_v[i-2]==0 && new_v[i+2]==0 && new_v[i]==0)k++;
    br=br-breven-brodd;//cout<<k<<endl;
    return ((1<<(breven+brodd))*perm(br)-k)%(1000000000+7);
    //return (breven*brodd)%(1000000000+7);
}
/*
6
1 3 1 4 2 5
7
1 2 3 2 5 6 5
*/
