#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix)
{
    vector<int> ans;

    if (matrix.size() == 0)
        return ans;

    int R = matrix.size(), C = matrix[0].size();
    vector<vector<bool> > seen(R, vector<bool>(C, false));
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
    int r = 0, c = 0, di = 0;
    for (int i = 0; i < R * C; i++) {
        ans.push_back(matrix[r]);
        seen[r] = true;
        int cr = r + dr[di];
        int cc = c + dc[di];

        if (0 <= cr && cr < R && 0 <= cc && cc < C
            && !seen[cr][cc]) {
            r = cr;
            c = cc;
        }
        else {
            di = (di + 1) % 4;
            r += dr[di];
            c += dc[di];
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int x;
    vector<vector<int> > a;
    for (int i=0;i<n;i++)
    {
        vector <int> b;
        for (int j=0;j<m;j++)
    {
        cin>>x;
        b.push_back(x);
    }
    a.push_back(b);
    }

    for (int x : spiralOrder(a)) {
        cout << x << " ";
    }
    return 0;
}
