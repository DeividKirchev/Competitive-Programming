#include <iostream>
#include <string>
using namespace std;
string s;
int a[10000001];
int n;
void read()
{
    getline(cin,s);
    n=s.size();
}
int nod (int x,int y)
{
    if(x<y)swap(x,y);
    int r;
    while (y>0)
     {
    x=x%y;
    swap(x,y);
     }
  return x;
}
void prefix()
{
    for (int i=1;i<n;i++)
    {
        int j = a[i-1];
        while (j > 0 && s[i]!=s[j])
            j = a[j-1];
        if (s[i] == s[j])
            j++;
        a[i] = j;
    }

    /*for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    cout<<endl;*/
}
void solve()
{
    prefix();
    int t=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]<i+1-a[i] or (i+1)%(i+1-a[i])!=0)continue;
        cout<<i+1<<" "<<nod(a[i],i+1)<<"\n";
    }
}
int main ()
{
    read();
    solve();
    return 0;
}
