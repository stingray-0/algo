#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int ans = 0;
    int power = 1;
    while (n >= pow(5,power))
    {
        // cout << pow(5, power);
        ans += n/pow(5,power);
        power++;
    }
    cout << ans;
    return 0;
}