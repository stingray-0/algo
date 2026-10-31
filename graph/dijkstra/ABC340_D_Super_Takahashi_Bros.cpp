#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b, x;
    cin >> n;

    vector<vector<pair<ll, int>>> adj(n+1, vector<pair<ll, int>>());
    vector<ll> dist(n+1, LLONG_MAX);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> x;
        adj[i].push_back({a, i+1});
        adj[i].push_back({b, x});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    ll cur_dist;
    int cur_lvl;

    while (!pq.empty())
    {
        cur_dist = pq.top().first;
        cur_lvl = pq.top().second;
        pq.pop();

        for (auto& i : adj[cur_lvl])
        {
            if (cur_dist + i.first < dist[i.second])
            {
                dist[i.second] = cur_dist + i.first;
                pq.push({dist[i.second], i.second});
            }
        }
    }


    cout << dist[n] << '\n';


    return 0;
}