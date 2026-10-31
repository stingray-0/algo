#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long x, y;
        cin >> y >> x;
        if (x > y)
        {
            if (x%2)
            {
                cout << x*x - y + 1 << '\n';
            }
            else
            {
                cout << (x-1)*(x-1) + y << '\n';
            }
        }
        else
        {
           if (y%2)
           {
                cout << (y-1)*(y-1) + x << '\n';
           }
           else
           {
                cout << y*y - x + 1 << '\n';
           }
        }
    }

    return 0;
}