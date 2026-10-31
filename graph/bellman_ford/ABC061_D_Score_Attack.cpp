#define ll long long
#include <bits/stdc++.h>
using namespace std;

const ll neg_inf = -1e15;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    
    ll u, v, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<ll> score(n+1, neg_inf);

    score[1] = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (auto& edge : edges)
        {
            u = edge[0];
            v = edge[1];
            wt = edge[2];

            if (score[u] != neg_inf && score[u] + wt > score[v])
            {
                score[v] = score[u] + wt;
            }
        }
    }

    vector<bool> is_inf(n+1, false);

    for (int i = 0; i < n; i++)
    {
        for (auto& edge : edges)
        {
            u = edge[0];
            v = edge[1];
            wt = edge[2];

            if (score[u] != neg_inf && score[u] + wt > score[v])
            {
                is_inf[v] = true;
                score[v] = score[u] + wt;
            }
        }
    }

    if (is_inf[n])
    {
        cout << "inf\n";
    }
    else
    {
        cout << score[n] << '\n';
    }


    return 0;
}