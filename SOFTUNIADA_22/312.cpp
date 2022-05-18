#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;

bool subsetSum(vector<int> const &S, int n, int a, int b, int c, auto &lookup)
{
    if (a == 0 && b == 0 && c == 0) {
        return true;
    }
    if (n < 0) {
        return false;
    }

    string key = to_string(a) + "|" + to_string(b) + "|" + to_string(c) +
                "|" + to_string(n);
    if (lookup.find(key) == lookup.end())
    {
        bool A = false;
        if (a - S[n] >= 0) {
            A = subsetSum(S, n - 1, a - S[n], b, c, lookup);
        }

        bool B = false;
        if (!A && (b - S[n] >= 0)) {
            B = subsetSum(S, n - 1, a, b - S[n], c, lookup);
        }
        bool C = false;
        if ((!A && !B) && (c - S[n] >= 0)) {
            C = subsetSum(S, n - 1, a, b, c - S[n], lookup);
        }
        lookup[key] = A || B || C;
    }
    return lookup[key];
}
vector <int>a[10];
int getPrice(int m)
{
    int sum=0;
    for (int i=0;i<a[m].size();i++)
        sum=sum+a[m][i];
        if(sum%3!=0)return -1;
    return sum/3;
}
bool partition(vector<int> const &S)
{
    int n = S.size();
    if (n < 3) {
        return false;
    }
    unordered_map<string, bool> lookup;

    int sum = accumulate(S.begin(), S.end(), 0);

    return !(sum % 3) && subsetSum(S, n - 1, sum/3, sum/3, sum/3, lookup);
}

void read()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        while (true)
        {
            char trash;
            int x;
            cin>>x;
            a[i].push_back(x);
            cin.get(trash);
            if(trash==' ')continue;
            break;
        }
        if (getPrice(i)==-1)
        {
            cout <<"No"<<endl;
            continue;
        }
        bool t = partition(a[i]);
        if (t) {
        cout << "Yes"<<endl;
    }
    else {
        cout << "No"<<endl;
    }
    }
}


int main ()
{
    read();
    return 0;
}
