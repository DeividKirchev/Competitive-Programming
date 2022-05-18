#include <iostream>

#include <queue>
#define val first
#define pos second
using namespace std;
queue <pair<int,int>> q;
int m,n,v;
int r[50];
void read()
{
    cin>>n;
    for (int i=0;i<n;i++)cin>>r[i];
    cin>>v>>m;
}
void bfs()
{
    q.push(make_pair(v,-1));
    while(!q.empty())
    {
        if(q.front().pos==n-1)break;
        if(q.front().pos<n)
        {
            if(!(q.front().val+r[q.front().pos+1]>m or q.front().val==-1))
            {
                q.push(make_pair(q.front().val+r[q.front().pos+1],q.front().pos+1));
            }
            if(!(q.front().val-r[q.front().pos+1]<0 or q.front().val==-1))
            {
                q.push(make_pair(q.front().val-r[q.front().pos+1],q.front().pos+1));
            }
        }
        q.pop();
    }
}
void output()
{
    int maxi=-1;
    while(!q.empty())
    {
        maxi=max(maxi,q.front().val);
        q.pop();
    }
    cout<<maxi<<endl;
}
void start()
{
    bfs();
    output();

}
int main ()
{
    read();
    start();
    return 0;
}
