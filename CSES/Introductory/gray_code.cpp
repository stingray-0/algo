#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string ans = string(n, '0'), prev;
    cout << ans << '\n';
    set<string> numbers;
    numbers.insert(ans);
    int i = 0;
    while (numbers.size() < pow(2, n))
    {
        prev = ans;
        if (ans[i]-'0')
        {
            ans[i] = '0';
        }
        else 
        {
            ans[i] = '1';
        }
        if (numbers.find(ans) != numbers.end())
        {
            i++;
            ans = prev;
        }
        else
        {
            i = 0;
            numbers.insert(ans);
            cout << ans << '\n';
        }
    }
    return 0;
}