#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t, n, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        vector<int> player_1(n);
        vector<int> player_2(n);
        if ((a == b || a*b != 0) && a+b <= n)
        {
            cout << "YES\n";
            for (int i = n; i > a+b; i--)
            {
                player_1[i-1] = i;
                player_2[i-1] = i;
            }
            for (int i = 0; i < a+b; i++)
            {
                player_1[i] = i+1;
                player_2[i] = (a+i)%(a+b)+1; 
            }
            for (auto &i : player_1)
            {
                cout << i << ' ';
            }
            cout << '\n';
            for (auto &i : player_2)
            {
                cout << i << ' ';
            }
            cout << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }
}