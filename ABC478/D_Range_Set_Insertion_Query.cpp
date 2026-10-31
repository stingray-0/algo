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
    set<int> s;
    vector<int> count(200001, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j : set_helper[i])
        {  
            if (j > 0)
            {
                count[j]++;
                s.insert(j);
            }
            else
            {
                count[-j]--;
                if (count[-j] == 0)
                {
                    s.erase(-j);
                }
            }
        }
        cout << s.size() << '\n';
    }
    return 0;
}