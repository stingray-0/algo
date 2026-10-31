#include <bits/stdc++.h>
using namespace std;


bool cmp (pair<int, int>& a, pair<int, int>& b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}


int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> movie(n);

    int a, b;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        movie[i] = {a, b};
    }

    sort(movie.begin(), movie.end(), cmp);

    int p1 = 0, p2 = 0;
    int count = 0;
    bool choose_smaller;

    while (p1 < n)
    {
        p2 = p1+1;
        choose_smaller = false;
        while (p2 < n && movie[p2].first < movie[p1].second)
        {
            if (movie[p2].second < movie[p1].second)
            {
                choose_smaller = true;
                break;
            }
            p2++;
        }
        if (!choose_smaller)
        {
            count ++;
        }
        p1 = p2;
    }

    cout << count;

    return 0;
}