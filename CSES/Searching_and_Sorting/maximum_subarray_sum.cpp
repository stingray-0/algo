#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    long long max_sum = arr[0];
    long long max_from_here = arr[0];

    for (int i = 1; i < n; i++)
    {
        max_from_here = max_from_here * (max_from_here + arr[i] > arr[i]) + arr[i];
        max_sum = max_sum > max_from_here ? max_sum : max_from_here;
    }

    cout << max_sum << '\n';

    return 0;
}