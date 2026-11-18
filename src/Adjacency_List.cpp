#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n]; // array of vector

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // undirected
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int x : adj_list[i])
            cout << x << " ";

        cout << nl;
    }

    return 0;
}
