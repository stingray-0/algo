#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ans = 1;
    while (n--)
    {
        ans = (ans<<1) % 1000000007;
    }
    cout << ans;
    
    return 0;
}