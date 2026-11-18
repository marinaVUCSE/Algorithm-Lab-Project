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

    int adj_mat[n][n];
    memset(adj_mat, 0, sizeof(adj_mat));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 1;
        }
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << nl;
    }

    return 0;
}
