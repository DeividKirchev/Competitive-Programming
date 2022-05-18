#include <iostream>
using namespace std;
int getDays(string time)
{
    int days=0;
    int i=0;
    while(true)
    {
        if(time[i]==':' && time[i+1]==':')return days;
        else if (time[i]==':')return 0;
        days=days*10+time[i]-'0';
        i++;
    }
}
int timeconv (string time)
{
    int l = time.size()-1;
    int mins=((time[l-1]-'0'))*10+(time[l]-'0');
    if(l<4 or time[l-4]==':')
    {
    mins=mins+(time[l-3]-'0')*60;
    }
    else mins=mins+((time[l-4]-'0')*10+(time[l-3]-'0'))*60;
    mins=mins+getDays(time)*24*60;
    return mins;
}
int main ()
{
    int mins1,mins2;
    string time;
    getline(cin,time);
    mins1=timeconv(time);
    getline(cin,time);
    mins2=timeconv(time);
    mins1+=mins2;
    if(mins1/(24*60)>0)
    {
        cout<<mins1/(24*60)<<"::";
        mins1=mins1%(24*60);
    }
    cout<<mins1/60<<":";
    mins1=mins1%60;
    if(mins1<10)cout<<0;
    cout<<mins1<<endl;
    return 0;
}
