#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<ll>> tramp(n, vector<ll>(3, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> tramp[i][0] >> tramp[i][1] >> tramp[i][2];
    }

    vector<vector<ll>> edge(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = (abs(tramp[i][0] - tramp[j][0]) + abs(tramp[i][1] - tramp[j][1]) + tramp[i][2] - 1)/tramp[i][2];
        }
    }

    vector<vector<ll>> power(n, vector<ll>(n, LLONG_MAX));
    
    for (int i = 0 ;i < n; i++)
    {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, i});
        power[i][i] = 0;
        ll cur_power, cur_v;
        while (!pq.empty())
        {
            cur_power = pq.top().first;
            cur_v = pq.top().second;
            pq.pop();

            if (cur_power > power[i][cur_v])
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                if (power[i][j] > max(cur_power, edge[cur_v][j]))
                {
                    power[i][j] = max(cur_power, edge[cur_v][j]);
                    pq.push({power[i][j], j});
                }
            }
        }
    }


    ll ans = LLONG_MAX;
    for(int i = 0 ;i < n; i++)
    {
        ll one_ans = 0;
        for (int j = 0; j < n; j++)
        {
            one_ans = max(one_ans, power[i][j]);
        }
        ans = min(ans, one_ans);
    }

    cout << ans;

    return 0;
}