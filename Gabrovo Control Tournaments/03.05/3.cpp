#include <iostream>
#include <string>
#include <vector>
using namespace std;
char a[500][500];
int n;
vector <pair<int,string>>dyn[500][500];
bool checkString(string s)
{
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])return 0;
    }

    return 1;
}
void setdyn(string s,int posR,int posC,int sum)
{
    //cout<<s<<endl;
    for(int i=0;i<500;i++)
    {
        if(i==dyn[posR][posC].size())
        {
             pair<int,string>dyn1;
             dyn1.first=sum;
             dyn1.second=s;
            dyn[posR][posC].push_back(dyn1);
            return;
        }
        if(dyn[posR][posC][i].first!=0 && s==dyn[posR][posC][i].second)
        {
            dyn[posR][posC][i].first+=sum;
            return;
        }
    }
}
int checkdyn (string s,int posR,int posC)
{
//cout<<s<<endl;
//cout<<"POS = "<<posR<<" "<<posC<<endl;
    for(int i=0;i<500;i++)
    {
        if(i==dyn[posR][posC].size())return 0;
        if(s==dyn[posR][posC][i].second)
        {
            //cout<<111111<<endl;
            return dyn[posR][posC][i].first;
        }
    }
    return 0;
}
int rec(string s,int posR,int posC)
{
    s=s+a[posR][posC];
    if(posR==n-1 && posC==n-1)
    {
        if(checkString(s))
        {
            return 1;
        }
        else return 0;
    }

    int sum=checkdyn(s,posR,posC);
    if(sum!=0)return sum;
    if(posR!=n-1)
    {
        sum=sum+rec(s,posR+1,posC);
    }
    if(posC!=n-1)
    {
        sum=sum+rec(s,posR,posC+1);
    }
    setdyn(s,posR,posC,sum);
    return sum;
}
void read()
{
    cin>>n;
    char trash;
        cin.get(trash);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cin.get(a[i][j]);
        char trash;
        cin.get(trash);
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<a[i][j];
        cout<<endl;
    }*/

}
int main ()
{
    read();
    cout<<rec("",0,0)<<endl;
    return 0;
}
