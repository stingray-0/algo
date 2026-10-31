#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> possibles;
    vector<vector<int>> grid(n, vector(n, -1));
    for (int dx = 0; dx < n; dx++)
    {
        for (int dy = 0; dy < n; dy++)
        {
            if (dx == 0 && dy == 0) continue;
            if (dx*dx + dy*dy == m)
            {
                possibles.push_back({dx,dy});
                possibles.push_back({-dx,dy});
                possibles.push_back({-dx,-dy});
                possibles.push_back({dx,-dy});
            }
        }
    }

    grid[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (auto& p : possibles)
        {
            int new_x = cur_x + p.first;
            int new_y = cur_y + p.second;
            if (new_x < n && new_x >= 0 && new_y < n && new_y >= 0 && grid[new_x][new_y] < 0)
            {
                grid[new_x][new_y] = grid[cur_x][cur_y]+1;
                q.push({new_x, new_y});
            }

        }

    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}