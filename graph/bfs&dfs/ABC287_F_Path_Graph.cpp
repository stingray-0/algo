#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>());
    vector<bool> visited(n+1, 0);
    int v1, v2;
    for (int i = 0; i < m ; i++)
    {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    queue<pair<int, int>> q;
    q.push({1, -1});
    visited[1] = 1;
    int node, parent;
    while(!q.empty())
    {
        node = q.front().first;
        parent = q.front().second;
        q.pop();

        if (adj[node].size() > 2)
        {
            cout << "No\n";
            return 0;
        }
        for (int i : adj[node])
        {
            if (i == parent) continue;
            if (visited[i])
            {
                cout << "No\n";
                return 0;
            }
            q.push({i, node});
            visited[i] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";




    return 0;
}