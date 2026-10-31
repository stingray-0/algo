#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a = m/n;
    int b = m%n;

    for (int i = 0; i < n; i++)
    {
        if (i < b)
        {
            cout << a+1 << '\n';
        }
        else
        {
            cout << a << '\n';
        }
    }

    return 0;
}