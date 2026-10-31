#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> h(n+1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    vector<vector<int>> adj(n+1, vector<int>());

    int v1, v2;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1); 
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> penalty(n+1, LLONG_MAX);
    penalty[1] = 0;

    pq.push({0 , 1});
    int cur_v;
    ll cur_penalty;
    while (!pq.empty())
    {
        cur_penalty = pq.top().first;
        cur_v = pq.top().second;
        pq.pop();
        
        if (cur_penalty > penalty[cur_v])
        {
            continue;
        }

        for (int v : adj[cur_v])
        {
            if (h[v] > h[cur_v])
            {
                if (cur_penalty + h[v] - h[cur_v] < penalty[v])
                {
                    penalty[v] = cur_penalty + h[v] - h[cur_v];
                    pq.push({penalty[v], v});
                }
            }
            else
            {
                if (cur_penalty < penalty[v])
                {
                    penalty[v] = cur_penalty;
                    pq.push({cur_penalty, v});
                }
            }
        }
    }


    // for (int i : penalty)
    // {
    //     cout << i << ' ';
    // }

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, h[1] - h[i] - penalty[i]);
    }

    cout << ans;

    return 0;
}