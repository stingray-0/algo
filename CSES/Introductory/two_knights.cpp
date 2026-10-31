#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for (long long i = 1; i <= n; i++)
    {
        cout << (i*i*(i*i-1) - (i-1)*(i-2)*8)/2 << '\n';
    }
}