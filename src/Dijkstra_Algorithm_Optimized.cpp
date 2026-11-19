#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
using ll = long long int;

vector<pair<int, int>> adj_list[100];
int dis[105];

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int p_dis = p.first;
        int p_node = p.second;

        for (auto c : adj_list[p_node])
        {
            int c_node = c.first;
            int c_dis = c.second;

            if (p_dis + c_dis < dis[c_node])
            {
                dis[c_node] = p_dis + c_dis;
                pq.push({dis[c_node], c_node});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, e, s;
    cin >> n >> e;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj_list[a].push_back({b, w});
        // adj_list[b].push_back({a,w});
    }

    // memset(dis,INT_MAX,sizeof(dis));
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    // cin >> s;
    dijkstra(0);

    for (int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << nl;
    return 0;
}