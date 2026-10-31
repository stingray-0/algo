#include <bits/stdc++.h>
using namespace std;


void fill(int row, int column, vector<vector<int>>& v)
{
    set<int> nums;
    for (int i = 0; i < 500; i++)
    {
        nums.insert(i);
    }
    for (int i = 0; i < row; i++)
    {
        nums.erase(v[i][column]);
    }
    for (int i = 0; i < column; i++)
    {
        nums.erase(v[row][i]);
    }
    v[row][column] = *nums.begin();
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        grid[i][0] = i;
        grid[0][i] = i;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            fill(i, j, grid);
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