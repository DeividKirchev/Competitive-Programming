#include<iostream>
using namespace std;
string s,s1;
int n;
void read()
{
    getline(cin,s);
    n=s.size();
}
bool cmp (string a,int i,int j)
{
    int t=0;
    for (i=i;i<=j;i++)
    {
        if(a[t]!=s[i])return false;
        t++;
    }
    return true;
}
void solve()
{
    s1="";
    for (int i=0;i<n/2;i++)
    {
        s1=s1+s[i];
        int si=s1.size();

        for(int j=i+1;j<n;j=j+si)
        {
            if(cmp(s1,j,j+si-1))
            {
                cout<<j+si<<" "<<si<<endl;
            }
            else break;
        }
    }
}
int main ()
{
    read();
    solve();
    return 0;
}
