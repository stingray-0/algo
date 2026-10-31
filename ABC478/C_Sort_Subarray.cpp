#include <bits/stdc++.h>
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

    int increase_left = 1;
    int increase_right = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] >= v[i-1])
        {
            increase_left++;
        }
        else
        {
            break;
        }
    }

    for (int i = n-1; i > 0; i--)
    {
        if (v[i] >= v[i-1])
        {
            increase_right++;
        }
        else
        {
            break;
        }
    }

    if (increase_right + increase_left < n-k)
    {
        cout << "No\n";
        return 0;
    }
    
    bool ans = false;

    for (int i = 0; i < n-k+1; i++)
    {
        if (i+1 > increase_left)
        {
            break;
        }
        if (n-(i+k+1) > increase_right)
        {
            continue;
        }
        vector<int> sub(v.begin()+i, v.begin()+i+k);
        sort(sub.begin(), sub.end());
        if (i == 0)
        {
            if (sub[k-1] <= v[i+k])
            {
                cout << "Yes\n";
                ans = true;
                break;
            }
        }
        else if(sub[0] >= v[i-1] && sub[k-1] <= v[i+k])
        {
            cout << "Yes\n";
            ans = true;
            break;
        }
    }
    if (!ans)
    {
        cout << "No\n";
    }


    return 0;
}