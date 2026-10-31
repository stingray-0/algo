#include <bits/stdc++.h>
using namespace std;


int main()
{
    int h, w;
    cin >> h >> w;
    
    vector<vector<char>> grid(h+2, vector<char>(w+2, '#'));
    vector<vector<int>> dis(h+2, vector<int>(w+2, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'E')
            {
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (grid[i+1][j] != '#' && dis[i+1][j] > dis[i][j] + 1)
        {
            grid[i+1][j] = '^';
            dis[i+1][j] = dis[i][j]+1;
            q.push({i+1, j});
        }
        if (grid[i-1][j] != '#' && dis[i-1][j] > dis[i][j] + 1)
        {
            grid[i-1][j] = 'v';
            dis[i-1][j] = dis[i][j]+1;
            q.push({i-1, j});
        }
        if (grid[i][j+1] != '#' && dis[i][j+1] > dis[i][j] + 1)
        {
            grid[i][j+1] = '<';
            dis[i][j+1] = dis[i][j]+1;
            q.push({i, j+1});
        }
        if (grid[i][j-1] != '#' && dis[i][j-1] > dis[i][j] + 1)
        {
            grid[i][j-1] = '>';
            dis[i][j-1] = dis[i][j]+1;
            q.push({i, j-1});
        }
    }
    
    
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cout << grid[i][j];
        }
        cout << '\n';
    }


    return 0;
}