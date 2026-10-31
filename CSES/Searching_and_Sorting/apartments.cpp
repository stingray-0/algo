#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m , k;
    cin >> n >> m >> k;

    vector<int> apt(n);
    vector<int> demand(m);

    for (int i = 0; i < n; i++)
    {
        cin >> apt[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> demand[i];
    }

    sort(apt.begin(), apt.end());

    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(demand[i] - apt[j]) <= k)
            {
                int diff = demand[i] - apt[j];
                while (j != n-1 && demand[i] - apt[j+1] < diff)
                {
                    diff = demand[i] - apt[j+1];
                    j++;
                }
                apt.erase(apt.begin()+j);
                count ++;
                break;
            }
        }
        
    }
    cout << count;



    return 0;
}