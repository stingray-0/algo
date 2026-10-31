#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> knight_moves = {{1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1}};

void fill(vector<vector<int>>& v, int size)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    int moves = 0;

    while (!q.empty())
    {
        int r = q.front().first, c = q.front().second;
        for(auto [move_r, move_c] : knight_moves)
        {
            int new_r = r + move_r, new_c = c + move_c;
            if (new_r >= 0 && new_c >= 0 && new_r < size && new_c < size && v[new_r][new_c] == -1)
            {
                v[new_r][new_c] = v[r][c] + 1;
                q.push({new_r, new_c});
            }
        }
        q.pop();
    }
}


int main()
{
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, -1));
    board[0][0] = 0;

    fill(board, n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << ' '; 
        }
        cout << '\n';
    }
}