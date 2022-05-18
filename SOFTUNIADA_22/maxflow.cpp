#include <iostream>
#include <queue>
using namespace std;
struct block {
    int h,w,l;
};
block x[1000];
block graph[1000][1000];
int n;
void read()
{

    cin>>n;
    for (int i=0;i<n;i++)
    {
        int h,w,l;
        cin>>h>>w>>l;
        x[i].h=h;
        x[i].w=w;
        x[i].l=l;
    }

}
void getGraph()
{
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            if(x[i].w >= x[j].w && x[i].l >= x[j].l)graph[i][j].h=x[j].h;
            else graph[i][j].h=0;
            if(x[i].h >= x[j].h && x[i].l >= x[j].l)graph[i][j].w=x[j].w;
            else graph[i][j].w=0;
            if(x[i].w >= x[j].w && x[i].h >= x[j].h)graph[i][j].l=x[j].l;
            else graph[i][j].l=0;
        }
    }
}
void rec (int pos,int height,char p)
{

}
int main ()
{

    return 0;
}
