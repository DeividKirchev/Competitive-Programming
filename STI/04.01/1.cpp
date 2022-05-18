#include <iostream>
using namespace std;

int n,k;
int a[300000];
bool l[300000];
pair <double,int> dynl[300000];
pair <double,int> dynr[300000];
int findL()
{
    int maxi=0;
    int maxpos =0;
    for(int i=0;i<n;i++)
    {
        if(maxi<a[i] && l[i]==false)
        {
            maxi=a[i];
            maxpos=i;
        }
    }
    l[maxpos]=true;
    return maxpos;
}
void read()
{
        cin>>n;
    cin>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
}
int getl(int start)
{
    for(int i=start-1;i>0;i--)
    {
        if(l[i]==true)return i;
    }
    return 1;
}
int getr(int start)
{
    for(int i=start+1;i<n;i++)
    {
        if(l[i]==true)return i;
    }
    return n-1;
}
double getsa(int start)
{
    int br=0;
    double maxsa=0;
    int nl = getl(start);
    int nr = getr(start);
    //cout<<nl<<" --- "<<nr<<endl;
    for(int i=start;i<=nr;i++)
    {
        br=br+a[i];
        if(i-start+1>=k)
        {
            double sa = br/double(i-start+1);
            if(maxsa<sa)
            {
                maxsa=sa;
                dynr[start] = make_pair(maxsa,i-start+1);
            }
        }
    }
    br=br-a[nr];
    double sa=(br+dynr[nr].first*dynr[nr].second)/(nr-start+dynr[nr].second);
    //cout<<sa<<endl;
    if(sa>maxsa && nr-start+dynr[nr].second>=k)
    {
        maxsa=sa;
        dynr[start] = make_pair(maxsa,nr-start+dynr[nr].second);
    }
    br=0;
    for(int i=start;i>=nl;i--)
    {
        br=br+a[i];
        if(start-i+1>=k)
        {
            double sa = br/double(start-i+1);
            if(maxsa<sa)
            {
                maxsa=sa;
                dynl[start] = make_pair(maxsa,start-i+1);
            }
        }
    }
    br=br-a[nl];
    sa=(br+dynl[nl].first*dynl[nl].second)/(nl-start+dynl[nl].second);
    if(sa>maxsa && start-nl+dynl[nl].second>=k)
    {
        maxsa=sa;
                dynl[start] = make_pair(maxsa,start-nl+dynl[nl].second);
    }
    return maxsa;
}
void calc()
{
    dynl[0].first = a[0];
    dynr[n-1].first = a[n-1];
    dynl[0].second= 1 ;
    dynr[n-1].second =1;
    l[0]=true;
    l[n-1]=true;
    double maxsa;
    while(true)
    {
        double sa = getsa(findL());
        if(sa<maxsa)break;
        maxsa=sa;
    }
    for(int i=0;i<950;i++)
    {
        double sa = getsa(findL());
        if(sa<maxsa)continue;
        maxsa=sa;
    }
    cout<<maxsa<<endl;
}
int main()
{
    read();
    calc();
    return 0;
}
