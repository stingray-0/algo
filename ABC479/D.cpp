#define ll long long
#include<bits/stdc++.h>
using namespace std;

const ll inf = 1e10;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    vector<ll> left(n, inf);
    vector<ll> right(n, inf);
    vector<ll> smallest_right(n, inf);
    vector<ll> smallest_left(n, inf);

    for (int i = 1; i < n; i++)
    {
        cin >> left[i];
    }
    for (int i = n-1; i > 0; i--)
    {
        smallest_left[i-1] = min(smallest_left[i], left[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        cin >> right[i];
        smallest_right[i+1] = min(smallest_right[i], right[i]);
    }


    for (int i = 0 ;i < q; i++)
    {
        ll s, t;
        cin >> s >> t;
        if (s < t)
        {
            cout << min(right[s-1], left[s-1] + smallest_right[s-1]) << '\n';
        }
        else
        {
            cout << min(left[s-1], right[s-1]+ smallest_left[s-1])<< '\n';
        }
    }


    return 0;
}