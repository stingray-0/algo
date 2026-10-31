#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end());
    // we can compare the sorted array and the original array to see if it is possible to achieve 
    // an ascending array at the size of k

    int l = 0, r = n-1;
    while (l < n && sorted_v[l] == v[l])
    {
        l++;
    }

    while (r >= 0 && sorted_v[r] == v[r])
    {
        r--;
    }


    if (r - l + 1 <= k)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}