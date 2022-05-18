#include <iostream>
using namespace std;
int main()
{
    int n,k;
    double sr = 0;
    int br=0;
    int maxi = 0;
    int a[10000];
   cin>>n>>k;
   int j;
   for(int j=k;j<n;j++){
    for (int i=0;i<n;i++)
    {
        //cout<<sr<<endl;
        cin>>a[i];
        if(br==k)
        {
            maxi=max(maxi,(int)sr);
            sr=sr-a[i-k];
            sr=sr+a[i];
            continue;
        }
        br++;
        sr=sr+a[i];
    }
   }
    cout<<sr/k<<endl;
    return 0;
}
