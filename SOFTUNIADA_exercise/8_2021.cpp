#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int K;
struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (cost < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

        return cost;
}
string names[10000];
int costs[10000];
int cap[10000];
void read()
{
    cin>>K;
    int i=0;
    char trash;
    cin>>names[i];
    i++;

    while(true)
    {
        cin.get(trash);
        cin.get(trash);
        if(isalpha(trash))
        {
            cin>>names[i];
            names[i]=trash+names[i];
            i++;
            continue;
        }
        else break;

    }
    for (int j=1;j<i;j++)
    {
        cin>>costs[j];
    }
    for (int j=1;j<i;j++)
    {
        cin>>cap[j];
    }

    vector<Edge> edges;
    Edge e;
    for (int j=1;j<=i;j++)
    {
            e.from=0;
            e.to=j;
            e.capacity=cap[j];
            e.cost=costs[j];
            edges.push_back(e);
    }
    for (int j=1;j<=i;j++)
    {
            e.from=j;
            e.to=i+1;
            e.capacity=cap[j];
            e.cost=costs[j];
            edges.push_back(e);
    }
    cout<<min_cost_flow(i+2,edges,0,i+1)<<endl;
}
int main ()
{
    read();

    return 0;
}
