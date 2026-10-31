#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    long long moves = 0 ;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i-1])
        {
            moves += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }

    cout << moves;

    return 0;
}