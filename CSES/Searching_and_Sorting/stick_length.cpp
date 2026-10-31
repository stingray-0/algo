#include <bits/stdc++.h>
using namespace std;


int main ()
{
    int n;
    cin >> n;
    
    vector<long long> sticks(n);

    for (int i = 0; i < n; i++)
    {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());
    long long mode;
    int count = 1;
    int max_count = -1;
    for (int i = 0; i < n-1; i++)
    {
        if (sticks[i] == sticks[i+1])
        {
            count++;
            if (count > max_count)
            {
                max_count = count;
                mode = sticks[i];
            }
        }
        else
        {
            count = 1;
        }
    }
    long long mode_sum = 0;
    for (auto& i : sticks)
    {
        mode_sum += abs(i-mode);
    }
    long long medium = 0;
    if (n%2)
    {
        medium = sticks[(n-1)/2];
    }
    else
    {
        medium = (sticks[n/2] + sticks[n/2-1])/2;
    }

    long long medium_sum = 0;
    for (auto& i : sticks)
    {
        medium_sum += abs(i-medium);
    }    
    cout << min(mode_sum, medium_sum);


    return 0;
}