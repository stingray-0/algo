#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    bool possible =  true;
    for (int i = 0; i < s.size()-1; i++)
    {
        if (s[i] == s[i+1])
        {
            int j = i+1;
            while(s[i] == s[j])
            {
                j++;
                if (j == s.size())
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                swap(s[i+1], s[j]);
            }
            else
            {
                break;
            }
        }
    }
    possible = true;
    for (int i = s.size()-1; i > 0; i--)
    {
        if (s[i] == s[i-1])
        {
            int j = i-1;
            while(s[i] == s[j])
            {
                j--;
                if (j == -1)
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                swap(s[i-1], s[j]);
            }
            else
            {
                break;
            }
        }
    }
    if (possible)
    {
        cout << s;
    }
    else
    {
        cout << -1;
    }
}