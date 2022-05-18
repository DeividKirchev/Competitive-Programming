#include <iostream>
using namespace std;
int main ()
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if (a+b==c+d)
  {
    cout<<"Yes"<<endl;
    cout<<a+b<<endl;
    return 0;
  }
  if (a+c==b+d)
  {
    cout<<"Yes"<<endl;
    cout<<a+c<<endl;
    return 0;
  }
  if (a+d==b+c)
  {
    cout<<"Yes"<<endl;
    cout<<a+d<<endl;
    return 0;
  }
  if (a+b+c==d)
  {
    cout<<"Yes"<<endl;
    cout<<d<<endl;
    return 0;
  }
  if (a+b+d==c)
  {
    cout<<"Yes"<<endl;
    cout<<c<<endl;
    return 0;
  }
  if (a+d+c==b)
  {
    cout<<"Yes"<<endl;
    cout<<b<<endl;
    return 0;
  }
  if (b+c+d==a)
  {
    cout<<"Yes"<<endl;
    cout<<a<<endl;
    return 0;
  }
  cout<<"No"<<endl;
 return 0;
}
