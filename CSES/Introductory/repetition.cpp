#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p = 0;
    std::string dna;
    cin >> dna;

    int l = dna.length();
    int max_l = 1;

    for (int i = 1; i < l; i++)
    {
        if (dna[i] != dna[p])
        {
            if (i-p > max_l)
            {
                max_l = i-p;
            }
            p = i;
        }
    }
    if (l-p > max_l)
    {
        max_l = l-p;
    }
    cout << max_l;

    return 0;
}