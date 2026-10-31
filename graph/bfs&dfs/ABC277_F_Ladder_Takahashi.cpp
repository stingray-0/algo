#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, vector<int>> adj;
    vector<bool> visited(1e9, 0);
    int v1, v2;
    for (int i = 0; i < n; i++)
    {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    queue<int> q;
    int max_floor = 1;
    int cur_floor;
    q.push(1);
    visited[0] = 1;
    
    while (!q.empty())
    {
        cur_floor = q.front();
        q.pop();
        if (cur_floor > max_floor)
        {
            max_floor = cur_floor;
        }
        for (int i : adj[cur_floor])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    cout << max_floor << '\n';

    return 0;
}