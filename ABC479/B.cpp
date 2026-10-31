#define ll long long

#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    cin >> s;

    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            cur++;
        }
        else
        {
            cur = 0;
        }
        ans = max(cur, ans);
    }

    cout << ans;




    return 0;
}