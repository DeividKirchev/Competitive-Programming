#include <iostream>
#include <vector>
using namespace std;
int a[300000];
int n;
double k;
vector <int> sbor[300000];
double sa = 0;
void read()
{
    cin>>n;
    cin>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void calc()
{
    sbor[0].push_back(a[0]);
    if(k==1)sa=sbor[0][0];
    for(int i=1;i<n;i++)
    {
        sbor[0].push_back(sbor[0][i-1]+a[i]);
        double sa1 = sbor[0][i]/double(i+1);
        if(i+1>=k && sa1>sa)sa=sa1;
    }

    for(int i=1;i<n-k+1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            //cout<<sa<<endl;
            sbor[i].push_back(sbor[i-1][j+1]-a[i-1]);
            double sa1 = sbor[i][j]/double(j+1);
           // cout<<sa1<<endl;
            if(j+1>=k && sa1>sa)sa=sa1;
        }

    }
    cout<<sa<<endl;
}
int main()
{
    read();
    calc();

    return 0;
}
