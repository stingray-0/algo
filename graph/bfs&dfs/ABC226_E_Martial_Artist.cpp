#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<int> time(n, 0);
    vector<vector<int>> prerequisite(n, vector<int>());
    vector<bool> learn(n, 0);
    
    int move;
    for (int i = 0; i < n; i++)
    {
        cin >> time[i] >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> move;
            prerequisite[i].push_back(move-1);
        }
    }

    long long total_time = time[n-1];
    queue<int> q;
    q.push(n-1);
    learn[n-1] = 1;

    while (!q.empty())
    {
        move = q.front();
        q.pop();
        for (int i : prerequisite[move])
        {
            if (!learn[i])
            {
                learn[i] = 1;
                total_time += time[i];
                q.push(i);
            }
        }
    }

    cout << total_time << '\n';



    return 0;
}