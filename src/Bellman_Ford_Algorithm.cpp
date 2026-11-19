#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
using ll = long long int;

int dis[105];
int n, e, a, b, w;
vector<pair<int, pair<int, int>>> edge_list;

void bellman_ford()
{
    for (int i = 0; i < n-1; i++)
    {
        for (auto e : edge_list)
        {
            a = e.first;
            b = e.second.first;
            w = e.second.second;

            if (dis[a] != INT_MIN && dis[a] + w < dis[b])
                dis[b] = dis[a] + w;
        }
    }
    bool cycle = false;
    for (auto e : edge_list)
    {
        a = e.first;
        b = e.second.first;
        w = e.second.second;

        if (dis[a] != INT_MIN && dis[a] + w < dis[b])
        {
            cycle = true;
            break;
        }
    }

    if(cycle)
        cout << "Negative weighted cycle detected" << nl;
    else
    {
        for (int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << nl;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> e;

    while (e--)
    {
        cin >> a >> b >> w;
        edge_list.push_back({a, {b, w}});
        // edge_list.push_back({b,{a,w}}); undirected
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;
    bellman_ford();

    return 0;
}