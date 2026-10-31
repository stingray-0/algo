#include<bits/stdc++.h>
using namespace std;


int find_paths(string& path, int move, int x_pos, int y_pos, vector<vector<int>>& visited_grids)
{
    if (x_pos == 0 && y_pos == 6) return move == 48;
    if (move == 48) return 0; 
    if (visited_grids[x_pos][y_pos] == 1) return 0;


    int up = y_pos > 0 ? visited_grids[x_pos][y_pos-1] : -1;
    int down = y_pos < 6 ? visited_grids[x_pos][y_pos+1] : -1;
    int left = x_pos > 0 ? visited_grids[x_pos-1][y_pos] : -1;
    int right = x_pos < 6 ? visited_grids[x_pos+1][y_pos] : -1;

    if (up && down && !left && !right) return 0;
    if (!up && !down && left && right) return 0;

    if (up > -1 && left > -1)
    {
        if (visited_grids[x_pos-1][y_pos-1] == 1 && !up && !left) return 0;
    }
    if (up > -1 && right > -1)
    {
        if (visited_grids[x_pos+1][y_pos-1] == 1 && !up && !right) return 0;
    }
    if (down > -1 && left > -1)
    {
        if (visited_grids[x_pos-1][y_pos+1] == 1 && !down && !left) return 0;
    }
    if (down > -1 && right > -1)
    {
        if (visited_grids[x_pos+1][y_pos+1] == 1 && !down && !right) return 0;
    }


    visited_grids[x_pos][y_pos] = 1;
    
    int possible_paths = 0;

    if ((path[move] == 'U' || path[move] == '?') && y_pos > 0)
    {
        possible_paths += find_paths(path, move+1, x_pos, y_pos-1,visited_grids);
    }
    if ((path[move] == 'D' || path[move] == '?') && y_pos < 6)
    {
        possible_paths += find_paths(path, move+1, x_pos, y_pos+1, visited_grids);
    }
    if ((path[move] == 'L' || path[move] == '?') && x_pos > 0)
    {
        possible_paths += find_paths(path, move+1, x_pos-1, y_pos, visited_grids);
    }
    if ((path[move] == 'R' || path[move] == '?') && x_pos < 6 )
    {
        possible_paths += find_paths(path, move+1, x_pos+1, y_pos, visited_grids);
    }

    visited_grids[x_pos][y_pos] = 0;
    return possible_paths;
}

int main()
{
    string path; 
    cin >> path;
    vector<vector<int>> empty_grid(7, vector<int>(7, 0));
    cout << find_paths(path, 0, 0, 0, empty_grid);
    return 0;
}


