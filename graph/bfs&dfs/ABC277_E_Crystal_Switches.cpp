#include<bits/stdc++.h>
using namespace std;


// skip



int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
    vector<vector<bool>> visited(n+1, vector<bool>(2, 0));
    vector<bool> switches(n+1, 0);

    int v1, v2, s, a;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> a;
        adj[v1].push_back({v2, a});
        adj[v2].push_back({v1, a});
    }

    for (int i = 0; i < k; i++)
    {
        cin >> s;
        switches[s] = 1;
    }


    deque<vector<int>> q;
    q.push_back({1, 0, 0});
    //v, move, switch
    int cur_v, cur_move, cur_switch = 0;
    int ans = -1;
    while (!q.empty())
    {
        cur_v = q.front()[0];
        cur_move = q.front()[1];
        cur_switch = q.front()[2];
        visited[cur_v][cur_switch] = 1;
        q.pop_front();
        if (cur_v == n)
        {
            ans = cur_move;
            break;
        }
        if (switches[cur_v] && !visited[cur_v][cur_switch^1])
        {
            q.push_front({cur_v, cur_move, cur_switch^1});
        }
        for (auto& v : adj[cur_v])
        {
            if (cur_switch)
            {
                if (!v.second && !visited[v.first][cur_switch])
                {
                    q.push_back({v.first, cur_move+1, cur_switch});
                }
            }
            else
            {
                if (v.second && !visited[v.first][cur_switch])
                {
                    q.push_back({v.first, cur_move+1, cur_switch});
                }
            }
        }
    }

    cout << ans << '\n';


    return 0;
}