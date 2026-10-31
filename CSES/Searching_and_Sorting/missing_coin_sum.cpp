#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> coins;

vector<ll> find_possible(int l)
{
    vector<ll> v;
    if (l== 1)
    {
        v.push_back(coins[0]);
    }
    else
    {
        vector<ll> v_last = find_possible(l-1);
        ll cur = coins[l-1];
        v.push_back(cur);
        for (auto &i : v_last)
        {
            v.push_back(i + cur);
        }
        v.insert(v.end(), v_last.begin(), v_last.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    return v;
}


int main()
{
    cin >> n;
    coins.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<ll> possible = find_possible(n);
    sort(possible.begin(), possible.end());
    for (int i = 0; i < n-1; i++)
    {
        if ((possible[i+1] - possible[i])!= 1)
        {
            cout << possible[i] + 1;
            break;
        }
    }
    return 0;
}