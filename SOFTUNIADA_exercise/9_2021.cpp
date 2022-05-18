#include <iostream>
#include <vector>
using namespace std;
vector <long long> table[101];
int n,a,b;
int pos[100];
void read()
{
    cin>>a>>b;
    cin>>n;
}
void setFirstRow()
{
    for (int i=1;i<=100;i++)
    table[i].push_back(0);
    for (int i=1;i<=100;i++)
    table[1].push_back(i);
}
void setFirstColumn()
{
    for (int i=1;i<=100;i++)table[i].push_back(1);
}
void check()
{
    for (int i=1;i<5;i++)
    {
        for (int j=1;j<5;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}
void setTable ()
{
    setFirstRow();
    setFirstColumn();
    int i,j;
    for (j=2;;j++)
    {
        for (i=2;i<=b;i++)
        {
            table[i].push_back((long long)(table[i-1][j]+table[i][j-1]-1));

        }
        if(table[b][j]>n)
        {
           // cout<<j<<"--"<<endl;
            break;
        }

    }
    pos[1]=j-1;
//cout<<"Table Done"<<endl;
}
void findNum()
{
    n=n-table[b][pos[1]]+1;
   // cout<<n<<endl;
    int k=1;
    for (int i=b-1;i>0;i--)
    {
        for (int j=pos[k];j>=1;j--)
        {
            if(n-table[i][j]>=0)
            {
                pos[k+1]=j;
                n=n-table[i][j]+1;
                j=-1;
                k++;
               // cout<<n<<endl;
            }
        }
    }
//cout<<"findNum Done"<<endl;
}
void nuli(int x)
{
    for (int i=0;i<x;i++)
    {
        cout<<0;
        a--;
    }
}
void output()
{
    for(int i=b,j=1;i>=1;i--,j++)
       pos[j]=pos[j]+i-1;

    nuli(a+b-pos[1]);
    cout<<1;
    for (int i=2;i<=b;i++)
    {
        nuli(pos[i-1]-pos[i]-1);
        cout<<1;
    }
    nuli(a);
    cout<<endl;

}
int main ()
{
    read();
    setTable();
    findNum();
    output();
    return 0;
}
