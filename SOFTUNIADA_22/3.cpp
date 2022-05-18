#incluce <iostream>
#include <algorithm>

using namespace std;
int n;
vector <int>a[10];
int getPrice(int m)
{
    int sum=0;
    for (int i=0;i<a[m].size();i++)
        sum=sum+a[m][i];
        if(sum%3!=0)return -1;
    return sum/3;
}
void solve()
{
    for (int i=0;i<n;i++)
        {

         int pr = getPrice(i);
         if(pr==-1)
         {
             cout<<"No"<<endl;
             continue;
         }
         sort(a[i].begin().a[i].end());
         int m=a[i].size();
         for (int j=m-1;j>=0;j--)
         {

         }
        }
}
void read()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        while (true)
        {
            char trash;
            int x;
            cin>>x;
            a[i].push_back(x);
            cin.get(trash);
            if(trash==' ')continue;
            break;
        }
    }
}
int main ()
{
    read();
    solve();
    return 0;
}

