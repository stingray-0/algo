#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << n;
    }
    else if (n < 4)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        int num = 2;
        int even_count = n/2;
        for (int i = 0; i < even_count; i++)
        {
            cout << num << ' ';
            num += 2;
        }
        
        num = 1;
        int odd_count = n - n/2;
        for (int i = 0; i < odd_count; i++)
        {
            cout << num << ' ';
            num += 2;
        }
    }

    return 0;
}