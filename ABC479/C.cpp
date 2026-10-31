#define ll long long

#include<bits/stdc++.h>
using namespace std;

ll find_max(int i, int n, int w, vector<pair<int, int>>& dish)
{
    if (i == n)
    {
        if (w >= dish[i].second)
        {
            return dish[i].first;
        }
        return 0;
    }
    ll take = 0;
    if (w >= dish[i].second)
    {
        take =  dish[i].first + find_max(i+1, n, w-dish[i].second, dish);
    }
    ll not_take = find_max(i+1, n, w, dish);

    return max(not_take, take);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, w;
    cin >> n >> w;
    vector<pair<int, int>> dish(n, {0, 0});

    for (int i = 0; i < n; i++)
    {
        cin >> dish[i].first >> dish[i].second;
    }

    cout << find_max(0, n-1, w, dish);

    return 0;
}