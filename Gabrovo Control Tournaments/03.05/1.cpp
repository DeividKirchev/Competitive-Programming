#include <iostream>
#define MOD 1020847
using namespace std;
int n,m;
int fence[2000][2000];
int rec (int last,int br,bool used[2000],int pos)
{
    if(pos==n)
    {
        if (br==m)return 1;
        else return 0;
    }
    used[last]=true;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        //cout<<"last - I "<<last<<" - "<<i<<endl;
        //for (int j=1;j<=n;j++)cout<<used[j];
        //cout<<endl;
        if(used[i]==0)
        {
            //cout<<"br "<<br<<endl;

            if(br==m)
            {
                if(last<i)break;
                bool used1[2000];
                for (int j=1;j<=n;j++)used1[j]=used[j];
                sum=sum+rec(i,br,used1,pos+1);
            }
            if(br<m)
            {
                if(last<i)
                {
                    bool used1[2000];
                     for (int j=1;j<=n;j++)used1[j]=used[j];
                sum=sum+rec(i,br+1,used1,pos+1);
                }
                if(last>i)
                {
                    bool used1[2000];
                     for (int j=1;j<=n;j++)used1[j]=used[j];
                sum=sum+rec(i,br,used1,pos+1);
                }
            }
        }
    }
    return sum%MOD;

}
void read()
{
    cin>>n>>m;
}
int main ()
{
    read();
    bool used[2000];
    for(int i=0;i<=n;i++)used[i]=false;
    cout<<rec(0,0,used,0)<<endl;
    return 0;
}
