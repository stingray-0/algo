#include <bits/stdc++.h>
using namespace std;


int max_hap(int i, int v, vector<int>& hap, int n, int ccf) //ccf means can choose left
{
    if (ccf == 0)
    {
        return 0;
    }
    if (i == n)
    {
        return hap[n]*(v >= i);
    }

    if (v < i)
    {
        return 0;
    }

    return max(max_hap(i+1, v, hap, n, ccf), hap[i] + max_hap(i+1, v-i, hap, n, ccf-1));
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, v;
    cin >> n >> v;

    vector<int> hap(n+1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> hap[i];
    }
    
    cout << max_hap(1, v, hap, n, 3) << '\n';


    return 0;
}