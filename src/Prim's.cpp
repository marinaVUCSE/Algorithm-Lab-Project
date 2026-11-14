#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e, cost = 0, a, b, w, edge_count = 0;
    cin >> n >> e;

    int adj_mat[n][n];
    memset(adj_mat, 0, sizeof(adj_mat));

    while (e--)
    {
        cin >> a >> b >> w;
        adj_mat[a][b] = w;
        adj_mat[b][a] = w;
    }

    bool selected[n] = {false};
    selected[0] = true;

    cout << endl << "Minimum Spanning Tree: " << endl;
    while (edge_count < n - 1)
    {
        int s, e, m = INT_MAX;
        
        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (selected[j] == false && adj_mat[i][j] != 0 && adj_mat[i][j] < m)
                    {
                        s = i;
                        e = j;
                        m = adj_mat[i][j];
                    }
                }
            }
        }
        cout << s << " " << e << " " << m << endl;
        edge_count++;
        cost += m;
        selected[e] = true;
    }
    cout << endl << "Total cost " << cost;
}