#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n%4 == 1 || n%4 == 2)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n" << n/2 << '\n';
        for (int i = 1; i <= n/4; i++) cout << i <<' ';
        for (int i = n; i > 3*n/4; i--) cout << i << ' ';
        cout <<'\n' << (n+1)/2 << '\n';
        for (int i = n/2; i > n/4; i--) cout << i << ' ';
        for (int i = n/2+1; i <= 3*n/4; i++) cout << i << ' ';
    }

    return 0;
}