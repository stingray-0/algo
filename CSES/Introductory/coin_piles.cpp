#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, left, right;
    cin >> n;
    while (n--)
    {
        cin >> left >> right;
        if ((left == 0 && right == 0) || (left && right && max(left,right) <= min(left, right)*2 && (right+left)%3 == 0))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}