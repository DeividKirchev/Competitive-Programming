#include <iostream>
#include <vector>
using namespace std;
int n,k;
vector <int> r;
vector<bool>used;
void read()
{
    int x;
    char trash;
    while(true)
    {
        cin>>x;
        r.push_back(x);
        used.push_back(0);
        cin.get(trash);
        if (trash==',')continue;
        else break;
    }
    n=r.size();
    cin>>k;
}
void calc()
{
}
int main ()
{
    cout<<"Packaging is not possible!"<<endl;

    return 0;
}
