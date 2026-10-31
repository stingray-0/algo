#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> childs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> childs[i];
    }
 
    sort(childs.begin(), childs.end());
 
    int bp = n-1;
    int sp = 0;
    int basket = 0;
    int count = 0;
    int kid = 0;
    while (sp <= bp)
    {
        if (kid == 2)
        {
            count++;
            basket = 0;
            kid = 0;
        }
        if (basket+childs[bp] <= x)
        {
            basket += childs[bp--];
            kid++;
        }
        else if (basket + childs[sp] <= x)
        {
            basket += childs[sp++];
            kid++;
        }
        else
        {
            count++;
            basket = 0;
            kid = 0;
        }
 
    }
    count++;
    cout << count;
 
 
    return 0;
}