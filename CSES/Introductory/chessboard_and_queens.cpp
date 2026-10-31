#include <bits/stdc++.h>
using namespace std;


bool detect(vector<vector<int>> map, int row, int column)
{
    if (map[row][column] == 2) return false;

    for (int i = 0; i < row; i++)
    {
        if (map[i][column] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = column - 1; i >= 0 && j >= 0 ; i--, j--)
    {
        if (map[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = column + 1; i >= 0 && j < 8; i--, j++)
    {
        if (map[i][j] == 1) return false;
    }

    return true;
}
int place_queen(vector<vector<int>> map, int row)
{
    if (row == 8)
    {
        return 1;
    }       
    int count = 0;
    
    for (int i = 0; i < 8; i++)
    {
        if (map[row][i] == 2) continue;
  
        if (detect(map, row, i))
        {
            map[row][i] = 1;
            count += place_queen(map, row+1);
            map[row][i] = 0;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> board(8, vector(8, 0));
    char c;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> c;
            if (c == '*') board[i][j] = 2;
        }
    }
    cout << place_queen(board, 0);
}