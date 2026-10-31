#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end());

    int p1 = 0, p2 = n-1;

    int found = false;

    while (p1 < p2)
    {
        if (sorted_v[p1] + sorted_v[p2] == target)
        {
            found = true;
            break;
        }

        if (sorted_v[p1] + sorted_v[p2] > target)
        {
            p2--;
        }
        else
        {
            p1++;
        }
    }

    bool find1 = false, find2 = false;
    if (!found)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] == sorted_v[p1] && !find1)
            {
                cout << i+1 << ' ';
                find1 = true;
            }
            else if (v[i] == sorted_v[p2] && !find2)
            {
                cout << i+1 << ' ';
                find2 = true;
            }
        }
    }


    return 0;
}