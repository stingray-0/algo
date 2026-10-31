#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> set_helper(n, vector<int>());
    int l, r, x;
    for (int i = 0 ;i < q; i++)
    {
        cin >> l >> r >> x;
        set_helper[l-1].push_back(x);
        if (r < n)
        {
            set_helper[r].push_back(-x);
        }
    }

    // we can use a map instead of a set and a large vector
    map<int, int> active_elements;
    for (int i = 0; i < n; i++)
    {
        for (int j : set_helper[i])
        {  
            if (j > 0)
            {
                active_elements[j]++;
            }
            else
            {
                active_elements[-j]--;
                if (active_elements[-j] == 0)
                {
                    active_elements.erase(-j);
                }
            }
        }
        cout << active_elements.size() << '\n';
    }
    return 0;
}