#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, e;
    cin >> n >> e;
    vector<pair<int, int>> edge_list;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        edge_list.push_back({a, b});
    }
    for (auto p : edge_list)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
