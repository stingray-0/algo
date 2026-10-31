#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    
    unordered_map<char, int> mp;

    for (char c : s)
    {
        mp[c]++;
    }
    string half = "", middle = "";
    for (auto i : mp)
    {
        if (i.second%2)
        {
            middle += i.first;
            half += string((i.second-1)/2, i.first);
        }
        else
        {
            half += string(i.second/2, i.first);
        }
    }
    if (middle.length() > 1)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        cout << half + middle;
        reverse(half.begin(), half.end());
        cout << half << '\n';
    }

    return 0;
}