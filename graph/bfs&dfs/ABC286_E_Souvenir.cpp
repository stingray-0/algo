#define ll long long

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;

    vector<int> souvenir(n+1, 0);
    vector<vector<int>> adj(n+1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        cin >> souvenir[i];
    }

    char c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            if (c == 'Y')
            {
                adj[i].push_back(j);
            }
        }
    }

    vector<vector<ll>> value(n+1, vector<ll>(n+1, -1));
    vector<vector<int>> dist(n+1, vector<int>(n+1, INT_MAX));
    for (int start = 1; start <= n; start++)
    {
        value[start][start] = souvenir[start];
        dist[start][start] = 0;
        
        queue<int> q;
        q.push(start);
        int cur_v;

        while (!q.empty())
        {
            cur_v = q.front();
            q.pop();

            for(int v : adj[cur_v])
            {
                if (dist[start][cur_v] + 1 < dist[start][v])
                {
                    dist[start][v] = dist[start][cur_v] + 1;
                    value[start][v] = value[start][cur_v] + souvenir[v];
                    q.push(v);
                }
                else if (dist[start][cur_v] + 1 == dist[start][v])
                {
                    value[start][v] = max(value[start][v], value[start][cur_v] + souvenir[v]);
                }
            }
        }
    }

    int queries, v1, v2;
    cin >> queries;
    for (int i = 0; i < queries; i++)
    {
        cin >> v1 >> v2;
        if (dist[v1][v2] == INT_MAX)
        {
            cout << "Impossible\n";
        }
        else
        {
            cout << dist[v1][v2] << ' ' << value[v1][v2] << '\n';
        }
    }


    

    return 0;
}