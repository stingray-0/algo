#define ll long long

#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    cin >> n;
    ll total = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (i%2)
        {
            total += a;
        }
    }

    cout << total<< '\n';



    return 0;
}