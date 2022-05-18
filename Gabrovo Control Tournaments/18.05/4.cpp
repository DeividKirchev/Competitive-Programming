#include <iostream>
using namespace std;
int n,m;
int a[500000];
int b[10000][10000];
int calc(int x,int y)
{
    bool t[500000];
    for(int i=0;i<n;i++)t[i]=false;
    for(int i=x;i<=y;i++)
    {
        t[a[i]]=true;
    }
    for(int i=0;i<n;i++)
    {
        if(t[i]==false)return i;
    }
}
void solve()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            b[i][j]=calc(i,j);
    }

    for(int t=0;t<m;t++)
    {
        char c;
        cin>>c;
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        //cout<<"here"<<endl;
        if(c=='?')cout<<b[x][y]<<endl;
        else
        {
             a[x]=y+1;
             for(int i=0;i<n;i++)
             {
                 for(int j=0;j<n;j++)
                    {
                        if(x>=i && x<=j)
                            {
                                   b[i][j]=calc(i,j);
                            }
                    }
             }
        }
    }
}
void read()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    solve();
}
int main ()
{
    read();
    return 0;
}
