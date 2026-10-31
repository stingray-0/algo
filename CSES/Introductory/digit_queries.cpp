#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    long long k;
    while (q--)
    {
        cin >> k;
        if (k < 10)
        {
            cout << k << '\n';
            continue;
        }
        
        long long n = 1, p = 1;
        while(k - n*9*p > 0)
        {
            k -= n*9*p;
            p*= 10;
            n++;
        }
        string num = to_string((k-1)/n + p);
        cout << num[(k-1)%n] << '\n';
    }
    
    return 0;
}