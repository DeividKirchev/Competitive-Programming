#include <iostream>
#include <queue>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;
int n;
vector <int> a[1000];
vector <string> name;
int island[1000];
int m;
void bfs(int p,int num)
{
    queue <int> q;
    q.push(p);
    island[p]=num;
    while(!q.empty())
        {
    for (int i=0;i<a[q.front()].size();i++)
    {
        if(island[a[q.front()][i]]==0)
        {
            island[a[q.front()][i]]=num;
            q.push(a[q.front()][i]);
        }
    }
    q.pop();
        }
}
void bfsout(int p)
{
    sort(name.begin(),name.end());
    for (int i=0;i<n;i++)
    {
        if(island[i]==p)
        {
            for (int j=0;j<a[i].size();j++)
                cout<<name[i]<<" <-> "<<name[a[i][j]]<<endl;
        }
    }
}
void islands()
{
    int t=1;
    for (int i=0;i<n;i++)
    {
        if(island[i]==0)
        {
            bfs(i,t);
            t++;
        }
    }
    //for (int i=0;i<n;i++)cout<<island[i];
}
int getIslandSize(int p)
{
    int sum=0;
    for (int i=0;i<n;i++)
    {
        if(island[i]==p)sum++;
    }
    return sum;
}
bool used[1000];
int check3(int p)
{
        for (int i=0;i<n;i++)
    {
        if(island[i]==p && a[i].size()!=3)return -1;
    }
    return 4;
}
int check2 (int p)
{
    for (int i=0;i<n;i++)
    {
        if(island[i]==p && a[i].size()!=2)return -1;
    }
    return 3;
}
int checkNexus(int p)
{
    int br = getIslandSize(island[p]);
    queue <int> q;
    q.push(p);
    for (int i=0;i<n;i++)used[i]=0;
    used[p]=true;
    bool f2=0;
    if(br==4)return check3(island[p]);
    if (br==3)return check2(island[p]);
    if (br==2 or br==1) return -1;
    while(!q.empty())
        {
    for (int i=0;i<a[q.front()].size();i++)
    {
        int sizer = a[q.front()].size();
        if(sizer!=3 and sizer!=br-1)return -1;
        if (sizer == br-1 and f2==true)return -1;
        if (sizer == br-1)f2=true;

        if(used[a[q.front()][i]]==0)
        {
            used[a[q.front()][i]]=true;
            q.push(a[q.front()][i]);
        }
    }
    q.pop();
        }
        if(f2==false)return -1;
        else return br;
}
void output()
{
    int minn=10000000;
    int minpos=0;
    for (int i=0;i<n;i++)
    {
        if (used[i]==0)
        {
            int t=checkNexus(i);
            //cout<<t<<endl;
            if(t==-1)continue;
            if(t<minn)
            {
                minn=t;
                minpos=i;
            }
        }
    }
    bfsout(island[minpos]);

}
void read()
{
    cin>>m;
    for (int i=0;i<m;i++)
    {
        string x,y;
        cin>>x;
        cin>>y;
        int p1=-1,p2=-1;
        for (int t=0;t<name.size();t++)
        {
            if(x==name[t])p1=t;
            if(y==name[t])p2=t;
        }
        if(p1==-1)
        {
            name.push_back(x);
            p1=name.size()-1;
        }
        if(p2==-1)
        {
            name.push_back(y);
            p2=name.size()-1;
        }
        a[p1].push_back(p2);
        a[p2].push_back(p1);
    }
    n=name.size();
    /*for(int i=0;i<n;i++){
        for (int j=0;j<n;j++)
        {cout<<a[i][j]<<" ";}
        cout<<endl;
    }*/
    islands();
}
int main ()
{
    read();
    output();
    return 0;
}
/*
13
A1 B
A1 C
A1 D
B C
B E
C D
C E
D E
F G
F H
F I
G H
G I



*/
