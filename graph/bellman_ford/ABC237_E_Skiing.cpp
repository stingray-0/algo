// this will TLE so idk why it is listed in the category

#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m;
    cin >> n >> m;
    vector<ll> height(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> height[i];
    }
    vector<vector<ll>> edges;
    ll u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        if (height[u] >= height[v])
        {
            edges.push_back({u, v, height[u]-height[v]});
            edges.push_back({v, u, 2*(height[v]-height[u])});
        } 
        else
        {
            edges.push_back({v, u, height[v]-height[u]});
            edges.push_back({u, v, 2*(height[u]-height[v])});
        }
    }
    vector<ll> hap(n+1, LLONG_MIN);
    hap[1] = 0;
    ll wt;
    ll max_hap = 0;
    for (int i = 0 ;i < n; i++)
    {
        for (auto& edge : edges)
        {
            u = edge[0];
            v = edge[1];
            wt = edge[2];
            if (hap[u] != LLONG_MIN && hap[u] + wt > hap[v])
            {
                hap[v] = hap[u] + wt;
                if (hap[v] > max_hap)
                {
                    max_hap = hap[v];
                }
            }
        }
    }

    cout << max_hap << '\n';




    return 0;
}